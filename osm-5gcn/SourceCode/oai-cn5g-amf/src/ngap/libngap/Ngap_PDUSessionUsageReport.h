/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "asn.1/Information Element Definitions.asn1"
 * 	`asn1c -pdu=all -fcompound-names -fno-include-deps -findirect-choice
 * -no-gen-example -gen-APER -gen-UPER -no-gen-JER -gen-BER -D src`
 */

#ifndef _Ngap_PDUSessionUsageReport_H_
#define _Ngap_PDUSessionUsageReport_H_

#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include "Ngap_VolumeTimedReportList.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Ngap_PDUSessionUsageReport__rATType {
  Ngap_PDUSessionUsageReport__rATType_nr    = 0,
  Ngap_PDUSessionUsageReport__rATType_eutra = 1,
  /*
   * Enumeration is extensible
   */
  Ngap_PDUSessionUsageReport__rATType_nr_unlicensed     = 2,
  Ngap_PDUSessionUsageReport__rATType_e_utra_unlicensed = 3
} e_Ngap_PDUSessionUsageReport__rATType;

/* Forward declarations */
struct Ngap_ProtocolExtensionContainer;

/* Ngap_PDUSessionUsageReport */
typedef struct Ngap_PDUSessionUsageReport {
  long rATType;
  Ngap_VolumeTimedReportList_t pDUSessionTimedReportList;
  struct Ngap_ProtocolExtensionContainer* iE_Extensions; /* OPTIONAL */
  /*
   * This type is extensible,
   * possible extensions are below.
   */

  /* Context for parsing across buffer boundaries */
  asn_struct_ctx_t _asn_ctx;
} Ngap_PDUSessionUsageReport_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_Ngap_rATType_2;	// (Use
 * -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_Ngap_PDUSessionUsageReport;
extern asn_SEQUENCE_specifics_t asn_SPC_Ngap_PDUSessionUsageReport_specs_1;
extern asn_TYPE_member_t asn_MBR_Ngap_PDUSessionUsageReport_1[3];

#ifdef __cplusplus
}
#endif

#endif /* _Ngap_PDUSessionUsageReport_H_ */
#include <asn_internal.h>
