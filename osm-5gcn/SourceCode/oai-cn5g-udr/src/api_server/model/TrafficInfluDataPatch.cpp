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

#include "TrafficInfluDataPatch.h"

namespace oai::udr::model {

TrafficInfluDataPatch::TrafficInfluDataPatch() {
  m_UpPathChgNotifCorreId      = "";
  m_UpPathChgNotifCorreIdIsSet = false;
  m_AppReloInd                 = false;
  m_AppReloIndIsSet            = false;
  m_Dnn                        = "";
  m_DnnIsSet                   = false;
  m_EthTrafficFiltersIsSet     = false;
  m_SnssaiIsSet                = false;
  m_InternalGroupId            = "";
  m_InternalGroupIdIsSet       = false;
  m_Supi                       = "";
  m_SupiIsSet                  = false;
  m_TrafficFiltersIsSet        = false;
  m_TrafficRoutesIsSet         = false;
  m_TraffCorreInd              = false;
  m_TraffCorreIndIsSet         = false;
  m_ValidStartTime             = "";
  m_ValidStartTimeIsSet        = false;
  m_ValidEndTime               = "";
  m_ValidEndTimeIsSet          = false;
  m_TempValiditiesIsSet        = false;
  m_NwAreaInfoIsSet            = false;
  m_UpPathChgNotifUri          = "";
  m_UpPathChgNotifUriIsSet     = false;
  m_HeadersIsSet               = false;
  m_AfAckInd                   = false;
  m_AfAckIndIsSet              = false;
  m_AddrPreserInd              = false;
  m_AddrPreserIndIsSet         = false;
}

TrafficInfluDataPatch::~TrafficInfluDataPatch() {}

void TrafficInfluDataPatch::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const TrafficInfluDataPatch& o) {
  j = nlohmann::json();
  if (o.upPathChgNotifCorreIdIsSet())
    j["upPathChgNotifCorreId"] = o.m_UpPathChgNotifCorreId;
  if (o.appReloIndIsSet()) j["appReloInd"] = o.m_AppReloInd;
  if (o.dnnIsSet()) j["dnn"] = o.m_Dnn;
  if (o.ethTrafficFiltersIsSet() || !o.m_EthTrafficFilters.empty())
    j["ethTrafficFilters"] = o.m_EthTrafficFilters;
  if (o.snssaiIsSet()) j["snssai"] = o.m_Snssai;
  if (o.internalGroupIdIsSet()) j["internalGroupId"] = o.m_InternalGroupId;
  if (o.supiIsSet()) j["supi"] = o.m_Supi;
  if (o.trafficFiltersIsSet() || !o.m_TrafficFilters.empty())
    j["trafficFilters"] = o.m_TrafficFilters;
  if (o.trafficRoutesIsSet() || !o.m_TrafficRoutes.empty())
    j["trafficRoutes"] = o.m_TrafficRoutes;
  if (o.traffCorreIndIsSet()) j["traffCorreInd"] = o.m_TraffCorreInd;
  if (o.validStartTimeIsSet()) j["validStartTime"] = o.m_ValidStartTime;
  if (o.validEndTimeIsSet()) j["validEndTime"] = o.m_ValidEndTime;
  if (o.tempValiditiesIsSet() || !o.m_TempValidities.empty())
    j["tempValidities"] = o.m_TempValidities;
  if (o.nwAreaInfoIsSet()) j["nwAreaInfo"] = o.m_NwAreaInfo;
  if (o.upPathChgNotifUriIsSet())
    j["upPathChgNotifUri"] = o.m_UpPathChgNotifUri;
  if (o.headersIsSet() || !o.m_Headers.empty()) j["headers"] = o.m_Headers;
  if (o.afAckIndIsSet()) j["afAckInd"] = o.m_AfAckInd;
  if (o.addrPreserIndIsSet()) j["addrPreserInd"] = o.m_AddrPreserInd;
}

