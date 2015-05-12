#ifndef __c12_MiL_BMS_Bat_h__
#define __c12_MiL_BMS_Bat_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  int32_T c12_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c12_doneDoubleBufferReInit;
  boolean_T c12_error_code_not_empty;
  boolean_T c12_error_index_not_empty;
  boolean_T c12_error_not_empty;
  boolean_T c12_isStable;
  boolean_T c12_timer_not_empty;
  uint8_T c12_error;
  uint8_T c12_error_code;
  uint8_T c12_error_index;
  uint8_T c12_is_active_c12_MiL_BMS_Bat;
  uint8_T c12_timer;
  ChartInfoStruct chartInfo;
} SFc12_MiL_BMS_BatInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c12_MiL_BMS_Bat_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c12_MiL_BMS_Bat_get_check_sum(mxArray *plhs[]);
extern void c12_MiL_BMS_Bat_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
