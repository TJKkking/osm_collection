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
/*
 * NotificationType.h
 *
 *
 */

#ifndef NotificationType_H_
#define NotificationType_H_

#include <nlohmann/json.hpp>

namespace oai::model::nrf {

/// <summary>
///
/// </summary>
class NotificationType {
 public:
  NotificationType();
  virtual ~NotificationType();

  void validate();

  /////////////////////////////////////////////
  /// NotificationType members

  friend void to_json(nlohmann::json& j, const NotificationType& o);
  friend void from_json(const nlohmann::json& j, NotificationType& o);

 protected:
};

}  // namespace oai::model::nrf

#endif /* NotificationType_H_ */
