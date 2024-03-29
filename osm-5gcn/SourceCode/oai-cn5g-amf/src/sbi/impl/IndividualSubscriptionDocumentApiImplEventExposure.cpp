/**
 * Namf_EventExposure
 * AMF Event Exposure Service © 2019, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "IndividualSubscriptionDocumentApiImplEventExposure.h"

namespace oai {
namespace amf {
namespace api {

using namespace oai::model::common;

IndividualSubscriptionDocumentApiImplEventExposure::
    IndividualSubscriptionDocumentApiImplEventExposure(
        const std::shared_ptr<Pistache::Rest::Router>& rtr,
        amf_application::amf_app* amf_app_inst)
    : IndividualSubscriptionDocumentApiEventExposure(rtr),
      m_amf_app(amf_app_inst) {}

void IndividualSubscriptionDocumentApiImplEventExposure::delete_subscription(
    const std::string& subscriptionId,
    Pistache::Http::ResponseWriter& response) {
  Logger::amf_server().info(
      "SubscriptionsCollectionDocumentApiImplEventExposure::delete_"
      "subscription");

  Logger::amf_server().debug(
      "Delete a subscription with ID %s", subscriptionId.c_str());

  if (m_amf_app->handle_event_exposure_delete(subscriptionId)) {
    response.send(Pistache::Http::Code::No_Content);
  } else {
    // Send response
    nlohmann::json json_data       = {};
    ProblemDetails problem_details = {};
    problem_details.setCause("SUBSCRIPTION_NOT_FOUND");
    to_json(json_data, problem_details);
    response.send(Pistache::Http::Code::Not_Found, json_data.dump().c_str());
  }
}

void IndividualSubscriptionDocumentApiImplEventExposure::modify_subscription(
    const std::string& subscriptionId,
    const AmfUpdateEventOptionItem& amfUpdateEventOptionItem,
    Pistache::Http::ResponseWriter& response) {
  response.send(
      Pistache::Http::Code::Ok, "This API has not been implemented yet!\n");
}

}  // namespace api
}  // namespace amf
}  // namespace oai
