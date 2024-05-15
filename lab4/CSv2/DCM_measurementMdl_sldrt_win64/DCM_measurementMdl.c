/*
 * DCM_measurementMdl.c
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
#include "DCM_measurementMdl_dt.h"

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
B_DCM_measurementMdl_T DCM_measurementMdl_B;

/* Block states (default storage) */
DW_DCM_measurementMdl_T DCM_measurementMdl_DW;

/* Real-time model */
static RT_MODEL_DCM_measurementMdl_T DCM_measurementMdl_M_;
RT_MODEL_DCM_measurementMdl_T *const DCM_measurementMdl_M =
  &DCM_measurementMdl_M_;
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
  (DCM_measurementMdl_M->Timing.TaskCounters.TID[1])++;
  if ((DCM_measurementMdl_M->Timing.TaskCounters.TID[1]) > 2999) {/* Sample time: [3.0s, 0.0s] */
    DCM_measurementMdl_M->Timing.TaskCounters.TID[1] = 0;
  }

  DCM_measurementMdl_M->Timing.sampleHits[1] =
    (DCM_measurementMdl_M->Timing.TaskCounters.TID[1] == 0);
}

/* Model output function */
void DCM_measurementMdl_output(void)
{
  /* local block i/o variables */
  real_T rtb_AnalogInput[3];
  uint8_T rtb_Output_d;
  if (DCM_measurementMdl_M->Timing.TaskCounters.TID[1] == 0) {
    /* UnitDelay: '<S2>/Output' */
    rtb_Output_d = DCM_measurementMdl_DW.Output_DSTATE;

    /* SignalConversion: '<S1>/Out' incorporates:
     *  Constant: '<S1>/Vector'
     *  MultiPortSwitch: '<S1>/Output'
     *  UnitDelay: '<S2>/Output'
     */
    DCM_measurementMdl_B.Out =
      DCM_measurementMdl_P.RepeatingSequenceStair_OutValues[DCM_measurementMdl_DW.Output_DSTATE];

    /* Gain: '<Root>/1//kPA' */
    DCM_measurementMdl_B.ukPA = DCM_measurementMdl_P.ukPA_Gain *
      DCM_measurementMdl_B.Out;
  }

  /* S-Function (sldrtao): '<Root>/Analog Output' */
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) DCM_measurementMdl_P.AnalogOutput_RangeMode;
      parm.rangeidx = DCM_measurementMdl_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &DCM_measurementMdl_P.AnalogOutput_Channels, ((real_T*)
        (&DCM_measurementMdl_B.ukPA)), &parm);
    }
  }

  /* S-Function (sldrtai): '<Root>/Analog Input' */
  /* S-Function Block: <Root>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) DCM_measurementMdl_P.AnalogInput_RangeMode;
    parm.rangeidx = DCM_measurementMdl_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 3,
                   DCM_measurementMdl_P.AnalogInput_Channels, &rtb_AnalogInput[0],
                   &parm);
  }

  /* Gain: '<Root>/1//kVS' */
  DCM_measurementMdl_B.ukVS = DCM_measurementMdl_P.ukVS_Gain * rtb_AnalogInput[0];

  /* Gain: '<Root>/1//kCS' */
  DCM_measurementMdl_B.ukCS = DCM_measurementMdl_P.ukCS_Gain * rtb_AnalogInput[1];

  /* Gain: '<Root>/1//kTG' */
  DCM_measurementMdl_B.ukTG = DCM_measurementMdl_P.ukTG_Gain * rtb_AnalogInput[2];
  if (DCM_measurementMdl_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S3>/FixPt Sum1' incorporates:
     *  Constant: '<S3>/FixPt Constant'
     */
    rtb_Output_d = (uint8_T)((uint32_T)rtb_Output_d +
      DCM_measurementMdl_P.FixPtConstant_Value);

    /* Switch: '<S4>/FixPt Switch' */
    if (rtb_Output_d > DCM_measurementMdl_P.LimitedCounter_uplimit) {
      /* Switch: '<S4>/FixPt Switch' incorporates:
       *  Constant: '<S4>/Constant'
       */
      DCM_measurementMdl_B.FixPtSwitch = DCM_measurementMdl_P.Constant_Value;
    } else {
      /* Switch: '<S4>/FixPt Switch' */
      DCM_measurementMdl_B.FixPtSwitch = rtb_Output_d;
    }

    /* End of Switch: '<S4>/FixPt Switch' */
  }
}

/* Model update function */
void DCM_measurementMdl_update(void)
{
  if (DCM_measurementMdl_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S2>/Output' */
    DCM_measurementMdl_DW.Output_DSTATE = DCM_measurementMdl_B.FixPtSwitch;
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
  if (!(++DCM_measurementMdl_M->Timing.clockTick0)) {
    ++DCM_measurementMdl_M->Timing.clockTickH0;
  }

  DCM_measurementMdl_M->Timing.t[0] = DCM_measurementMdl_M->Timing.clockTick0 *
    DCM_measurementMdl_M->Timing.stepSize0 +
    DCM_measurementMdl_M->Timing.clockTickH0 *
    DCM_measurementMdl_M->Timing.stepSize0 * 4294967296.0;
  if (DCM_measurementMdl_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [3.0s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++DCM_measurementMdl_M->Timing.clockTick1)) {
      ++DCM_measurementMdl_M->Timing.clockTickH1;
    }

    DCM_measurementMdl_M->Timing.t[1] = DCM_measurementMdl_M->Timing.clockTick1 *
      DCM_measurementMdl_M->Timing.stepSize1 +
      DCM_measurementMdl_M->Timing.clockTickH1 *
      DCM_measurementMdl_M->Timing.stepSize1 * 4294967296.0;
  }

  rate_scheduler();
}

