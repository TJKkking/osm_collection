/**
 * NRF NFManagement Service
 * NRF NFManagement Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "AusfInfo.h"

namespace oai::model::nrf {

AusfInfo::AusfInfo() {
  m_GroupId                = "";
  m_GroupIdIsSet           = false;
  m_SupiRangesIsSet        = false;
  m_RoutingIndicatorsIsSet = false;
}

AusfInfo::~AusfInfo() {}

void AusfInfo::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const AusfInfo& o) {
  j = nlohmann::json();
  if (o.groupIdIsSet()) j["groupId"] = o.m_GroupId;
  if (o.supiRangesIsSet() || !o.m_SupiRanges.empty())
    j["supiRanges"] = o.m_SupiRanges;
  if (o.routingIndicatorsIsSet() || !o.m_RoutingIndicators.empty())
    j["routingIndicators"] = o.m_RoutingIndicators;
}

void from_json(const nlohmann::json& j, AusfInfo& o) {
  if (j.find("groupId") != j.end()) {
    j.at("groupId").get_to(o.m_GroupId);
    o.m_GroupIdIsSet = true;
  }
  if (j.find("supiRanges") != j.end()) {
    j.at("supiRanges").get_to(o.m_SupiRanges);
    o.m_SupiRangesIsSet = true;
  }
  if (j.find("routingIndicators") != j.end()) {
    j.at("routingIndicators").get_to(o.m_RoutingIndicators);
    o.m_RoutingIndicatorsIsSet = true;
  }
}

std::string AusfInfo::getGroupId() const {
  return m_GroupId;
}
void AusfInfo::setGroupId(std::string const& value) {
  m_GroupId      = value;
  m_GroupIdIsSet = true;
}
bool AusfInfo::groupIdIsSet() const {
  return m_GroupIdIsSet;
}
void AusfInfo::unsetGroupId() {
  m_GroupIdIsSet = false;
}
std::vector<SupiRange>& AusfInfo::getSupiRanges() {
  return m_SupiRanges;
}
void AusfInfo::setSupiRanges(std::vector<SupiRange> const& value) {
  m_SupiRanges      = value;
  m_SupiRangesIsSet = true;
}
bool AusfInfo::supiRangesIsSet() const {
  return m_SupiRangesIsSet;
}
void AusfInfo::unsetSupiRanges() {
  m_SupiRangesIsSet = false;
}
std::vector<std::string>& AusfInfo::getRoutingIndicators() {
  return m_RoutingIndicators;
}
void AusfInfo::setRoutingIndicators(std::vector<std::string> const& value) {
  m_RoutingIndicators      = value;
  m_RoutingIndicatorsIsSet = true;
}
bool AusfInfo::routingIndicatorsIsSet() const {
  return m_RoutingIndicatorsIsSet;
}
void AusfInfo::unsetRoutingIndicators() {
  m_RoutingIndicatorsIsSet = false;
}

}  // namespace oai::model::nrf
