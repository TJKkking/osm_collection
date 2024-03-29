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
 * IpEndPoint.h
 *
 *
 */

#ifndef IpEndPoint_H_
#define IpEndPoint_H_

#include "TransportProtocol.h"
#include <string>
#include "Ipv6Addr.h"
#include <nlohmann/json.hpp>

namespace oai::model::nrf {

/// <summary>
///
/// </summary>
class IpEndPoint {
 public:
  IpEndPoint();
  virtual ~IpEndPoint();

  void validate();

  /////////////////////////////////////////////
  /// IpEndPoint members

  /// <summary>
  ///
  /// </summary>
  std::string getIpv4Address() const;
  void setIpv4Address(std::string const& value);
  bool ipv4AddressIsSet() const;
  void unsetIpv4Address();
  /// <summary>
  ///
  /// </summary>
  oai::model::common::Ipv6Addr getIpv6Address() const;
  void setIpv6Address(oai::model::common::Ipv6Addr const& value);
  bool ipv6AddressIsSet() const;
  void unsetIpv6Address();
  /// <summary>
  ///
  /// </summary>
  oai::model::common::TransportProtocol getTransport() const;
  void setTransport(oai::model::common::TransportProtocol const& value);
  bool transportIsSet() const;
  void unsetTransport();
  /// <summary>
  ///
  /// </summary>
  int32_t getPort() const;
  void setPort(int32_t const value);
  bool portIsSet() const;
  void unsetPort();

  friend void to_json(nlohmann::json& j, const IpEndPoint& o);
  friend void from_json(const nlohmann::json& j, IpEndPoint& o);

 protected:
  std::string m_Ipv4Address;
  bool m_Ipv4AddressIsSet;
  oai::model::common::Ipv6Addr m_Ipv6Address;
  bool m_Ipv6AddressIsSet;
  oai::model::common::TransportProtocol m_Transport;
  bool m_TransportIsSet;
  int32_t m_Port;
  bool m_PortIsSet;
};

}  // namespace oai::model::nrf

#endif /* IpEndPoint_H_ */
