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

#include "DeleteEESubscriptionApiImpl.h"
#include "logger.hpp"
namespace oai {
namespace udm {
namespace api {

using namespace oai::model::common;

DeleteEESubscriptionApiImpl::DeleteEESubscriptionApiImpl(
    const std::shared_ptr<Pistache::Rest::Router>& rtr, udm_app* udm_app_inst,
    std::string address)
    : DeleteEESubscriptionApi(rtr) {}

void DeleteEESubscriptionApiImpl::delete_ee_subscription(
    const std::string& ueIdentity, const std::string& subscriptionId,
    Pistache::Http::ResponseWriter& response) {
  Logger::udm_ee().info("Handle Delete EE Subscription");

  Pistache::Http::Code code     = {};
  long http_code                = 0;
  nlohmann::json json_data      = {};
  ProblemDetails problemDetails = {};

  m_udm_app->handle_delete_ee_subscription(
      ueIdentity, subscriptionId, problemDetails, http_code);

  code = static_cast<Pistache::Http::Code>(http_code);

  Logger::udm_ee().info("Send response to NF");
  if (code == Pistache::Http::Code::No_Content) {
    response.send(code);
  } else {
    response.headers().add<Pistache::Http::Header::ContentType>(
        Pistache::Http::Mime::MediaType("application/problem+json"));
    to_json(json_data, problemDetails);
    response.send(code, json_data.dump().c_str());
  }
}

}  // namespace api
}  // namespace udm
}  // namespace oai
