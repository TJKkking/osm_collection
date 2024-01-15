/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "asn.1/Information Element Definitions.asn1"
 * 	`asn1c -pdu=all -fcompound-names -fno-include-deps -findirect-choice
 * -no-gen-example -gen-APER -gen-UPER -no-gen-JER -gen-BER -D src`
 */

#ifndef _Ngap_CauseProtocol_H_
#define _Ngap_CauseProtocol_H_

#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Ngap_CauseProtocol {
  Ngap_CauseProtocol_transfer_syntax_error                             = 0,
  Ngap_CauseProtocol_abstract_syntax_error_reject                      = 1,
  Ngap_CauseProtocol_abstract_syntax_error_ignore_and_notify           = 2,
  Ngap_CauseProtocol_message_not_compatible_with_receiver_state        = 3,
  Ngap_CauseProtocol_semantic_error                                    = 4,
  Ngap_CauseProtocol_abstract_syntax_error_falsely_constructed_message = 5,
  Ngap_CauseProtocol_unspecified                                       = 6
  /*
   * Enumeration is extensible
   */
} e_Ngap_CauseProtocol;

/* Ngap_CauseProtocol */
typedef long Ngap_CauseProtocol_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_Ngap_CauseProtocol_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_Ngap_CauseProtocol;
extern const asn_INTEGER_specifics_t asn_SPC_Ngap_CauseProtocol_specs_1;
asn_struct_free_f Ngap_CauseProtocol_free;
asn_struct_print_f Ngap_CauseProtocol_print;
asn_constr_check_f Ngap_CauseProtocol_constraint;
ber_type_decoder_f Ngap_CauseProtocol_decode_ber;
der_type_encoder_f Ngap_CauseProtocol_encode_der;
xer_type_decoder_f Ngap_CauseProtocol_decode_xer;
xer_type_encoder_f Ngap_CauseProtocol_encode_xer;
oer_type_decoder_f Ngap_CauseProtocol_decode_oer;
oer_type_encoder_f Ngap_CauseProtocol_encode_oer;
per_type_decoder_f Ngap_CauseProtocol_decode_uper;
per_type_encoder_f Ngap_CauseProtocol_encode_uper;
per_type_decoder_f Ngap_CauseProtocol_decode_aper;
per_type_encoder_f Ngap_CauseProtocol_encode_aper;

#ifdef __cplusplus
}
#endif

#endif /* _Ngap_CauseProtocol_H_ */
#include <asn_internal.h>
