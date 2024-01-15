/**
 * Namf_Communication
 * AMF Communication Service © 2019, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "PWSResponseData.h"

namespace oai {
namespace amf {
namespace model {

PWSResponseData::PWSResponseData() {
  m_NgapMessageType     = 0;
  m_SerialNumber        = 0;
  m_MessageIdentifier   = 0;
  m_UnknownTaiListIsSet = false;
}

PWSResponseData::~PWSResponseData() {}

void PWSResponseData::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const PWSResponseData& o) {
  j                      = nlohmann::json();
  j["ngapMessageType"]   = o.m_NgapMessageType;
  j["serialNumber"]      = o.m_SerialNumber;
  j["messageIdentifier"] = o.m_MessageIdentifier;
  if (o.unknownTaiListIsSet()) j["unknownTaiList"] = o.m_UnknownTaiList;
}

void from_json(const nlohmann::json& j, PWSResponseData& o) {
  j.at("ngapMessageType").get_to(o.m_NgapMessageType);
  j.at("serialNumber").get_to(o.m_SerialNumber);
  j.at("messageIdentifier").get_to(o.m_MessageIdentifier);
  if (j.find("unknownTaiList") != j.end()) {
    j.at("unknownTaiList").get_to(o.m_UnknownTaiList);
    o.m_UnknownTaiListIsSet = true;
  }
}

int32_t PWSResponseData::getNgapMessageType() const {
  return m_NgapMessageType;
}
void PWSResponseData::setNgapMessageType(int32_t const value) {
  m_NgapMessageType = value;
}
int32_t PWSResponseData::getSerialNumber() const {
  return m_SerialNumber;
}
void PWSResponseData::setSerialNumber(int32_t const value) {
  m_SerialNumber = value;
}
int32_t PWSResponseData::getMessageIdentifier() const {
  return m_MessageIdentifier;
}
void PWSResponseData::setMessageIdentifier(int32_t const value) {
  m_MessageIdentifier = value;
}
std::vector<oai::model::common::Tai>& PWSResponseData::getUnknownTaiList() {
  return m_UnknownTaiList;
}
bool PWSResponseData::unknownTaiListIsSet() const {
  return m_UnknownTaiListIsSet;
}
void PWSResponseData::unsetUnknownTaiList() {
  m_UnknownTaiListIsSet = false;
}

}  // namespace model
}  // namespace amf
}  // namespace oai
