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

#include "RmState_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace oai::amf::model {

RmState_anyOf::RmState_anyOf() {}

void RmState_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw oai::model::common::helpers::ValidationException(msg.str());
  }
}

bool RmState_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool RmState_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "RmState_anyOf" : pathPrefix;

  if (m_value ==
      RmState_anyOf::eRmState_anyOf::INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool RmState_anyOf::operator==(const RmState_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool RmState_anyOf::operator!=(const RmState_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const RmState_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case RmState_anyOf::eRmState_anyOf::INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case RmState_anyOf::eRmState_anyOf::REGISTERED:
      j = "REGISTERED";
      break;
    case RmState_anyOf::eRmState_anyOf::DEREGISTERED:
      j = "DEREGISTERED";
      break;
  }
}

void from_json(const nlohmann::json& j, RmState_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "REGISTERED") {
    o.setValue(RmState_anyOf::eRmState_anyOf::REGISTERED);
  } else if (s == "DEREGISTERED") {
    o.setValue(RmState_anyOf::eRmState_anyOf::DEREGISTERED);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " RmState_anyOf::eRmState_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

RmState_anyOf::eRmState_anyOf RmState_anyOf::getValue() const {
  return m_value;
}
void RmState_anyOf::setValue(RmState_anyOf::eRmState_anyOf value) {
  m_value = value;
}

}  // namespace oai::amf::model