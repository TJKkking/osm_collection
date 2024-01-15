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

#include "ReachabilityForDataReportConfig.h"
#include "Helpers.h"

#include <sstream>

namespace oai::udm::model {

ReachabilityForDataReportConfig::ReachabilityForDataReportConfig() {}

void ReachabilityForDataReportConfig::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw oai::model::common::helpers::ValidationException(msg.str());
  }
}

bool ReachabilityForDataReportConfig::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ReachabilityForDataReportConfig::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ReachabilityForDataReportConfig" : pathPrefix;

  return success;
}

bool ReachabilityForDataReportConfig::operator==(
    const ReachabilityForDataReportConfig& rhs) const {
  return true;
}

bool ReachabilityForDataReportConfig::operator!=(
    const ReachabilityForDataReportConfig& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ReachabilityForDataReportConfig& o) {
  j = nlohmann::json();
}

void from_json(const nlohmann::json& j, ReachabilityForDataReportConfig& o) {}

}  // namespace oai::udm::model
