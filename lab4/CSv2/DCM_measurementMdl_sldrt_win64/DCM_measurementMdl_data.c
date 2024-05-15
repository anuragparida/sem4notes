/*
 * DCM_measurementMdl_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DCM_measurementMdl".
 *
 * Model version              : 6.2
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Thu May  2 14:55:08 2024
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DCM_measurementMdl.h"
#include "DCM_measurementMdl_private.h"

/* Block parameters (default storage) */
P_DCM_measurementMdl_T DCM_measurementMdl_P = {
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
  { 0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0 },

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
   * Referenced by: '<S4>/FixPt Switch'
   */
  6U,

  /* Expression: 1/4.2
   * Referenced by: '<Root>/1//kPA'
   */
  0.23809523809523808,

  /* Expression: 5
   * Referenced by: '<Root>/1//kVS'
   */
  5.0,

  /* Expression: 4
   * Referenced by: '<Root>/1//kCS'
   */
  4.0,

  /* Expression: 300
   * Referenced by: '<Root>/1//kTG'
   */
  300.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S4>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S2>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S3>/FixPt Constant'
   */
  1U
};
