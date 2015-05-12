/* Include files */

#include "blascompat32.h"
#include "MiL_BMS_Bat_sfun.h"
#include "c2_MiL_BMS_Bat.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "MiL_BMS_Bat_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[8] = { "voltage", "current", "nargin",
  "nargout", "currents_in", "voltages_in", "current_out", "voltage_out" };

/* Function Declarations */
static void initialize_c2_MiL_BMS_Bat(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance);
static void initialize_params_c2_MiL_BMS_Bat(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance);
static void enable_c2_MiL_BMS_Bat(SFc2_MiL_BMS_BatInstanceStruct *chartInstance);
static void disable_c2_MiL_BMS_Bat(SFc2_MiL_BMS_BatInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_MiL_BMS_Bat
  (SFc2_MiL_BMS_BatInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_MiL_BMS_Bat
  (SFc2_MiL_BMS_BatInstanceStruct *chartInstance);
static void set_sim_state_c2_MiL_BMS_Bat(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_MiL_BMS_Bat(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance);
static void sf_c2_MiL_BMS_Bat(SFc2_MiL_BMS_BatInstanceStruct *chartInstance);
static void c2_chartstep_c2_MiL_BMS_Bat(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance);
static void initSimStructsc2_MiL_BMS_Bat(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static uint16_T c2_emlrt_marshallIn(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c2_voltage_out, const char_T *c2_identifier);
static uint16_T c2_b_emlrt_marshallIn(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int16_T c2_c_emlrt_marshallIn(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c2_current_out, const char_T *c2_identifier);
static int16_T c2_d_emlrt_marshallIn(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_e_emlrt_marshallIn(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_f_emlrt_marshallIn(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_g_emlrt_marshallIn(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_MiL_BMS_Bat, const char_T
  *c2_identifier);
static uint8_T c2_h_emlrt_marshallIn(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_MiL_BMS_BatInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_MiL_BMS_Bat(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_MiL_BMS_Bat = 0U;
}

static void initialize_params_c2_MiL_BMS_Bat(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance)
{
}

static void enable_c2_MiL_BMS_Bat(SFc2_MiL_BMS_BatInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_MiL_BMS_Bat(SFc2_MiL_BMS_BatInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_MiL_BMS_Bat
  (SFc2_MiL_BMS_BatInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_MiL_BMS_Bat
  (SFc2_MiL_BMS_BatInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int16_T c2_hoistedGlobal;
  int16_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint16_T c2_b_hoistedGlobal;
  uint16_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  int16_T *c2_current_out;
  uint16_T *c2_voltage_out;
  c2_voltage_out = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_current_out = (int16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(3), FALSE);
  c2_hoistedGlobal = *c2_current_out;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 4, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_voltage_out;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 5, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = chartInstance->c2_is_active_c2_MiL_BMS_Bat;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_MiL_BMS_Bat(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  int16_T *c2_current_out;
  uint16_T *c2_voltage_out;
  c2_voltage_out = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_current_out = (int16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_current_out = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 0)), "current_out");
  *c2_voltage_out = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 1)), "voltage_out");
  chartInstance->c2_is_active_c2_MiL_BMS_Bat = c2_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
     "is_active_c2_MiL_BMS_Bat");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_MiL_BMS_Bat(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_MiL_BMS_Bat(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance)
{
}

static void sf_c2_MiL_BMS_Bat(SFc2_MiL_BMS_BatInstanceStruct *chartInstance)
{
  int32_T c2_i0;
  int32_T c2_i1;
  int16_T *c2_current_out;
  uint16_T *c2_voltage_out;
  uint16_T (*c2_voltages_in)[12];
  int32_T (*c2_currents_in)[12];
  c2_voltage_out = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_voltages_in = (uint16_T (*)[12])ssGetInputPortSignal(chartInstance->S, 1);
  c2_currents_in = (int32_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
  c2_current_out = (int16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_current_out, 0U);
  for (c2_i0 = 0; c2_i0 < 12; c2_i0++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_currents_in)[c2_i0], 1U);
  }

  for (c2_i1 = 0; c2_i1 < 12; c2_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_voltages_in)[c2_i1], 2U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c2_voltage_out, 3U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_MiL_BMS_Bat(chartInstance);
  sf_debug_check_for_state_inconsistency(_MiL_BMS_BatMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_MiL_BMS_Bat(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_currents_in[12];
  int32_T c2_i3;
  uint16_T c2_voltages_in[12];
  uint32_T c2_debug_family_var_map[8];
  uint16_T c2_voltage;
  int16_T c2_current;
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 2.0;
  int16_T c2_current_out;
  uint16_T c2_voltage_out;
  int32_T c2_i4;
  uint16_T c2_x[12];
  real_T c2_y;
  int32_T c2_k;
  int32_T c2_b_k;
  real_T c2_d0;
  real_T c2_d1;
  uint16_T c2_u0;
  int32_T c2_i5;
  int32_T c2_b_x[12];
  real_T c2_b_y;
  int32_T c2_c_k;
  int32_T c2_d_k;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_c_y;
  real_T c2_d2;
  real_T c2_d3;
  int16_T c2_i6;
  uint16_T *c2_b_voltage_out;
  int16_T *c2_b_current_out;
  uint16_T (*c2_b_voltages_in)[12];
  int32_T (*c2_b_currents_in)[12];
  c2_b_voltage_out = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_voltages_in = (uint16_T (*)[12])ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_currents_in = (int32_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
  c2_b_current_out = (int16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i2 = 0; c2_i2 < 12; c2_i2++) {
    c2_currents_in[c2_i2] = (*c2_b_currents_in)[c2_i2];
  }

  for (c2_i3 = 0; c2_i3 < 12; c2_i3++) {
    c2_voltages_in[c2_i3] = (*c2_b_voltages_in)[c2_i3];
  }

  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_voltage, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_current, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 2U, c2_e_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 3U, c2_e_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_currents_in, 4U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_voltages_in, 5U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_current_out, 6U,
    c2_b_sf_marshallOut, c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_voltage_out, 7U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  for (c2_i4 = 0; c2_i4 < 12; c2_i4++) {
    c2_x[c2_i4] = c2_voltages_in[c2_i4];
  }

  c2_y = (real_T)c2_x[0];
  for (c2_k = 2; c2_k < 13; c2_k++) {
    c2_b_k = c2_k;
    c2_y += (real_T)c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 12, 1, 0) - 1];
  }

  c2_d0 = c2_y;
  c2_d0 = c2_d0 < 0.0 ? muDoubleScalarCeil(c2_d0 - 0.5) : muDoubleScalarFloor
    (c2_d0 + 0.5);
  c2_d1 = c2_d0;
  if (c2_d1 < 65536.0) {
    if (c2_d1 >= 0.0) {
      c2_u0 = (uint16_T)c2_d1;
    } else {
      c2_u0 = 0U;
    }
  } else if (c2_d1 >= 65536.0) {
    c2_u0 = MAX_uint16_T;
  } else {
    c2_u0 = 0U;
  }

  c2_voltage = c2_u0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  for (c2_i5 = 0; c2_i5 < 12; c2_i5++) {
    c2_b_x[c2_i5] = c2_currents_in[c2_i5];
  }

  c2_b_y = (real_T)c2_b_x[0];
  for (c2_c_k = 2; c2_c_k < 13; c2_c_k++) {
    c2_d_k = c2_c_k;
    c2_b_y += (real_T)c2_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_d_k), 1, 12, 1, 0) - 1];
  }

  c2_c_x = c2_b_y;
  c2_d_x = c2_c_x;
  c2_c_y = c2_d_x / 12.0;
  c2_d2 = c2_c_y;
  c2_d2 = c2_d2 < 0.0 ? muDoubleScalarCeil(c2_d2 - 0.5) : muDoubleScalarFloor
    (c2_d2 + 0.5);
  c2_d3 = c2_d2;
  if (c2_d3 < 32768.0) {
    if (c2_d3 >= -32768.0) {
      c2_i6 = (int16_T)c2_d3;
    } else {
      c2_i6 = MIN_int16_T;
    }
  } else if (c2_d3 >= 32768.0) {
    c2_i6 = MAX_int16_T;
  } else {
    c2_i6 = 0;
  }

  c2_current = c2_i6;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_current_out = c2_current;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_voltage_out = c2_voltage;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -10);
  sf_debug_symbol_scope_pop();
  *c2_b_current_out = c2_current_out;
  *c2_b_voltage_out = c2_voltage_out;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_MiL_BMS_Bat(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  uint16_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc2_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint16_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 5, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static uint16_T c2_emlrt_marshallIn(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c2_voltage_out, const char_T *c2_identifier)
{
  uint16_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_voltage_out),
    &c2_thisId);
  sf_mex_destroy(&c2_voltage_out);
  return c2_y;
}

static uint16_T c2_b_emlrt_marshallIn(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint16_T c2_y;
  uint16_T c2_u1;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u1, 1, 5, 0U, 0, 0U, 0);
  c2_y = c2_u1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_voltage_out;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint16_T c2_y;
  SFc2_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc2_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c2_voltage_out = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_voltage_out),
    &c2_thisId);
  sf_mex_destroy(&c2_voltage_out);
  *(uint16_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int16_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc2_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int16_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 4, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int16_T c2_c_emlrt_marshallIn(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c2_current_out, const char_T *c2_identifier)
{
  int16_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_current_out),
    &c2_thisId);
  sf_mex_destroy(&c2_current_out);
  return c2_y;
}

static int16_T c2_d_emlrt_marshallIn(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int16_T c2_y;
  int16_T c2_i7;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i7, 1, 4, 0U, 0, 0U, 0);
  c2_y = c2_i7;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_current_out;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int16_T c2_y;
  SFc2_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc2_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c2_current_out = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_current_out),
    &c2_thisId);
  sf_mex_destroy(&c2_current_out);
  *(int16_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i8;
  uint16_T c2_b_inData[12];
  int32_T c2_i9;
  uint16_T c2_u[12];
  const mxArray *c2_y = NULL;
  SFc2_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc2_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i8 = 0; c2_i8 < 12; c2_i8++) {
    c2_b_inData[c2_i8] = (*(uint16_T (*)[12])c2_inData)[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 12; c2_i9++) {
    c2_u[c2_i9] = c2_b_inData[c2_i9];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 5, 0U, 1U, 0U, 1, 12), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i10;
  int32_T c2_b_inData[12];
  int32_T c2_i11;
  int32_T c2_u[12];
  const mxArray *c2_y = NULL;
  SFc2_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc2_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i10 = 0; c2_i10 < 12; c2_i10++) {
    c2_b_inData[c2_i10] = (*(int32_T (*)[12])c2_inData)[c2_i10];
  }

  for (c2_i11 = 0; c2_i11 < 12; c2_i11++) {
    c2_u[c2_i11] = c2_b_inData[c2_i11];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 6, 0U, 1U, 0U, 1, 12), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc2_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_e_emlrt_marshallIn(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d4;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d4, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d4;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc2_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_MiL_BMS_Bat_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[12];
  c2_ResolvedFunctionInfo (*c2_b_info)[12];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i12;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[12])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "sum";
  (*c2_b_info)[0].dominantType = "uint16";
  (*c2_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  (*c2_b_info)[0].fileTimeLo = 1286818700U;
  (*c2_b_info)[0].fileTimeHi = 0U;
  (*c2_b_info)[0].mFileTimeLo = 0U;
  (*c2_b_info)[0].mFileTimeHi = 0U;
  (*c2_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  (*c2_b_info)[1].name = "isequal";
  (*c2_b_info)[1].dominantType = "uint16";
  (*c2_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  (*c2_b_info)[1].fileTimeLo = 1286818758U;
  (*c2_b_info)[1].fileTimeHi = 0U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  (*c2_b_info)[2].name = "eml_isequal_core";
  (*c2_b_info)[2].dominantType = "uint16";
  (*c2_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  (*c2_b_info)[2].fileTimeLo = 1286818786U;
  (*c2_b_info)[2].fileTimeHi = 0U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  (*c2_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  (*c2_b_info)[3].name = "eml_const_nonsingleton_dim";
  (*c2_b_info)[3].dominantType = "uint16";
  (*c2_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  (*c2_b_info)[3].fileTimeLo = 1286818696U;
  (*c2_b_info)[3].fileTimeHi = 0U;
  (*c2_b_info)[3].mFileTimeLo = 0U;
  (*c2_b_info)[3].mFileTimeHi = 0U;
  (*c2_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  (*c2_b_info)[4].name = "eml_scalar_eg";
  (*c2_b_info)[4].dominantType = "double";
  (*c2_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c2_b_info)[4].fileTimeLo = 1286818796U;
  (*c2_b_info)[4].fileTimeHi = 0U;
  (*c2_b_info)[4].mFileTimeLo = 0U;
  (*c2_b_info)[4].mFileTimeHi = 0U;
  (*c2_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  (*c2_b_info)[5].name = "eml_index_class";
  (*c2_b_info)[5].dominantType = "";
  (*c2_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c2_b_info)[5].fileTimeLo = 1286818778U;
  (*c2_b_info)[5].fileTimeHi = 0U;
  (*c2_b_info)[5].mFileTimeLo = 0U;
  (*c2_b_info)[5].mFileTimeHi = 0U;
  (*c2_b_info)[6].context = "";
  (*c2_b_info)[6].name = "mean";
  (*c2_b_info)[6].dominantType = "int32";
  (*c2_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m";
  (*c2_b_info)[6].fileTimeLo = 1286818694U;
  (*c2_b_info)[6].fileTimeHi = 0U;
  (*c2_b_info)[6].mFileTimeLo = 0U;
  (*c2_b_info)[6].mFileTimeHi = 0U;
  (*c2_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  (*c2_b_info)[7].name = "eml_assert_valid_dim";
  (*c2_b_info)[7].dominantType = "double";
  (*c2_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  (*c2_b_info)[7].fileTimeLo = 1286818694U;
  (*c2_b_info)[7].fileTimeHi = 0U;
  (*c2_b_info)[7].mFileTimeLo = 0U;
  (*c2_b_info)[7].mFileTimeHi = 0U;
  (*c2_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  (*c2_b_info)[8].name = "eml_scalar_floor";
  (*c2_b_info)[8].dominantType = "double";
  (*c2_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  (*c2_b_info)[8].fileTimeLo = 1286818726U;
  (*c2_b_info)[8].fileTimeHi = 0U;
  (*c2_b_info)[8].mFileTimeLo = 0U;
  (*c2_b_info)[8].mFileTimeHi = 0U;
  (*c2_b_info)[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  (*c2_b_info)[9].name = "intmax";
  (*c2_b_info)[9].dominantType = "char";
  (*c2_b_info)[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  (*c2_b_info)[9].fileTimeLo = 1286818756U;
  (*c2_b_info)[9].fileTimeHi = 0U;
  (*c2_b_info)[9].mFileTimeLo = 0U;
  (*c2_b_info)[9].mFileTimeHi = 0U;
  (*c2_b_info)[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m";
  (*c2_b_info)[10].name = "rdivide";
  (*c2_b_info)[10].dominantType = "double";
  (*c2_b_info)[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[10].fileTimeLo = 1286818844U;
  (*c2_b_info)[10].fileTimeHi = 0U;
  (*c2_b_info)[10].mFileTimeLo = 0U;
  (*c2_b_info)[10].mFileTimeHi = 0U;
  (*c2_b_info)[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[11].name = "eml_div";
  (*c2_b_info)[11].dominantType = "double";
  (*c2_b_info)[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c2_b_info)[11].fileTimeLo = 1305318000U;
  (*c2_b_info)[11].fileTimeHi = 0U;
  (*c2_b_info)[11].mFileTimeLo = 0U;
  (*c2_b_info)[11].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 12), FALSE);
  for (c2_i12 = 0; c2_i12 < 12; c2_i12++) {
    c2_r0 = &c2_info[c2_i12];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i12);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc2_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_f_emlrt_marshallIn(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i13;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i13, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i13;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc2_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_MiL_BMS_Bat, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_MiL_BMS_Bat), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_MiL_BMS_Bat);
  return c2_y;
}

static uint8_T c2_h_emlrt_marshallIn(SFc2_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u2;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u2, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u2;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_MiL_BMS_BatInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_MiL_BMS_Bat_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4033586841U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2459813174U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1579657962U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(889286292U);
}

mxArray *sf_c2_MiL_BMS_Bat_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("iqZlCE3QVJsbsfIx198lnH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(6));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_MiL_BMS_Bat(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[4],T\"current_out\",},{M[1],M[7],T\"voltage_out\",},{M[8],M[0],T\"is_active_c2_MiL_BMS_Bat\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_MiL_BMS_Bat_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_MiL_BMS_BatInstanceStruct *chartInstance;
    chartInstance = (SFc2_MiL_BMS_BatInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_MiL_BMS_BatMachineNumber_,
           2,
           1,
           1,
           4,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_MiL_BMS_BatMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_MiL_BMS_BatMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_MiL_BMS_BatMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"current_out");
          _SFD_SET_DATA_PROPS(1,1,1,0,"currents_in");
          _SFD_SET_DATA_PROPS(2,1,1,0,"voltages_in");
          _SFD_SET_DATA_PROPS(3,2,0,1,"voltage_out");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,318);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT16,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          int16_T *c2_current_out;
          uint16_T *c2_voltage_out;
          int32_T (*c2_currents_in)[12];
          uint16_T (*c2_voltages_in)[12];
          c2_voltage_out = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_voltages_in = (uint16_T (*)[12])ssGetInputPortSignal
            (chartInstance->S, 1);
          c2_currents_in = (int32_T (*)[12])ssGetInputPortSignal
            (chartInstance->S, 0);
          c2_current_out = (int16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_current_out);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_currents_in);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_voltages_in);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_voltage_out);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_MiL_BMS_BatMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_MiL_BMS_Bat(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_MiL_BMS_BatInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c2_MiL_BMS_Bat((SFc2_MiL_BMS_BatInstanceStruct*)
    chartInstanceVar);
  initialize_c2_MiL_BMS_Bat((SFc2_MiL_BMS_BatInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_MiL_BMS_Bat(void *chartInstanceVar)
{
  enable_c2_MiL_BMS_Bat((SFc2_MiL_BMS_BatInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_MiL_BMS_Bat(void *chartInstanceVar)
{
  disable_c2_MiL_BMS_Bat((SFc2_MiL_BMS_BatInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_MiL_BMS_Bat(void *chartInstanceVar)
{
  sf_c2_MiL_BMS_Bat((SFc2_MiL_BMS_BatInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_MiL_BMS_Bat(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_MiL_BMS_Bat
    ((SFc2_MiL_BMS_BatInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_MiL_BMS_Bat();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_MiL_BMS_Bat(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_MiL_BMS_Bat();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_MiL_BMS_Bat((SFc2_MiL_BMS_BatInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_MiL_BMS_Bat(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_MiL_BMS_Bat(S);
}

static void sf_opaque_set_sim_state_c2_MiL_BMS_Bat(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_MiL_BMS_Bat(S, st);
}

static void sf_opaque_terminate_c2_MiL_BMS_Bat(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_MiL_BMS_BatInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_MiL_BMS_Bat((SFc2_MiL_BMS_BatInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_MiL_BMS_Bat_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_MiL_BMS_Bat((SFc2_MiL_BMS_BatInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_MiL_BMS_Bat(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_MiL_BMS_Bat((SFc2_MiL_BMS_BatInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_MiL_BMS_Bat(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_MiL_BMS_Bat_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,2,2);
      sf_mark_chart_reusable_outputs(S,infoStruct,2,2);
    }

    sf_set_rtw_dwork_info(S,infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3531183102U));
  ssSetChecksum1(S,(3433407584U));
  ssSetChecksum2(S,(2474485120U));
  ssSetChecksum3(S,(281111244U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_MiL_BMS_Bat(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_MiL_BMS_Bat(SimStruct *S)
{
  SFc2_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc2_MiL_BMS_BatInstanceStruct *)malloc(sizeof
    (SFc2_MiL_BMS_BatInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_MiL_BMS_BatInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_MiL_BMS_Bat;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_MiL_BMS_Bat;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_MiL_BMS_Bat;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_MiL_BMS_Bat;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_MiL_BMS_Bat;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_MiL_BMS_Bat;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_MiL_BMS_Bat;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_MiL_BMS_Bat;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_MiL_BMS_Bat;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_MiL_BMS_Bat;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_MiL_BMS_Bat;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_MiL_BMS_Bat_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_MiL_BMS_Bat(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_MiL_BMS_Bat(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_MiL_BMS_Bat(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_MiL_BMS_Bat_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
