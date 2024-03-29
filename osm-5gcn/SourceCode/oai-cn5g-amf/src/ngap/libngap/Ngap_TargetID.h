/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "asn.1/Information Element Definitions.asn1"
 * 	`asn1c -pdu=all -fcompound-names -fno-include-deps -findirect-choice
 * -no-gen-example -gen-APER -gen-UPER -no-gen-JER -gen-BER -D src`
 */

#ifndef _Ngap_TargetID_H_
#define _Ngap_TargetID_H_

#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Ngap_TargetID_PR {
  Ngap_TargetID_PR_NOTHING, /* No components present */
  Ngap_TargetID_PR_targetRANNodeID,
  Ngap_TargetID_PR_targeteNB_ID,
  Ngap_TargetID_PR_choice_Extensions
} Ngap_TargetID_PR;

/* Forward declarations */
struct Ngap_TargetRANNodeID;
struct Ngap_TargeteNB_ID;
struct Ngap_ProtocolIE_SingleContainer;

/* Ngap_TargetID */
typedef struct Ngap_TargetID {
  Ngap_TargetID_PR present;
  union Ngap_TargetID_u {
    struct Ngap_TargetRANNodeID* targetRANNodeID;
    struct Ngap_TargeteNB_ID* targeteNB_ID;
    struct Ngap_ProtocolIE_SingleContainer* choice_Extensions;
  } choice;

  /* Context for parsing across buffer boundaries */
  asn_struct_ctx_t _asn_ctx;
} Ngap_TargetID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Ngap_TargetID;
extern asn_CHOICE_specifics_t asn_SPC_Ngap_TargetID_specs_1;
extern asn_TYPE_member_t asn_MBR_Ngap_TargetID_1[3];
extern asn_per_constraints_t asn_PER_type_Ngap_TargetID_constr_1;

#ifdef __cplusplus
}
#endif

#endif /* _Ngap_TargetID_H_ */
#include <asn_internal.h>