void from_json(const nlohmann::json& j, TrafficInfluDataPatch& o) {
  if (j.find("upPathChgNotifCorreId") != j.end()) {
    j.at("upPathChgNotifCorreId").get_to(o.m_UpPathChgNotifCorreId);
    o.m_UpPathChgNotifCorreIdIsSet = true;
  }
  if (j.find("appReloInd") != j.end()) {
    j.at("appReloInd").get_to(o.m_AppReloInd);
    o.m_AppReloIndIsSet = true;
  }
  if (j.find("dnn") != j.end()) {
    j.at("dnn").get_to(o.m_Dnn);
    o.m_DnnIsSet = true;
  }
  if (j.find("ethTrafficFilters") != j.end()) {
    j.at("ethTrafficFilters").get_to(o.m_EthTrafficFilters);
    o.m_EthTrafficFiltersIsSet = true;
  }
  if (j.find("snssai") != j.end()) {
    j.at("snssai").get_to(o.m_Snssai);
    o.m_SnssaiIsSet = true;
  }
  if (j.find("internalGroupId") != j.end()) {
    j.at("internalGroupId").get_to(o.m_InternalGroupId);
    o.m_InternalGroupIdIsSet = true;
  }
  if (j.find("supi") != j.end()) {
    j.at("supi").get_to(o.m_Supi);
    o.m_SupiIsSet = true;
  }
  if (j.find("trafficFilters") != j.end()) {
    j.at("trafficFilters").get_to(o.m_TrafficFilters);
    o.m_TrafficFiltersIsSet = true;
  }
  if (j.find("trafficRoutes") != j.end()) {
    j.at("trafficRoutes").get_to(o.m_TrafficRoutes);
    o.m_TrafficRoutesIsSet = true;
  }
  if (j.find("traffCorreInd") != j.end()) {
    j.at("traffCorreInd").get_to(o.m_TraffCorreInd);
    o.m_TraffCorreIndIsSet = true;
  }
  if (j.find("validStartTime") != j.end()) {
    j.at("validStartTime").get_to(o.m_ValidStartTime);
    o.m_ValidStartTimeIsSet = true;
  }
  if (j.find("validEndTime") != j.end()) {
    j.at("validEndTime").get_to(o.m_ValidEndTime);
    o.m_ValidEndTimeIsSet = true;
  }
  if (j.find("tempValidities") != j.end()) {
    j.at("tempValidities").get_to(o.m_TempValidities);
    o.m_TempValiditiesIsSet = true;
  }
  if (j.find("nwAreaInfo") != j.end()) {
    j.at("nwAreaInfo").get_to(o.m_NwAreaInfo);
    o.m_NwAreaInfoIsSet = true;
  }
  if (j.find("upPathChgNotifUri") != j.end()) {
    j.at("upPathChgNotifUri").get_to(o.m_UpPathChgNotifUri);
    o.m_UpPathChgNotifUriIsSet = true;
  }
  if (j.find("headers") != j.end()) {
    j.at("headers").get_to(o.m_Headers);
    o.m_HeadersIsSet = true;
  }
  if (j.find("afAckInd") != j.end()) {
    j.at("afAckInd").get_to(o.m_AfAckInd);
    o.m_AfAckIndIsSet = true;
  }
  if (j.find("addrPreserInd") != j.end()) {
    j.at("addrPreserInd").get_to(o.m_AddrPreserInd);
    o.m_AddrPreserIndIsSet = true;
  }
}

