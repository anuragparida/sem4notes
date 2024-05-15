/*
 * DCM_Mdl_Validation.c
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
#include "DCM_Mdl_Validation_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCIe-6321", 4294967295U, 7, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_DCM_Mdl_Validation_T DCM_Mdl_Validation_B;

/* Continuous states */
X_DCM_Mdl_Validation_T DCM_Mdl_Validation_X;

/* Block states (default storage) */
DW_DCM_Mdl_Validation_T DCM_Mdl_Validation_DW;

/* Real-time model */
static RT_MODEL_DCM_Mdl_Validation_T DCM_Mdl_Validation_M_;
RT_MODEL_DCM_Mdl_Validation_T *const DCM_Mdl_Validation_M =
  &DCM_Mdl_Validation_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (DCM_Mdl_Validation_M->Timing.TaskCounters.TID[2])++;
  if ((DCM_Mdl_Validation_M->Timing.TaskCounters.TID[2]) > 2999) {/* Sample time: [3.0s, 0.0s] */
    DCM_Mdl_Validation_M->Timing.TaskCounters.TID[2] = 0;
  }

  DCM_Mdl_Validation_M->Timing.sampleHits[2] =
    (DCM_Mdl_Validation_M->Timing.TaskCounters.TID[2] == 0);
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  DCM_Mdl_Validation_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void DCM_Mdl_Validation_output(void)
{
  /* local block i/o variables */
  real_T rtb_AnalogInput[3];
  real_T tmp;
  uint8_T rtb_Output_d;
  if (rtmIsMajorTimeStep(DCM_Mdl_Validation_M)) {
    /* set solver stop time */
    if (!(DCM_Mdl_Validation_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&DCM_Mdl_Validation_M->solverInfo,
                            ((DCM_Mdl_Validation_M->Timing.clockTickH0 + 1) *
        DCM_Mdl_Validation_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&DCM_Mdl_Validation_M->solverInfo,
                            ((DCM_Mdl_Validation_M->Timing.clockTick0 + 1) *
        DCM_Mdl_Validation_M->Timing.stepSize0 +
        DCM_Mdl_Validation_M->Timing.clockTickH0 *
        DCM_Mdl_Validation_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(DCM_Mdl_Validation_M)) {
    DCM_Mdl_Validation_M->Timing.t[0] = rtsiGetT
      (&DCM_Mdl_Validation_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(DCM_Mdl_Validation_M) &&
      DCM_Mdl_Validation_M->Timing.TaskCounters.TID[2] == 0) {
    /* UnitDelay: '<S3>/Output' */
    rtb_Output_d = DCM_Mdl_Validation_DW.Output_DSTATE;

    /* SignalConversion: '<S1>/Out' incorporates:
     *  Constant: '<S1>/Vector'
     *  MultiPortSwitch: '<S1>/Output'
     *  UnitDelay: '<S3>/Output'
     */
    DCM_Mdl_Validation_B.Out =
      DCM_Mdl_Validation_P.RepeatingSequenceStair_OutValues[DCM_Mdl_Validation_DW.Output_DSTATE];

    /* Gain: '<Root>/1//kPA' */
    DCM_Mdl_Validation_B.ukPA = DCM_Mdl_Validation_P.ukPA_Gain *
      DCM_Mdl_Validation_B.Out;
  }

  if (rtmIsMajorTimeStep(DCM_Mdl_Validation_M) &&
      DCM_Mdl_Validation_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) DCM_Mdl_Validation_P.AnalogOutput_RangeMode;
        parm.rangeidx = DCM_Mdl_Validation_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &DCM_Mdl_Validation_P.AnalogOutput_Channels, ((real_T*) (
          &DCM_Mdl_Validation_B.ukPA)), &parm);
      }
    }

    /* S-Function (sldrtai): '<Root>/Analog Input' */
    /* S-Function Block: <Root>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) DCM_Mdl_Validation_P.AnalogInput_RangeMode;
      parm.rangeidx = DCM_Mdl_Validation_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 3,
                     DCM_Mdl_Validation_P.AnalogInput_Channels,
                     &rtb_AnalogInput[0], &parm);
    }

    /* Gain: '<Root>/1//kCS' */
    DCM_Mdl_Validation_B.ukCS = DCM_Mdl_Validation_P.ukCS_Gain *
      rtb_AnalogInput[1];

    /* Gain: '<Root>/1//kTG' */
    DCM_Mdl_Validation_B.ukTG = DCM_Mdl_Validation_P.ukTG_Gain *
      rtb_AnalogInput[2];
  }

  /* Integrator: '<S2>/Integrator' */
  DCM_Mdl_Validation_B.Integrator = DCM_Mdl_Validation_X.Integrator_CSTATE;

  /* Gain: '<S2>/Gain1' incorporates:
   *  Integrator: '<S2>/Integrator1'
   */
  DCM_Mdl_Validation_B.Gain1 = DCM_Mdl_Validation_P.Gain1_Gain *
    DCM_Mdl_Validation_X.Integrator1_CSTATE;
  if (rtmIsMajorTimeStep(DCM_Mdl_Validation_M) &&
      DCM_Mdl_Validation_M->Timing.TaskCounters.TID[1] == 0) {
  }

  if (rtmIsMajorTimeStep(DCM_Mdl_Validation_M) &&
      DCM_Mdl_Validation_M->Timing.TaskCounters.TID[2] == 0) {
    /* Sum: '<S4>/FixPt Sum1' incorporates:
     *  Constant: '<S4>/FixPt Constant'
     */
    rtb_Output_d = (uint8_T)((uint32_T)rtb_Output_d +
      DCM_Mdl_Validation_P.FixPtConstant_Value);

    /* Switch: '<S5>/FixPt Switch' */
    if (rtb_Output_d > DCM_Mdl_Validation_P.LimitedCounter_uplimit) {
      /* Switch: '<S5>/FixPt Switch' incorporates:
       *  Constant: '<S5>/Constant'
       */
      DCM_Mdl_Validation_B.FixPtSwitch = DCM_Mdl_Validation_P.Constant_Value_k;
    } else {
      /* Switch: '<S5>/FixPt Switch' */
      DCM_Mdl_Validation_B.FixPtSwitch = rtb_Output_d;
    }

    /* End of Switch: '<S5>/FixPt Switch' */
  }

  /* Signum: '<S2>/Sign' incorporates:
   *  Integrator: '<S2>/Integrator1'
   */
  if (DCM_Mdl_Validation_X.Integrator1_CSTATE < 0.0) {
    tmp = -1.0;
  } else if (DCM_Mdl_Validation_X.Integrator1_CSTATE > 0.0) {
    tmp = 1.0;
  } else if (DCM_Mdl_Validation_X.Integrator1_CSTATE == 0.0) {
    tmp = 0.0;
  } else {
    tmp = (rtNaN);
  }

  /* End of Signum: '<S2>/Sign' */

  /* Gain: '<S2>/1//J' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<S2>/Gain2'
   *  Gain: '<S2>/Gain3'
   *  Gain: '<S2>/KG1'
   *  Integrator: '<S2>/Integrator1'
   *  Sum: '<S2>/Sum2'
   *  Sum: '<S2>/Sum3'
   */
  DCM_Mdl_Validation_B.uJ = ((DCM_Mdl_Validation_P.KG1_Gain *
    DCM_Mdl_Validation_B.Integrator - DCM_Mdl_Validation_P.Constant_Value) -
    (DCM_Mdl_Validation_P.Gain2_Gain * DCM_Mdl_Validation_X.Integrator1_CSTATE +
     DCM_Mdl_Validation_P.Gain3_Gain * tmp)) * DCM_Mdl_Validation_P.uJ_Gain;

  /* Gain: '<S2>/Gain' incorporates:
   *  Gain: '<S2>/KG'
   *  Gain: '<S2>/Ra'
   *  Integrator: '<S2>/Integrator1'
   *  Sum: '<S2>/Sum'
   *  Sum: '<S2>/Sum1'
   */
  DCM_Mdl_Validation_B.Gain = ((DCM_Mdl_Validation_B.Out -
    DCM_Mdl_Validation_P.KG_Gain * DCM_Mdl_Validation_X.Integrator1_CSTATE) -
    DCM_Mdl_Validation_P.Ra_Gain * DCM_Mdl_Validation_B.Integrator) *
    DCM_Mdl_Validation_P.Gain_Gain;
}

/* Model update function */
void DCM_Mdl_Validation_update(void)
{
  if (rtmIsMajorTimeStep(DCM_Mdl_Validation_M) &&
      DCM_Mdl_Validation_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for UnitDelay: '<S3>/Output' */
    DCM_Mdl_Validation_DW.Output_DSTATE = DCM_Mdl_Validation_B.FixPtSwitch;
  }

  if (rtmIsMajorTimeStep(DCM_Mdl_Validation_M)) {
    rt_ertODEUpdateContinuousStates(&DCM_Mdl_Validation_M->solverInfo);
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
  if (!(++DCM_Mdl_Validation_M->Timing.clockTick0)) {
    ++DCM_Mdl_Validation_M->Timing.clockTickH0;
  }

  DCM_Mdl_Validation_M->Timing.t[0] = rtsiGetSolverStopTime
    (&DCM_Mdl_Validation_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++DCM_Mdl_Validation_M->Timing.clockTick1)) {
      ++DCM_Mdl_Validation_M->Timing.clockTickH1;
    }

    DCM_Mdl_Validation_M->Timing.t[1] = DCM_Mdl_Validation_M->Timing.clockTick1 *
      DCM_Mdl_Validation_M->Timing.stepSize1 +
      DCM_Mdl_Validation_M->Timing.clockTickH1 *
      DCM_Mdl_Validation_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(DCM_Mdl_Validation_M) &&
      DCM_Mdl_Validation_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [3.0s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++DCM_Mdl_Validation_M->Timing.clockTick2)) {
      ++DCM_Mdl_Validation_M->Timing.clockTickH2;
    }

    DCM_Mdl_Validation_M->Timing.t[2] = DCM_Mdl_Validation_M->Timing.clockTick2 *
      DCM_Mdl_Validation_M->Timing.stepSize2 +
      DCM_Mdl_Validation_M->Timing.clockTickH2 *
      DCM_Mdl_Validation_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void DCM_Mdl_Validation_derivatives(void)
{
  XDot_DCM_Mdl_Validation_T *_rtXdot;
  _rtXdot = ((XDot_DCM_Mdl_Validation_T *) DCM_Mdl_Validation_M->derivs);

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE = DCM_Mdl_Validation_B.Gain;

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = DCM_Mdl_Validation_B.uJ;
}

/* Model initialize function */
void DCM_Mdl_Validation_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) DCM_Mdl_Validation_P.AnalogOutput_RangeMode;
      parm.rangeidx = DCM_Mdl_Validation_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &DCM_Mdl_Validation_P.AnalogOutput_Channels,
                     &DCM_Mdl_Validation_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for UnitDelay: '<S3>/Output' */
  DCM_Mdl_Validation_DW.Output_DSTATE =
    DCM_Mdl_Validation_P.Output_InitialCondition;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  DCM_Mdl_Validation_X.Integrator_CSTATE = DCM_Mdl_Validation_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator1' */
  DCM_Mdl_Validation_X.Integrator1_CSTATE = DCM_Mdl_Validation_P.Integrator1_IC;
}

