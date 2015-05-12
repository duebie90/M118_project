/* Include files */

#include "blascompat32.h"
#include "MiL_BMS_Bat_sfun.h"
#include "c12_MiL_BMS_Bat.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "MiL_BMS_Bat_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c12_debug_family_names[23] = { "nargin", "nargout", "fcn",
  "cell_voltage_in", "cell_temperatures_in", "current_in", "voltage_in",
  "CellNo", "I_min_line", "I_max_line", "V_min_cell", "V_max_cell", "T_min_cell",
  "T_max_cell", "V_min_bat", "V_max_bat", "error_out", "error_code_out",
  "error_index_out", "error", "error_code", "error_index", "timer" };

/* Function Declarations */
static void initialize_c12_MiL_BMS_Bat(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance);
static void initialize_params_c12_MiL_BMS_Bat(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance);
static void enable_c12_MiL_BMS_Bat(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance);
static void disable_c12_MiL_BMS_Bat(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance);
static void c12_update_debugger_state_c12_MiL_BMS_Bat
  (SFc12_MiL_BMS_BatInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c12_MiL_BMS_Bat
  (SFc12_MiL_BMS_BatInstanceStruct *chartInstance);
static void set_sim_state_c12_MiL_BMS_Bat(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_st);
static void finalize_c12_MiL_BMS_Bat(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance);
static void sf_c12_MiL_BMS_Bat(SFc12_MiL_BMS_BatInstanceStruct *chartInstance);
static void initSimStructsc12_MiL_BMS_Bat(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber);
static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static uint8_T c12_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_b_timer, const char_T *c12_identifier);
static uint8_T c12_b_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static uint8_T c12_c_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_b_error_index, const char_T *c12_identifier);
static uint8_T c12_d_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static uint8_T c12_e_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_b_error_code, const char_T *c12_identifier);
static uint8_T c12_f_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static uint8_T c12_g_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_b_error, const char_T *c12_identifier);
static uint8_T c12_h_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_e_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int32_T c12_i_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_error_index_out, const char_T
  *c12_identifier);
static int32_T c12_j_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_f_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_k_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_error_code_out, const char_T
  *c12_identifier, uint16_T c12_y[12]);
static void c12_l_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId,
  uint16_T c12_y[12]);
static void c12_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_g_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static const mxArray *c12_h_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_m_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static uint8_T c12_n_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_MiL_BMS_Bat, const char_T
  *c12_identifier);
