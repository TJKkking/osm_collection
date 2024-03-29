/**
 * NRF NFDiscovery Service
 * NRF NFDiscovery Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include "DiscNFInstancesStoreApi.h"
#include "Helpers.h"
#include "nrf_config.hpp"
#include "logger.hpp"

extern std::unique_ptr<oai::config::nrf::nrf_config> nrf_cfg;

namespace oai {
namespace nrf {
namespace api {

using namespace oai::model::common::helpers;
using namespace oai::model::nrf;
using namespace oai::model::common;

DiscNFInstancesStoreApi::DiscNFInstancesStoreApi(
    std::shared_ptr<Pistache::Rest::Router> rtr) {
  router = rtr;
}

void DiscNFInstancesStoreApi::init() {
  setupRoutes();
}

void DiscNFInstancesStoreApi::setupRoutes() {
  using namespace Pistache::Rest;

  Routes::Get(
      *router,
      base + nrf_cfg->local().get_sbi().get_api_version() + "/nf-instances",
      Routes::bind(
          &DiscNFInstancesStoreApi::search_nf_instances_handler, this));

  // Default handler, called when a route is not found
  router->addCustomHandler(Routes::bind(
      &DiscNFInstancesStoreApi::nf_instances_store_api_default_handler, this));
}

void DiscNFInstancesStoreApi::search_nf_instances_handler(
    const Pistache::Rest::Request& request,
    Pistache::Http::ResponseWriter response) {
  // Getting the query params
  // TODO Stefan: We should use the model values everywhere and then to_json,
  // e.g. NFType, so we can use the enum and we are typesafe
  auto targetNfTypeQuery = request.query().get("target-nf-type");
  Pistache::Optional<std::string> targetNfType;
  if (!targetNfTypeQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(targetNfTypeQuery.get(), valueQuery_instance)) {
      targetNfType = Pistache::Some(valueQuery_instance);
    }
  }
  auto requesterNfTypeQuery = request.query().get("requester-nf-type");
  Pistache::Optional<std::string> requesterNfType;
  if (!requesterNfTypeQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(requesterNfTypeQuery.get(), valueQuery_instance)) {
      requesterNfType = Pistache::Some(valueQuery_instance);
    }
  }
  auto requesterNfInstanceIdQuery =
      request.query().get("requester-nf-instance-id");
  Pistache::Optional<std::string> requesterNfInstanceId;
  if (!requesterNfInstanceIdQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(
            requesterNfInstanceIdQuery.get(), valueQuery_instance)) {
      requesterNfInstanceId = Pistache::Some(valueQuery_instance);
    }
  }
  Pistache::Optional<std::vector<ServiceName>> serviceNames =
      model_from_query_string<std::vector<ServiceName>>(
          request, "service-names", true);

  auto requesterNfInstanceFqdnQuery =
      request.query().get("requester-nf-instance-fqdn");
  Pistache::Optional<std::string> requesterNfInstanceFqdn;
  if (!requesterNfInstanceFqdnQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(
            requesterNfInstanceFqdnQuery.get(), valueQuery_instance)) {
      requesterNfInstanceFqdn = Pistache::Some(valueQuery_instance);
    }
  }
  Pistache::Optional<std::vector<PlmnId>> targetPlmnList =
      model_from_query_string<std::vector<PlmnId>>(
          request, "target-plmn-list", true);

  Pistache::Optional<std::vector<PlmnId>> requesterPlmnList =
      model_from_query_string<std::vector<PlmnId>>(
          request, "requester-plmn-list", true);

  auto targetNfInstanceIdQuery = request.query().get("target-nf-instance-id");
  Pistache::Optional<std::string> targetNfInstanceId;
  if (!targetNfInstanceIdQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(targetNfInstanceIdQuery.get(), valueQuery_instance)) {
      targetNfInstanceId = Pistache::Some(valueQuery_instance);
    }
  }
  auto targetNfFqdnQuery = request.query().get("target-nf-fqdn");
  Pistache::Optional<std::string> targetNfFqdn;
  if (!targetNfFqdnQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(targetNfFqdnQuery.get(), valueQuery_instance)) {
      targetNfFqdn = Pistache::Some(valueQuery_instance);
    }
  }
  auto hnrfUriQuery = request.query().get("hnrf-uri");
  Pistache::Optional<std::string> hnrfUri;
  if (!hnrfUriQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(hnrfUriQuery.get(), valueQuery_instance)) {
      hnrfUri = Pistache::Some(valueQuery_instance);
    }
  }

  Pistache::Optional<std::vector<Snssai>> snssais =
      model_from_query_string<std::vector<Snssai>>(request, "snssais", true);
  Pistache::Optional<std::vector<Snssai>> requesterSnssais =
      model_from_query_string<std::vector<Snssai>>(
          request, "requester-snssais", true);
  Pistache::Optional<std::vector<PlmnSnssai>> plmnSpecificSnssaiList =
      model_from_query_string<std::vector<PlmnSnssai>>(
          request, "plmn-specific-snssai-list", true);

  auto dnnQuery = request.query().get("dnn");
  Pistache::Optional<std::string> dnn;
  if (!dnnQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(dnnQuery.get(), valueQuery_instance)) {
      dnn = Pistache::Some(valueQuery_instance);
    }
  }
  auto nsiListQuery = request.query().get("nsi-list");
  Pistache::Optional<std::vector<std::string>> nsiList;
  if (!nsiListQuery.isEmpty()) {
    std::vector<std::string> valueQuery_instance;
    if (fromStringValue(nsiListQuery.get(), valueQuery_instance)) {
      nsiList = Pistache::Some(valueQuery_instance);
    }
  }
  auto smfServingAreaQuery = request.query().get("smf-serving-area");
  Pistache::Optional<std::string> smfServingArea;
  if (!smfServingAreaQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(smfServingAreaQuery.get(), valueQuery_instance)) {
      smfServingArea = Pistache::Some(valueQuery_instance);
    }
  }
  Pistache::Optional<Tai> tai = model_from_query_string<Tai>(request, "tai");
  auto amfRegionIdQuery       = request.query().get("amf-region-id");
  Pistache::Optional<std::string> amfRegionId;
  if (!amfRegionIdQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(amfRegionIdQuery.get(), valueQuery_instance)) {
      amfRegionId = Pistache::Some(valueQuery_instance);
    }
  }
  auto amfSetIdQuery = request.query().get("amf-set-id");
  Pistache::Optional<std::string> amfSetId;
  if (!amfSetIdQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(amfSetIdQuery.get(), valueQuery_instance)) {
      amfSetId = Pistache::Some(valueQuery_instance);
    }
  }
  Pistache::Optional<Guami> guami =
      model_from_query_string<Guami>(request, "guami");
  auto supiQuery = request.query().get("supi");
  Pistache::Optional<std::string> supi;
  if (!supiQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(supiQuery.get(), valueQuery_instance)) {
      supi = Pistache::Some(valueQuery_instance);
    }
  }
  auto ueIpv4AddressQuery = request.query().get("ue-ipv4-address");
  Pistache::Optional<std::string> ueIpv4Address;
  if (!ueIpv4AddressQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(ueIpv4AddressQuery.get(), valueQuery_instance)) {
      ueIpv4Address = Pistache::Some(valueQuery_instance);
    }
  }
  auto ipDomainQuery = request.query().get("ip-domain");
  Pistache::Optional<std::string> ipDomain;
  if (!ipDomainQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(ipDomainQuery.get(), valueQuery_instance)) {
      ipDomain = Pistache::Some(valueQuery_instance);
    }
  }
  Pistache::Optional<Ipv6Prefix> ueIpv6Prefix =
      model_from_query_string<Ipv6Prefix>(request, "ue-ipv6-prefix");

  auto pgwIndQuery = request.query().get("pgw-ind");
  Pistache::Optional<bool> pgwInd;
  if (!pgwIndQuery.isEmpty()) {
    bool valueQuery_instance;
    if (fromStringValue(pgwIndQuery.get(), valueQuery_instance)) {
      pgwInd = Pistache::Some(valueQuery_instance);
    }
  }
  auto pgwQuery = request.query().get("pgw");
  Pistache::Optional<std::string> pgw;
  if (!pgwQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(pgwQuery.get(), valueQuery_instance)) {
      pgw = Pistache::Some(valueQuery_instance);
    }
  }
  auto gpsiQuery = request.query().get("gpsi");
  Pistache::Optional<std::string> gpsi;
  if (!gpsiQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(gpsiQuery.get(), valueQuery_instance)) {
      gpsi = Pistache::Some(valueQuery_instance);
    }
  }
  auto externalGroupIdentityQuery =
      request.query().get("external-group-identity");
  Pistache::Optional<std::string> externalGroupIdentity;
  if (!externalGroupIdentityQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(
            externalGroupIdentityQuery.get(), valueQuery_instance)) {
      externalGroupIdentity = Pistache::Some(valueQuery_instance);
    }
  }
  Pistache::Optional<DataSetId> dataSet =
      model_from_query_string<DataSetId>(request, "data-set");

  auto routingIndicatorQuery = request.query().get("routing-indicator");
  Pistache::Optional<std::string> routingIndicator;
  if (!routingIndicatorQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(routingIndicatorQuery.get(), valueQuery_instance)) {
      routingIndicator = Pistache::Some(valueQuery_instance);
    }
  }
  auto groupIdListQuery = request.query().get("group-id-list");
  Pistache::Optional<std::vector<std::string>> groupIdList;
  if (!groupIdListQuery.isEmpty()) {
    std::vector<std::string> valueQuery_instance;
    if (fromStringValue(groupIdListQuery.get(), valueQuery_instance)) {
      groupIdList = Pistache::Some(valueQuery_instance);
    }
  }
  auto dnaiListQuery = request.query().get("dnai-list");
  Pistache::Optional<std::vector<std::string>> dnaiList;
  if (!dnaiListQuery.isEmpty()) {
    std::vector<std::string> valueQuery_instance;
    if (fromStringValue(dnaiListQuery.get(), valueQuery_instance)) {
      dnaiList = Pistache::Some(valueQuery_instance);
    }
  }
  Pistache::Optional<std::vector<PduSessionType>> pduSessionTypes =
      model_from_query_string<std::vector<PduSessionType>>(
          request, "pdu-session-types", true);

  Pistache::Optional<std::vector<EventId>> eventIdList =
      model_from_query_string<std::vector<EventId>>(
          request, "event-id-list", true);

  Pistache::Optional<std::vector<NwdafEvent>> nwdafEventList =
      model_from_query_string<std::vector<NwdafEvent>>(
          request, "nwdaf-event-list", true);

  auto supportedFeaturesQuery = request.query().get("supported-features");
  Pistache::Optional<std::string> supportedFeatures;
  if (!supportedFeaturesQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(supportedFeaturesQuery.get(), valueQuery_instance)) {
      supportedFeatures = Pistache::Some(valueQuery_instance);
    }
  }
  auto upfIwkEpsIndQuery = request.query().get("upf-iwk-eps-ind");
  Pistache::Optional<bool> upfIwkEpsInd;
  if (!upfIwkEpsIndQuery.isEmpty()) {
    bool valueQuery_instance;
    if (fromStringValue(upfIwkEpsIndQuery.get(), valueQuery_instance)) {
      upfIwkEpsInd = Pistache::Some(valueQuery_instance);
    }
  }
  Pistache::Optional<PlmnId> chfSupportedPlmn =
      model_from_query_string<PlmnId>(request, "chf-supported-plmn");

  auto preferredLocalityQuery = request.query().get("preferred-locality");
  Pistache::Optional<std::string> preferredLocality;
  if (!preferredLocalityQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(preferredLocalityQuery.get(), valueQuery_instance)) {
      preferredLocality = Pistache::Some(valueQuery_instance);
    }
  }
  Pistache::Optional<AccessType> accessType =
      model_from_query_string<AccessType>(request, "access-type");

  auto limitQuery = request.query().get("limit");
  Pistache::Optional<int32_t> limit;
  if (!limitQuery.isEmpty()) {
    int32_t valueQuery_instance;
    if (fromStringValue(limitQuery.get(), valueQuery_instance)) {
      limit = Pistache::Some(valueQuery_instance);
    }
  }
  auto requiredFeaturesQuery = request.query().get("required-features");
  Pistache::Optional<std::vector<std::string>> requiredFeatures;
  if (!requiredFeaturesQuery.isEmpty()) {
    std::vector<std::string> valueQuery_instance;
    if (fromStringValue(requiredFeaturesQuery.get(), valueQuery_instance)) {
      requiredFeatures = Pistache::Some(valueQuery_instance);
    }
  }
  Pistache::Optional<ComplexQuery> complexQuery =
      model_from_query_string<ComplexQuery>(request, "complex-query");

  auto maxPayloadSizeQuery = request.query().get("max-payload-size");
  Pistache::Optional<int32_t> maxPayloadSize;
  if (!maxPayloadSizeQuery.isEmpty()) {
    int32_t valueQuery_instance;
    if (fromStringValue(maxPayloadSizeQuery.get(), valueQuery_instance)) {
      maxPayloadSize = Pistache::Some(valueQuery_instance);
    }
  }
  Pistache::Optional<AtsssCapability> atsssCapability =
      model_from_query_string<AtsssCapability>(request, "atsss-capability");

  auto upfUeIpAddrIndQuery = request.query().get("upf-ue-ip-addr-ind");
  Pistache::Optional<bool> upfUeIpAddrInd;
  if (!upfUeIpAddrIndQuery.isEmpty()) {
    bool valueQuery_instance;
    if (fromStringValue(upfUeIpAddrIndQuery.get(), valueQuery_instance)) {
      upfUeIpAddrInd = Pistache::Some(valueQuery_instance);
    }
  }

  // Getting the header params
  auto ifNoneMatch = request.headers().tryGetRaw("If-None-Match");

  try {
    this->search_nf_instances(
        targetNfType, requesterNfType, requesterNfInstanceId, serviceNames,
        requesterNfInstanceFqdn, targetPlmnList, requesterPlmnList,
        targetNfInstanceId, targetNfFqdn, hnrfUri, snssais, requesterSnssais,
        plmnSpecificSnssaiList, dnn, nsiList, smfServingArea, tai, amfRegionId,
        amfSetId, guami, supi, ueIpv4Address, ipDomain, ueIpv6Prefix, pgwInd,
        pgw, gpsi, externalGroupIdentity, dataSet, routingIndicator,
        groupIdList, dnaiList, pduSessionTypes, eventIdList, nwdafEventList,
        supportedFeatures, upfIwkEpsInd, chfSupportedPlmn, preferredLocality,
        accessType, limit, requiredFeatures, complexQuery, maxPayloadSize,
        atsssCapability, upfUeIpAddrInd, ifNoneMatch, response);
  } catch (nlohmann::detail::exception& e) {
    // send a 400 error
    response.send(Pistache::Http::Code::Bad_Request, e.what());
    return;
  } catch (Pistache::Http::HttpError& e) {
    response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
    return;
  } catch (std::exception& e) {
    // send a 500 error
    response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    return;
  }
}

void DiscNFInstancesStoreApi::nf_instances_store_api_default_handler(
    const Pistache::Rest::Request&, Pistache::Http::ResponseWriter response) {
  response.send(
      Pistache::Http::Code::Not_Found, "The requested method does not exist");
}

template<class T>
Pistache::Optional<T> DiscNFInstancesStoreApi::model_from_query_string(
    const Pistache::Rest::Request& request, const std::string& query_param,
    bool make_json_array) {
  auto query = request.query().get(query_param);
  Pistache::Optional<T> ret_optional;
  if (!query.isEmpty()) {
    nlohmann::json j = query.get();
    if (make_json_array) {
      std::string qry_string = query.get();
      std::vector<std::string> split_arr;
      boost::split(
          split_arr, qry_string, boost::is_any_of(","),
          boost::token_compress_on);
      j = split_arr;
    }

    std::cout << "test: " << j.dump() << std::endl;

    T valueQuery_instance;
    nlohmann::from_json(j, valueQuery_instance);
    ret_optional = Pistache::Some(valueQuery_instance);
  }
  return ret_optional;
}

}  // namespace api
}  // namespace nrf
}  // namespace oai
