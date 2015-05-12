/*
 * Batterymodel_HiL.c
 *
 * Code generation for model "Batterymodel_HiL.mdl".
 *
 * Model version              : 1.809
 * Simulink Coder version : 8.1 (R2011b) 08-Jul-2011
 * C source code generated on : Tue May 12 19:08:03 2015
 *
 * Target selection: lcrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Batterymodel_HiL.h"
#include "Batterymodel_HiL_private.h"

/* Block signals (auto storage) */
BlockIO_Batterymodel_HiL Batterymodel_HiL_B;

/* Block states (auto storage) */
D_Work_Batterymodel_HiL Batterymodel_HiL_DWork;

/* Real-time model */
RT_MODEL_Batterymodel_HiL Batterymodel_HiL_M_;
RT_MODEL_Batterymodel_HiL *const Batterymodel_HiL_M = &Batterymodel_HiL_M_;

/* Model output function */
static void Batterymodel_HiL_output(int_T tid)
{
  real_T current;
  int32_T i;
  int32_T i_0;

  /* FromWorkspace: '<S11>/FromWs' */
  {
    real_T *pDataValues = (real_T *) Batterymodel_HiL_DWork.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) Batterymodel_HiL_DWork.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = Batterymodel_HiL_DWork.FromWs_IWORK.PrevIndex;
    real_T t = Batterymodel_HiL_M->Timing.t[0];

    /* get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[15]) {
      currTimeIndex = 14;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    Batterymodel_HiL_DWork.FromWs_IWORK.PrevIndex = currTimeIndex;

    /* post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          Batterymodel_HiL_B.FromWs = pDataValues[currTimeIndex];
        } else {
          Batterymodel_HiL_B.FromWs = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        Batterymodel_HiL_B.FromWs = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 16;
      }
    }
  }

  /* MultiPortSwitch: '<S10>/Multiport Switch' incorporates:
   *  Constant: '<S10>/ChargeCurrent[A]'
   *  Constant: '<S10>/ChargeCurrent[A]1'
   *  Constant: '<S10>/ChargeSwitch'
   */
  switch ((int32_T)Batterymodel_HiL_P.ChargeSwitch_Value) {
   case 1:
    Batterymodel_HiL_B.ChargeCurrentA = Batterymodel_HiL_P.ChargeCurrentA1_Value;
    break;

   case 2:
    Batterymodel_HiL_B.ChargeCurrentA = Batterymodel_HiL_P.ChargeCurrentA_Value;
    break;

   default:
    Batterymodel_HiL_B.ChargeCurrentA = Batterymodel_HiL_B.FromWs;
    break;
  }

  /* End of MultiPortSwitch: '<S10>/Multiport Switch' */

  /* Product: '<S10>/Product' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  for (i_0 = 0; i_0 < 12; i_0++) {
    Batterymodel_HiL_B.ChargeCurrentA_l[i_0] = Batterymodel_HiL_B.ChargeCurrentA
      * Batterymodel_HiL_P.Constant1_Value[i_0];
  }

  /* End of Product: '<S10>/Product' */

  /* Level2 S-Function Block: '<S15>/Temp_01' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S15>/Temp_02' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[1];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S15>/Temp_03' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[2];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S15>/Temp_04' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[3];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S15>/Temp_05' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[4];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S15>/Temp_06' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[5];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S15>/Temp_07' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[6];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S15>/Temp_08' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[7];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S15>/Temp_09' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[8];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S15>/Temp_10' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[9];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S15>/Temp_11' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[10];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S15>/Temp_12' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[11];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S14>/Curr_01' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[12];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S14>/Curr_02' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[13];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S14>/Curr_03' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[14];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S14>/Curr_04' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[15];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S14>/Curr_05' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[16];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S14>/Curr_06' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[17];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S14>/Curr_07' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[18];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S14>/Curr_08' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[19];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S14>/Curr_09' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[20];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S14>/Curr_10' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[21];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S14>/Curr_11' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[22];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S14>/Curr_12' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[23];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S6>/bat_modus' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[24];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S6>/current [mA]' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[25];
    sfcnOutputs(rts, 0);
  }

  /* Gain: '<S6>/Gain1' */
  for (i_0 = 0; i_0 < 12; i_0++) {
    Batterymodel_HiL_B.Gain1[i_0] = Batterymodel_HiL_P.Gain1_Gain *
      Batterymodel_HiL_B.ChargeCurrentA_l[i_0];
  }

  /* End of Gain: '<S6>/Gain1' */

  /* Sum: '<S6>/Sum of Elements' */
  current = Batterymodel_HiL_B.Gain1[0];
  for (i = 0; i < 11; i++) {
    i_0 = i + 1;
    current += Batterymodel_HiL_B.Gain1[i_0];
  }

  Batterymodel_HiL_B.SumofElements = current;

  /* End of Sum: '<S6>/Sum of Elements' */

  /* Product: '<S6>/Divide' incorporates:
   *  Constant: '<S6>/Constant'
   */
  Batterymodel_HiL_B.Divide = Batterymodel_HiL_B.SumofElements /
    Batterymodel_HiL_P.Constant_Value;

  /* Abs: '<S6>/Abs' */
  Batterymodel_HiL_B.Abs = fabs(Batterymodel_HiL_B.Divide);

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  current = floor(Batterymodel_HiL_B.Abs);
  if (rtIsNaN(current) || rtIsInf(current)) {
    current = 0.0;
  } else {
    current = fmod(current, 65536.0);
  }

  Batterymodel_HiL_B.DataTypeConversion_f = (uint16_T)(current < 0.0 ? (uint16_T)
    (int32_T)(int16_T)-(int16_T)(uint16_T)-current : (uint16_T)current);

  /* End of DataTypeConversion: '<S6>/Data Type Conversion' */

  /* MATLAB Function: '<S6>/Embedded MATLAB Function' */
  /* MATLAB Function 'Outports/Embedded MATLAB Function': '<S12>:1' */
  if (Batterymodel_HiL_B.Divide > 0.0) {
    /* '<S12>:1:3' */
    /* '<S12>:1:4' */
    Batterymodel_HiL_B.bat_modus = 0.0;
  } else {
    /* '<S12>:1:6' */
    Batterymodel_HiL_B.bat_modus = 1.0;
  }

  /* End of MATLAB Function: '<S6>/Embedded MATLAB Function' */

  /* Level2 S-Function Block: '<S13>/Volt_01' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[26];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S13>/Volt_02' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[27];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S13>/Volt_03' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[28];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S13>/Volt_04' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[29];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S13>/Volt_05' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[30];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S13>/Volt_06' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[31];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S13>/Volt_07' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[32];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S13>/Volt_08' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[33];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S13>/Volt_09' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[34];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S13>/Volt_10' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[35];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S13>/Volt_11' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[36];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S13>/Volt_12' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[37];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S6>/voltage [mV]' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[38];
    sfcnOutputs(rts, 0);
  }

  for (i_0 = 0; i_0 < 12; i_0++) {
    /* Gain: '<S16>/Vektorize' */
    Batterymodel_HiL_B.Vektorize[i_0] = Batterymodel_HiL_P.Vektorize_Gain[i_0] *
      Batterymodel_HiL_B.ChargeCurrentA_l[i_0];

    /* Gain: '<S18>/Vektorize' */
    Batterymodel_HiL_B.Vektorize_d[i_0] =
      Batterymodel_HiL_P.Vektorize_Gain_o[i_0] *
      Batterymodel_HiL_B.Vektorize[i_0];

    /* UnitDelay: '<S18>/Unit Delay' */
    Batterymodel_HiL_B.UnitDelay[i_0] =
      Batterymodel_HiL_DWork.UnitDelay_DSTATE[i_0];

    /* Product: '<S18>/Divide' incorporates:
     *  Constant: '<S16>/R_balance'
     */
    Batterymodel_HiL_B.Divide_k[i_0] = Batterymodel_HiL_B.UnitDelay[i_0] /
      Batterymodel_HiL_P.R_balance_Value[i_0];
  }

  /* Level2 S-Function Block: '<S4>/bala_01' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[39];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S4>/bala_02' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[40];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S4>/bala_03' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[41];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S4>/bala_04' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[42];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S4>/bala_05' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[43];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S4>/bala_06' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[44];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S4>/bala_07' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[45];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S4>/bala_08' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[46];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S4>/bala_09' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[47];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S4>/bala_10' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[48];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S4>/bala_11' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[49];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S4>/bala_12' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[50];
    sfcnOutputs(rts, 1);
  }

  /* Product: '<S18>/Product' */
  Batterymodel_HiL_B.Product[0] = Batterymodel_HiL_B.Divide_k[0] *
    Batterymodel_HiL_B.bala_01;
  Batterymodel_HiL_B.Product[1] = Batterymodel_HiL_B.Divide_k[1] *
    Batterymodel_HiL_B.bala_02;
  Batterymodel_HiL_B.Product[2] = Batterymodel_HiL_B.Divide_k[2] *
    Batterymodel_HiL_B.bala_03;
  Batterymodel_HiL_B.Product[3] = Batterymodel_HiL_B.Divide_k[3] *
    Batterymodel_HiL_B.bala_04;
  Batterymodel_HiL_B.Product[4] = Batterymodel_HiL_B.Divide_k[4] *
    Batterymodel_HiL_B.bala_05;
  Batterymodel_HiL_B.Product[5] = Batterymodel_HiL_B.Divide_k[5] *
    Batterymodel_HiL_B.bala_06;
  Batterymodel_HiL_B.Product[6] = Batterymodel_HiL_B.Divide_k[6] *
    Batterymodel_HiL_B.bala_07;
  Batterymodel_HiL_B.Product[7] = Batterymodel_HiL_B.Divide_k[7] *
    Batterymodel_HiL_B.bala_08;
  Batterymodel_HiL_B.Product[8] = Batterymodel_HiL_B.Divide_k[8] *
    Batterymodel_HiL_B.bala_09;
  Batterymodel_HiL_B.Product[9] = Batterymodel_HiL_B.Divide_k[9] *
    Batterymodel_HiL_B.bala_10;
  Batterymodel_HiL_B.Product[10] = Batterymodel_HiL_B.Divide_k[10] *
    Batterymodel_HiL_B.bala_11;
  Batterymodel_HiL_B.Product[11] = Batterymodel_HiL_B.Divide_k[11] *
    Batterymodel_HiL_B.bala_12;

  /* MATLAB Function 'battery/Batteriemodell/battery_electrical_values/MATLAB Function': '<S19>:1' */
  /* '<S19>:1:2' */
  for (i_0 = 0; i_0 < 12; i_0++) {
    /* Sum: '<S18>/Add' */
    Batterymodel_HiL_B.Add[i_0] = Batterymodel_HiL_B.Vektorize_d[i_0] +
      Batterymodel_HiL_B.Product[i_0];

    /* Product: '<S20>/Product' incorporates:
     *  Constant: '<S20>/1.//C_diff'
     */
    Batterymodel_HiL_B.Product_d[i_0] = Batterymodel_HiL_P.C_diff_Value *
      Batterymodel_HiL_B.Add[i_0];

    /* Gain: '<S20>/Gain' */
    Batterymodel_HiL_B.Gain[i_0] = Batterymodel_HiL_P.Gain_Gain *
      Batterymodel_HiL_B.Product_d[i_0];

    /* UnitDelay: '<S20>/Unit Delay1' */
    Batterymodel_HiL_B.UnitDelay1[i_0] =
      Batterymodel_HiL_DWork.UnitDelay1_DSTATE[i_0];

    /* Product: '<S20>/Product1' incorporates:
     *  Constant: '<S20>/1//C_diff*R_diff)'
     */
    Batterymodel_HiL_B.Product1[i_0] = Batterymodel_HiL_P.C_diffR_diff_Value *
      Batterymodel_HiL_B.UnitDelay1[i_0];

    /* Gain: '<S20>/Gain1' */
    Batterymodel_HiL_B.Gain1_g[i_0] = Batterymodel_HiL_P.Gain1_Gain_a *
      Batterymodel_HiL_B.Product1[i_0];

    /* UnitDelay: '<S20>/Unit Delay' */
    Batterymodel_HiL_B.UnitDelay_l[i_0] =
      Batterymodel_HiL_DWork.UnitDelay_DSTATE_n[i_0];

    /* Sum: '<S20>/Add' */
    Batterymodel_HiL_B.Add_o[i_0] = (Batterymodel_HiL_B.Gain[i_0] -
      Batterymodel_HiL_B.Gain1_g[i_0]) + Batterymodel_HiL_B.UnitDelay_l[i_0];

    /* Product: '<S20>/Product2' incorporates:
     *  Constant: '<S20>/R_ct+R_i'
     */
    Batterymodel_HiL_B.Product2[i_0] = Batterymodel_HiL_B.Add[i_0] *
      Batterymodel_HiL_P.R_ctR_i_Value;

    /* UnitDelay: '<S7>/Unit Delay' */
    Batterymodel_HiL_B.UnitDelay_o[i_0] =
      Batterymodel_HiL_DWork.UnitDelay_DSTATE_l[i_0];

    /* Gain: '<S18>/Gain' */
    Batterymodel_HiL_B.Gain_p[i_0] = Batterymodel_HiL_P.Gain_Gain_e *
      Batterymodel_HiL_B.UnitDelay_o[i_0];

    /* MATLAB Function: '<S18>/MATLAB Function' incorporates:
     *  Constant: '<S18>/ poles_soc'
     */
    Batterymodel_HiL_B.y[i_0] = Batterymodel_HiL_P.poles_soc_Value[0];
  }

  /* MATLAB Function: '<S18>/MATLAB Function' incorporates:
   *  Constant: '<S18>/ poles_soc'
   */
  for (i_0 = 0; i_0 < 4; i_0++) {
    current = Batterymodel_HiL_P.poles_soc_Value[1 + i_0];
    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.y[i] = Batterymodel_HiL_B.Gain_p[i] *
        Batterymodel_HiL_B.y[i] + current;
    }
  }

  for (i_0 = 0; i_0 < 12; i_0++) {
    /* Sum: '<S20>/Add1' */
    Batterymodel_HiL_B.Add1[i_0] = (Batterymodel_HiL_B.y[i_0] -
      Batterymodel_HiL_B.Add_o[i_0]) - Batterymodel_HiL_B.Product2[i_0];

    /* Gain: '<S6>/Gain' */
    Batterymodel_HiL_B.Gain_k[i_0] = Batterymodel_HiL_P.Gain_Gain_f *
      Batterymodel_HiL_B.Add1[i_0];
  }

  /* Sum: '<S6>/Sum of Elements1' */
  current = Batterymodel_HiL_B.Gain_k[0];
  for (i = 0; i < 11; i++) {
    i_0 = i + 1;
    current += Batterymodel_HiL_B.Gain_k[i_0];
  }

  Batterymodel_HiL_B.SumofElements1 = current;

  /* End of Sum: '<S6>/Sum of Elements1' */

  /* DataTypeConversion: '<S6>/Data Type Conversion1' */
  current = floor(Batterymodel_HiL_B.SumofElements1);
  if (rtIsNaN(current) || rtIsInf(current)) {
    current = 0.0;
  } else {
    current = fmod(current, 65536.0);
  }

  Batterymodel_HiL_B.DataTypeConversion1 = (uint16_T)(current < 0.0 ? (uint16_T)
    (int32_T)(int16_T)-(int16_T)(uint16_T)-current : (uint16_T)current);

  /* End of DataTypeConversion: '<S6>/Data Type Conversion1' */

  /* Gain: '<S17>/1//Q_0' */
  for (i_0 = 0; i_0 < 12; i_0++) {
    Batterymodel_HiL_B.Q_0[i_0] = Batterymodel_HiL_P.Q_0_Gain[i_0] *
      Batterymodel_HiL_B.Add[i_0];
  }

  /* End of Gain: '<S17>/1//Q_0' */

  /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  if (Batterymodel_HiL_DWork.DiscreteTimeIntegrator_SYSTEM_E != 0) {
    memcpy((void *)(&Batterymodel_HiL_B.DiscreteTimeIntegrator[0]), (void *)
           Batterymodel_HiL_DWork.DiscreteTimeIntegrator_DSTATE, 12U * sizeof
           (real_T));
  } else {
    for (i_0 = 0; i_0 < 12; i_0++) {
      Batterymodel_HiL_B.DiscreteTimeIntegrator[i_0] =
        Batterymodel_HiL_P.DiscreteTimeIntegrator_gainval *
        Batterymodel_HiL_B.Q_0[i_0] +
        Batterymodel_HiL_DWork.DiscreteTimeIntegrator_DSTATE[i_0];
    }
  }

  for (i_0 = 0; i_0 < 12; i_0++) {
    /* Sum: '<S17>/Add' incorporates:
     *  Constant: '<S5>/Init SoC [%]'
     */
    Batterymodel_HiL_B.Add_d[i_0] = Batterymodel_HiL_P.InitSoC_Value[i_0] -
      Batterymodel_HiL_B.DiscreteTimeIntegrator[i_0];

    /* Gain: '<S7>/0.01->1%' */
    Batterymodel_HiL_B.u11[i_0] = Batterymodel_HiL_P.u11_Gain *
      Batterymodel_HiL_B.Add_d[i_0];

    /* Gain: '<S22>/charge_current [A]' */
    Batterymodel_HiL_B.charge_currentA[i_0] =
      Batterymodel_HiL_P.charge_currentA_Gain *
      Batterymodel_HiL_B.ChargeCurrentA_l[i_0];

    /* Gain: '<S22>/charge_current [mA]' */
    Batterymodel_HiL_B.charge_currentmA[i_0] =
      Batterymodel_HiL_P.charge_currentmA_Gain *
      Batterymodel_HiL_B.charge_currentA[i_0];
  }

  /* End of DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */

  /* Level2 S-Function Block: '<S22>/bat_mode_system' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[51];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S22>/current_system' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[52];
    sfcnOutputs(rts, 1);
  }

  /* MATLAB Function: '<S22>/current_system [mA]' */
  /* MATLAB Function 'displays/Batteriestrom/current_system [mA]': '<S24>:1' */
  if (Batterymodel_HiL_B.bat_mode_system == 0.0) {
    /* '<S24>:1:3' */
    /* '<S24>:1:4' */
    current = Batterymodel_HiL_B.current_system;
  } else {
    /* '<S24>:1:6' */
    current = -Batterymodel_HiL_B.current_system;
  }

  /* Ausgabe */
  /* '<S24>:1:10' */
  Batterymodel_HiL_B.current_out = current;

  /* End of MATLAB Function: '<S22>/current_system [mA]' */

  /* Gain: '<S22>/current_system [A]' */
  Batterymodel_HiL_B.current_systemA = Batterymodel_HiL_P.current_systemA_Gain *
    Batterymodel_HiL_B.current_out;

  /* Sum: '<S23>/Sum of Elements' */
  current = Batterymodel_HiL_B.u11[0];
  for (i = 0; i < 11; i++) {
    i_0 = i + 1;
    current += Batterymodel_HiL_B.u11[i_0];
  }

  Batterymodel_HiL_B.SumofElements_c = current;

  /* End of Sum: '<S23>/Sum of Elements' */

  /* Product: '<S23>/SoC Model_% ' incorporates:
   *  Constant: '<S23>/Cellno'
   */
  Batterymodel_HiL_B.SoCModel_ = Batterymodel_HiL_B.SumofElements_c /
    Batterymodel_HiL_P.Cellno_Value;

  /* Level2 S-Function Block: '<S23>/SoC_Kalman' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[53];
    sfcnOutputs(rts, 1);
  }

  /* DataTypeConversion: '<S23>/Data Type Conversion' */
  Batterymodel_HiL_B.DataTypeConversion = (real32_T)
    Batterymodel_HiL_B.SoC_Kalman;

  /* Gain: '<S23>/SoC_Kalman_%' */
  Batterymodel_HiL_B.SoC_Kalman_ = Batterymodel_HiL_P.SoC_Kalman__Gain *
    Batterymodel_HiL_B.DataTypeConversion;

  /* Sum: '<S23>/delta SoC' */
  Batterymodel_HiL_B.deltaSoC = Batterymodel_HiL_B.SoCModel_ - (real_T)
    Batterymodel_HiL_B.SoC_Kalman_;

  /* Sum: '<S21>/sum_bat_voltage [V]' */
  current = Batterymodel_HiL_B.Add1[0];
  for (i = 0; i < 11; i++) {
    i_0 = i + 1;
    current += Batterymodel_HiL_B.Add1[i_0];
  }

  Batterymodel_HiL_B.sum_bat_voltageV = current;

  /* End of Sum: '<S21>/sum_bat_voltage [V]' */

  /* Gain: '<S21>/bat_voltage [mV]' */
  Batterymodel_HiL_B.bat_voltagemV = Batterymodel_HiL_P.bat_voltagemV_Gain *
    Batterymodel_HiL_B.sum_bat_voltageV;

  /* Level2 S-Function Block: '<S21>/voltage_system' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[54];
    sfcnOutputs(rts, 1);
  }

  /* Gain: '<S21>/voltage_system [mV]' */
  Batterymodel_HiL_B.voltage_systemmV = Batterymodel_HiL_P.voltage_systemmV_Gain
    * Batterymodel_HiL_B.voltage_system;

  /* Gain: '<S21>/voltage_system [V]' */
  Batterymodel_HiL_B.voltage_systemV = Batterymodel_HiL_P.voltage_systemV_Gain *
    Batterymodel_HiL_B.voltage_systemmV;

  /* Level2 S-Function Block: '<S9>/Mod_CAN_RS232_Com' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[55];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S1>/CellT01' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[56];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S1>/CellT02' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[57];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S1>/CellT03' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[58];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S1>/CellT04' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[59];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S1>/CellT05' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[60];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S1>/CellT06' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[61];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S1>/CellT07' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[62];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S1>/CellT08' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[63];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S1>/CellT09' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[64];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S1>/CellT10' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[65];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S1>/CellT11' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[66];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S1>/CellT12' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[67];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S2>/CellV01' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[68];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S2>/CellV02' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[69];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S2>/CellV03' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[70];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S2>/CellV04' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[71];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S2>/CellV05' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[72];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S2>/CellV06' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[73];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S2>/CellV07' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[74];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S2>/CellV08' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[75];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S2>/CellV09' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[76];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S2>/CellV10' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[77];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S2>/CellV11' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[78];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S2>/CellV12' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[79];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S3>/Error_CellNo' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[80];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S3>/Error_Event' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[81];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S3>/Error_Indication' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[82];
    sfcnOutputs(rts, 1);
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
static void Batterymodel_HiL_update(int_T tid)
{
  int32_T i;

  /* Level2 S-Function Block: '<S15>/Temp_01' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[0];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_02' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[1];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_03' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[2];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_04' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[3];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_05' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[4];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_06' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[5];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_07' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[6];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_08' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[7];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_09' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[8];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_10' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[9];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_11' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[10];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_12' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[11];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_01' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[12];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_02' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[13];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_03' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[14];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_04' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[15];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_05' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[16];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_06' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[17];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_07' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[18];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_08' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[19];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_09' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[20];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_10' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[21];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_11' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[22];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_12' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[23];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S6>/bat_modus' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[24];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S6>/current [mA]' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[25];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_01' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[26];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_02' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[27];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_03' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[28];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_04' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[29];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_05' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[30];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_06' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[31];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_07' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[32];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_08' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[33];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_09' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[34];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_10' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[35];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_11' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[36];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_12' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[37];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S6>/voltage [mV]' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[38];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S18>/Unit Delay' */
  memcpy((void *)Batterymodel_HiL_DWork.UnitDelay_DSTATE, (void *)
         (&Batterymodel_HiL_B.Add1[0]), 12U * sizeof(real_T));

  /* Level2 S-Function Block: '<S4>/bala_01' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[39];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_02' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[40];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_03' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[41];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_04' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[42];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_05' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[43];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_06' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[44];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_07' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[45];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_08' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[46];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_09' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[47];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_10' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[48];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_11' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[49];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_12' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[50];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  Batterymodel_HiL_DWork.DiscreteTimeIntegrator_SYSTEM_E = 0U;
  for (i = 0; i < 12; i++) {
    /* Update for UnitDelay: '<S20>/Unit Delay1' */
    Batterymodel_HiL_DWork.UnitDelay1_DSTATE[i] =
      Batterymodel_HiL_B.UnitDelay_l[i];

    /* Update for UnitDelay: '<S20>/Unit Delay' */
    Batterymodel_HiL_DWork.UnitDelay_DSTATE_n[i] = Batterymodel_HiL_B.Add_o[i];

    /* Update for UnitDelay: '<S7>/Unit Delay' */
    Batterymodel_HiL_DWork.UnitDelay_DSTATE_l[i] = Batterymodel_HiL_B.Add_d[i];
    Batterymodel_HiL_DWork.DiscreteTimeIntegrator_DSTATE[i] =
      Batterymodel_HiL_P.DiscreteTimeIntegrator_gainval *
      Batterymodel_HiL_B.Q_0[i] + Batterymodel_HiL_B.DiscreteTimeIntegrator[i];
  }

  /* End of Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  /* Level2 S-Function Block: '<S22>/bat_mode_system' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[51];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S22>/current_system' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[52];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S23>/SoC_Kalman' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[53];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S21>/voltage_system' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[54];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S9>/Mod_CAN_RS232_Com' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[55];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT01' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[56];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT02' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[57];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT03' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[58];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT04' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[59];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT05' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[60];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT06' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[61];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT07' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[62];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT08' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[63];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT09' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[64];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT10' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[65];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT11' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[66];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT12' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[67];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV01' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[68];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV02' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[69];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV03' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[70];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV04' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[71];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV05' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[72];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV06' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[73];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV07' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[74];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV08' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[75];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV09' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[76];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV10' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[77];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV11' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[78];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV12' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[79];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S3>/Error_CellNo' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[80];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S3>/Error_Event' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[81];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S3>/Error_Indication' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[82];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Batterymodel_HiL_M->Timing.clockTick0)) {
    ++Batterymodel_HiL_M->Timing.clockTickH0;
  }

  Batterymodel_HiL_M->Timing.t[0] = Batterymodel_HiL_M->Timing.clockTick0 *
    Batterymodel_HiL_M->Timing.stepSize0 +
    Batterymodel_HiL_M->Timing.clockTickH0 *
    Batterymodel_HiL_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Batterymodel_HiL_M->Timing.clockTick1)) {
      ++Batterymodel_HiL_M->Timing.clockTickH1;
    }

    Batterymodel_HiL_M->Timing.t[1] = Batterymodel_HiL_M->Timing.clockTick1 *
      Batterymodel_HiL_M->Timing.stepSize1 +
      Batterymodel_HiL_M->Timing.clockTickH1 *
      Batterymodel_HiL_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void Batterymodel_HiL_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Batterymodel_HiL_M, 0,
                sizeof(RT_MODEL_Batterymodel_HiL));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Batterymodel_HiL_M->solverInfo,
                          &Batterymodel_HiL_M->Timing.simTimeStep);
    rtsiSetTPtr(&Batterymodel_HiL_M->solverInfo, &rtmGetTPtr(Batterymodel_HiL_M));
    rtsiSetStepSizePtr(&Batterymodel_HiL_M->solverInfo,
                       &Batterymodel_HiL_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Batterymodel_HiL_M->solverInfo, (&rtmGetErrorStatus
      (Batterymodel_HiL_M)));
    rtsiSetRTModelPtr(&Batterymodel_HiL_M->solverInfo, Batterymodel_HiL_M);
  }

  rtsiSetSimTimeStep(&Batterymodel_HiL_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Batterymodel_HiL_M->solverInfo,"FixedStepDiscrete");
  Batterymodel_HiL_M->solverInfoPtr = (&Batterymodel_HiL_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Batterymodel_HiL_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Batterymodel_HiL_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Batterymodel_HiL_M->Timing.sampleTimes =
      (&Batterymodel_HiL_M->Timing.sampleTimesArray[0]);
    Batterymodel_HiL_M->Timing.offsetTimes =
      (&Batterymodel_HiL_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Batterymodel_HiL_M->Timing.sampleTimes[0] = (0.0);
    Batterymodel_HiL_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    Batterymodel_HiL_M->Timing.offsetTimes[0] = (0.0);
    Batterymodel_HiL_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Batterymodel_HiL_M, &Batterymodel_HiL_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Batterymodel_HiL_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Batterymodel_HiL_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Batterymodel_HiL_M, -1);
  Batterymodel_HiL_M->Timing.stepSize0 = 0.01;
  Batterymodel_HiL_M->Timing.stepSize1 = 0.01;
  Batterymodel_HiL_M->solverInfoPtr = (&Batterymodel_HiL_M->solverInfo);
  Batterymodel_HiL_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Batterymodel_HiL_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Batterymodel_HiL_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Batterymodel_HiL_M->ModelData.blockIO = ((void *) &Batterymodel_HiL_B);
  (void) memset(((void *) &Batterymodel_HiL_B), 0,
                sizeof(BlockIO_Batterymodel_HiL));

  {
    int_T i;
    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.ChargeCurrentA_l[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.Gain1[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.Vektorize[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.Vektorize_d[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.UnitDelay[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.Divide_k[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.Product[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.Add[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.Product_d[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.Gain[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.UnitDelay1[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.Product1[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.Gain1_g[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.UnitDelay_l[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.Add_o[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.Product2[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.UnitDelay_o[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.Gain_p[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.Add1[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.Gain_k[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.Q_0[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.DiscreteTimeIntegrator[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.Add_d[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.u11[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.charge_currentA[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.charge_currentmA[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_B.y[i] = 0.0;
    }

    Batterymodel_HiL_B.FromWs = 0.0;
    Batterymodel_HiL_B.ChargeCurrentA = 0.0;
    Batterymodel_HiL_B.SumofElements = 0.0;
    Batterymodel_HiL_B.Divide = 0.0;
    Batterymodel_HiL_B.Abs = 0.0;
    Batterymodel_HiL_B.bala_01 = 0.0;
    Batterymodel_HiL_B.bala_02 = 0.0;
    Batterymodel_HiL_B.bala_03 = 0.0;
    Batterymodel_HiL_B.bala_04 = 0.0;
    Batterymodel_HiL_B.bala_05 = 0.0;
    Batterymodel_HiL_B.bala_06 = 0.0;
    Batterymodel_HiL_B.bala_07 = 0.0;
    Batterymodel_HiL_B.bala_08 = 0.0;
    Batterymodel_HiL_B.bala_09 = 0.0;
    Batterymodel_HiL_B.bala_10 = 0.0;
    Batterymodel_HiL_B.bala_11 = 0.0;
    Batterymodel_HiL_B.bala_12 = 0.0;
    Batterymodel_HiL_B.SumofElements1 = 0.0;
    Batterymodel_HiL_B.bat_mode_system = 0.0;
    Batterymodel_HiL_B.current_system = 0.0;
    Batterymodel_HiL_B.current_systemA = 0.0;
    Batterymodel_HiL_B.SumofElements_c = 0.0;
    Batterymodel_HiL_B.SoCModel_ = 0.0;
    Batterymodel_HiL_B.SoC_Kalman = 0.0;
    Batterymodel_HiL_B.deltaSoC = 0.0;
    Batterymodel_HiL_B.sum_bat_voltageV = 0.0;
    Batterymodel_HiL_B.bat_voltagemV = 0.0;
    Batterymodel_HiL_B.voltage_system = 0.0;
    Batterymodel_HiL_B.voltage_systemmV = 0.0;
    Batterymodel_HiL_B.voltage_systemV = 0.0;
    Batterymodel_HiL_B.CellT01 = 0.0;
    Batterymodel_HiL_B.CellT02 = 0.0;
    Batterymodel_HiL_B.CellT03 = 0.0;
    Batterymodel_HiL_B.CellT04 = 0.0;
    Batterymodel_HiL_B.CellT05 = 0.0;
    Batterymodel_HiL_B.CellT06 = 0.0;
    Batterymodel_HiL_B.CellT07 = 0.0;
    Batterymodel_HiL_B.CellT08 = 0.0;
    Batterymodel_HiL_B.CellT09 = 0.0;
    Batterymodel_HiL_B.CellT10 = 0.0;
    Batterymodel_HiL_B.CellT11 = 0.0;
    Batterymodel_HiL_B.CellT12 = 0.0;
    Batterymodel_HiL_B.CellV01 = 0.0;
    Batterymodel_HiL_B.CellV02 = 0.0;
    Batterymodel_HiL_B.CellV03 = 0.0;
    Batterymodel_HiL_B.CellV04 = 0.0;
    Batterymodel_HiL_B.CellV05 = 0.0;
    Batterymodel_HiL_B.CellV06 = 0.0;
    Batterymodel_HiL_B.CellV07 = 0.0;
    Batterymodel_HiL_B.CellV08 = 0.0;
    Batterymodel_HiL_B.CellV09 = 0.0;
    Batterymodel_HiL_B.CellV10 = 0.0;
    Batterymodel_HiL_B.CellV11 = 0.0;
    Batterymodel_HiL_B.CellV12 = 0.0;
    Batterymodel_HiL_B.Error_CellNo = 0.0;
    Batterymodel_HiL_B.Error_Event = 0.0;
    Batterymodel_HiL_B.Error_Indication = 0.0;
    Batterymodel_HiL_B.current_out = 0.0;
    Batterymodel_HiL_B.bat_modus = 0.0;
    Batterymodel_HiL_B.DataTypeConversion = 0.0F;
    Batterymodel_HiL_B.SoC_Kalman_ = 0.0F;
  }

  /* parameters */
  Batterymodel_HiL_M->ModelData.defaultParam = ((real_T *)&Batterymodel_HiL_P);

  /* states (dwork) */
  Batterymodel_HiL_M->Work.dwork = ((void *) &Batterymodel_HiL_DWork);
  (void) memset((void *)&Batterymodel_HiL_DWork, 0,
                sizeof(D_Work_Batterymodel_HiL));

  {
    int_T i;
    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_DWork.UnitDelay_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_DWork.UnitDelay1_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_DWork.UnitDelay_DSTATE_n[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_DWork.UnitDelay_DSTATE_l[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_DWork.DiscreteTimeIntegrator_DSTATE[i] = 0.0;
    }
  }

  Batterymodel_HiL_DWork.deltaSoC_DWORK1 = 0.0;

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Batterymodel_HiL_M->NonInlinedSFcns.sfcnInfo;
    Batterymodel_HiL_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Batterymodel_HiL_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Batterymodel_HiL_M->Sizes.numSampTimes);
    Batterymodel_HiL_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (Batterymodel_HiL_M)[0]);
    Batterymodel_HiL_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (Batterymodel_HiL_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,Batterymodel_HiL_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Batterymodel_HiL_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Batterymodel_HiL_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (Batterymodel_HiL_M));
    rtssSetStepSizePtr(sfcnInfo, &Batterymodel_HiL_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Batterymodel_HiL_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Batterymodel_HiL_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Batterymodel_HiL_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &Batterymodel_HiL_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &Batterymodel_HiL_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Batterymodel_HiL_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Batterymodel_HiL_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Batterymodel_HiL_M->solverInfoPtr);
  }

  Batterymodel_HiL_M->Sizes.numSFcns = (83);

  /* register each child */
  {
    (void) memset((void *)&Batterymodel_HiL_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  83*sizeof(SimStruct));
    Batterymodel_HiL_M->childSfunctions =
      (&Batterymodel_HiL_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 83; i++) {
        Batterymodel_HiL_M->childSfunctions[i] =
          (&Batterymodel_HiL_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S15>/Temp_01 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               Batterymodel_HiL_P.InitAmbientTemperatureK_Value);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Temp_01");
      ssSetPath(rts,
                "Batterymodel_HiL/Outports/Outports Zelltemperaturen/Temp_01");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Temp_01_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Temp_01_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S15>/Temp_02 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &Batterymodel_HiL_P.InitAmbientTemperatureK_Value[
                               1]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Temp_02");
      ssSetPath(rts,
                "Batterymodel_HiL/Outports/Outports Zelltemperaturen/Temp_02");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Temp_02_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Temp_02_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S15>/Temp_03 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &Batterymodel_HiL_P.InitAmbientTemperatureK_Value[
                               2]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Temp_03");
      ssSetPath(rts,
                "Batterymodel_HiL/Outports/Outports Zelltemperaturen/Temp_03");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Temp_03_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Temp_03_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S15>/Temp_04 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &Batterymodel_HiL_P.InitAmbientTemperatureK_Value[
                               3]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Temp_04");
      ssSetPath(rts,
                "Batterymodel_HiL/Outports/Outports Zelltemperaturen/Temp_04");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Temp_04_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Temp_04_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S15>/Temp_05 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &Batterymodel_HiL_P.InitAmbientTemperatureK_Value[
                               4]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Temp_05");
      ssSetPath(rts,
                "Batterymodel_HiL/Outports/Outports Zelltemperaturen/Temp_05");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Temp_05_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Temp_05_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S15>/Temp_06 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &Batterymodel_HiL_P.InitAmbientTemperatureK_Value[
                               5]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Temp_06");
      ssSetPath(rts,
                "Batterymodel_HiL/Outports/Outports Zelltemperaturen/Temp_06");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Temp_06_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Temp_06_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S15>/Temp_07 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &Batterymodel_HiL_P.InitAmbientTemperatureK_Value[
                               6]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Temp_07");
      ssSetPath(rts,
                "Batterymodel_HiL/Outports/Outports Zelltemperaturen/Temp_07");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Temp_07_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Temp_07_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S15>/Temp_08 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &Batterymodel_HiL_P.InitAmbientTemperatureK_Value[
                               7]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Temp_08");
      ssSetPath(rts,
                "Batterymodel_HiL/Outports/Outports Zelltemperaturen/Temp_08");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Temp_08_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Temp_08_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S15>/Temp_09 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &Batterymodel_HiL_P.InitAmbientTemperatureK_Value[
                               8]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Temp_09");
      ssSetPath(rts,
                "Batterymodel_HiL/Outports/Outports Zelltemperaturen/Temp_09");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Temp_09_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Temp_09_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S15>/Temp_10 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[9]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[9]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2[9]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn9.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &Batterymodel_HiL_P.InitAmbientTemperatureK_Value[
                               9]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Temp_10");
      ssSetPath(rts,
                "Batterymodel_HiL/Outports/Outports Zelltemperaturen/Temp_10");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Temp_10_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Temp_10_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S15>/Temp_11 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[10]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[10]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[10]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [10]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn10.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &Batterymodel_HiL_P.InitAmbientTemperatureK_Value[
                               10]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Temp_11");
      ssSetPath(rts,
                "Batterymodel_HiL/Outports/Outports Zelltemperaturen/Temp_11");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Temp_11_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Temp_11_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S15>/Temp_12 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[11]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[11]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[11]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [11]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn11.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &Batterymodel_HiL_P.InitAmbientTemperatureK_Value[
                               11]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Temp_12");
      ssSetPath(rts,
                "Batterymodel_HiL/Outports/Outports Zelltemperaturen/Temp_12");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Temp_12_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Temp_12_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S14>/Curr_01 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[12];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn12.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[12]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[12]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[12]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [12]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn12.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain1[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Curr_01");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellströme/Curr_01");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Curr_01_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Curr_01_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S14>/Curr_02 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[13];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn13.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn13.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn13.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[13]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[13]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[13]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [13]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn13.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain1[1]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Curr_02");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellströme/Curr_02");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn13.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Curr_02_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Curr_02_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S14>/Curr_03 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[14];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn14.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn14.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn14.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[14]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[14]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[14]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [14]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn14.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain1[2]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Curr_03");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellströme/Curr_03");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn14.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Curr_03_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Curr_03_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S14>/Curr_04 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[15];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn15.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn15.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn15.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[15]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[15]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[15]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [15]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn15.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain1[3]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Curr_04");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellströme/Curr_04");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn15.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Curr_04_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Curr_04_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S14>/Curr_05 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[16];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn16.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn16.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn16.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[16]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[16]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[16]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [16]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn16.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain1[4]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Curr_05");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellströme/Curr_05");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn16.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Curr_05_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Curr_05_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S14>/Curr_06 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[17];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn17.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn17.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn17.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[17]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[17]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[17]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [17]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn17.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain1[5]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Curr_06");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellströme/Curr_06");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn17.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Curr_06_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Curr_06_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S14>/Curr_07 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[18];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn18.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn18.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn18.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[18]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[18]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[18]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [18]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn18.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain1[6]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Curr_07");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellströme/Curr_07");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn18.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Curr_07_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Curr_07_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S14>/Curr_08 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[19];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn19.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn19.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn19.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[19]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[19]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[19]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [19]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn19.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain1[7]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Curr_08");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellströme/Curr_08");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn19.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Curr_08_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Curr_08_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S14>/Curr_09 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[20];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn20.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn20.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn20.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[20]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[20]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[20]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [20]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn20.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain1[8]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Curr_09");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellströme/Curr_09");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn20.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Curr_09_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Curr_09_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S14>/Curr_10 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[21];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn21.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn21.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn21.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[21]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[21]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[21]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [21]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn21.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain1[9]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Curr_10");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellströme/Curr_10");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn21.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Curr_10_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Curr_10_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S14>/Curr_11 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[22];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn22.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn22.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn22.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[22]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[22]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[22]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [22]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn22.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain1[10]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Curr_11");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellströme/Curr_11");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn22.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Curr_11_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Curr_11_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S14>/Curr_12 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[23];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn23.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn23.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn23.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[23]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[23]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[23]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [23]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn23.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain1[11]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Curr_12");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellströme/Curr_12");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn23.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Curr_12_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Curr_12_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S6>/bat_modus (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[24];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn24.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn24.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn24.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[24]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[24]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[24]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [24]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn24.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.bat_modus);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "bat_modus");
      ssSetPath(rts, "Batterymodel_HiL/Outports/bat_modus");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn24.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.bat_modus_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.bat_modus_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S6>/current [mA] (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[25];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn25.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn25.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn25.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[25]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[25]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[25]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [25]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn25.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.DataTypeConversion_f);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "current [mA]");
      ssSetPath(rts, "Batterymodel_HiL/Outports/current [mA]");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn25.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.currentmA_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.currentmA_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_UINT16);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S13>/Volt_01 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[26];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn26.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn26.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn26.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[26]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[26]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[26]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [26]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn26.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain_k[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Volt_01");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellspannungen/Volt_01");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn26.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Volt_01_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Volt_01_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S13>/Volt_02 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[27];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn27.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn27.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn27.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[27]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[27]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[27]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [27]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn27.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain_k[1]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Volt_02");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellspannungen/Volt_02");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn27.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Volt_02_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Volt_02_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S13>/Volt_03 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[28];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn28.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn28.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn28.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[28]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[28]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[28]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [28]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn28.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain_k[2]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Volt_03");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellspannungen/Volt_03");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn28.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Volt_03_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Volt_03_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S13>/Volt_04 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[29];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn29.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn29.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn29.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[29]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[29]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[29]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [29]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn29.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain_k[3]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Volt_04");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellspannungen/Volt_04");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn29.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Volt_04_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Volt_04_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S13>/Volt_05 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[30];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn30.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn30.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn30.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[30]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[30]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[30]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [30]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn30.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain_k[4]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Volt_05");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellspannungen/Volt_05");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn30.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Volt_05_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Volt_05_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S13>/Volt_06 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[31];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn31.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn31.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn31.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[31]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[31]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[31]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [31]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn31.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain_k[5]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Volt_06");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellspannungen/Volt_06");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn31.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Volt_06_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Volt_06_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S13>/Volt_07 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[32];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn32.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn32.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn32.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[32]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[32]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[32]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [32]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn32.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain_k[6]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Volt_07");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellspannungen/Volt_07");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn32.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Volt_07_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Volt_07_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S13>/Volt_08 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[33];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn33.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn33.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn33.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[33]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[33]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[33]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [33]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn33.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain_k[7]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Volt_08");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellspannungen/Volt_08");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn33.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Volt_08_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Volt_08_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S13>/Volt_09 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[34];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn34.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn34.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn34.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[34]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[34]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[34]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [34]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn34.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain_k[8]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Volt_09");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellspannungen/Volt_09");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn34.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Volt_09_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Volt_09_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S13>/Volt_10 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[35];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn35.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn35.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn35.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[35]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[35]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[35]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [35]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn35.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain_k[9]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Volt_10");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellspannungen/Volt_10");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn35.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Volt_10_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Volt_10_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S13>/Volt_11 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[36];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn36.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn36.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn36.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[36]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[36]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[36]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [36]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn36.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain_k[10]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Volt_11");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellspannungen/Volt_11");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn36.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Volt_11_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Volt_11_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S13>/Volt_12 (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[37];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn37.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn37.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn37.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[37]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[37]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[37]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [37]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn37.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.Gain_k[11]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Volt_12");
      ssSetPath(rts, "Batterymodel_HiL/Outports/Outports Zellspannungen/Volt_12");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn37.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Volt_12_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Volt_12_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S6>/voltage [mV] (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[38];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn38.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn38.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn38.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[38]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[38]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[38]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [38]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn38.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_B.DataTypeConversion1);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "voltage [mV]");
      ssSetPath(rts, "Batterymodel_HiL/Outports/voltage [mV]");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn38.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.voltagemV_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.voltagemV_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_UINT16);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S4>/bala_01 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[39];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn39.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn39.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn39.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[39]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[39]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[39]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [39]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn39.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.bala_01));
        }
      }

      /* path info */
      ssSetModelName(rts, "bala_01");
      ssSetPath(rts, "Batterymodel_HiL/Inports_Balance /bala_01");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn39.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.bala_01_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.bala_01_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.bala_01_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.bala_01_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S4>/bala_02 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[40];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn40.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn40.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn40.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[40]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[40]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[40]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [40]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn40.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.bala_02));
        }
      }

      /* path info */
      ssSetModelName(rts, "bala_02");
      ssSetPath(rts, "Batterymodel_HiL/Inports_Balance /bala_02");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn40.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.bala_02_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.bala_02_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.bala_02_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.bala_02_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S4>/bala_03 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[41];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn41.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn41.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn41.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[41]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[41]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[41]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [41]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn41.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.bala_03));
        }
      }

      /* path info */
      ssSetModelName(rts, "bala_03");
      ssSetPath(rts, "Batterymodel_HiL/Inports_Balance /bala_03");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn41.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.bala_03_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.bala_03_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.bala_03_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.bala_03_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S4>/bala_04 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[42];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn42.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn42.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn42.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[42]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[42]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[42]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [42]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn42.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.bala_04));
        }
      }

      /* path info */
      ssSetModelName(rts, "bala_04");
      ssSetPath(rts, "Batterymodel_HiL/Inports_Balance /bala_04");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn42.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.bala_04_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.bala_04_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.bala_04_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.bala_04_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S4>/bala_05 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[43];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn43.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn43.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn43.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[43]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[43]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[43]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [43]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn43.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.bala_05));
        }
      }

      /* path info */
      ssSetModelName(rts, "bala_05");
      ssSetPath(rts, "Batterymodel_HiL/Inports_Balance /bala_05");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn43.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.bala_05_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.bala_05_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.bala_05_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.bala_05_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S4>/bala_06 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[44];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn44.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn44.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn44.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[44]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[44]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[44]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [44]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn44.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.bala_06));
        }
      }

      /* path info */
      ssSetModelName(rts, "bala_06");
      ssSetPath(rts, "Batterymodel_HiL/Inports_Balance /bala_06");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn44.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.bala_06_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.bala_06_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.bala_06_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.bala_06_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S4>/bala_07 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[45];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn45.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn45.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn45.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[45]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[45]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[45]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [45]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn45.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.bala_07));
        }
      }

      /* path info */
      ssSetModelName(rts, "bala_07");
      ssSetPath(rts, "Batterymodel_HiL/Inports_Balance /bala_07");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn45.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.bala_07_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.bala_07_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.bala_07_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.bala_07_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S4>/bala_08 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[46];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn46.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn46.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn46.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[46]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[46]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[46]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [46]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn46.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.bala_08));
        }
      }

      /* path info */
      ssSetModelName(rts, "bala_08");
      ssSetPath(rts, "Batterymodel_HiL/Inports_Balance /bala_08");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn46.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.bala_08_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.bala_08_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.bala_08_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.bala_08_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S4>/bala_09 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[47];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn47.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn47.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn47.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[47]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[47]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[47]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [47]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn47.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.bala_09));
        }
      }

      /* path info */
      ssSetModelName(rts, "bala_09");
      ssSetPath(rts, "Batterymodel_HiL/Inports_Balance /bala_09");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn47.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.bala_09_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.bala_09_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.bala_09_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.bala_09_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S4>/bala_10 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[48];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn48.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn48.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn48.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[48]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[48]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[48]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [48]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn48.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.bala_10));
        }
      }

      /* path info */
      ssSetModelName(rts, "bala_10");
      ssSetPath(rts, "Batterymodel_HiL/Inports_Balance /bala_10");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn48.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.bala_10_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.bala_10_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.bala_10_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.bala_10_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S4>/bala_11 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[49];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn49.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn49.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn49.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[49]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[49]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[49]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [49]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn49.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.bala_11));
        }
      }

      /* path info */
      ssSetModelName(rts, "bala_11");
      ssSetPath(rts, "Batterymodel_HiL/Inports_Balance /bala_11");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn49.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.bala_11_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.bala_11_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.bala_11_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.bala_11_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S4>/bala_12 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[50];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn50.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn50.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn50.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[50]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[50]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[50]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [50]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn50.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.bala_12));
        }
      }

      /* path info */
      ssSetModelName(rts, "bala_12");
      ssSetPath(rts, "Batterymodel_HiL/Inports_Balance /bala_12");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn50.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.bala_12_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.bala_12_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.bala_12_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.bala_12_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S22>/bat_mode_system (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[51];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn51.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn51.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn51.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[51]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[51]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[51]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [51]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn51.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Batterymodel_HiL_B.bat_mode_system));
        }
      }

      /* path info */
      ssSetModelName(rts, "bat_mode_system");
      ssSetPath(rts, "Batterymodel_HiL/displays/Batteriestrom/bat_mode_system");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn51.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Batterymodel_HiL_P.bat_mode_system_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Batterymodel_HiL_P.bat_mode_system_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Batterymodel_HiL_P.bat_mode_system_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Batterymodel_HiL_P.bat_mode_system_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S22>/current_system (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[52];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn52.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn52.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn52.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[52]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[52]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[52]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [52]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn52.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Batterymodel_HiL_B.current_system));
        }
      }

      /* path info */
      ssSetModelName(rts, "current_system");
      ssSetPath(rts, "Batterymodel_HiL/displays/Batteriestrom/current_system");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn52.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Batterymodel_HiL_P.current_system_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Batterymodel_HiL_P.current_system_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Batterymodel_HiL_P.current_system_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Batterymodel_HiL_P.current_system_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S23>/SoC_Kalman (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[53];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn53.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn53.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn53.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[53]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[53]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[53]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [53]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn53.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Batterymodel_HiL_B.SoC_Kalman));
        }
      }

      /* path info */
      ssSetModelName(rts, "SoC_Kalman");
      ssSetPath(rts, "Batterymodel_HiL/displays/Vergleich SoC/SoC_Kalman");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn53.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.SoC_Kalman_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.SoC_Kalman_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.SoC_Kalman_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.SoC_Kalman_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S21>/voltage_system (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[54];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn54.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn54.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn54.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[54]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[54]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[54]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [54]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn54.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Batterymodel_HiL_B.voltage_system));
        }
      }

      /* path info */
      ssSetModelName(rts, "voltage_system");
      ssSetPath(rts, "Batterymodel_HiL/displays/Batteirespannung/voltage_system");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn54.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Batterymodel_HiL_P.voltage_system_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Batterymodel_HiL_P.voltage_system_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Batterymodel_HiL_P.voltage_system_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Batterymodel_HiL_P.voltage_system_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S9>/Mod_CAN_RS232_Com (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[55];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn55.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn55.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn55.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[55]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[55]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[55]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [55]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn55.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Batterymodel_HiL_P.Mod_CAN_RS232_Value);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Mod_CAN_RS232_Com");
      ssSetPath(rts, "Batterymodel_HiL/Inputs/Betriebsmodus/Mod_CAN_RS232_Com");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn55.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Batterymodel_HiL_P.Mod_CAN_RS232_Com_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Batterymodel_HiL_P.Mod_CAN_RS232_Com_P2_Size);
      }

      /* registration */
      LCOutport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S1>/CellT01 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[56];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn56.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn56.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn56.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[56]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[56]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[56]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [56]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn56.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellT01));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellT01");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cel_Temperatures/CellT01");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn56.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellT01_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellT01_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellT01_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellT01_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S1>/CellT02 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[57];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn57.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn57.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn57.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[57]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[57]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[57]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [57]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn57.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellT02));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellT02");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cel_Temperatures/CellT02");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn57.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellT02_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellT02_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellT02_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellT02_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S1>/CellT03 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[58];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn58.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn58.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn58.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[58]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[58]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[58]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [58]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn58.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellT03));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellT03");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cel_Temperatures/CellT03");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn58.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellT03_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellT03_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellT03_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellT03_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S1>/CellT04 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[59];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn59.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn59.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn59.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[59]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[59]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[59]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [59]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn59.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellT04));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellT04");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cel_Temperatures/CellT04");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn59.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellT04_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellT04_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellT04_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellT04_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S1>/CellT05 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[60];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn60.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn60.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn60.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[60]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[60]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[60]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [60]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn60.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellT05));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellT05");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cel_Temperatures/CellT05");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn60.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellT05_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellT05_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellT05_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellT05_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S1>/CellT06 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[61];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn61.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn61.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn61.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[61]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[61]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[61]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [61]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn61.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellT06));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellT06");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cel_Temperatures/CellT06");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn61.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellT06_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellT06_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellT06_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellT06_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S1>/CellT07 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[62];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn62.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn62.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn62.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[62]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[62]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[62]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [62]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn62.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellT07));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellT07");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cel_Temperatures/CellT07");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn62.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellT07_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellT07_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellT07_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellT07_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S1>/CellT08 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[63];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn63.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn63.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn63.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[63]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[63]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[63]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [63]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn63.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellT08));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellT08");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cel_Temperatures/CellT08");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn63.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellT08_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellT08_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellT08_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellT08_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S1>/CellT09 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[64];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn64.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn64.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn64.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[64]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[64]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[64]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [64]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn64.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellT09));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellT09");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cel_Temperatures/CellT09");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn64.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellT09_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellT09_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellT09_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellT09_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S1>/CellT10 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[65];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn65.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn65.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn65.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[65]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[65]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[65]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [65]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn65.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellT10));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellT10");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cel_Temperatures/CellT10");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn65.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellT10_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellT10_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellT10_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellT10_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S1>/CellT11 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[66];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn66.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn66.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn66.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[66]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[66]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[66]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [66]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn66.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellT11));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellT11");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cel_Temperatures/CellT11");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn66.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellT11_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellT11_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellT11_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellT11_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S1>/CellT12 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[67];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn67.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn67.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn67.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[67]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[67]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[67]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [67]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn67.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellT12));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellT12");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cel_Temperatures/CellT12");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn67.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellT12_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellT12_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellT12_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellT12_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S2>/CellV01 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[68];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn68.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn68.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn68.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[68]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[68]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[68]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [68]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn68.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellV01));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellV01");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cell_Voltage/CellV01");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn68.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellV01_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellV01_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellV01_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellV01_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S2>/CellV02 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[69];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn69.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn69.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn69.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[69]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[69]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[69]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [69]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn69.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellV02));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellV02");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cell_Voltage/CellV02");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn69.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellV02_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellV02_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellV02_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellV02_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S2>/CellV03 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[70];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn70.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn70.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn70.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[70]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[70]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[70]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [70]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn70.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellV03));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellV03");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cell_Voltage/CellV03");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn70.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellV03_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellV03_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellV03_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellV03_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S2>/CellV04 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[71];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn71.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn71.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn71.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[71]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[71]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[71]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [71]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn71.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellV04));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellV04");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cell_Voltage/CellV04");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn71.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellV04_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellV04_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellV04_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellV04_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S2>/CellV05 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[72];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn72.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn72.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn72.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[72]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[72]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[72]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [72]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn72.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellV05));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellV05");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cell_Voltage/CellV05");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn72.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellV05_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellV05_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellV05_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellV05_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S2>/CellV06 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[73];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn73.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn73.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn73.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[73]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[73]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[73]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [73]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn73.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellV06));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellV06");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cell_Voltage/CellV06");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn73.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellV06_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellV06_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellV06_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellV06_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S2>/CellV07 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[74];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn74.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn74.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn74.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[74]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[74]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[74]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [74]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn74.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellV07));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellV07");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cell_Voltage/CellV07");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn74.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellV07_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellV07_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellV07_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellV07_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S2>/CellV08 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[75];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn75.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn75.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn75.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[75]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[75]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[75]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [75]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn75.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellV08));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellV08");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cell_Voltage/CellV08");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn75.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellV08_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellV08_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellV08_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellV08_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S2>/CellV09 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[76];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn76.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn76.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn76.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[76]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[76]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[76]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [76]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn76.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellV09));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellV09");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cell_Voltage/CellV09");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn76.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellV09_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellV09_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellV09_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellV09_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S2>/CellV10 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[77];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn77.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn77.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn77.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[77]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[77]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[77]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [77]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn77.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellV10));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellV10");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cell_Voltage/CellV10");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn77.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellV10_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellV10_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellV10_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellV10_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S2>/CellV11 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[78];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn78.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn78.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn78.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[78]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[78]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[78]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [78]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn78.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellV11));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellV11");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cell_Voltage/CellV11");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn78.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellV11_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellV11_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellV11_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellV11_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S2>/CellV12 (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[79];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn79.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn79.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn79.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[79]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[79]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[79]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [79]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn79.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Batterymodel_HiL_B.CellV12));
        }
      }

      /* path info */
      ssSetModelName(rts, "CellV12");
      ssSetPath(rts, "Batterymodel_HiL/Inports Cell_Voltage/CellV12");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn79.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.CellV12_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.CellV12_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.CellV12_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.CellV12_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S3>/Error_CellNo (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[80];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn80.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn80.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn80.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[80]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[80]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[80]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [80]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn80.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Batterymodel_HiL_B.Error_CellNo));
        }
      }

      /* path info */
      ssSetModelName(rts, "Error_CellNo");
      ssSetPath(rts, "Batterymodel_HiL/Inports Error/Error_CellNo");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn80.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Error_CellNo_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Error_CellNo_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.Error_CellNo_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.Error_CellNo_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S3>/Error_Event (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[81];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn81.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn81.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn81.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[81]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[81]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[81]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [81]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn81.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Batterymodel_HiL_B.Error_Event));
        }
      }

      /* path info */
      ssSetModelName(rts, "Error_Event");
      ssSetPath(rts, "Batterymodel_HiL/Inports Error/Error_Event");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn81.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Batterymodel_HiL_P.Error_Event_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Batterymodel_HiL_P.Error_Event_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Batterymodel_HiL_P.Error_Event_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Batterymodel_HiL_P.Error_Event_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Batterymodel_HiL/<S3>/Error_Indication (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[82];

      /* timing info */
      time_T *sfcnPeriod = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn82.sfcnPeriod;
      time_T *sfcnOffset = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn82.sfcnOffset;
      int_T *sfcnTsMap = Batterymodel_HiL_M->NonInlinedSFcns.Sfcn82.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Batterymodel_HiL_M->NonInlinedSFcns.blkInfo2[82]);
      }

      ssSetRTWSfcnInfo(rts, Batterymodel_HiL_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods2[82]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Batterymodel_HiL_M->NonInlinedSFcns.methods3[82]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Batterymodel_HiL_M->NonInlinedSFcns.statesInfo2
                         [82]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn82.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Batterymodel_HiL_B.Error_Indication));
        }
      }

      /* path info */
      ssSetModelName(rts, "Error_Indication");
      ssSetPath(rts, "Batterymodel_HiL/Inports Error/Error_Indication");
      ssSetRTModel(rts,Batterymodel_HiL_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Batterymodel_HiL_M->NonInlinedSFcns.Sfcn82.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Batterymodel_HiL_P.Error_Indication_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Batterymodel_HiL_P.Error_Indication_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Batterymodel_HiL_P.Error_Indication_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Batterymodel_HiL_P.Error_Indication_P4_Size);
      }

      /* registration */
      LCInport(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }
}