static uint8_T c12_o_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void init_dsm_address_info(SFc12_MiL_BMS_BatInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c12_MiL_BMS_Bat(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance)
{
  chartInstance->c12_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c12_error_not_empty = FALSE;
  chartInstance->c12_error_code_not_empty = FALSE;
  chartInstance->c12_error_index_not_empty = FALSE;
  chartInstance->c12_timer_not_empty = FALSE;
  chartInstance->c12_is_active_c12_MiL_BMS_Bat = 0U;
}

static void initialize_params_c12_MiL_BMS_Bat(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance)
{
}

static void enable_c12_MiL_BMS_Bat(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c12_MiL_BMS_Bat(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c12_update_debugger_state_c12_MiL_BMS_Bat
  (SFc12_MiL_BMS_BatInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c12_MiL_BMS_Bat
  (SFc12_MiL_BMS_BatInstanceStruct *chartInstance)
{
  const mxArray *c12_st;
  const mxArray *c12_y = NULL;
  int32_T c12_i0;
  uint16_T c12_u[12];
  const mxArray *c12_b_y = NULL;
  int32_T c12_hoistedGlobal;
  int32_T c12_b_u;
  const mxArray *c12_c_y = NULL;
  int32_T c12_i1;
  uint16_T c12_c_u[12];
  const mxArray *c12_d_y = NULL;
  uint8_T c12_b_hoistedGlobal;
  uint8_T c12_d_u;
  const mxArray *c12_e_y = NULL;
  uint8_T c12_c_hoistedGlobal;
  uint8_T c12_e_u;
  const mxArray *c12_f_y = NULL;
  uint8_T c12_d_hoistedGlobal;
  uint8_T c12_f_u;
  const mxArray *c12_g_y = NULL;
  uint8_T c12_e_hoistedGlobal;
  uint8_T c12_g_u;
  const mxArray *c12_h_y = NULL;
  uint8_T c12_f_hoistedGlobal;
  uint8_T c12_h_u;
  const mxArray *c12_i_y = NULL;
  int32_T *c12_error_index_out;
  uint16_T (*c12_error_out)[12];
  uint16_T (*c12_error_code_out)[12];
  c12_error_index_out = (int32_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c12_error_code_out = (uint16_T (*)[12])ssGetOutputPortSignal(chartInstance->S,
    2);
  c12_error_out = (uint16_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
  c12_st = NULL;
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellarray(8), FALSE);
  for (c12_i0 = 0; c12_i0 < 12; c12_i0++) {
    c12_u[c12_i0] = (*c12_error_code_out)[c12_i0];
  }

  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_u, 5, 0U, 1U, 0U, 1, 12), FALSE);
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_hoistedGlobal = *c12_error_index_out;
  c12_b_u = c12_hoistedGlobal;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_b_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c12_y, 1, c12_c_y);
  for (c12_i1 = 0; c12_i1 < 12; c12_i1++) {
    c12_c_u[c12_i1] = (*c12_error_out)[c12_i1];
  }

  c12_d_y = NULL;
  sf_mex_assign(&c12_d_y, sf_mex_create("y", c12_c_u, 5, 0U, 1U, 0U, 1, 12),
                FALSE);
  sf_mex_setcell(c12_y, 2, c12_d_y);
  c12_b_hoistedGlobal = chartInstance->c12_error;
  c12_d_u = c12_b_hoistedGlobal;
  c12_e_y = NULL;
  if (!chartInstance->c12_error_not_empty) {
    sf_mex_assign(&c12_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c12_e_y, sf_mex_create("y", &c12_d_u, 3, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c12_y, 3, c12_e_y);
  c12_c_hoistedGlobal = chartInstance->c12_error_code;
  c12_e_u = c12_c_hoistedGlobal;
  c12_f_y = NULL;
  if (!chartInstance->c12_error_code_not_empty) {
    sf_mex_assign(&c12_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c12_f_y, sf_mex_create("y", &c12_e_u, 3, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c12_y, 4, c12_f_y);
  c12_d_hoistedGlobal = chartInstance->c12_error_index;
  c12_f_u = c12_d_hoistedGlobal;
  c12_g_y = NULL;
  if (!chartInstance->c12_error_index_not_empty) {
    sf_mex_assign(&c12_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c12_g_y, sf_mex_create("y", &c12_f_u, 3, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c12_y, 5, c12_g_y);
  c12_e_hoistedGlobal = chartInstance->c12_timer;
  c12_g_u = c12_e_hoistedGlobal;
  c12_h_y = NULL;
  if (!chartInstance->c12_timer_not_empty) {
    sf_mex_assign(&c12_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c12_h_y, sf_mex_create("y", &c12_g_u, 3, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c12_y, 6, c12_h_y);
  c12_f_hoistedGlobal = chartInstance->c12_is_active_c12_MiL_BMS_Bat;
  c12_h_u = c12_f_hoistedGlobal;
  c12_i_y = NULL;
  sf_mex_assign(&c12_i_y, sf_mex_create("y", &c12_h_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c12_y, 7, c12_i_y);
  sf_mex_assign(&c12_st, c12_y, FALSE);
  return c12_st;
}

static void set_sim_state_c12_MiL_BMS_Bat(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_st)
{
  const mxArray *c12_u;
  uint16_T c12_uv0[12];
  int32_T c12_i2;
  uint16_T c12_uv1[12];
  int32_T c12_i3;
  int32_T *c12_error_index_out;
  uint16_T (*c12_error_code_out)[12];
  uint16_T (*c12_error_out)[12];
  c12_error_index_out = (int32_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c12_error_code_out = (uint16_T (*)[12])ssGetOutputPortSignal(chartInstance->S,
    2);
  c12_error_out = (uint16_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c12_doneDoubleBufferReInit = TRUE;
  c12_u = sf_mex_dup(c12_st);
  c12_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 0)),
    "error_code_out", c12_uv0);
  for (c12_i2 = 0; c12_i2 < 12; c12_i2++) {
    (*c12_error_code_out)[c12_i2] = c12_uv0[c12_i2];
  }

  *c12_error_index_out = c12_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 1)), "error_index_out");
  c12_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 2)),
    "error_out", c12_uv1);
  for (c12_i3 = 0; c12_i3 < 12; c12_i3++) {
    (*c12_error_out)[c12_i3] = c12_uv1[c12_i3];
  }

  chartInstance->c12_error = c12_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 3)), "error");
  chartInstance->c12_error_code = c12_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 4)), "error_code");
  chartInstance->c12_error_index = c12_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 5)), "error_index");
  chartInstance->c12_timer = c12_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 6)), "timer");
  chartInstance->c12_is_active_c12_MiL_BMS_Bat = c12_n_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 7)),
     "is_active_c12_MiL_BMS_Bat");
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_MiL_BMS_Bat(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_MiL_BMS_Bat(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance)
{
}

static void sf_c12_MiL_BMS_Bat(SFc12_MiL_BMS_BatInstanceStruct *chartInstance)
{
  int32_T c12_i4;
  int32_T c12_i5;
  int32_T c12_i6;
  int32_T c12_i7;
  real_T c12_hoistedGlobal;
  int32_T c12_b_hoistedGlobal;
  uint16_T c12_c_hoistedGlobal;
  real_T c12_d_hoistedGlobal;
  real_T c12_e_hoistedGlobal;
  real_T c12_f_hoistedGlobal;
  real_T c12_g_hoistedGlobal;
  real_T c12_h_hoistedGlobal;
  real_T c12_i_hoistedGlobal;
  real_T c12_j_hoistedGlobal;
  real_T c12_k_hoistedGlobal;
  real_T c12_l_hoistedGlobal;
  real_T c12_fcn;
  int32_T c12_i8;
  uint16_T c12_cell_voltage_in[12];
  int32_T c12_i9;
  uint16_T c12_cell_temperatures_in[12];
  int32_T c12_current_in;
  uint16_T c12_voltage_in;
  real_T c12_CellNo;
  real_T c12_I_min_line;
  real_T c12_I_max_line;
  real_T c12_V_min_cell;
  real_T c12_V_max_cell;
  real_T c12_T_min_cell;
  real_T c12_T_max_cell;
  real_T c12_V_min_bat;
  real_T c12_V_max_bat;
  uint32_T c12_debug_family_var_map[23];
  real_T c12_nargin = 14.0;
  real_T c12_nargout = 3.0;
  uint16_T c12_error_out[12];
  uint16_T c12_error_code_out[12];
  int32_T c12_error_index_out;
  int32_T c12_i10;
  int32_T c12_i11;
  int32_T c12_i12;
  int32_T c12_i13;
  int32_T *c12_b_error_index_out;
  real_T *c12_b_fcn;
  int32_T *c12_b_current_in;
  uint16_T *c12_b_voltage_in;
  real_T *c12_b_CellNo;
  real_T *c12_b_I_min_line;
  real_T *c12_b_I_max_line;
  real_T *c12_b_V_min_cell;
  real_T *c12_b_V_max_cell;
  real_T *c12_b_T_min_cell;
  real_T *c12_b_T_max_cell;
  real_T *c12_b_V_min_bat;
  real_T *c12_b_V_max_bat;
  uint16_T (*c12_b_error_out)[12];
  uint16_T (*c12_b_error_code_out)[12];
  uint16_T (*c12_b_cell_temperatures_in)[12];
  uint16_T (*c12_b_cell_voltage_in)[12];
  c12_b_V_max_bat = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c12_b_V_min_bat = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c12_b_T_max_cell = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c12_b_T_min_cell = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c12_b_V_max_cell = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c12_b_V_min_cell = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c12_b_I_max_line = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c12_b_I_min_line = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c12_b_CellNo = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c12_b_voltage_in = (uint16_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c12_b_current_in = (int32_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c12_b_cell_temperatures_in = (uint16_T (*)[12])ssGetInputPortSignal
    (chartInstance->S, 2);
  c12_b_cell_voltage_in = (uint16_T (*)[12])ssGetInputPortSignal
    (chartInstance->S, 1);
  c12_b_fcn = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c12_b_error_index_out = (int32_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c12_b_error_code_out = (uint16_T (*)[12])ssGetOutputPortSignal
    (chartInstance->S, 2);
  c12_b_error_out = (uint16_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c12_sfEvent);
  for (c12_i4 = 0; c12_i4 < 12; c12_i4++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c12_b_error_out)[c12_i4], 0U);
  }

  for (c12_i5 = 0; c12_i5 < 12; c12_i5++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c12_b_error_code_out)[c12_i5], 1U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c12_b_error_index_out, 2U);
  _SFD_DATA_RANGE_CHECK(*c12_b_fcn, 3U);
  for (c12_i6 = 0; c12_i6 < 12; c12_i6++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c12_b_cell_voltage_in)[c12_i6], 4U);
  }

  for (c12_i7 = 0; c12_i7 < 12; c12_i7++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c12_b_cell_temperatures_in)[c12_i7], 5U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c12_b_current_in, 6U);
  _SFD_DATA_RANGE_CHECK((real_T)*c12_b_voltage_in, 7U);
  _SFD_DATA_RANGE_CHECK(*c12_b_CellNo, 8U);
  _SFD_DATA_RANGE_CHECK(*c12_b_I_min_line, 9U);
  _SFD_DATA_RANGE_CHECK(*c12_b_I_max_line, 10U);
  _SFD_DATA_RANGE_CHECK(*c12_b_V_min_cell, 11U);
  _SFD_DATA_RANGE_CHECK(*c12_b_V_max_cell, 12U);
  _SFD_DATA_RANGE_CHECK(*c12_b_T_min_cell, 13U);
  _SFD_DATA_RANGE_CHECK(*c12_b_T_max_cell, 14U);
  _SFD_DATA_RANGE_CHECK(*c12_b_V_min_bat, 15U);
  _SFD_DATA_RANGE_CHECK(*c12_b_V_max_bat, 16U);
  chartInstance->c12_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c12_sfEvent);
  c12_hoistedGlobal = *c12_b_fcn;
  c12_b_hoistedGlobal = *c12_b_current_in;
  c12_c_hoistedGlobal = *c12_b_voltage_in;
  c12_d_hoistedGlobal = *c12_b_CellNo;
  c12_e_hoistedGlobal = *c12_b_I_min_line;
  c12_f_hoistedGlobal = *c12_b_I_max_line;
  c12_g_hoistedGlobal = *c12_b_V_min_cell;
  c12_h_hoistedGlobal = *c12_b_V_max_cell;
  c12_i_hoistedGlobal = *c12_b_T_min_cell;
  c12_j_hoistedGlobal = *c12_b_T_max_cell;
  c12_k_hoistedGlobal = *c12_b_V_min_bat;
  c12_l_hoistedGlobal = *c12_b_V_max_bat;
  c12_fcn = c12_hoistedGlobal;
  for (c12_i8 = 0; c12_i8 < 12; c12_i8++) {
    c12_cell_voltage_in[c12_i8] = (*c12_b_cell_voltage_in)[c12_i8];
  }

  for (c12_i9 = 0; c12_i9 < 12; c12_i9++) {
    c12_cell_temperatures_in[c12_i9] = (*c12_b_cell_temperatures_in)[c12_i9];
  }

  c12_current_in = c12_b_hoistedGlobal;
  c12_voltage_in = c12_c_hoistedGlobal;
  c12_CellNo = c12_d_hoistedGlobal;
  c12_I_min_line = c12_e_hoistedGlobal;
  c12_I_max_line = c12_f_hoistedGlobal;
  c12_V_min_cell = c12_g_hoistedGlobal;
  c12_V_max_cell = c12_h_hoistedGlobal;
  c12_T_min_cell = c12_i_hoistedGlobal;
  c12_T_max_cell = c12_j_hoistedGlobal;
  c12_V_min_bat = c12_k_hoistedGlobal;
  c12_V_max_bat = c12_l_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 23U, 23U, c12_debug_family_names,
    c12_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c12_nargin, 0U, c12_g_sf_marshallOut,
    c12_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_nargout, 1U,
    c12_g_sf_marshallOut, c12_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c12_fcn, 2U, c12_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c12_cell_voltage_in, 3U, c12_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c12_cell_temperatures_in, 4U,
    c12_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c12_current_in, 5U, c12_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c12_voltage_in, 6U, c12_h_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c12_CellNo, 7U, c12_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c12_I_min_line, 8U, c12_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c12_I_max_line, 9U, c12_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c12_V_min_cell, 10U, c12_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c12_V_max_cell, 11U, c12_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c12_T_min_cell, 12U, c12_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c12_T_max_cell, 13U, c12_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c12_V_min_bat, 14U, c12_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c12_V_max_bat, 15U, c12_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c12_error_out, 16U,
    c12_f_sf_marshallOut, c12_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c12_error_code_out, 17U,
    c12_f_sf_marshallOut, c12_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_error_index_out, 18U,
    c12_e_sf_marshallOut, c12_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c12_error, 19U,
    c12_d_sf_marshallOut, c12_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c12_error_code, 20U,
    c12_c_sf_marshallOut, c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c12_error_index, 21U,
    c12_b_sf_marshallOut, c12_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c12_timer, 22U,
    c12_sf_marshallOut, c12_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 5);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c12_error_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 6);
    chartInstance->c12_error = 0U;
    chartInstance->c12_error_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 10);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c12_error_code_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 11);
    chartInstance->c12_error_code = 0U;
    chartInstance->c12_error_code_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 15);
  if (CV_EML_IF(0, 1, 2, !chartInstance->c12_error_index_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 16);
    chartInstance->c12_error_index = 0U;
    chartInstance->c12_error_index_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 20);
  if (CV_EML_IF(0, 1, 3, !chartInstance->c12_timer_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 21);
    chartInstance->c12_timer = 1U;
    chartInstance->c12_timer_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 29);
  for (c12_i10 = 0; c12_i10 < 12; c12_i10++) {
    c12_error_out[c12_i10] = c12_cell_voltage_in[c12_i10];
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 30);
  for (c12_i11 = 0; c12_i11 < 12; c12_i11++) {
    c12_error_code_out[c12_i11] = c12_cell_temperatures_in[c12_i11];
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 31);
  c12_error_index_out = c12_current_in;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, -31);
  sf_debug_symbol_scope_pop();
  for (c12_i12 = 0; c12_i12 < 12; c12_i12++) {
    (*c12_b_error_out)[c12_i12] = c12_error_out[c12_i12];
  }

  for (c12_i13 = 0; c12_i13 < 12; c12_i13++) {
    (*c12_b_error_code_out)[c12_i13] = c12_error_code_out[c12_i13];
  }

  *c12_b_error_index_out = c12_error_index_out;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c12_sfEvent);
  sf_debug_check_for_state_inconsistency(_MiL_BMS_BatMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc12_MiL_BMS_Bat(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber)
{
}

static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  uint8_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc12_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(uint8_T *)c12_inData;
  c12_y = NULL;
  if (!chartInstance->c12_timer_not_empty) {
    sf_mex_assign(&c12_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 3, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static uint8_T c12_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_b_timer, const char_T *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_timer),
    &c12_thisId);
  sf_mex_destroy(&c12_b_timer);
  return c12_y;
}

