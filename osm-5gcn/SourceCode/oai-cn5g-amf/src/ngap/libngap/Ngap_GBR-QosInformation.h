/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "asn.1/Information Element Definitions.asn1"
 * 	`asn1c -pdu=all -fcompound-names -fno-include-deps -findirect-choice
 * -no-gen-example -gen-APER -gen-UPER -no-gen-JER -gen-BER -D src`
 */

#ifndef _Ngap_GBR_QosInformation_H_
#define _Ngap_GBR_QosInformation_H_

#include <asn_application.h>

/* Including external dependencies */
#include "Ngap_BitRate.h"
#include "Ngap_NotificationControl.h"
#include "Ngap_PacketLossRate.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct Ngap_ProtocolExtensionContainer;

/* Ngap_GBR-QosInformation */
typedef struct Ngap_GBR_QosInformation {
  Ngap_BitRate_t maximumFlowBitRateDL;
  Ngap_BitRate_t maximumFlowBitRateUL;
  Ngap_BitRate_t guaranteedFlowBitRateDL;
  Ngap_BitRate_t guaranteedFlowBitRateUL;
  Ngap_NotificationControl_t* notificationControl;       /* OPTIONAL */
  Ngap_PacketLossRate_t* maximumPacketLossRateDL;        /* OPTIONAL */
  Ngap_PacketLossRate_t* maximumPacketLossRateUL;        /* OPTIONAL */
  struct Ngap_ProtocolExtensionContainer* iE_Extensions; /* OPTIONAL */
  /*
   * This type is extensible,
   * possible extensions are below.
   */

  /* Context for parsing across buffer boundaries */
  asn_struct_ctx_t _asn_ctx;
} Ngap_GBR_QosInformation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Ngap_GBR_QosInformation;
extern asn_SEQUENCE_specifics_t asn_SPC_Ngap_GBR_QosInformation_specs_1;
extern asn_TYPE_member_t asn_MBR_Ngap_GBR_QosInformation_1[8];

#ifdef __cplusplus
}
#endif

#endif /* _Ngap_GBR_QosInformation_H_ */
#include <asn_internal.h>