/* Model terminate function */
void Batterymodel_HiL_terminate(void)
{
  /* Level2 S-Function Block: '<S15>/Temp_01' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S15>/Temp_02' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S15>/Temp_03' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S15>/Temp_04' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S15>/Temp_05' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S15>/Temp_06' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S15>/Temp_07' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S15>/Temp_08' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S15>/Temp_09' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S15>/Temp_10' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S15>/Temp_11' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S15>/Temp_12' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/Curr_01' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/Curr_02' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[13];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/Curr_03' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[14];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/Curr_04' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[15];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/Curr_05' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[16];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/Curr_06' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[17];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/Curr_07' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[18];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/Curr_08' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[19];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/Curr_09' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[20];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/Curr_10' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[21];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/Curr_11' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[22];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/Curr_12' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[23];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S6>/bat_modus' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[24];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S6>/current [mA]' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[25];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/Volt_01' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[26];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/Volt_02' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[27];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/Volt_03' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[28];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/Volt_04' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[29];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/Volt_05' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[30];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/Volt_06' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[31];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/Volt_07' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[32];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/Volt_08' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[33];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/Volt_09' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[34];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/Volt_10' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[35];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/Volt_11' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[36];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/Volt_12' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[37];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S6>/voltage [mV]' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[38];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/bala_01' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[39];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/bala_02' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[40];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/bala_03' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[41];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/bala_04' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[42];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/bala_05' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[43];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/bala_06' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[44];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/bala_07' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[45];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/bala_08' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[46];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/bala_09' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[47];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/bala_10' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[48];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/bala_11' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[49];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/bala_12' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[50];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S22>/bat_mode_system' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[51];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S22>/current_system' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[52];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S23>/SoC_Kalman' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[53];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S21>/voltage_system' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[54];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/Mod_CAN_RS232_Com' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[55];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/CellT01' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[56];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/CellT02' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[57];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/CellT03' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[58];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/CellT04' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[59];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/CellT05' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[60];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/CellT06' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[61];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/CellT07' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[62];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/CellT08' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[63];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/CellT09' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[64];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/CellT10' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[65];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/CellT11' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[66];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/CellT12' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[67];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/CellV01' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[68];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/CellV02' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[69];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/CellV03' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[70];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/CellV04' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[71];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/CellV05' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[72];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/CellV06' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[73];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/CellV07' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[74];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/CellV08' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[75];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/CellV09' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[76];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/CellV10' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[77];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/CellV11' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[78];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/CellV12' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[79];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/Error_CellNo' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[80];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/Error_Event' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[81];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/Error_Indication' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[82];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Batterymodel_HiL_output(tid);
}

void MdlUpdate(int_T tid)
{
  Batterymodel_HiL_update(tid);
}

void MdlInitializeSizes(void)
{
  Batterymodel_HiL_M->Sizes.numContStates = (0);/* Number of continuous states */
  Batterymodel_HiL_M->Sizes.numY = (0);/* Number of model outputs */
  Batterymodel_HiL_M->Sizes.numU = (0);/* Number of model inputs */
  Batterymodel_HiL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Batterymodel_HiL_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Batterymodel_HiL_M->Sizes.numBlocks = (163);/* Number of blocks */
  Batterymodel_HiL_M->Sizes.numBlockIO = (90);/* Number of block outputs */
  Batterymodel_HiL_M->Sizes.numBlockPrms = (2118);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  {
    int32_T i;

    /* Level2 S-Function Block: '<S15>/Temp_01' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[0];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S15>/Temp_02' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[1];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S15>/Temp_03' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[2];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S15>/Temp_04' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[3];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S15>/Temp_05' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[4];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S15>/Temp_06' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[5];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S15>/Temp_07' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[6];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S15>/Temp_08' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[7];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S15>/Temp_09' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[8];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S15>/Temp_10' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[9];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S15>/Temp_11' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[10];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S15>/Temp_12' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[11];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S14>/Curr_01' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[12];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S14>/Curr_02' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[13];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S14>/Curr_03' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[14];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S14>/Curr_04' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[15];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S14>/Curr_05' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[16];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S14>/Curr_06' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[17];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S14>/Curr_07' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[18];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S14>/Curr_08' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[19];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S14>/Curr_09' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[20];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S14>/Curr_10' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[21];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S14>/Curr_11' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[22];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S14>/Curr_12' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[23];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S6>/bat_modus' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[24];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S6>/current [mA]' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[25];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S13>/Volt_01' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[26];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S13>/Volt_02' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[27];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S13>/Volt_03' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[28];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S13>/Volt_04' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[29];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S13>/Volt_05' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[30];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S13>/Volt_06' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[31];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S13>/Volt_07' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[32];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S13>/Volt_08' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[33];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S13>/Volt_09' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[34];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S13>/Volt_10' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[35];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S13>/Volt_11' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[36];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S13>/Volt_12' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[37];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S6>/voltage [mV]' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[38];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* InitializeConditions for UnitDelay: '<S18>/Unit Delay' */
    for (i = 0; i < 12; i++) {
      Batterymodel_HiL_DWork.UnitDelay_DSTATE[i] =
        Batterymodel_HiL_P.UnitDelay_X0;
    }

    /* End of InitializeConditions for UnitDelay: '<S18>/Unit Delay' */
    /* Level2 S-Function Block: '<S4>/bala_01' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[39];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S4>/bala_02' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[40];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S4>/bala_03' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[41];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S4>/bala_04' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[42];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S4>/bala_05' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[43];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S4>/bala_06' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[44];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S4>/bala_07' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[45];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S4>/bala_08' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[46];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S4>/bala_09' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[47];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S4>/bala_10' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[48];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S4>/bala_11' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[49];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S4>/bala_12' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[50];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    for (i = 0; i < 12; i++) {
      /* InitializeConditions for UnitDelay: '<S20>/Unit Delay1' */
      Batterymodel_HiL_DWork.UnitDelay1_DSTATE[i] =
        Batterymodel_HiL_P.UnitDelay1_X0;

      /* InitializeConditions for UnitDelay: '<S20>/Unit Delay' */
      Batterymodel_HiL_DWork.UnitDelay_DSTATE_n[i] =
        Batterymodel_HiL_P.UnitDelay_X0_n;

      /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
      Batterymodel_HiL_DWork.UnitDelay_DSTATE_l[i] =
        Batterymodel_HiL_P.UnitDelay_X0_k;

      /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
      Batterymodel_HiL_DWork.DiscreteTimeIntegrator_DSTATE[i] =
        Batterymodel_HiL_P.DiscreteTimeIntegrator_IC;
    }

    /* Level2 S-Function Block: '<S22>/bat_mode_system' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[51];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S22>/current_system' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[52];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S23>/SoC_Kalman' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[53];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S21>/voltage_system' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[54];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S9>/Mod_CAN_RS232_Com' (LCOutport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[55];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S1>/CellT01' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[56];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S1>/CellT02' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[57];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S1>/CellT03' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[58];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S1>/CellT04' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[59];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S1>/CellT05' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[60];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S1>/CellT06' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[61];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S1>/CellT07' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[62];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S1>/CellT08' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[63];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S1>/CellT09' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[64];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S1>/CellT10' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[65];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S1>/CellT11' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[66];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S1>/CellT12' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[67];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S2>/CellV01' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[68];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S2>/CellV02' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[69];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S2>/CellV03' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[70];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S2>/CellV04' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[71];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S2>/CellV05' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[72];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S2>/CellV06' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[73];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S2>/CellV07' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[74];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S2>/CellV08' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[75];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S2>/CellV09' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[76];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S2>/CellV10' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[77];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S2>/CellV11' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[78];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S2>/CellV12' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[79];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S3>/Error_CellNo' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[80];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S3>/Error_Event' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[81];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S3>/Error_Indication' (LCInport) */
    {
      SimStruct *rts = Batterymodel_HiL_M->childSfunctions[82];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }
}