static uint8_T c12_b_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u0;
  if (mxIsEmpty(c12_u)) {
    chartInstance->c12_timer_not_empty = FALSE;
  } else {
    chartInstance->c12_timer_not_empty = TRUE;
    sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u0, 1, 3, 0U, 0, 0U, 0);
    c12_y = c12_u0;
  }

  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_timer;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  uint8_T c12_y;
  SFc12_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc12_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c12_b_timer = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_timer),
    &c12_thisId);
  sf_mex_destroy(&c12_b_timer);
  *(uint8_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  uint8_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc12_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(uint8_T *)c12_inData;
  c12_y = NULL;
  if (!chartInstance->c12_error_index_not_empty) {
    sf_mex_assign(&c12_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 3, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static uint8_T c12_c_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_b_error_index, const char_T *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_error_index),
    &c12_thisId);
  sf_mex_destroy(&c12_b_error_index);
  return c12_y;
}

static uint8_T c12_d_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u1;
  if (mxIsEmpty(c12_u)) {
    chartInstance->c12_error_index_not_empty = FALSE;
  } else {
    chartInstance->c12_error_index_not_empty = TRUE;
    sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u1, 1, 3, 0U, 0, 0U, 0);
    c12_y = c12_u1;
  }

  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_error_index;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  uint8_T c12_y;
  SFc12_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc12_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c12_b_error_index = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_error_index),
    &c12_thisId);
  sf_mex_destroy(&c12_b_error_index);
  *(uint8_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  uint8_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc12_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(uint8_T *)c12_inData;
  c12_y = NULL;
  if (!chartInstance->c12_error_code_not_empty) {
    sf_mex_assign(&c12_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 3, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static uint8_T c12_e_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_b_error_code, const char_T *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_error_code),
    &c12_thisId);
  sf_mex_destroy(&c12_b_error_code);
  return c12_y;
}

