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
 * NonUEN2MessagesCollectionDocumentApiImpl.h
 *
 *
 */

#ifndef NON_UEN2_MESSAGES_COLLECTION_DOCUMENT_API_IMPL_H_
#define NON_UEN2_MESSAGES_COLLECTION_DOCUMENT_API_IMPL_H_

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <memory>

#include <NonUEN2MessagesCollectionDocumentApi.h>

#include <pistache/optional.h>

#include "N2InformationTransferError.h"
#include "N2InformationTransferReqData.h"
#include "N2InformationTransferRspData.h"
#include "ProblemDetails.h"

#include "amf_app.hpp"
#include "mime_parser.hpp"

namespace oai {
namespace amf {
namespace api {

using namespace oai::amf::model;

class NonUEN2MessagesCollectionDocumentApiImpl
    : public oai::amf::api::NonUEN2MessagesCollectionDocumentApi {
 public:
  NonUEN2MessagesCollectionDocumentApiImpl(
      std::shared_ptr<Pistache::Rest::Router>,
      amf_application::amf_app* amf_app_inst);
  ~NonUEN2MessagesCollectionDocumentApiImpl() {}

  void non_ue_n2_message_transfer(
      std::unordered_map<std::string, mime_part>& parts,
      Pistache::Http::ResponseWriter& response);

 private:
  amf_application::amf_app* m_amf_app;
};

}  // namespace api
}  // namespace amf
}  // namespace oai

#endif