/* Model terminate function */
void DCM_Mdl_Validation_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) DCM_Mdl_Validation_P.AnalogOutput_RangeMode;
      parm.rangeidx = DCM_Mdl_Validation_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &DCM_Mdl_Validation_P.AnalogOutput_Channels,
                     &DCM_Mdl_Validation_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  DCM_Mdl_Validation_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  DCM_Mdl_Validation_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  DCM_Mdl_Validation_initialize();
}

void MdlTerminate(void)
{
  DCM_Mdl_Validation_terminate();
}

/* Registration function */
RT_MODEL_DCM_Mdl_Validation_T *DCM_Mdl_Validation(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)DCM_Mdl_Validation_M, 0,
                sizeof(RT_MODEL_DCM_Mdl_Validation_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&DCM_Mdl_Validation_M->solverInfo,
                          &DCM_Mdl_Validation_M->Timing.simTimeStep);
    rtsiSetTPtr(&DCM_Mdl_Validation_M->solverInfo, &rtmGetTPtr
                (DCM_Mdl_Validation_M));
    rtsiSetStepSizePtr(&DCM_Mdl_Validation_M->solverInfo,
                       &DCM_Mdl_Validation_M->Timing.stepSize0);
    rtsiSetdXPtr(&DCM_Mdl_Validation_M->solverInfo,
                 &DCM_Mdl_Validation_M->derivs);
    rtsiSetContStatesPtr(&DCM_Mdl_Validation_M->solverInfo, (real_T **)
                         &DCM_Mdl_Validation_M->contStates);
    rtsiSetNumContStatesPtr(&DCM_Mdl_Validation_M->solverInfo,
      &DCM_Mdl_Validation_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&DCM_Mdl_Validation_M->solverInfo,
      &DCM_Mdl_Validation_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&DCM_Mdl_Validation_M->solverInfo,
      &DCM_Mdl_Validation_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&DCM_Mdl_Validation_M->solverInfo,
      &DCM_Mdl_Validation_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&DCM_Mdl_Validation_M->solverInfo, (&rtmGetErrorStatus
      (DCM_Mdl_Validation_M)));
    rtsiSetRTModelPtr(&DCM_Mdl_Validation_M->solverInfo, DCM_Mdl_Validation_M);
  }

  rtsiSetSimTimeStep(&DCM_Mdl_Validation_M->solverInfo, MAJOR_TIME_STEP);
  DCM_Mdl_Validation_M->intgData.f[0] = DCM_Mdl_Validation_M->odeF[0];
  DCM_Mdl_Validation_M->contStates = ((real_T *) &DCM_Mdl_Validation_X);
  rtsiSetSolverData(&DCM_Mdl_Validation_M->solverInfo, (void *)
                    &DCM_Mdl_Validation_M->intgData);
  rtsiSetSolverName(&DCM_Mdl_Validation_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = DCM_Mdl_Validation_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    DCM_Mdl_Validation_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    DCM_Mdl_Validation_M->Timing.sampleTimes =
      (&DCM_Mdl_Validation_M->Timing.sampleTimesArray[0]);
    DCM_Mdl_Validation_M->Timing.offsetTimes =
      (&DCM_Mdl_Validation_M->Timing.offsetTimesArray[0]);

    /* task periods */
    DCM_Mdl_Validation_M->Timing.sampleTimes[0] = (0.0);
    DCM_Mdl_Validation_M->Timing.sampleTimes[1] = (0.001);
    DCM_Mdl_Validation_M->Timing.sampleTimes[2] = (3.0);

    /* task offsets */
    DCM_Mdl_Validation_M->Timing.offsetTimes[0] = (0.0);
    DCM_Mdl_Validation_M->Timing.offsetTimes[1] = (0.0);
    DCM_Mdl_Validation_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(DCM_Mdl_Validation_M, &DCM_Mdl_Validation_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = DCM_Mdl_Validation_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    DCM_Mdl_Validation_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(DCM_Mdl_Validation_M, 33.0);
  DCM_Mdl_Validation_M->Timing.stepSize0 = 0.001;
  DCM_Mdl_Validation_M->Timing.stepSize1 = 0.001;
  DCM_Mdl_Validation_M->Timing.stepSize2 = 3.0;

  /* External mode info */
  DCM_Mdl_Validation_M->Sizes.checksums[0] = (2980701743U);
  DCM_Mdl_Validation_M->Sizes.checksums[1] = (1678432419U);
  DCM_Mdl_Validation_M->Sizes.checksums[2] = (4202857359U);
  DCM_Mdl_Validation_M->Sizes.checksums[3] = (254472297U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    DCM_Mdl_Validation_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(DCM_Mdl_Validation_M->extModeInfo,
      &DCM_Mdl_Validation_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DCM_Mdl_Validation_M->extModeInfo,
                        DCM_Mdl_Validation_M->Sizes.checksums);
    rteiSetTPtr(DCM_Mdl_Validation_M->extModeInfo, rtmGetTPtr
                (DCM_Mdl_Validation_M));
  }

  DCM_Mdl_Validation_M->solverInfoPtr = (&DCM_Mdl_Validation_M->solverInfo);
  DCM_Mdl_Validation_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&DCM_Mdl_Validation_M->solverInfo, 0.001);
  rtsiSetSolverMode(&DCM_Mdl_Validation_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  DCM_Mdl_Validation_M->blockIO = ((void *) &DCM_Mdl_Validation_B);
  (void) memset(((void *) &DCM_Mdl_Validation_B), 0,
                sizeof(B_DCM_Mdl_Validation_T));

  {
    DCM_Mdl_Validation_B.Out = 0.0;
    DCM_Mdl_Validation_B.ukPA = 0.0;
    DCM_Mdl_Validation_B.ukCS = 0.0;
    DCM_Mdl_Validation_B.Integrator = 0.0;
    DCM_Mdl_Validation_B.ukTG = 0.0;
    DCM_Mdl_Validation_B.Gain1 = 0.0;
    DCM_Mdl_Validation_B.uJ = 0.0;
    DCM_Mdl_Validation_B.Gain = 0.0;
  }

  /* parameters */
  DCM_Mdl_Validation_M->defaultParam = ((real_T *)&DCM_Mdl_Validation_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &DCM_Mdl_Validation_X;
    DCM_Mdl_Validation_M->contStates = (x);
    (void) memset((void *)&DCM_Mdl_Validation_X, 0,
                  sizeof(X_DCM_Mdl_Validation_T));
  }

  /* states (dwork) */
  DCM_Mdl_Validation_M->dwork = ((void *) &DCM_Mdl_Validation_DW);
  (void) memset((void *)&DCM_Mdl_Validation_DW, 0,
                sizeof(DW_DCM_Mdl_Validation_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    DCM_Mdl_Validation_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  DCM_Mdl_Validation_M->Sizes.numContStates = (2);/* Number of continuous states */
  DCM_Mdl_Validation_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  DCM_Mdl_Validation_M->Sizes.numY = (0);/* Number of model outputs */
  DCM_Mdl_Validation_M->Sizes.numU = (0);/* Number of model inputs */
  DCM_Mdl_Validation_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  DCM_Mdl_Validation_M->Sizes.numSampTimes = (3);/* Number of sample times */
  DCM_Mdl_Validation_M->Sizes.numBlocks = (31);/* Number of blocks */
  DCM_Mdl_Validation_M->Sizes.numBlockIO = (9);/* Number of block outputs */
  DCM_Mdl_Validation_M->Sizes.numBlockPrms = (43);/* Sum of parameter "widths" */
  return DCM_Mdl_Validation_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