static uint8_T c12_f_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u2;
  if (mxIsEmpty(c12_u)) {
    chartInstance->c12_error_code_not_empty = FALSE;
  } else {
    chartInstance->c12_error_code_not_empty = TRUE;
    sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u2, 1, 3, 0U, 0, 0U, 0);
    c12_y = c12_u2;
  }

  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_error_code;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  uint8_T c12_y;
  SFc12_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc12_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c12_b_error_code = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_error_code),
    &c12_thisId);
  sf_mex_destroy(&c12_b_error_code);
  *(uint8_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  uint8_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc12_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(uint8_T *)c12_inData;
  c12_y = NULL;
  if (!chartInstance->c12_error_not_empty) {
    sf_mex_assign(&c12_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 3, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static uint8_T c12_g_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_b_error, const char_T *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_error),
    &c12_thisId);
  sf_mex_destroy(&c12_b_error);
  return c12_y;
}

static uint8_T c12_h_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u3;
  if (mxIsEmpty(c12_u)) {
    chartInstance->c12_error_not_empty = FALSE;
  } else {
    chartInstance->c12_error_not_empty = TRUE;
    sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u3, 1, 3, 0U, 0, 0U, 0);
    c12_y = c12_u3;
  }

  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_error;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  uint8_T c12_y;
  SFc12_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc12_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c12_b_error = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_error),
    &c12_thisId);
  sf_mex_destroy(&c12_b_error);
  *(uint8_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_e_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc12_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static int32_T c12_i_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_error_index_out, const char_T
  *c12_identifier)
{
  int32_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_error_index_out),
    &c12_thisId);
  sf_mex_destroy(&c12_error_index_out);
  return c12_y;
}