/* Model initialize function */
void DCM_measurementMdl_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) DCM_measurementMdl_P.AnalogOutput_RangeMode;
      parm.rangeidx = DCM_measurementMdl_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &DCM_measurementMdl_P.AnalogOutput_Channels,
                     &DCM_measurementMdl_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for UnitDelay: '<S2>/Output' */
  DCM_measurementMdl_DW.Output_DSTATE =
    DCM_measurementMdl_P.Output_InitialCondition;
}

/* Model terminate function */
void DCM_measurementMdl_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) DCM_measurementMdl_P.AnalogOutput_RangeMode;
      parm.rangeidx = DCM_measurementMdl_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &DCM_measurementMdl_P.AnalogOutput_Channels,
                     &DCM_measurementMdl_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  DCM_measurementMdl_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  DCM_measurementMdl_update();
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
  DCM_measurementMdl_initialize();
}

void MdlTerminate(void)
{
  DCM_measurementMdl_terminate();
}

/* Registration function */
RT_MODEL_DCM_measurementMdl_T *DCM_measurementMdl(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)DCM_measurementMdl_M, 0,
                sizeof(RT_MODEL_DCM_measurementMdl_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = DCM_measurementMdl_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    DCM_measurementMdl_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    DCM_measurementMdl_M->Timing.sampleTimes =
      (&DCM_measurementMdl_M->Timing.sampleTimesArray[0]);
    DCM_measurementMdl_M->Timing.offsetTimes =
      (&DCM_measurementMdl_M->Timing.offsetTimesArray[0]);

    /* task periods */
    DCM_measurementMdl_M->Timing.sampleTimes[0] = (0.001);
    DCM_measurementMdl_M->Timing.sampleTimes[1] = (3.0);

    /* task offsets */
    DCM_measurementMdl_M->Timing.offsetTimes[0] = (0.0);
    DCM_measurementMdl_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(DCM_measurementMdl_M, &DCM_measurementMdl_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = DCM_measurementMdl_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    DCM_measurementMdl_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(DCM_measurementMdl_M, 40.0);
  DCM_measurementMdl_M->Timing.stepSize0 = 0.001;
  DCM_measurementMdl_M->Timing.stepSize1 = 3.0;

  /* External mode info */
  DCM_measurementMdl_M->Sizes.checksums[0] = (74917817U);
  DCM_measurementMdl_M->Sizes.checksums[1] = (2422490601U);
  DCM_measurementMdl_M->Sizes.checksums[2] = (2685198218U);
  DCM_measurementMdl_M->Sizes.checksums[3] = (1169488868U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    DCM_measurementMdl_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(DCM_measurementMdl_M->extModeInfo,
      &DCM_measurementMdl_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DCM_measurementMdl_M->extModeInfo,
                        DCM_measurementMdl_M->Sizes.checksums);
    rteiSetTPtr(DCM_measurementMdl_M->extModeInfo, rtmGetTPtr
                (DCM_measurementMdl_M));
  }

  DCM_measurementMdl_M->solverInfoPtr = (&DCM_measurementMdl_M->solverInfo);
  DCM_measurementMdl_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&DCM_measurementMdl_M->solverInfo, 0.001);
  rtsiSetSolverMode(&DCM_measurementMdl_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  DCM_measurementMdl_M->blockIO = ((void *) &DCM_measurementMdl_B);
  (void) memset(((void *) &DCM_measurementMdl_B), 0,
                sizeof(B_DCM_measurementMdl_T));

  {
    DCM_measurementMdl_B.Out = 0.0;
    DCM_measurementMdl_B.ukPA = 0.0;
    DCM_measurementMdl_B.ukVS = 0.0;
    DCM_measurementMdl_B.ukCS = 0.0;
    DCM_measurementMdl_B.ukTG = 0.0;
  }

  /* parameters */
  DCM_measurementMdl_M->defaultParam = ((real_T *)&DCM_measurementMdl_P);

  /* states (dwork) */
  DCM_measurementMdl_M->dwork = ((void *) &DCM_measurementMdl_DW);
  (void) memset((void *)&DCM_measurementMdl_DW, 0,
                sizeof(DW_DCM_measurementMdl_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    DCM_measurementMdl_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  DCM_measurementMdl_M->Sizes.numContStates = (0);/* Number of continuous states */
  DCM_measurementMdl_M->Sizes.numY = (0);/* Number of model outputs */
  DCM_measurementMdl_M->Sizes.numU = (0);/* Number of model inputs */
  DCM_measurementMdl_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  DCM_measurementMdl_M->Sizes.numSampTimes = (2);/* Number of sample times */
  DCM_measurementMdl_M->Sizes.numBlocks = (16);/* Number of blocks */
  DCM_measurementMdl_M->Sizes.numBlockIO = (6);/* Number of block outputs */
  DCM_measurementMdl_M->Sizes.numBlockPrms = (29);/* Sum of parameter "widths" */
  return DCM_measurementMdl_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
