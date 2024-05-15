/*
 * DCM_Mdl_Validation_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DCM_Mdl_Validation".
 *
 * Model version              : 6.3
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Thu May  2 18:00:53 2024
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DCM_Mdl_Validation.h"
#include "DCM_Mdl_Validation_private.h"

/* Block parameters (default storage) */
P_DCM_Mdl_Validation_T DCM_Mdl_Validation_P = {
  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output'
   */
  10.0,

  /* Mask Parameter: AnalogInput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Input'
   */
  10.0,

  /* Mask Parameter: RepeatingSequenceStair_OutValues
   * Referenced by: '<S1>/Vector'
   */
  { 0.0, 3.0, 6.0, 9.0, 12.0, 15.0, 18.0, 21.0, 24.0, 27.0, 30.0 },

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogInput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_Channels
   * Referenced by: '<Root>/Analog Input'
   */
  { 0, 1, 2 },

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_RangeMode
   * Referenced by: '<Root>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_VoltRange
   * Referenced by: '<Root>/Analog Input'
   */
  0,

  /* Mask Parameter: LimitedCounter_uplimit
   * Referenced by: '<S5>/FixPt Switch'
   */
  10U,

  /* Expression: 1/4.2
   * Referenced by: '<Root>/1//kPA'
   */
  0.23809523809523808,

  /* Expression: 4
   * Referenced by: '<Root>/1//kCS'
   */
  4.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator'
   */
  0.0,

  /* Expression: 300
   * Referenced by: '<Root>/1//kTG'
   */
  300.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator1'
   */
  0.0,

  /* Expression: 30/pi
   * Referenced by: '<S2>/Gain1'
   */
  9.5492965855137211,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 0.1269
   * Referenced by: '<S2>/KG1'
   */
  0.1269,

  /* Expression: 0.0002407
   * Referenced by: '<S2>/Gain2'
   */
  0.0002407,

  /* Expression: 0.03945
   * Referenced by: '<S2>/Gain3'
   */
  0.03945,

  /* Expression: 1/0.00438
   * Referenced by: '<S2>/1//J'
   */
  228.31050228310502,

  /* Expression: 0.1269
   * Referenced by: '<S2>/KG'
   */
  0.1269,

  /* Expression: 5/2.9
   * Referenced by: '<S2>/Ra'
   */
  1.7241379310344829,

  /* Expression: 1/0.00862
   * Referenced by: '<S2>/Gain'
   */
  116.00928074245941,

  /* Computed Parameter: Constant_Value_k
   * Referenced by: '<S5>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S3>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S4>/FixPt Constant'
   */
  1U
};
