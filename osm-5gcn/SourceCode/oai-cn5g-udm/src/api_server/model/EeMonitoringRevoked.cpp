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
/**
 * Nudm_EE
 * Nudm Event Exposure Service. © 2021, 3GPP Organizational Partners (ARIB,
 * ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.2.0-alpha.3
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "EeMonitoringRevoked.h"
#include "Helpers.h"

#include <sstream>

namespace oai::udm::model {

EeMonitoringRevoked::EeMonitoringRevoked() {}

void EeMonitoringRevoked::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw oai::model::common::helpers::ValidationException(msg.str());
  }
}

bool EeMonitoringRevoked::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool EeMonitoringRevoked::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "EeMonitoringRevoked" : pathPrefix;

  /* RevokedMonitoringEventList */ {
    const std::map<std::string, MonitoringEvent>& value =
        m_RevokedMonitoringEventList;
    const std::string currentValuePath =
        _pathPrefix + ".revokedMonitoringEventList";
  }

  return success;
}

bool EeMonitoringRevoked::operator==(const EeMonitoringRevoked& rhs) const {
  return

      (getRevokedMonitoringEventList() == rhs.getRevokedMonitoringEventList())

          ;
}

bool EeMonitoringRevoked::operator!=(const EeMonitoringRevoked& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const EeMonitoringRevoked& o) {
  j                               = nlohmann::json();
  j["revokedMonitoringEventList"] = o.m_RevokedMonitoringEventList;
}

void from_json(const nlohmann::json& j, EeMonitoringRevoked& o) {
  j.at("revokedMonitoringEventList").get_to(o.m_RevokedMonitoringEventList);
}

std::map<std::string, MonitoringEvent>
EeMonitoringRevoked::getRevokedMonitoringEventList() const {
  return m_RevokedMonitoringEventList;
}
void EeMonitoringRevoked::setRevokedMonitoringEventList(
    std::map<std::string, MonitoringEvent> const& value) {
  m_RevokedMonitoringEventList = value;
}

}  // namespace oai::udm::model
