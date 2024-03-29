/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this
 * file except in compliance with the License. You may obtain a copy of the
 * License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

/*! \file upf_config.cpp
  \brief
  \author Lionel Gauthier
  \company Eurecom
  \email: lionel.gauthier@eurecom.fr
*/

#include "3gpp_conversions.hpp"
#include "async_shell_cmd.hpp"
#include "common_defs.h"
#include "conversions.hpp"
#include "get_gateway_netlink.hpp"
#include "if.hpp"
#include "logger.hpp"
#include "upf_config.hpp"
#include "string.hpp"
#include "fqdn.hpp"

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;
using namespace libconfig;
using namespace oai::config;

// C includes
#include <arpa/inet.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

namespace oai::config {
//------------------------------------------------------------------------------
int upf_config::execute() {
  return RETURNok;
}

//------------------------------------------------------------------------------
int upf_config::get_pfcp_node_id(pfcp::node_id_t& node_id) {
  node_id = {};
  if (fqdn.length() >= 3) {
    node_id.node_id_type = pfcp::NODE_ID_TYPE_FQDN;
    node_id.fqdn         = fqdn;
    return RETURNok;
  }
  if (n4.addr4.s_addr) {
    node_id.node_id_type    = pfcp::NODE_ID_TYPE_IPV4_ADDRESS;
    node_id.u1.ipv4_address = n4.addr4;
    return RETURNok;
  }
  if (n4.addr6.s6_addr32[0] | n4.addr6.s6_addr32[1] | n4.addr6.s6_addr32[2] |
      n4.addr6.s6_addr32[3]) {
    node_id.node_id_type    = pfcp::NODE_ID_TYPE_IPV6_ADDRESS;
    node_id.u1.ipv6_address = n4.addr6;
    return RETURNok;
  }
  return RETURNerror;
}
//------------------------------------------------------------------------------
int upf_config::get_pfcp_fseid(pfcp::fseid_t& fseid) {
  int rc = RETURNerror;
  fseid  = {};
  if (n4.addr4.s_addr) {
    fseid.v4           = 1;
    fseid.ipv4_address = n4.addr4;
    rc                 = RETURNok;
  }
  if (n4.addr6.s6_addr32[0] | n4.addr6.s6_addr32[1] | n4.addr6.s6_addr32[2] |
      n4.addr6.s6_addr32[3]) {
    fseid.v6           = 1;
    fseid.ipv6_address = n4.addr6;
    rc                 = RETURNok;
  }
  return rc;
}
//------------------------------------------------------------------------------
int upf_config::load_thread_sched_params(
    const Setting& thread_sched_params_cfg, util::thread_sched_params& cfg) {
  try {
    thread_sched_params_cfg.lookupValue(
        UPF_CONFIG_STRING_THREAD_RD_CPU_ID, cfg.cpu_id);
  } catch (const SettingNotFoundException& nfex) {
    Logger::upf_app().info(
        "%s : %s, using defaults", nfex.what(), nfex.getPath());
  }
  try {
    std::string thread_rd_sched_policy;
    thread_sched_params_cfg.lookupValue(
        UPF_CONFIG_STRING_THREAD_RD_SCHED_POLICY, thread_rd_sched_policy);
    util::trim(thread_rd_sched_policy);
    if (boost::iequals(thread_rd_sched_policy, "SCHED_OTHER")) {
      cfg.sched_policy = SCHED_OTHER;
    } else if (boost::iequals(thread_rd_sched_policy, "SCHED_IDLE")) {
      cfg.sched_policy = SCHED_IDLE;
    } else if (boost::iequals(thread_rd_sched_policy, "SCHED_BATCH")) {
      cfg.sched_policy = SCHED_BATCH;
    } else if (boost::iequals(thread_rd_sched_policy, "SCHED_FIFO")) {
      cfg.sched_policy = SCHED_FIFO;
    } else if (boost::iequals(thread_rd_sched_policy, "SCHED_RR")) {
      cfg.sched_policy = SCHED_RR;
    } else {
      Logger::upf_app().error(
          "thread_rd_sched_policy: %s, unknown in config file",
          thread_rd_sched_policy.c_str());
      return RETURNerror;
    }
  } catch (const SettingNotFoundException& nfex) {
    Logger::upf_app().info(
        "%s : %s, using defaults", nfex.what(), nfex.getPath());
  }

  try {
    thread_sched_params_cfg.lookupValue(
        UPF_CONFIG_STRING_THREAD_RD_SCHED_PRIORITY, cfg.sched_priority);
    if ((cfg.sched_priority > 99) || (cfg.sched_priority < 1)) {
      Logger::upf_app().error(
          "thread_rd_sched_priority: %d, must be in interval [1..99] in config "
          "file",
          cfg.sched_priority);
      return RETURNerror;
    }
  } catch (const SettingNotFoundException& nfex) {
    Logger::upf_app().info(
        "%s : %s, using defaults", nfex.what(), nfex.getPath());
  }

  try {
    thread_sched_params_cfg.lookupValue(
        UPF_CONFIG_STRING_THREAD_POOL_SIZE, cfg.thread_pool_size);
    Logger::upf_app().info("THREAD_POOL_SIZE : %d", cfg.thread_pool_size);
  } catch (const SettingNotFoundException& nfex) {
    Logger::upf_app().info(
        "%s : %s, using defaults", nfex.what(), nfex.getPath());
  }
  return RETURNok;
}
//------------------------------------------------------------------------------
int upf_config::load_itti(const Setting& itti_cfg, itti_cfg_t& cfg) {
  try {
    const Setting& sched_params_cfg =
        itti_cfg[UPF_CONFIG_STRING_ITTI_TIMER_SCHED_PARAMS];
    load_thread_sched_params(sched_params_cfg, cfg.itti_timer_sched_params);
  } catch (const SettingNotFoundException& nfex) {
    Logger::upf_app().info(
        "%s : %s, using defaults", nfex.what(), nfex.getPath());
  }

  try {
    const Setting& n3_sched_params_cfg =
        itti_cfg[UPF_CONFIG_STRING_N3_SCHED_PARAMS];
    load_thread_sched_params(n3_sched_params_cfg, cfg.n3_sched_params);
  } catch (const SettingNotFoundException& nfex) {
    Logger::upf_app().info(
        "%s : %s, using defaults", nfex.what(), nfex.getPath());
  }

  try {
    const Setting& n4_sched_params_cfg =
        itti_cfg[UPF_CONFIG_STRING_SX_SCHED_PARAMS];
    load_thread_sched_params(n4_sched_params_cfg, cfg.n4_sched_params);
  } catch (const SettingNotFoundException& nfex) {
    Logger::upf_app().info(
        "%s : %s, using defaults", nfex.what(), nfex.getPath());
  }

  try {
    const Setting& upf_app_sched_params_cfg =
        itti_cfg[UPF_CONFIG_STRING_SX_SCHED_PARAMS];
    load_thread_sched_params(
        upf_app_sched_params_cfg, cfg.upf_app_sched_params);
  } catch (const SettingNotFoundException& nfex) {
    Logger::upf_app().info(
        "%s : %s, using defaults", nfex.what(), nfex.getPath());
  }

  try {
    const Setting& async_cmd_sched_params_cfg =
        itti_cfg[UPF_CONFIG_STRING_ASYNC_CMD_SCHED_PARAMS];
    load_thread_sched_params(
        async_cmd_sched_params_cfg, cfg.async_cmd_sched_params);
  } catch (const SettingNotFoundException& nfex) {
    Logger::upf_app().info(
        "%s : %s, using defaults", nfex.what(), nfex.getPath());
  }

  return RETURNok;
}

//------------------------------------------------------------------------------
int upf_config::load_interface(const Setting& if_cfg, interface_cfg_t& cfg) {
  if_cfg.lookupValue(UPF_CONFIG_STRING_INTERFACE_NAME, cfg.if_name);
  util::trim(cfg.if_name);
  if (not boost::iequals(cfg.if_name, "none")) {
    std::string address = {};
    if_cfg.lookupValue(UPF_CONFIG_STRING_IPV4_ADDRESS, address);
    util::trim(address);
    if (boost::iequals(address, "read")) {
      if (get_inet_addr_infos_from_iface(
              cfg.if_name, cfg.addr4, cfg.network4, cfg.mtu)) {
        Logger::upf_app().error(
            "Could not read %s network interface configuration", cfg.if_name);
        return RETURNerror;
      }
    } else {
      std::vector<std::string> words;
      boost::split(
          words, address, boost::is_any_of("/"), boost::token_compress_on);
      if (words.size() != 2) {
        Logger::upf_app().error(
            "Bad value " UPF_CONFIG_STRING_IPV4_ADDRESS " = %s in config file",
            address.c_str());
        return RETURNerror;
      }
      unsigned char buf_in_addr[sizeof(struct in6_addr)];  // you never know...
      if (inet_pton(AF_INET, util::trim(words.at(0)).c_str(), buf_in_addr) ==
          1) {
        memcpy(&cfg.addr4, buf_in_addr, sizeof(struct in_addr));
      } else {
        Logger::upf_app().error(
            "In conversion: Bad value " UPF_CONFIG_STRING_IPV4_ADDRESS
            " = %s in config file",
            util::trim(words.at(0)).c_str());
        return RETURNerror;
      }
      cfg.network4.s_addr = htons(
          ntohs(cfg.addr4.s_addr) &
          0xFFFFFFFF << (32 - std::stoi(util::trim(words.at(1)))));
    }
    if_cfg.lookupValue(UPF_CONFIG_STRING_PORT, cfg.port);
    try {
      const Setting& sched_params_cfg = if_cfg[UPF_CONFIG_STRING_SCHED_PARAMS];
      load_thread_sched_params(sched_params_cfg, cfg.thread_rd_sched_params);
    } catch (const SettingNotFoundException& nfex) {
      Logger::upf_app().info(
          "%s : %s, using defaults", nfex.what(), nfex.getPath());
    }
  }
  return RETURNok;
}

//------------------------------------------------------------------------------
int upf_config::load(const string& config_file) {
  Config cfg;
  unsigned char buf_in_addr[sizeof(struct in_addr) + 1];
  unsigned char buf_in6_addr[sizeof(struct in6_addr) + 1];

  // Read the file. If there is an error, report it and exit.
  try {
    cfg.readFile(config_file.c_str());
  } catch (const FileIOException& fioex) {
    Logger::upf_app().error(
        "I/O error while reading file %s - %s", config_file.c_str(),
        fioex.what());
    throw;
  } catch (const ParseException& pex) {
    Logger::upf_app().error(
        "Parse error at %s:%d - %s", pex.getFile(), pex.getLine(),
        pex.getError());
    throw;
  }

  const Setting& root = cfg.getRoot();

  try {
    const Setting& upf_cfg = root[UPF_CONFIG_STRING_UPF_CONFIG];
  } catch (const SettingNotFoundException& nfex) {
    Logger::upf_app().error("%s : %s", nfex.what(), nfex.getPath());
    return RETURNerror;
  }

  const Setting& upf_cfg = root[UPF_CONFIG_STRING_UPF_CONFIG];

  try {
    upf_cfg.lookupValue(UPF_CONFIG_STRING_INSTANCE, instance);
  } catch (const SettingNotFoundException& nfex) {
    Logger::upf_app().info(
        "%s : %s, using defaults", nfex.what(), nfex.getPath());
  }

  try {
    upf_cfg.lookupValue(UPF_CONFIG_STRING_FQDN, fqdn);
    util::trim(fqdn);
  } catch (const SettingNotFoundException& nfex) {
    Logger::upf_app().info(
        "%s : %s, No FQDN configured", nfex.what(), nfex.getPath());
  }

  // Log Level
  try {
    std::string string_level;
    upf_cfg.lookupValue(UPF_CONFIG_STRING_LOG_LEVEL, string_level);
    log_level = spdlog::level::from_str(string_level);
  } catch (const SettingNotFoundException& nfex) {
    Logger::upf_app().error(
        "%s : %s, using defaults", nfex.what(), nfex.getPath());
  }

  try {
    const Setting& itti_cfg = upf_cfg[UPF_CONFIG_STRING_ITTI_TASKS];
    load_itti(itti_cfg, itti);
  } catch (const SettingNotFoundException& nfex) {
    Logger::upf_app().info(
        "%s : %s, using defaults", nfex.what(), nfex.getPath());
  }

  try {
    const Setting& nw_if_cfg = upf_cfg[UPF_CONFIG_STRING_INTERFACES];

    const Setting& n3_cfg = nw_if_cfg[UPF_CONFIG_STRING_INTERFACE_N3];
    load_interface(n3_cfg, n3);

    const Setting& n4_cfg = nw_if_cfg[UPF_CONFIG_STRING_INTERFACE_N4];
    load_interface(n4_cfg, n4);

    const Setting& n6_cfg = nw_if_cfg[UPF_CONFIG_STRING_INTERFACE_N6];
    load_interface(n6_cfg, n6);

    if ((boost::iequals(n6.if_name, "none")) ||
        (boost::iequals(n6.if_name, "default_gateway"))) {
      if (util::get_gateway_and_iface(gateway, n6.if_name)) {
        std::string copy = n6.if_name;
        if (get_inet_addr_infos_from_iface(
                n6.if_name, n6.addr4, n6.network4, n6.mtu)) {
          Logger::upf_app().error(
              "Could not read %s network interface configuration from system",
              n6.if_name);
          return RETURNerror;
        }
      } else {
        Logger::upf_app().error("Could not find N6 interface and N6 gateway");
        return RETURNerror;
      }
    }

    try {
      const Setting& nsf_cfg = upf_cfg[UPF_CONFIG_STRING_NON_STANDART_FEATURES];
      nsf.bypass_ul_pfcp_rules = false;
      std::string astring      = {};
      if (nsf_cfg.lookupValue(
              UPF_CONFIG_STRING_BYPASS_UL_PFCP_RULES, astring)) {
        if (boost::iequals(astring, "yes")) {
          nsf.bypass_ul_pfcp_rules = true;
        }
      }
    } catch (const SettingNotFoundException& nfex) {
      Logger::upf_app().info(
          "%s : %s, using defaults", nfex.what(), nfex.getPath());
    }

    const Setting& pdn_network_list_cfg =
        upf_cfg[UPF_CONFIG_STRING_PDN_NETWORK_LIST];
    int count = pdn_network_list_cfg.getLength();
    for (int i = 0; i < count; i++) {
      pdn_cfg_t pdn_cfg              = {};
      const Setting& pdn_network_cfg = pdn_network_list_cfg[i];

      string network_ipv4 = {};
      if (pdn_network_cfg.lookupValue(
              UPF_CONFIG_STRING_NETWORK_IPV4, network_ipv4)) {
        std::vector<std::string> ips = {};
        boost::split(
            ips, network_ipv4,
            boost::is_any_of(UPF_CONFIG_STRING_ADDRESS_PREFIX_DELIMITER),
            boost::token_compress_on);
        if (ips.size() != 2) {
          Logger::upf_app().error(
              "Bad value %s : %s in config file %s",
              UPF_CONFIG_STRING_ADDRESS_PREFIX_DELIMITER, network_ipv4.c_str(),
              config_file.c_str());
          throw(
              "Bad value %s : %s in config file %s",
              UPF_CONFIG_STRING_ADDRESS_PREFIX_DELIMITER, network_ipv4.c_str(),
              config_file.c_str());
        }

        if (inet_pton(AF_INET, util::trim(ips.at(0)).c_str(), buf_in_addr) ==
            1) {
          memcpy(&pdn_cfg.network_ipv4, buf_in_addr, sizeof(struct in_addr));
        } else {
          Logger::upf_app().error(
              "CONFIG: BAD IPV4 NETWORK ADDRESS "
              "in " UPF_CONFIG_STRING_PDN_NETWORK_LIST " PDN item %d",
              i);
          throw(
              "CONFIG: BAD NETWORK ADDRESS "
              "in " UPF_CONFIG_STRING_PDN_NETWORK_LIST);
        }
        pdn_cfg.prefix_ipv4          = std::stoul(ips.at(1), nullptr, 0);
        pdn_cfg.network_ipv4_be      = htobe32(pdn_cfg.network_ipv4.s_addr);
        pdn_cfg.network_mask_ipv4    = 0xFFFFFFFF << (32 - pdn_cfg.prefix_ipv4);
        pdn_cfg.network_mask_ipv4_be = htobe32(pdn_cfg.network_mask_ipv4);
      }

      string network_ipv6 = {};
      if (pdn_network_cfg.lookupValue(
              UPF_CONFIG_STRING_NETWORK_IPV6, network_ipv6)) {
        std::vector<std::string> ips = {};
        boost::split(
            ips, network_ipv6,
            boost::is_any_of(UPF_CONFIG_STRING_ADDRESS_PREFIX_DELIMITER),
            boost::token_compress_on);
        if (ips.size() != 2) {
          Logger::upf_app().error(
              "Bad value %s : %s in config file %s",
              UPF_CONFIG_STRING_ADDRESS_PREFIX_DELIMITER, network_ipv6.c_str(),
              config_file.c_str());
          throw(
              "Bad value %s : %s in config file %s",
              UPF_CONFIG_STRING_ADDRESS_PREFIX_DELIMITER, network_ipv6.c_str(),
              config_file.c_str());
        }

        if (inet_pton(AF_INET6, util::trim(ips.at(0)).c_str(), buf_in6_addr) ==
            1) {
          memcpy(&pdn_cfg.network_ipv6, buf_in6_addr, sizeof(struct in6_addr));
        } else {
          Logger::upf_app().error(
              "CONFIG: BAD IPV6 NETWORK ADDRESS "
              "in " UPF_CONFIG_STRING_PDN_NETWORK_LIST " PDN item %d",
              i);
          throw(
              "CONFIG: BAD IPV6 NETWORK ADDRESS "
              "in " UPF_CONFIG_STRING_PDN_NETWORK_LIST);
        }
        pdn_cfg.prefix_ipv6 = std::stoul(ips.at(1), nullptr, 0);
        Logger::upf_app().info(
            "  %s......: %s/%d", ips.at(0).c_str(),
            conv::toString(pdn_cfg.network_ipv6).c_str(), pdn_cfg.prefix_ipv6);
      }
      pdns.push_back(pdn_cfg);
    }

    enable_snat         = false;
    std::string astring = {};
    if (upf_cfg.lookupValue(UPF_CONFIG_STRING_SNAT, astring)) {
      if (boost::iequals(astring, "yes")) {
        enable_snat = true;
      }
    }

    const Setting& smf_list_cfg = upf_cfg[UPF_CONFIG_STRING_SMF_LIST];
    count                       = smf_list_cfg.getLength();
    for (int i = 0; i < count; i++) {
      pdn_cfg_t pdn_cfg      = {};
      const Setting& smf_cfg = smf_list_cfg[i];

      string address = {};
      if (smf_cfg.lookupValue(UPF_CONFIG_STRING_IPV4_ADDRESS, address)) {
        pfcp::node_id_t n = {};
        n.node_id_type    = pfcp::NODE_ID_TYPE_IPV4_ADDRESS;  // actually
        if (inet_pton(AF_INET, util::trim(address).c_str(), buf_in_addr) == 1) {
          memcpy(&n.u1.ipv4_address, buf_in_addr, sizeof(struct in_addr));
        } else {
          Logger::upf_app().error(
              "CONFIG: BAD IPV4 ADDRESS in " UPF_CONFIG_STRING_SMF_LIST
              " item %d",
              i);
          throw("CONFIG: BAD ADDRESS in " UPF_CONFIG_STRING_SMF_LIST);
        }
        smfs.push_back(n);
      } else {
        // TODO IPV6_ADDRESS, FQDN
        throw(
            "Bad value in section %s : item no %d in config file %s",
            UPF_CONFIG_STRING_SMF_LIST, i, config_file.c_str());
      }
    }

    // Support 5G features
    const Setting& support_features = upf_cfg[UPF_CONFIG_STRING_5G_FEATURES];
    string opt;

    support_features.lookupValue(UPF_CONFIG_STRING_5G_FEATURES_UPF_FQDN, fqdn);
    enable_5g_features = true;

    support_features.lookupValue(
        UPF_CONFIG_STRING_5G_FEATURES_REGISTER_NRF, opt);
    if (boost::iequals(opt, "yes")) {
      register_nrf = true;
    } else {
      register_nrf = false;
    }

    support_features.lookupValue(UPF_CONFIG_STRING_ENABLE_BPF_DATAPATH, opt);
    if (boost::iequals(opt, "yes")) {
      enable_bpf_datapath = true;
    } else {
      enable_bpf_datapath = false;
    }

    support_features.lookupValue(
        UPF_CONFIG_STRING_5G_FEATURES_USE_FQDN_NRF, opt);
    if (boost::iequals(opt, "yes")) {
      use_fqdn_dns = true;
    } else {
      use_fqdn_dns = false;
    }

    support_features.lookupValue(UPF_CONFIG_REMOTE_N6_GW_CONFIG, opt);
    std::string remote_n6_addr;
    uint8_t addr_type = {};
    unsigned int port = 0;
    fqdn::resolve(opt, remote_n6_addr, port, addr_type);
    if (addr_type != 0) {  // IPv6: TODO
      throw("DO NOT SUPPORT IPV6 ADDR FOR NRF!");
    } else {  // IPv4
      IPV4_STR_ADDR_TO_INADDR(
          util::trim(remote_n6_addr).c_str(), remote_n6,
          "BAD IPv4 ADDRESS FORMAT FOR N6 DN !");
    }

    support_features.lookupValue(UPF_CONFIG_STRING_HTTP_VERSION, http_version);

    // NRF
    const Setting& nrf_cfg =
        support_features[UPF_CONFIG_STRING_5G_FEATURES_NRF];
    struct in_addr nrf_ipv4_addr;
    unsigned int nrf_port    = 0;
    unsigned int httpVersion = 0;
    std::string nrf_api_version;
    string nrf_address = {};

    if (!(nrf_cfg.lookupValue(
            UPF_CONFIG_STRING_5G_FEATURES_NRF_HTTP_VERSION, httpVersion))) {
      Logger::upf_app().error(UPF_CONFIG_STRING_5G_FEATURES_NRF_HTTP_VERSION
                              "failed");
      throw(UPF_CONFIG_STRING_5G_FEATURES_NRF_HTTP_VERSION "failed");
    }
    nrf_addr.http_version = httpVersion;

    if (!use_fqdn_dns) {
      nrf_cfg.lookupValue(
          UPF_CONFIG_STRING_5G_FEATURES_NRF_IPV4_ADDRESS, nrf_address);
      IPV4_STR_ADDR_TO_INADDR(
          util::trim(nrf_address).c_str(), nrf_ipv4_addr,
          "BAD IPv4 ADDRESS FORMAT FOR NRF !");
      nrf_addr.ipv4_addr = nrf_ipv4_addr;
      if (!(nrf_cfg.lookupValue(
              UPF_CONFIG_STRING_5G_FEATURES_NRF_PORT, nrf_port))) {
        Logger::upf_app().error(UPF_CONFIG_STRING_5G_FEATURES_NRF_PORT
                                "failed");
        throw(UPF_CONFIG_STRING_5G_FEATURES_NRF_PORT "failed");
      }
      nrf_addr.port = nrf_port;

      if (!(nrf_cfg.lookupValue(
              UPF_CONFIG_STRING_5G_FEATURES_NRF_API_VERSION,
              nrf_api_version))) {
        Logger::upf_app().error(UPF_CONFIG_STRING_5G_FEATURES_NRF_API_VERSION
                                "failed");
        throw(UPF_CONFIG_STRING_5G_FEATURES_NRF_API_VERSION "failed");
      }
      nrf_addr.api_version = nrf_api_version;
    } else {
      Logger::upf_app().info("USE FQDN");
      std::string nrf_fqdn = {};
      nrf_cfg.lookupValue(UPF_CONFIG_STRING_FQDN, nrf_fqdn);
      nrf_addr.fqdn     = nrf_fqdn;  // TODO: Resolve FQDN at runtime
      uint8_t addr_type = {};
      fqdn::resolve(nrf_fqdn, nrf_address, nrf_port, addr_type);
      if (addr_type != 0) {  // IPv6: TODO
        throw("DO NOT SUPPORT IPV6 ADDR FOR NRF!");
      } else {  // IPv4
        IPV4_STR_ADDR_TO_INADDR(
            util::trim(nrf_address).c_str(), nrf_ipv4_addr,
            "BAD IPv4 ADDRESS FORMAT FOR NRF !");
        nrf_addr.ipv4_addr = nrf_ipv4_addr;

        // We hardcode nrf port from config for the moment
        if (!(nrf_cfg.lookupValue(
                UPF_CONFIG_STRING_5G_FEATURES_NRF_PORT, nrf_port))) {
          Logger::upf_app().error(UPF_CONFIG_STRING_5G_FEATURES_NRF_PORT
                                  "failed");
          throw(UPF_CONFIG_STRING_5G_FEATURES_NRF_PORT "failed");
        }
        nrf_addr.port = nrf_port;

        nrf_addr.api_version = "v1";  // TODO: get API version
      }
    }

    // UPF info
    const Setting& upf_info_cfg =
        support_features[UPF_CONFIG_STRING_5G_FEATURES_UPF_INFO];
    count = upf_info_cfg.getLength();
    for (int i = 0; i < count; i++) {
      const Setting& upf_info_item_cfg = upf_info_cfg[i];
      unsigned int nssai_sst           = 0;
      unsigned int nssai_sd            = 0;

      if (!(upf_info_item_cfg.lookupValue(
              UPF_CONFIG_STRING_5G_FEATURES_NSSAI_SST, nssai_sst))) {
        Logger::upf_app().error(UPF_CONFIG_STRING_5G_FEATURES_NSSAI_SST
                                "failed");
        throw(UPF_CONFIG_STRING_5G_FEATURES_NSSAI_SST " failed");
      }

      if (!(upf_info_item_cfg.lookupValue(
              UPF_CONFIG_STRING_5G_FEATURES_NSSAI_SD, nssai_sd))) {
        Logger::upf_app().error(UPF_CONFIG_STRING_5G_FEATURES_NSSAI_SD
                                "failed");
        throw(UPF_CONFIG_STRING_5G_FEATURES_NSSAI_SD " failed");
      }

      snssai_upf_info_item_t snssai_item = {};
      snssai_t snssai                    = {};
      snssai.sst                         = nssai_sst;
      snssai.sd                          = nssai_sd;
      snssai_item.snssai                 = snssai;

      const Setting& dnn_cfg =
          upf_info_item_cfg[UPF_CONFIG_STRING_5G_FEATURES_UPF_INFO_DNN_LIST];
      uint8_t number_dnns = dnn_cfg.getLength();
      for (int i = 0; i < number_dnns; i++) {
        string dnn                  = {};
        const Setting& dnn_item_cfg = dnn_cfg[i];
        if (!(dnn_item_cfg.lookupValue(
                UPF_CONFIG_STRING_5G_FEATURES_DNN, dnn))) {
          Logger::upf_app().error(UPF_CONFIG_STRING_5G_FEATURES_DNN "failed");
          throw(UPF_CONFIG_STRING_5G_FEATURES_DNN "failed");
        }

        dnn_upf_info_item_t dnn_item = {};
        dnn_item.dnn                 = dnn;
        snssai_item.dnn_upf_info_list.insert(dnn_item);
      }

      upf_info.snssai_upf_info_list.push_back(snssai_item);
    }

  } catch (const SettingNotFoundException& nfex) {
    Logger::upf_app().error("%s : %s", nfex.what(), nfex.getPath());
    return RETURNerror;
  }
  return RETURNok;
}

//------------------------------------------------------------------------------
void upf_config::display() {
  Logger::upf_app().info(
      "==== EURECOM %s v%s ====", PACKAGE_NAME, PACKAGE_VERSION);
  Logger::upf_app().info("Configuration:");
  Logger::upf_app().info("- FQDN ..................: %s", fqdn.c_str());
  Logger::upf_app().info("- Instance ..............: %d", instance);
  Logger::upf_app().info("- ITTI tasks:");
  Logger::upf_app().info("    ITTI Timer task:");
  Logger::upf_app().info(
      "      CPU ID .........: %d", itti.itti_timer_sched_params.cpu_id);
  Logger::upf_app().info(
      "      sched policy....: %d", itti.itti_timer_sched_params.sched_policy);
  Logger::upf_app().info(
      "      sched priority..: %d",
      itti.itti_timer_sched_params.sched_priority);
  Logger::upf_app().info("    UPF-N3 task:");
  Logger::upf_app().info(
      "      CPU ID .........: %d", itti.n3_sched_params.cpu_id);
  Logger::upf_app().info(
      "      sched policy....: %d", itti.n3_sched_params.sched_policy);
  Logger::upf_app().info(
      "      sched priority..: %d", itti.n3_sched_params.sched_priority);
  Logger::upf_app().info("    UPF-N4 task:");
  Logger::upf_app().info(
      "      CPU ID .........: %d", itti.n4_sched_params.cpu_id);
  Logger::upf_app().info(
      "      sched policy....: %d", itti.n4_sched_params.sched_policy);
  Logger::upf_app().info(
      "      sched priority..: %d", itti.n4_sched_params.sched_priority);
  Logger::upf_app().info("    UPF_APP task:");
  Logger::upf_app().info(
      "      CPU ID .........: %d", itti.upf_app_sched_params.cpu_id);
  Logger::upf_app().info(
      "      sched policy....: %d", itti.upf_app_sched_params.sched_policy);
  Logger::upf_app().info(
      "      sched priority..: %d", itti.upf_app_sched_params.sched_priority);
  Logger::upf_app().info("    ASYNC_SHELL_CMD task:");
  Logger::upf_app().info(
      "      CPU ID .........: %d", itti.async_cmd_sched_params.cpu_id);
  Logger::upf_app().info(
      "      sched policy....: %d", itti.async_cmd_sched_params.sched_policy);
  Logger::upf_app().info(
      "      sched priority..: %d", itti.async_cmd_sched_params.sched_priority);
  Logger::upf_app().info("- N3:");
  Logger::upf_app().info("    iface ............: %s", n3.if_name.c_str());
  Logger::upf_app().info("    ipv4.addr ........: %s", inet_ntoa(n3.addr4));
  Logger::upf_app().info("    ipv4.mask ........: %s", inet_ntoa(n3.network4));
  Logger::upf_app().info("    mtu ..............: %d", n3.mtu);
  Logger::upf_app().info("    port .............: %d", n3.port);
  // Logger::upf_app().info("    Reader thread:");
  // Logger::upf_app().info(
  //     "      CPU ID .........: %d", n3.thread_rd_sched_params.cpu_id);
  // Logger::upf_app().info(
  //     "      sched policy....: %d", n3.thread_rd_sched_params.sched_policy);
  // Logger::upf_app().info(
  //     "      sched priority..: %d",
  //     n3.thread_rd_sched_params.sched_priority);
  // Logger::upf_app().info(
  //     "      thread pool size: %d",
  //     n3.thread_rd_sched_params.thread_pool_size);
  Logger::upf_app().info("- N4:");
  Logger::upf_app().info("    iface ............: %s", n4.if_name.c_str());
  Logger::upf_app().info("    ipv4.addr ........: %s", inet_ntoa(n4.addr4));
  Logger::upf_app().info("    ipv4.mask ........: %s", inet_ntoa(n4.network4));
  Logger::upf_app().info("    mtu ..............: %d", n4.mtu);
  Logger::upf_app().info("    port .............: %u", n4.port);
  // Logger::upf_app().info("    Reader thread:");
  // Logger::upf_app().info(
  //     "      CPU ID .........: %d (TODO)", n4.thread_rd_sched_params.cpu_id);
  // Logger::upf_app().info(
  //     "      sched policy....: %d (TODO)",
  //     n4.thread_rd_sched_params.sched_policy);
  // Logger::upf_app().info(
  //     "      sched priority..: %d (TODO)",
  //     n4.thread_rd_sched_params.sched_priority);
  // Logger::upf_app().info(
  //     "      thread pool size: %d (TODO)",
  //     n4.thread_rd_sched_params.thread_pool_size);
  Logger::upf_app().info("- N6:");
  Logger::upf_app().info("    iface ............: %s", n6.if_name.c_str());
  Logger::upf_app().info("    ipv4.addr ........: %s", inet_ntoa(n6.addr4));
  Logger::upf_app().info("    ipv4.mask ........: %s", inet_ntoa(n6.network4));
  Logger::upf_app().info("    mtu ..............: %d", n6.mtu);
  Logger::upf_app().info("    gateway ..........: %s", gateway.c_str());
  // Logger::upf_app().info("    Reader thread:");
  // Logger::upf_app().info(
  //     "      CPU ID .........: %d", n6.thread_rd_sched_params.cpu_id);
  // Logger::upf_app().info(
  // //     "      sched policy....: %d",
  // n6.thread_rd_sched_params.sched_policy); Logger::upf_app().info(
  //     "      sched priority..: %d",
  //     n6.thread_rd_sched_params.sched_priority);
  // Logger::upf_app().info(
  //     "      thread pool size: %d",
  //     n6.thread_rd_sched_params.thread_pool_size);
  Logger::upf_app().info("- PDN networks:");
  Logger::upf_app().info(
      "    SNAT .............: %s", (enable_snat) ? "yes" : "no");
  int i = 1;
  for (auto it : pdns) {
    if (it.prefix_ipv4) {
      Logger::upf_app().info(
          "       NW .............: %s/%d",
          conv::toString(it.network_ipv4).c_str(), it.prefix_ipv4);
    }
    if (it.prefix_ipv6) {
      Logger::upf_app().info(
          "       NW .............: %s/%d",
          conv::toString(it.network_ipv6).c_str(), it.prefix_ipv6);
    }
    i++;
  }
  Logger::upf_app().info("- NON_STANDART_FEATURES:");
  Logger::upf_app().info(
      "    bypass_ul_pfcp_rules: %s",
      (nsf.bypass_ul_pfcp_rules) ? "yes" : "no");

  Logger::upf_app().info(
      "- Remote N6 Address .......: %s", inet_ntoa(remote_n6));

  Logger::upf_app().info("- SUPPORT_5G_FEATURES:");

  Logger::upf_app().info("    register_nrf: %s", (register_nrf) ? "yes" : "no");
  Logger::upf_app().info(
      "    enable_bpf_datapath: %s", (enable_bpf_datapath) ? "yes" : "no");
  Logger::upf_app().info("    use_fqdn_dns: %s", (use_fqdn_dns) ? "yes" : "no");
  if (register_nrf) {
    Logger::upf_app().info("    NRF:");
    Logger::upf_app().info(
        "        IPv4 Addr .......: %s",
        inet_ntoa(*((struct in_addr*) &nrf_addr.ipv4_addr)));
    Logger::upf_app().info("        Port ............: %lu  ", nrf_addr.port);
    Logger::upf_app().info(
        "        API version .....: %s", nrf_addr.api_version.c_str());
    if (use_fqdn_dns)
      Logger::upf_app().info(
          "        FQDN ............: %s", nrf_addr.fqdn.c_str());

    if (upf_info.snssai_upf_info_list.size() > 0) {
      Logger::upf_app().info("    UPF Info:");

      for (auto s : upf_info.snssai_upf_info_list) {
        // Logger::upf_app().debug(" Parameters supported by the UPF:");
        // if (s.snssai.sd.compare(std::to_string(SD_NO_VALUE)))
        //   Logger::upf_app().info(
        //       "        SNSSAI (SST %d, SD %d)", s.snssai.sst,
        //       s.snssai.sd);
        // else
        Logger::upf_app().info("        SNSSAI (SST %d)", s.snssai.sst);
        for (auto d : s.dnn_upf_info_list) {
          Logger::upf_app().info("            DNN %s", d.dnn.c_str());
        }
      }
    }
  }
  Logger::upf_app().info(
      "- Log Level will be .......: %s",
      spdlog::level::to_string_view(log_level));
}
}  // namespace oai::config
