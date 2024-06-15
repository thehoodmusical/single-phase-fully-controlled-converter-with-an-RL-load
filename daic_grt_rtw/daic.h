/*
 * daic.h
 *
 * Code generation for model "daic".
 *
 * Model version              : 1.22
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Sun Aug  6 09:52:21 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_daic_h_
#define RTW_HEADER_daic_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef daic_COMMON_INCLUDES_
#define daic_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* daic_COMMON_INCLUDES_ */

#include "daic_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Delay24;                      /* '<Root>/Delay24' */
  real_T Sum67;                        /* '<Root>/Sum67' */
  real_T Delay22;                      /* '<Root>/Delay22' */
  real_T Delay23;                      /* '<Root>/Delay23' */
  real_T Gain54;                       /* '<Root>/Gain54' */
  real_T Sum72;                        /* '<Root>/Sum72' */
  real_T Sum73;                        /* '<Root>/Sum73' */
  real_T Gain51;                       /* '<Root>/Gain51' */
  real_T Sum70;                        /* '<Root>/Sum70' */
  real_T Derivative14;                 /* '<Root>/Derivative14' */
  real_T Delay30;                      /* '<Root>/Delay30' */
  real_T Sum87;                        /* '<Root>/Sum87' */
  real_T Delay28;                      /* '<Root>/Delay28' */
  real_T Delay29;                      /* '<Root>/Delay29' */
  real_T Gain69;                       /* '<Root>/Gain69' */
  real_T Sum92;                        /* '<Root>/Sum92' */
  real_T Sum93;                        /* '<Root>/Sum93' */
  real_T Gain66;                       /* '<Root>/Gain66' */
  real_T Sum90;                        /* '<Root>/Sum90' */
  real_T Derivative20;                 /* '<Root>/Derivative20' */
} B_daic_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay24_DSTATE;               /* '<Root>/Delay24' */
  real_T Delay22_DSTATE;               /* '<Root>/Delay22' */
  real_T Delay23_DSTATE;               /* '<Root>/Delay23' */
  real_T Delay30_DSTATE;               /* '<Root>/Delay30' */
  real_T Delay28_DSTATE;               /* '<Root>/Delay28' */
  real_T Delay29_DSTATE;               /* '<Root>/Delay29' */
  real_T TimeStampA;                   /* '<Root>/Derivative17' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative17' */
  real_T TimeStampB;                   /* '<Root>/Derivative17' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative17' */
  real_T TimeStampA_m;                 /* '<Root>/Derivative22' */
  real_T LastUAtTimeA_h;               /* '<Root>/Derivative22' */
  real_T TimeStampB_c;                 /* '<Root>/Derivative22' */
  real_T LastUAtTimeB_e;               /* '<Root>/Derivative22' */
  real_T TimeStampA_c;                 /* '<Root>/Derivative14' */
  real_T LastUAtTimeA_o;               /* '<Root>/Derivative14' */
  real_T TimeStampB_j;                 /* '<Root>/Derivative14' */
  real_T LastUAtTimeB_h;               /* '<Root>/Derivative14' */
  real_T TimeStampA_e;                 /* '<Root>/Derivative21' */
  real_T LastUAtTimeA_k;               /* '<Root>/Derivative21' */
  real_T TimeStampB_e;                 /* '<Root>/Derivative21' */
  real_T LastUAtTimeB_a;               /* '<Root>/Derivative21' */
  real_T TimeStampA_h;                 /* '<Root>/Derivative20' */
  real_T LastUAtTimeA_i;               /* '<Root>/Derivative20' */
  real_T TimeStampB_f;                 /* '<Root>/Derivative20' */
  real_T LastUAtTimeB_l;               /* '<Root>/Derivative20' */
} DW_daic_T;

