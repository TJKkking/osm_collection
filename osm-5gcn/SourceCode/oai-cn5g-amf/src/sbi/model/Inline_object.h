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
/*
 * Inline_object.h
 *
 *
 */

#ifndef Inline_object_H_
#define Inline_object_H_

#include <string>
#include "UeContextCreateData.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace amf {
namespace model {

/// <summary>
///
/// </summary>
class Inline_object {
 public:
  Inline_object();
  virtual ~Inline_object();

  void validate();

  /////////////////////////////////////////////
  /// Inline_object members

  /// <summary>
  ///
  /// </summary>
  UeContextCreateData getJsonData() const;
  void setJsonData(UeContextCreateData const& value);
  bool jsonDataIsSet() const;
  void unsetJsonData();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN2Information() const;
  void setBinaryDataN2Information(std::string const& value);
  bool binaryDataN2InformationIsSet() const;
  void unsetBinaryDataN2Information();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN2InformationExt1() const;
  void setBinaryDataN2InformationExt1(std::string const& value);
  bool binaryDataN2InformationExt1IsSet() const;
  void unsetBinaryDataN2InformationExt1();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN2InformationExt2() const;
  void setBinaryDataN2InformationExt2(std::string const& value);
  bool binaryDataN2InformationExt2IsSet() const;
  void unsetBinaryDataN2InformationExt2();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN2InformationExt3() const;
  void setBinaryDataN2InformationExt3(std::string const& value);
  bool binaryDataN2InformationExt3IsSet() const;
  void unsetBinaryDataN2InformationExt3();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN2InformationExt4() const;
  void setBinaryDataN2InformationExt4(std::string const& value);
  bool binaryDataN2InformationExt4IsSet() const;
  void unsetBinaryDataN2InformationExt4();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN2InformationExt5() const;
  void setBinaryDataN2InformationExt5(std::string const& value);
  bool binaryDataN2InformationExt5IsSet() const;
  void unsetBinaryDataN2InformationExt5();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN2InformationExt6() const;
  void setBinaryDataN2InformationExt6(std::string const& value);
  bool binaryDataN2InformationExt6IsSet() const;
  void unsetBinaryDataN2InformationExt6();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN2InformationExt7() const;
  void setBinaryDataN2InformationExt7(std::string const& value);
  bool binaryDataN2InformationExt7IsSet() const;
  void unsetBinaryDataN2InformationExt7();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN2InformationExt8() const;
  void setBinaryDataN2InformationExt8(std::string const& value);
  bool binaryDataN2InformationExt8IsSet() const;
  void unsetBinaryDataN2InformationExt8();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN2InformationExt9() const;
  void setBinaryDataN2InformationExt9(std::string const& value);
  bool binaryDataN2InformationExt9IsSet() const;
  void unsetBinaryDataN2InformationExt9();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN2InformationExt10() const;
  void setBinaryDataN2InformationExt10(std::string const& value);
  bool binaryDataN2InformationExt10IsSet() const;
  void unsetBinaryDataN2InformationExt10();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN2InformationExt11() const;
  void setBinaryDataN2InformationExt11(std::string const& value);
  bool binaryDataN2InformationExt11IsSet() const;
  void unsetBinaryDataN2InformationExt11();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN2InformationExt12() const;
  void setBinaryDataN2InformationExt12(std::string const& value);
  bool binaryDataN2InformationExt12IsSet() const;
  void unsetBinaryDataN2InformationExt12();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN2InformationExt13() const;
  void setBinaryDataN2InformationExt13(std::string const& value);
  bool binaryDataN2InformationExt13IsSet() const;
  void unsetBinaryDataN2InformationExt13();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN2InformationExt14() const;
  void setBinaryDataN2InformationExt14(std::string const& value);
  bool binaryDataN2InformationExt14IsSet() const;
  void unsetBinaryDataN2InformationExt14();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN2InformationExt15() const;
  void setBinaryDataN2InformationExt15(std::string const& value);
  bool binaryDataN2InformationExt15IsSet() const;
  void unsetBinaryDataN2InformationExt15();
  /// <summary>
  ///
  /// </summary>
  std::string getBinaryDataN2InformationExt16() const;
  void setBinaryDataN2InformationExt16(std::string const& value);
  bool binaryDataN2InformationExt16IsSet() const;
  void unsetBinaryDataN2InformationExt16();

  friend void to_json(nlohmann::json& j, const Inline_object& o);
  friend void from_json(const nlohmann::json& j, Inline_object& o);

 protected:
  UeContextCreateData m_JsonData;
  bool m_JsonDataIsSet;
  std::string m_BinaryDataN2Information;
  bool m_BinaryDataN2InformationIsSet;
  std::string m_BinaryDataN2InformationExt1;
  bool m_BinaryDataN2InformationExt1IsSet;
  std::string m_BinaryDataN2InformationExt2;
  bool m_BinaryDataN2InformationExt2IsSet;
  std::string m_BinaryDataN2InformationExt3;
  bool m_BinaryDataN2InformationExt3IsSet;
  std::string m_BinaryDataN2InformationExt4;
  bool m_BinaryDataN2InformationExt4IsSet;
  std::string m_BinaryDataN2InformationExt5;
  bool m_BinaryDataN2InformationExt5IsSet;
  std::string m_BinaryDataN2InformationExt6;
  bool m_BinaryDataN2InformationExt6IsSet;
  std::string m_BinaryDataN2InformationExt7;
  bool m_BinaryDataN2InformationExt7IsSet;
  std::string m_BinaryDataN2InformationExt8;
  bool m_BinaryDataN2InformationExt8IsSet;
  std::string m_BinaryDataN2InformationExt9;
  bool m_BinaryDataN2InformationExt9IsSet;
  std::string m_BinaryDataN2InformationExt10;
  bool m_BinaryDataN2InformationExt10IsSet;
  std::string m_BinaryDataN2InformationExt11;
  bool m_BinaryDataN2InformationExt11IsSet;
  std::string m_BinaryDataN2InformationExt12;
  bool m_BinaryDataN2InformationExt12IsSet;
  std::string m_BinaryDataN2InformationExt13;
  bool m_BinaryDataN2InformationExt13IsSet;
  std::string m_BinaryDataN2InformationExt14;
  bool m_BinaryDataN2InformationExt14IsSet;
  std::string m_BinaryDataN2InformationExt15;
  bool m_BinaryDataN2InformationExt15IsSet;
  std::string m_BinaryDataN2InformationExt16;
  bool m_BinaryDataN2InformationExt16IsSet;
};

}  // namespace model
}  // namespace amf
}  // namespace oai

#endif /* Inline_object_H_ */