static int32_T c12_j_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int32_T c12_y;
  int32_T c12_i14;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i14, 1, 6, 0U, 0, 0U, 0);
  c12_y = c12_i14;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_error_index_out;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_y;
  SFc12_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc12_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c12_error_index_out = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_error_index_out),
    &c12_thisId);
  sf_mex_destroy(&c12_error_index_out);
  *(int32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_f_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i15;
  uint16_T c12_b_inData[12];
  int32_T c12_i16;
  uint16_T c12_u[12];
  const mxArray *c12_y = NULL;
  SFc12_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc12_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  for (c12_i15 = 0; c12_i15 < 12; c12_i15++) {
    c12_b_inData[c12_i15] = (*(uint16_T (*)[12])c12_inData)[c12_i15];
  }

  for (c12_i16 = 0; c12_i16 < 12; c12_i16++) {
    c12_u[c12_i16] = c12_b_inData[c12_i16];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 5, 0U, 1U, 0U, 1, 12), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static void c12_k_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_error_code_out, const char_T
  *c12_identifier, uint16_T c12_y[12])
{
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_error_code_out),
    &c12_thisId, c12_y);
  sf_mex_destroy(&c12_error_code_out);
}

static void c12_l_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId,
  uint16_T c12_y[12])
{
  uint16_T c12_uv2[12];
  int32_T c12_i17;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_uv2, 1, 5, 0U, 1, 0U, 1, 12);
  for (c12_i17 = 0; c12_i17 < 12; c12_i17++) {
    c12_y[c12_i17] = c12_uv2[c12_i17];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_error_code_out;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  uint16_T c12_y[12];
  int32_T c12_i18;
  SFc12_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc12_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c12_error_code_out = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_error_code_out),
    &c12_thisId, c12_y);
  sf_mex_destroy(&c12_error_code_out);
  for (c12_i18 = 0; c12_i18 < 12; c12_i18++) {
    (*(uint16_T (*)[12])c12_outData)[c12_i18] = c12_y[c12_i18];
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_g_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc12_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static const mxArray *c12_h_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  uint16_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc12_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(uint16_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 5, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static real_T c12_m_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d0;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d0, 1, 0, 0U, 0, 0U, 0);
  c12_y = c12_d0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_nargout;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y;
  SFc12_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc12_MiL_BMS_BatInstanceStruct *)chartInstanceVoid;
  c12_nargout = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_nargout),
    &c12_thisId);
  sf_mex_destroy(&c12_nargout);
  *(real_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

const mxArray *sf_c12_MiL_BMS_Bat_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo = NULL;
  c12_nameCaptureInfo = NULL;
  sf_mex_assign(&c12_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c12_nameCaptureInfo;
}

static uint8_T c12_n_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_MiL_BMS_Bat, const char_T
  *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_is_active_c12_MiL_BMS_Bat), &c12_thisId);
  sf_mex_destroy(&c12_b_is_active_c12_MiL_BMS_Bat);
  return c12_y;
}