/* Parameters (default storage) */
struct P_daic_T_ {
  real_T Delay24_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<Root>/Delay24'
                                        */
  real_T Constant40_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant40'
                                        */
  real_T SineWave10_Amp;               /* Expression: 0.005
                                        * Referenced by: '<Root>/Sine Wave10'
                                        */
  real_T SineWave10_Bias;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave10'
                                        */
  real_T SineWave10_Freq;              /* Expression: pi/2
                                        * Referenced by: '<Root>/Sine Wave10'
                                        */
  real_T SineWave10_Phase;             /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave10'
                                        */
  real_T SineWave17_Amp;               /* Expression: 0.1
                                        * Referenced by: '<Root>/Sine Wave17'
                                        */
  real_T SineWave17_Bias;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave17'
                                        */
  real_T SineWave17_Freq;              /* Expression: pi/2
                                        * Referenced by: '<Root>/Sine Wave17'
                                        */
  real_T SineWave17_Phase;             /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave17'
                                        */
  real_T Delay22_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<Root>/Delay22'
                                        */
  real_T Constant32_Value;             /* Expression: 0.5
                                        * Referenced by: '<Root>/Constant32'
                                        */
  real_T Delay23_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<Root>/Delay23'
                                        */
  real_T Gain54_Gain;                  /* Expression: 3000
                                        * Referenced by: '<Root>/Gain54'
                                        */
  real_T Constant41_Value;             /* Expression: 20
                                        * Referenced by: '<Root>/Constant41'
                                        */
  real_T Gain73_Gain;                  /* Expression: 30
                                        * Referenced by: '<Root>/Gain73'
                                        */
  real_T Gain74_Gain;                  /* Expression: 1.5
                                        * Referenced by: '<Root>/Gain74'
                                        */
  real_T Gain56_Gain;                  /* Expression: 1/60
                                        * Referenced by: '<Root>/Gain56'
                                        */
  real_T Constant44_Value;             /* Expression: 60
                                        * Referenced by: '<Root>/Constant44'
                                        */
  real_T Gain51_Gain;                  /* Expression: 2
                                        * Referenced by: '<Root>/Gain51'
                                        */
  real_T Gain55_Gain;                  /* Expression: 2
                                        * Referenced by: '<Root>/Gain55'
                                        */
  real_T Gain52_Gain;                  /* Expression: 0.005
                                        * Referenced by: '<Root>/Gain52'
                                        */
  real_T Gain53_Gain;                  /* Expression: 0.005
                                        * Referenced by: '<Root>/Gain53'
                                        */
  real_T Delay30_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<Root>/Delay30'
                                        */
  real_T Constant51_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant51'
                                        */
  real_T SineWave20_Amp;               /* Expression: 0.005
                                        * Referenced by: '<Root>/Sine Wave20'
                                        */
  real_T SineWave20_Bias;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave20'
                                        */
  real_T SineWave20_Freq;              /* Expression: pi/2
                                        * Referenced by: '<Root>/Sine Wave20'
                                        */
  real_T SineWave20_Phase;             /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave20'
                                        */
  real_T SineWave19_Amp;               /* Expression: 0.1
                                        * Referenced by: '<Root>/Sine Wave19'
                                        */
  real_T SineWave19_Bias;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave19'
                                        */
  real_T SineWave19_Freq;              /* Expression: pi/2
                                        * Referenced by: '<Root>/Sine Wave19'
                                        */
  real_T SineWave19_Phase;             /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave19'
                                        */
  real_T Delay28_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<Root>/Delay28'
                                        */
  real_T Constant53_Value;             /* Expression: 0.1
                                        * Referenced by: '<Root>/Constant53'
                                        */
  real_T Delay29_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<Root>/Delay29'
                                        */
  real_T Gain69_Gain;                  /* Expression: 3000
                                        * Referenced by: '<Root>/Gain69'
                                        */
  real_T Constant52_Value;             /* Expression: 20
                                        * Referenced by: '<Root>/Constant52'
                                        */
  real_T Gain71_Gain;                  /* Expression: 1/60
                                        * Referenced by: '<Root>/Gain71'
                                        */
  real_T Constant54_Value;             /* Expression: 60
                                        * Referenced by: '<Root>/Constant54'
                                        */
  real_T Gain66_Gain;                  /* Expression: 2
                                        * Referenced by: '<Root>/Gain66'
                                        */
  real_T Gain70_Gain;                  /* Expression: 2
                                        * Referenced by: '<Root>/Gain70'
                                        */
  real_T Gain67_Gain;                  /* Expression: 0.005
                                        * Referenced by: '<Root>/Gain67'
                                        */
  real_T Gain68_Gain;                  /* Expression: 0.005
                                        * Referenced by: '<Root>/Gain68'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_daic_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_daic_T daic_P;

/* Block signals (default storage) */
extern B_daic_T daic_B;

/* Block states (default storage) */
extern DW_daic_T daic_DW;

/* Model entry point functions */
extern void daic_initialize(void);
extern void daic_step(void);
extern void daic_terminate(void);

/* Real-time Model object */
extern RT_MODEL_daic_T *const daic_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'daic'
 * '<S1>'   : 'daic/Ramp10'
 * '<S2>'   : 'daic/Ramp7'
 */
#endif                                 /* RTW_HEADER_daic_h_ */