void MdlStart(void)
{
  /* Start for FromWorkspace: '<S11>/FromWs' */
  {
    static real_T pTimeValues[] = { 0.0, 50.0, 50.0, 100.0, 100.0, 110.0, 110.0,
      150.0, 150.0, 180.0, 180.0, 200.0, 200.0, 220.0, 220.0, 300.0 } ;

    static real_T pDataValues[] = { 0.0, -2.0, -2.0, -2.5, -2.5, 0.5, 0.5, -1.0,
      -1.0, -0.5, -0.5, -2.0, -2.0, 1.0, 1.0, -1.0 } ;

    Batterymodel_HiL_DWork.FromWs_PWORK.TimePtr = (void *) pTimeValues;
    Batterymodel_HiL_DWork.FromWs_PWORK.DataPtr = (void *) pDataValues;
    Batterymodel_HiL_DWork.FromWs_IWORK.PrevIndex = 0;
  }

  /* Level2 S-Function Block: '<S15>/Temp_01' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_02' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_03' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_04' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_05' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_06' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_07' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_08' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_09' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_10' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_11' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[10];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S15>/Temp_12' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[11];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_01' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[12];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_02' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[13];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_03' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[14];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_04' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[15];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_05' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[16];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_06' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[17];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_07' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[18];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_08' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[19];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_09' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[20];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_10' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[21];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_11' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[22];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/Curr_12' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[23];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S6>/bat_modus' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[24];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S6>/current [mA]' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[25];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_01' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[26];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_02' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[27];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_03' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[28];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_04' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[29];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_05' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[30];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_06' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[31];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_07' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[32];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_08' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[33];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_09' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[34];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_10' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[35];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_11' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[36];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S13>/Volt_12' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[37];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S6>/voltage [mV]' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[38];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_01' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[39];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_02' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[40];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_03' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[41];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_04' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[42];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_05' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[43];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_06' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[44];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_07' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[45];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_08' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[46];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_09' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[47];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_10' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[48];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_11' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[49];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/bala_12' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[50];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S22>/bat_mode_system' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[51];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S22>/current_system' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[52];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S23>/SoC_Kalman' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[53];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S21>/voltage_system' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[54];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S9>/Mod_CAN_RS232_Com' (LCOutport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[55];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT01' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[56];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT02' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[57];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT03' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[58];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT04' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[59];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT05' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[60];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT06' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[61];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT07' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[62];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT08' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[63];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT09' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[64];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT10' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[65];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT11' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[66];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/CellT12' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[67];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV01' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[68];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV02' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[69];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV03' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[70];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV04' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[71];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV05' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[72];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV06' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[73];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV07' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[74];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV08' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[75];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV09' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[76];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV10' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[77];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV11' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[78];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/CellV12' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[79];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S3>/Error_CellNo' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[80];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S3>/Error_Event' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[81];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S3>/Error_Indication' (LCInport) */
  {
    SimStruct *rts = Batterymodel_HiL_M->childSfunctions[82];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  MdlInitialize();

  /* Enable for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  Batterymodel_HiL_DWork.DiscreteTimeIntegrator_SYSTEM_E = 1U;
}

void MdlTerminate(void)
{
  Batterymodel_HiL_terminate();
}

RT_MODEL_Batterymodel_HiL *Batterymodel_HiL(void)
{
  Batterymodel_HiL_initialize(1);
  return Batterymodel_HiL_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