static uint8_T c12_o_emlrt_marshallIn(SFc12_MiL_BMS_BatInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u4;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u4, 1, 3, 0U, 0, 0U, 0);
  c12_y = c12_u4;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void init_dsm_address_info(SFc12_MiL_BMS_BatInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c12_MiL_BMS_Bat_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1704641329U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2943571160U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4208189441U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3206317752U);
}

mxArray *sf_c12_MiL_BMS_Bat_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("daJ2yPOQ0Lm8ig14kcsdcD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,14,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c12_MiL_BMS_Bat(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[9],T\"error_code_out\",},{M[1],M[20],T\"error_index_out\",},{M[1],M[8],T\"error_out\",},{M[4],M[0],T\"error\",S'l','i','p'{{M1x2[271 276],M[0],}}},{M[4],M[0],T\"error_code\",S'l','i','p'{{M1x2[334 344],M[0],}}},{M[4],M[0],T\"error_index\",S'l','i','p'{{M1x2[412 423],M[0],}}},{M[4],M[0],T\"timer\",S'l','i','p'{{M1x2[493 498],M[0],}}},{M[8],M[0],T\"is_active_c12_MiL_BMS_Bat\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_MiL_BMS_Bat_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_MiL_BMS_BatInstanceStruct *chartInstance;
    chartInstance = (SFc12_MiL_BMS_BatInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_MiL_BMS_BatMachineNumber_,
           12,
           1,
           1,
           17,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"error_out");
          _SFD_SET_DATA_PROPS(1,2,0,1,"error_code_out");
          _SFD_SET_DATA_PROPS(2,2,0,1,"error_index_out");
          _SFD_SET_DATA_PROPS(3,1,1,0,"fcn");
          _SFD_SET_DATA_PROPS(4,1,1,0,"cell_voltage_in");
          _SFD_SET_DATA_PROPS(5,1,1,0,"cell_temperatures_in");
          _SFD_SET_DATA_PROPS(6,1,1,0,"current_in");
          _SFD_SET_DATA_PROPS(7,1,1,0,"voltage_in");
          _SFD_SET_DATA_PROPS(8,1,1,0,"CellNo");
          _SFD_SET_DATA_PROPS(9,1,1,0,"I_min_line");
          _SFD_SET_DATA_PROPS(10,1,1,0,"I_max_line");
          _SFD_SET_DATA_PROPS(11,1,1,0,"V_min_cell");
          _SFD_SET_DATA_PROPS(12,1,1,0,"V_max_cell");
          _SFD_SET_DATA_PROPS(13,1,1,0,"T_min_cell");
          _SFD_SET_DATA_PROPS(14,1,1,0,"T_max_cell");
          _SFD_SET_DATA_PROPS(15,1,1,0,"V_min_bat");
          _SFD_SET_DATA_PROPS(16,1,1,0,"V_max_bat");
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
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,734);
        _SFD_CV_INIT_EML_IF(0,1,0,278,295,-1,321);
        _SFD_CV_INIT_EML_IF(0,1,1,346,368,-1,399);
        _SFD_CV_INIT_EML_IF(0,1,2,425,448,-1,480);
        _SFD_CV_INIT_EML_IF(0,1,3,500,517,-1,543);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT16,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_f_sf_marshallOut,(MexInFcnForType)
            c12_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT16,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_f_sf_marshallOut,(MexInFcnForType)
            c12_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_g_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT16,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT16,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_h_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_g_sf_marshallOut,(MexInFcnForType)NULL);

        {
          int32_T *c12_error_index_out;
          real_T *c12_fcn;
          int32_T *c12_current_in;
          uint16_T *c12_voltage_in;
          real_T *c12_CellNo;
          real_T *c12_I_min_line;
          real_T *c12_I_max_line;
          real_T *c12_V_min_cell;
          real_T *c12_V_max_cell;
          real_T *c12_T_min_cell;
          real_T *c12_T_max_cell;
          real_T *c12_V_min_bat;
          real_T *c12_V_max_bat;
          uint16_T (*c12_error_out)[12];
          uint16_T (*c12_error_code_out)[12];
          uint16_T (*c12_cell_voltage_in)[12];
          uint16_T (*c12_cell_temperatures_in)[12];
          c12_V_max_bat = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
          c12_V_min_bat = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c12_T_max_cell = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c12_T_min_cell = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c12_V_max_cell = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c12_V_min_cell = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c12_I_max_line = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c12_I_min_line = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c12_CellNo = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c12_voltage_in = (uint16_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c12_current_in = (int32_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c12_cell_temperatures_in = (uint16_T (*)[12])ssGetInputPortSignal
            (chartInstance->S, 2);
          c12_cell_voltage_in = (uint16_T (*)[12])ssGetInputPortSignal
            (chartInstance->S, 1);
          c12_fcn = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c12_error_index_out = (int32_T *)ssGetOutputPortSignal
            (chartInstance->S, 3);
          c12_error_code_out = (uint16_T (*)[12])ssGetOutputPortSignal
            (chartInstance->S, 2);
          c12_error_out = (uint16_T (*)[12])ssGetOutputPortSignal
            (chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c12_error_out);
          _SFD_SET_DATA_VALUE_PTR(1U, *c12_error_code_out);
          _SFD_SET_DATA_VALUE_PTR(2U, c12_error_index_out);
          _SFD_SET_DATA_VALUE_PTR(3U, c12_fcn);
          _SFD_SET_DATA_VALUE_PTR(4U, *c12_cell_voltage_in);
          _SFD_SET_DATA_VALUE_PTR(5U, *c12_cell_temperatures_in);
          _SFD_SET_DATA_VALUE_PTR(6U, c12_current_in);
          _SFD_SET_DATA_VALUE_PTR(7U, c12_voltage_in);
          _SFD_SET_DATA_VALUE_PTR(8U, c12_CellNo);
          _SFD_SET_DATA_VALUE_PTR(9U, c12_I_min_line);
          _SFD_SET_DATA_VALUE_PTR(10U, c12_I_max_line);
          _SFD_SET_DATA_VALUE_PTR(11U, c12_V_min_cell);
          _SFD_SET_DATA_VALUE_PTR(12U, c12_V_max_cell);
          _SFD_SET_DATA_VALUE_PTR(13U, c12_T_min_cell);
          _SFD_SET_DATA_VALUE_PTR(14U, c12_T_max_cell);
          _SFD_SET_DATA_VALUE_PTR(15U, c12_V_min_bat);
          _SFD_SET_DATA_VALUE_PTR(16U, c12_V_max_bat);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_MiL_BMS_BatMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c12_MiL_BMS_Bat(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc12_MiL_BMS_BatInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c12_MiL_BMS_Bat((SFc12_MiL_BMS_BatInstanceStruct*)
    chartInstanceVar);
  initialize_c12_MiL_BMS_Bat((SFc12_MiL_BMS_BatInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c12_MiL_BMS_Bat(void *chartInstanceVar)
{
  enable_c12_MiL_BMS_Bat((SFc12_MiL_BMS_BatInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c12_MiL_BMS_Bat(void *chartInstanceVar)
{
  disable_c12_MiL_BMS_Bat((SFc12_MiL_BMS_BatInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c12_MiL_BMS_Bat(void *chartInstanceVar)
{
  sf_c12_MiL_BMS_Bat((SFc12_MiL_BMS_BatInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c12_MiL_BMS_Bat(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c12_MiL_BMS_Bat
    ((SFc12_MiL_BMS_BatInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_MiL_BMS_Bat();/* state var info */
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

extern void sf_internal_set_sim_state_c12_MiL_BMS_Bat(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_MiL_BMS_Bat();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c12_MiL_BMS_Bat((SFc12_MiL_BMS_BatInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c12_MiL_BMS_Bat(SimStruct* S)
{
  return sf_internal_get_sim_state_c12_MiL_BMS_Bat(S);
}

static void sf_opaque_set_sim_state_c12_MiL_BMS_Bat(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c12_MiL_BMS_Bat(S, st);
}

static void sf_opaque_terminate_c12_MiL_BMS_Bat(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_MiL_BMS_BatInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c12_MiL_BMS_Bat((SFc12_MiL_BMS_BatInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_MiL_BMS_Bat_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc12_MiL_BMS_Bat((SFc12_MiL_BMS_BatInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_MiL_BMS_Bat(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c12_MiL_BMS_Bat((SFc12_MiL_BMS_BatInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c12_MiL_BMS_Bat(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_MiL_BMS_Bat_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,12,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,12,14);
      sf_mark_chart_reusable_outputs(S,infoStruct,12,3);
    }

    sf_set_rtw_dwork_info(S,infoStruct,12);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1891049020U));
  ssSetChecksum1(S,(1257623763U));
  ssSetChecksum2(S,(1505411704U));
  ssSetChecksum3(S,(400293626U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c12_MiL_BMS_Bat(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_MiL_BMS_Bat(SimStruct *S)
{
  SFc12_MiL_BMS_BatInstanceStruct *chartInstance;
  chartInstance = (SFc12_MiL_BMS_BatInstanceStruct *)malloc(sizeof
    (SFc12_MiL_BMS_BatInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc12_MiL_BMS_BatInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c12_MiL_BMS_Bat;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c12_MiL_BMS_Bat;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c12_MiL_BMS_Bat;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c12_MiL_BMS_Bat;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c12_MiL_BMS_Bat;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c12_MiL_BMS_Bat;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c12_MiL_BMS_Bat;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c12_MiL_BMS_Bat;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_MiL_BMS_Bat;
  chartInstance->chartInfo.mdlStart = mdlStart_c12_MiL_BMS_Bat;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c12_MiL_BMS_Bat;
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

void c12_MiL_BMS_Bat_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_MiL_BMS_Bat(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_MiL_BMS_Bat(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_MiL_BMS_Bat(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_MiL_BMS_Bat_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
