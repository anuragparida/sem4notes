/*
 * DCM_measurementMdl_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(void*),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&DCM_measurementMdl_B.Out), 0, 0, 5 },

  { (char_T *)(&DCM_measurementMdl_B.FixPtSwitch), 3, 0, 1 }
  ,

  { (char_T *)(&DCM_measurementMdl_DW.AnalogOutput_PWORK), 11, 0, 5 },

  { (char_T *)(&DCM_measurementMdl_DW.Output_DSTATE), 3, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  4U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&DCM_measurementMdl_P.AnalogOutput_FinalValue), 0, 0, 13 },

  { (char_T *)(&DCM_measurementMdl_P.AnalogOutput_Channels), 6, 0, 8 },

  { (char_T *)(&DCM_measurementMdl_P.LimitedCounter_uplimit), 3, 0, 1 },

  { (char_T *)(&DCM_measurementMdl_P.ukPA_Gain), 0, 0, 4 },

  { (char_T *)(&DCM_measurementMdl_P.Constant_Value), 3, 0, 3 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] DCM_measurementMdl_dt.h */