std::string TrafficInfluDataPatch::getUpPathChgNotifCorreId() const {
  return m_UpPathChgNotifCorreId;
}
void TrafficInfluDataPatch::setUpPathChgNotifCorreId(std::string const& value) {
  m_UpPathChgNotifCorreId      = value;
  m_UpPathChgNotifCorreIdIsSet = true;
}
bool TrafficInfluDataPatch::upPathChgNotifCorreIdIsSet() const {
  return m_UpPathChgNotifCorreIdIsSet;
}
void TrafficInfluDataPatch::unsetUpPathChgNotifCorreId() {
  m_UpPathChgNotifCorreIdIsSet = false;
}
bool TrafficInfluDataPatch::isAppReloInd() const {
  return m_AppReloInd;
}
void TrafficInfluDataPatch::setAppReloInd(bool const value) {
  m_AppReloInd      = value;
  m_AppReloIndIsSet = true;
}
bool TrafficInfluDataPatch::appReloIndIsSet() const {
  return m_AppReloIndIsSet;
}
void TrafficInfluDataPatch::unsetAppReloInd() {
  m_AppReloIndIsSet = false;
}
std::string TrafficInfluDataPatch::getDnn() const {
  return m_Dnn;
}
void TrafficInfluDataPatch::setDnn(std::string const& value) {
  m_Dnn      = value;
  m_DnnIsSet = true;
}
bool TrafficInfluDataPatch::dnnIsSet() const {
  return m_DnnIsSet;
}
void TrafficInfluDataPatch::unsetDnn() {
  m_DnnIsSet = false;
}
std::vector<EthFlowDescription>& TrafficInfluDataPatch::getEthTrafficFilters() {
  return m_EthTrafficFilters;
}
void TrafficInfluDataPatch::setEthTrafficFilters(
    std::vector<EthFlowDescription> const& value) {
  m_EthTrafficFilters      = value;
  m_EthTrafficFiltersIsSet = true;
}
bool TrafficInfluDataPatch::ethTrafficFiltersIsSet() const {
  return m_EthTrafficFiltersIsSet;
}
void TrafficInfluDataPatch::unsetEthTrafficFilters() {
  m_EthTrafficFiltersIsSet = false;
}
oai::model::common::Snssai TrafficInfluDataPatch::getSnssai() const {
  return m_Snssai;
}
void TrafficInfluDataPatch::setSnssai(oai::model::common::Snssai const& value) {
  m_Snssai      = value;
  m_SnssaiIsSet = true;
}
bool TrafficInfluDataPatch::snssaiIsSet() const {
  return m_SnssaiIsSet;
}
void TrafficInfluDataPatch::unsetSnssai() {
  m_SnssaiIsSet = false;
}
std::string TrafficInfluDataPatch::getInternalGroupId() const {
  return m_InternalGroupId;
}
void TrafficInfluDataPatch::setInternalGroupId(std::string const& value) {
  m_InternalGroupId      = value;
  m_InternalGroupIdIsSet = true;
}
bool TrafficInfluDataPatch::internalGroupIdIsSet() const {
  return m_InternalGroupIdIsSet;
}
void TrafficInfluDataPatch::unsetInternalGroupId() {
  m_InternalGroupIdIsSet = false;
}
std::string TrafficInfluDataPatch::getSupi() const {
  return m_Supi;
}
void TrafficInfluDataPatch::setSupi(std::string const& value) {
  m_Supi      = value;
  m_SupiIsSet = true;
}
bool TrafficInfluDataPatch::supiIsSet() const {
  return m_SupiIsSet;
}
void TrafficInfluDataPatch::unsetSupi() {
  m_SupiIsSet = false;
}
std::vector<FlowInfo>& TrafficInfluDataPatch::getTrafficFilters() {
  return m_TrafficFilters;
}
void TrafficInfluDataPatch::setTrafficFilters(
    std::vector<FlowInfo> const& value) {
  m_TrafficFilters      = value;
  m_TrafficFiltersIsSet = true;
}
bool TrafficInfluDataPatch::trafficFiltersIsSet() const {
  return m_TrafficFiltersIsSet;
}
void TrafficInfluDataPatch::unsetTrafficFilters() {
  m_TrafficFiltersIsSet = false;
}
std::vector<oai::model::common::RouteToLocation>&
TrafficInfluDataPatch::getTrafficRoutes() {
  return m_TrafficRoutes;
}
void TrafficInfluDataPatch::setTrafficRoutes(
    std::vector<oai::model::common::RouteToLocation> const& value) {
  m_TrafficRoutes      = value;
  m_TrafficRoutesIsSet = true;
}
bool TrafficInfluDataPatch::trafficRoutesIsSet() const {
  return m_TrafficRoutesIsSet;
}
void TrafficInfluDataPatch::unsetTrafficRoutes() {
  m_TrafficRoutesIsSet = false;
}
bool TrafficInfluDataPatch::isTraffCorreInd() const {
  return m_TraffCorreInd;
}
void TrafficInfluDataPatch::setTraffCorreInd(bool const value) {
  m_TraffCorreInd      = value;
  m_TraffCorreIndIsSet = true;
}
bool TrafficInfluDataPatch::traffCorreIndIsSet() const {
  return m_TraffCorreIndIsSet;
}
void TrafficInfluDataPatch::unsetTraffCorreInd() {
  m_TraffCorreIndIsSet = false;
}
std::string TrafficInfluDataPatch::getValidStartTime() const {
  return m_ValidStartTime;
}
void TrafficInfluDataPatch::setValidStartTime(std::string const& value) {
  m_ValidStartTime      = value;
  m_ValidStartTimeIsSet = true;
}
bool TrafficInfluDataPatch::validStartTimeIsSet() const {
  return m_ValidStartTimeIsSet;
}
void TrafficInfluDataPatch::unsetValidStartTime() {
  m_ValidStartTimeIsSet = false;
}
std::string TrafficInfluDataPatch::getValidEndTime() const {
  return m_ValidEndTime;
}
void TrafficInfluDataPatch::setValidEndTime(std::string const& value) {
  m_ValidEndTime      = value;
  m_ValidEndTimeIsSet = true;
}
bool TrafficInfluDataPatch::validEndTimeIsSet() const {
  return m_ValidEndTimeIsSet;
}
void TrafficInfluDataPatch::unsetValidEndTime() {
  m_ValidEndTimeIsSet = false;
}
std::vector<TemporalValidity>& TrafficInfluDataPatch::getTempValidities() {
  return m_TempValidities;
}
void TrafficInfluDataPatch::setTempValidities(
    std::vector<TemporalValidity> const& value) {
  m_TempValidities      = value;
  m_TempValiditiesIsSet = true;
}
bool TrafficInfluDataPatch::tempValiditiesIsSet() const {
  return m_TempValiditiesIsSet;
}
void TrafficInfluDataPatch::unsetTempValidities() {
  m_TempValiditiesIsSet = false;
}
NetworkAreaInfo_2 TrafficInfluDataPatch::getNwAreaInfo() const {
  return m_NwAreaInfo;
}
void TrafficInfluDataPatch::setNwAreaInfo(NetworkAreaInfo_2 const& value) {
  m_NwAreaInfo      = value;
  m_NwAreaInfoIsSet = true;
}
bool TrafficInfluDataPatch::nwAreaInfoIsSet() const {
  return m_NwAreaInfoIsSet;
}
void TrafficInfluDataPatch::unsetNwAreaInfo() {
  m_NwAreaInfoIsSet = false;
}
std::string TrafficInfluDataPatch::getUpPathChgNotifUri() const {
  return m_UpPathChgNotifUri;
}
void TrafficInfluDataPatch::setUpPathChgNotifUri(std::string const& value) {
  m_UpPathChgNotifUri      = value;
  m_UpPathChgNotifUriIsSet = true;
}
bool TrafficInfluDataPatch::upPathChgNotifUriIsSet() const {
  return m_UpPathChgNotifUriIsSet;
}
void TrafficInfluDataPatch::unsetUpPathChgNotifUri() {
  m_UpPathChgNotifUriIsSet = false;
}
std::vector<std::string>& TrafficInfluDataPatch::getHeaders() {
  return m_Headers;
}
void TrafficInfluDataPatch::setHeaders(std::vector<std::string> const& value) {
  m_Headers      = value;
  m_HeadersIsSet = true;
}
bool TrafficInfluDataPatch::headersIsSet() const {
  return m_HeadersIsSet;
}
void TrafficInfluDataPatch::unsetHeaders() {
  m_HeadersIsSet = false;
}
bool TrafficInfluDataPatch::isAfAckInd() const {
  return m_AfAckInd;
}
void TrafficInfluDataPatch::setAfAckInd(bool const value) {
  m_AfAckInd      = value;
  m_AfAckIndIsSet = true;
}
bool TrafficInfluDataPatch::afAckIndIsSet() const {
  return m_AfAckIndIsSet;
}
void TrafficInfluDataPatch::unsetAfAckInd() {
  m_AfAckIndIsSet = false;
}
bool TrafficInfluDataPatch::isAddrPreserInd() const {
  return m_AddrPreserInd;
}
void TrafficInfluDataPatch::setAddrPreserInd(bool const value) {
  m_AddrPreserInd      = value;
  m_AddrPreserIndIsSet = true;
}
bool TrafficInfluDataPatch::addrPreserIndIsSet() const {
  return m_AddrPreserIndIsSet;
}
void TrafficInfluDataPatch::unsetAddrPreserInd() {
  m_AddrPreserIndIsSet = false;
}

}  // namespace oai::udr::model
