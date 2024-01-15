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
 * Nudr_DataRepository API OpenAPI file
 * Unified Data Repository Service. © 2020, 3GPP Organizational Partners (ARIB,
 * ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 2.1.2
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "AmfSubscriptionInfo.h"

namespace oai::udr::model {

AmfSubscriptionInfo::AmfSubscriptionInfo() {
  m_AmfInstanceId                      = "";
  m_SubscriptionId                     = "";
  m_SubsChangeNotifyCorrelationId      = "";
  m_SubsChangeNotifyCorrelationIdIsSet = false;
}

AmfSubscriptionInfo::~AmfSubscriptionInfo() {}

void AmfSubscriptionInfo::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const AmfSubscriptionInfo& o) {
  j                   = nlohmann::json();
  j["amfInstanceId"]  = o.m_AmfInstanceId;
  j["subscriptionId"] = o.m_SubscriptionId;
  if (o.subsChangeNotifyCorrelationIdIsSet())
    j["subsChangeNotifyCorrelationId"] = o.m_SubsChangeNotifyCorrelationId;
}

void from_json(const nlohmann::json& j, AmfSubscriptionInfo& o) {
  j.at("amfInstanceId").get_to(o.m_AmfInstanceId);
  j.at("subscriptionId").get_to(o.m_SubscriptionId);
  if (j.find("subsChangeNotifyCorrelationId") != j.end()) {
    j.at("subsChangeNotifyCorrelationId")
        .get_to(o.m_SubsChangeNotifyCorrelationId);
    o.m_SubsChangeNotifyCorrelationIdIsSet = true;
  }
}

std::string AmfSubscriptionInfo::getAmfInstanceId() const {
  return m_AmfInstanceId;
}
void AmfSubscriptionInfo::setAmfInstanceId(std::string const& value) {
  m_AmfInstanceId = value;
}
std::string AmfSubscriptionInfo::getSubscriptionId() const {
  return m_SubscriptionId;
}
void AmfSubscriptionInfo::setSubscriptionId(std::string const& value) {
  m_SubscriptionId = value;
}
std::string AmfSubscriptionInfo::getSubsChangeNotifyCorrelationId() const {
  return m_SubsChangeNotifyCorrelationId;
}
void AmfSubscriptionInfo::setSubsChangeNotifyCorrelationId(
    std::string const& value) {
  m_SubsChangeNotifyCorrelationId      = value;
  m_SubsChangeNotifyCorrelationIdIsSet = true;
}
bool AmfSubscriptionInfo::subsChangeNotifyCorrelationIdIsSet() const {
  return m_SubsChangeNotifyCorrelationIdIsSet;
}
void AmfSubscriptionInfo::unsetSubsChangeNotifyCorrelationId() {
  m_SubsChangeNotifyCorrelationIdIsSet = false;
}

}  // namespace oai::udr::model