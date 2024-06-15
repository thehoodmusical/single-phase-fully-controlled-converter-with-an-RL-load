/*
 * daic.c
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

#include "daic.h"
#include "daic_private.h"

/* Block signals (default storage) */
B_daic_T daic_B;

/* Block states (default storage) */
DW_daic_T daic_DW;

/* Real-time model */
static RT_MODEL_daic_T daic_M_;
RT_MODEL_daic_T *const daic_M = &daic_M_;

/* Model step function */
void daic_step(void)
{
  {
    real_T Sum67_tmp;
    real_T rtb_Derivative21;
    real_T rtb_SineWave19;
    real_T tmp;
    real_T *lastU;

    /* Delay: '<Root>/Delay24' */
    daic_B.Delay24 = daic_DW.Delay24_DSTATE;

    /* Sin: '<Root>/Sine Wave10' incorporates:
     *  Sin: '<Root>/Sine Wave17'
     *  Sin: '<Root>/Sine Wave19'
     *  Sin: '<Root>/Sine Wave20'
     */
    Sum67_tmp = daic_M->Timing.t[0];

    /* Sum: '<Root>/Sum67' incorporates:
     *  Sin: '<Root>/Sine Wave10'
     *  Sin: '<Root>/Sine Wave17'
     */
    daic_B.Sum67 = (sin(daic_P.SineWave10_Freq * Sum67_tmp +
                        daic_P.SineWave10_Phase) * daic_P.SineWave10_Amp +
                    daic_P.SineWave10_Bias) + (sin(daic_P.SineWave17_Freq *
      Sum67_tmp + daic_P.SineWave17_Phase) * daic_P.SineWave17_Amp +
      daic_P.SineWave17_Bias);

    /* Derivative: '<Root>/Derivative17' incorporates:
     *  Derivative: '<Root>/Derivative14'
     *  Derivative: '<Root>/Derivative20'
     *  Derivative: '<Root>/Derivative21'
     *  Derivative: '<Root>/Derivative22'
     */
    tmp = daic_M->Timing.t[0];
    if ((daic_DW.TimeStampA >= tmp) && (daic_DW.TimeStampB >= tmp)) {
      rtb_Derivative21 = 0.0;
    } else {
      rtb_SineWave19 = daic_DW.TimeStampA;
      lastU = &daic_DW.LastUAtTimeA;
      if (daic_DW.TimeStampA < daic_DW.TimeStampB) {
        if (daic_DW.TimeStampB < tmp) {
          rtb_SineWave19 = daic_DW.TimeStampB;
          lastU = &daic_DW.LastUAtTimeB;
        }
      } else {
        if (daic_DW.TimeStampA >= tmp) {
          rtb_SineWave19 = daic_DW.TimeStampB;
          lastU = &daic_DW.LastUAtTimeB;
        }
      }

      rtb_Derivative21 = (daic_B.Sum67 - *lastU) / (tmp - rtb_SineWave19);
    }

    /* End of Derivative: '<Root>/Derivative17' */

    /* Delay: '<Root>/Delay22' */
    daic_B.Delay22 = daic_DW.Delay22_DSTATE;

    /* Delay: '<Root>/Delay23' */
    daic_B.Delay23 = daic_DW.Delay23_DSTATE;

    /* Gain: '<Root>/Gain54' incorporates:
     *  Sum: '<Root>/Sum71'
     */
    daic_B.Gain54 = (daic_B.Sum67 - daic_B.Delay23) * daic_P.Gain54_Gain;

    /* Sum: '<Root>/Sum72' incorporates:
     *  Constant: '<Root>/Constant41'
     */
    daic_B.Sum72 = daic_B.Gain54 - daic_P.Constant41_Value;

    /* Derivative: '<Root>/Derivative22' */
    if ((daic_DW.TimeStampA_m >= tmp) && (daic_DW.TimeStampB_c >= tmp)) {
      rtb_SineWave19 = 0.0;
    } else {
      rtb_SineWave19 = daic_DW.TimeStampA_m;
      lastU = &daic_DW.LastUAtTimeA_h;
      if (daic_DW.TimeStampA_m < daic_DW.TimeStampB_c) {
        if (daic_DW.TimeStampB_c < tmp) {
          rtb_SineWave19 = daic_DW.TimeStampB_c;
          lastU = &daic_DW.LastUAtTimeB_e;
        }
      } else {
        if (daic_DW.TimeStampA_m >= tmp) {
          rtb_SineWave19 = daic_DW.TimeStampB_c;
          lastU = &daic_DW.LastUAtTimeB_e;
        }
      }

      rtb_SineWave19 = (daic_B.Sum72 - *lastU) / (tmp - rtb_SineWave19);
    }

    /* Abs: '<Root>/Abs5' */
    rtb_SineWave19 = fabs(rtb_SineWave19);

    /* Sum: '<Root>/Sum73' incorporates:
     *  Abs: '<Root>/Abs4'
     *  Constant: '<Root>/Constant32'
     *  Gain: '<Root>/Gain56'
     *  Gain: '<Root>/Gain73'
     *  Gain: '<Root>/Gain74'
     *  Product: '<Root>/Divide4'
     *  Product: '<Root>/Product22'
     *  Sum: '<Root>/Sum94'
     *  UnaryMinus: '<Root>/Unary Minus7'
     */
    daic_B.Sum73 = daic_P.Constant32_Value / (daic_P.Gain73_Gain * fabs
      (daic_B.Sum72) + daic_P.Gain74_Gain * rtb_SineWave19) *
      (daic_P.Gain56_Gain * -daic_B.Sum72) + daic_B.Delay22;

    /* Gain: '<Root>/Gain51' incorporates:
     *  Constant: '<Root>/Constant44'
     */
    daic_B.Gain51 = daic_P.Gain51_Gain * daic_P.Constant44_Value;

    /* Sum: '<Root>/Sum70' incorporates:
     *  Constant: '<Root>/Constant40'
     *  Gain: '<Root>/Gain52'
     *  Gain: '<Root>/Gain53'
     *  Gain: '<Root>/Gain55'
     *  Product: '<Root>/Product21'
     *  Sum: '<Root>/Sum66'
     *  Sum: '<Root>/Sum68'
     *  Sum: '<Root>/Sum69'
     */
    daic_B.Sum70 = (((((rtb_Derivative21 - daic_B.Delay24) - daic_B.Sum73) *
                      daic_B.Gain51 + daic_P.Constant40_Value) +
                     daic_P.Gain55_Gain * daic_B.Sum72) * daic_P.Gain52_Gain +
                    daic_B.Delay24) * daic_P.Gain53_Gain + daic_B.Delay23;

    /* Derivative: '<Root>/Derivative14' */
    if ((daic_DW.TimeStampA_c >= tmp) && (daic_DW.TimeStampB_j >= tmp)) {
      /* Derivative: '<Root>/Derivative14' */
      daic_B.Derivative14 = 0.0;
    } else {
      rtb_SineWave19 = daic_DW.TimeStampA_c;
      lastU = &daic_DW.LastUAtTimeA_o;
      if (daic_DW.TimeStampA_c < daic_DW.TimeStampB_j) {
        if (daic_DW.TimeStampB_j < tmp) {
          rtb_SineWave19 = daic_DW.TimeStampB_j;
          lastU = &daic_DW.LastUAtTimeB_h;
        }
      } else {
        if (daic_DW.TimeStampA_c >= tmp) {
          rtb_SineWave19 = daic_DW.TimeStampB_j;
          lastU = &daic_DW.LastUAtTimeB_h;
        }
      }

      /* Derivative: '<Root>/Derivative14' */
      daic_B.Derivative14 = (daic_B.Sum70 - *lastU) / (tmp - rtb_SineWave19);
    }

    /* Delay: '<Root>/Delay30' */
    daic_B.Delay30 = daic_DW.Delay30_DSTATE;

    /* Sum: '<Root>/Sum87' incorporates:
     *  Sin: '<Root>/Sine Wave19'
     *  Sin: '<Root>/Sine Wave20'
     */
    daic_B.Sum87 = (sin(daic_P.SineWave20_Freq * Sum67_tmp +
                        daic_P.SineWave20_Phase) * daic_P.SineWave20_Amp +
                    daic_P.SineWave20_Bias) + (sin(daic_P.SineWave19_Freq *
      Sum67_tmp + daic_P.SineWave19_Phase) * daic_P.SineWave19_Amp +
      daic_P.SineWave19_Bias);

    /* Derivative: '<Root>/Derivative21' */
    if ((daic_DW.TimeStampA_e >= tmp) && (daic_DW.TimeStampB_e >= tmp)) {
      rtb_Derivative21 = 0.0;
    } else {
      rtb_SineWave19 = daic_DW.TimeStampA_e;
      lastU = &daic_DW.LastUAtTimeA_k;
      if (daic_DW.TimeStampA_e < daic_DW.TimeStampB_e) {
        if (daic_DW.TimeStampB_e < tmp) {
          rtb_SineWave19 = daic_DW.TimeStampB_e;
          lastU = &daic_DW.LastUAtTimeB_a;
        }
      } else {
        if (daic_DW.TimeStampA_e >= tmp) {
          rtb_SineWave19 = daic_DW.TimeStampB_e;
          lastU = &daic_DW.LastUAtTimeB_a;
        }
      }

      rtb_Derivative21 = (daic_B.Sum87 - *lastU) / (tmp - rtb_SineWave19);
    }

    /* Delay: '<Root>/Delay28' */
    daic_B.Delay28 = daic_DW.Delay28_DSTATE;

    /* Delay: '<Root>/Delay29' */
    daic_B.Delay29 = daic_DW.Delay29_DSTATE;

    /* Gain: '<Root>/Gain69' incorporates:
     *  Sum: '<Root>/Sum91'
     */
    daic_B.Gain69 = (daic_B.Sum87 - daic_B.Delay29) * daic_P.Gain69_Gain;

    /* Sum: '<Root>/Sum92' incorporates:
     *  Constant: '<Root>/Constant52'
     */
    daic_B.Sum92 = daic_B.Gain69 - daic_P.Constant52_Value;

    /* Sum: '<Root>/Sum93' incorporates:
     *  Constant: '<Root>/Constant53'
     *  Gain: '<Root>/Gain71'
     *  Product: '<Root>/Product27'
     *  UnaryMinus: '<Root>/Unary Minus9'
     */
    daic_B.Sum93 = daic_P.Gain71_Gain * -daic_B.Sum92 * daic_P.Constant53_Value
      + daic_B.Delay28;

    /* Gain: '<Root>/Gain66' incorporates:
     *  Constant: '<Root>/Constant54'
     */
    daic_B.Gain66 = daic_P.Gain66_Gain * daic_P.Constant54_Value;

    /* Sum: '<Root>/Sum90' incorporates:
     *  Constant: '<Root>/Constant51'
     *  Gain: '<Root>/Gain67'
     *  Gain: '<Root>/Gain68'
     *  Gain: '<Root>/Gain70'
     *  Product: '<Root>/Product26'
     *  Sum: '<Root>/Sum86'
     *  Sum: '<Root>/Sum88'
     *  Sum: '<Root>/Sum89'
     */
    daic_B.Sum90 = (((((rtb_Derivative21 - daic_B.Delay30) - daic_B.Sum93) *
                      daic_B.Gain66 + daic_P.Constant51_Value) +
                     daic_P.Gain70_Gain * daic_B.Sum92) * daic_P.Gain67_Gain +
                    daic_B.Delay30) * daic_P.Gain68_Gain + daic_B.Delay29;

    /* Derivative: '<Root>/Derivative20' */
    if ((daic_DW.TimeStampA_h >= tmp) && (daic_DW.TimeStampB_f >= tmp)) {
      /* Derivative: '<Root>/Derivative20' */
      daic_B.Derivative20 = 0.0;
    } else {
      rtb_SineWave19 = daic_DW.TimeStampA_h;
      lastU = &daic_DW.LastUAtTimeA_i;
      if (daic_DW.TimeStampA_h < daic_DW.TimeStampB_f) {
        if (daic_DW.TimeStampB_f < tmp) {
          rtb_SineWave19 = daic_DW.TimeStampB_f;
          lastU = &daic_DW.LastUAtTimeB_l;
        }
      } else {
        if (daic_DW.TimeStampA_h >= tmp) {
          rtb_SineWave19 = daic_DW.TimeStampB_f;
          lastU = &daic_DW.LastUAtTimeB_l;
        }
      }

      /* Derivative: '<Root>/Derivative20' */
      daic_B.Derivative20 = (daic_B.Sum90 - *lastU) / (tmp - rtb_SineWave19);
    }
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(daic_M->rtwLogInfo, (daic_M->Timing.t));

  {
    real_T *lastU;

    /* Update for Delay: '<Root>/Delay24' */
    daic_DW.Delay24_DSTATE = daic_B.Derivative14;

    /* Update for Derivative: '<Root>/Derivative17' */
    if (daic_DW.TimeStampA == (rtInf)) {
      daic_DW.TimeStampA = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeA;
    } else if (daic_DW.TimeStampB == (rtInf)) {
      daic_DW.TimeStampB = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeB;
    } else if (daic_DW.TimeStampA < daic_DW.TimeStampB) {
      daic_DW.TimeStampA = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeA;
    } else {
      daic_DW.TimeStampB = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeB;
    }

    *lastU = daic_B.Sum67;

    /* End of Update for Derivative: '<Root>/Derivative17' */

    /* Update for Delay: '<Root>/Delay22' */
    daic_DW.Delay22_DSTATE = daic_B.Sum73;

    /* Update for Delay: '<Root>/Delay23' */
    daic_DW.Delay23_DSTATE = daic_B.Sum70;

    /* Update for Derivative: '<Root>/Derivative22' */
    if (daic_DW.TimeStampA_m == (rtInf)) {
      daic_DW.TimeStampA_m = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeA_h;
    } else if (daic_DW.TimeStampB_c == (rtInf)) {
      daic_DW.TimeStampB_c = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeB_e;
    } else if (daic_DW.TimeStampA_m < daic_DW.TimeStampB_c) {
      daic_DW.TimeStampA_m = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeA_h;
    } else {
      daic_DW.TimeStampB_c = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeB_e;
    }

    *lastU = daic_B.Sum72;

    /* End of Update for Derivative: '<Root>/Derivative22' */

    /* Update for Derivative: '<Root>/Derivative14' */
    if (daic_DW.TimeStampA_c == (rtInf)) {
      daic_DW.TimeStampA_c = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeA_o;
    } else if (daic_DW.TimeStampB_j == (rtInf)) {
      daic_DW.TimeStampB_j = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeB_h;
    } else if (daic_DW.TimeStampA_c < daic_DW.TimeStampB_j) {
      daic_DW.TimeStampA_c = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeA_o;
    } else {
      daic_DW.TimeStampB_j = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeB_h;
    }

    *lastU = daic_B.Sum70;

    /* End of Update for Derivative: '<Root>/Derivative14' */

    /* Update for Delay: '<Root>/Delay30' */
    daic_DW.Delay30_DSTATE = daic_B.Derivative20;

    /* Update for Derivative: '<Root>/Derivative21' */
    if (daic_DW.TimeStampA_e == (rtInf)) {
      daic_DW.TimeStampA_e = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeA_k;
    } else if (daic_DW.TimeStampB_e == (rtInf)) {
      daic_DW.TimeStampB_e = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeB_a;
    } else if (daic_DW.TimeStampA_e < daic_DW.TimeStampB_e) {
      daic_DW.TimeStampA_e = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeA_k;
    } else {
      daic_DW.TimeStampB_e = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeB_a;
    }

    *lastU = daic_B.Sum87;

    /* End of Update for Derivative: '<Root>/Derivative21' */

    /* Update for Delay: '<Root>/Delay28' */
    daic_DW.Delay28_DSTATE = daic_B.Sum93;

    /* Update for Delay: '<Root>/Delay29' */
    daic_DW.Delay29_DSTATE = daic_B.Sum90;

    /* Update for Derivative: '<Root>/Derivative20' */
    if (daic_DW.TimeStampA_h == (rtInf)) {
      daic_DW.TimeStampA_h = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeA_i;
    } else if (daic_DW.TimeStampB_f == (rtInf)) {
      daic_DW.TimeStampB_f = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeB_l;
    } else if (daic_DW.TimeStampA_h < daic_DW.TimeStampB_f) {
      daic_DW.TimeStampA_h = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeA_i;
    } else {
      daic_DW.TimeStampB_f = daic_M->Timing.t[0];
      lastU = &daic_DW.LastUAtTimeB_l;
    }

    *lastU = daic_B.Sum90;

    /* End of Update for Derivative: '<Root>/Derivative20' */
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(daic_M)!=-1) &&
        !((rtmGetTFinal(daic_M)-daic_M->Timing.t[0]) > daic_M->Timing.t[0] *
          (DBL_EPSILON))) {
      rtmSetErrorStatus(daic_M, "Simulation finished");
    }
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
  if (!(++daic_M->Timing.clockTick0)) {
    ++daic_M->Timing.clockTickH0;
  }

  daic_M->Timing.t[0] = daic_M->Timing.clockTick0 * daic_M->Timing.stepSize0 +
    daic_M->Timing.clockTickH0 * daic_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    daic_M->Timing.clockTick1++;
    if (!daic_M->Timing.clockTick1) {
      daic_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void daic_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)daic_M, 0,
                sizeof(RT_MODEL_daic_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&daic_M->solverInfo, &daic_M->Timing.simTimeStep);
    rtsiSetTPtr(&daic_M->solverInfo, &rtmGetTPtr(daic_M));
    rtsiSetStepSizePtr(&daic_M->solverInfo, &daic_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&daic_M->solverInfo, (&rtmGetErrorStatus(daic_M)));
    rtsiSetRTModelPtr(&daic_M->solverInfo, daic_M);
  }

  rtsiSetSimTimeStep(&daic_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&daic_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(daic_M, &daic_M->Timing.tArray[0]);
  rtmSetTFinal(daic_M, 5.0);
  daic_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    daic_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(daic_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(daic_M->rtwLogInfo, (NULL));
    rtliSetLogT(daic_M->rtwLogInfo, "tout");
    rtliSetLogX(daic_M->rtwLogInfo, "");
    rtliSetLogXFinal(daic_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(daic_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(daic_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(daic_M->rtwLogInfo, 0);
    rtliSetLogDecimation(daic_M->rtwLogInfo, 1);
    rtliSetLogY(daic_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(daic_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(daic_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &daic_B), 0,
                sizeof(B_daic_T));

  /* states (dwork) */
  (void) memset((void *)&daic_DW, 0,
                sizeof(DW_daic_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(daic_M->rtwLogInfo, 0.0, rtmGetTFinal(daic_M),
    daic_M->Timing.stepSize0, (&rtmGetErrorStatus(daic_M)));

  /* InitializeConditions for Delay: '<Root>/Delay24' */
  daic_DW.Delay24_DSTATE = daic_P.Delay24_InitialCondition;

  /* InitializeConditions for Derivative: '<Root>/Derivative17' */
  daic_DW.TimeStampA = (rtInf);
  daic_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Delay: '<Root>/Delay22' */
  daic_DW.Delay22_DSTATE = daic_P.Delay22_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay23' */
  daic_DW.Delay23_DSTATE = daic_P.Delay23_InitialCondition;

  /* InitializeConditions for Derivative: '<Root>/Derivative22' */
  daic_DW.TimeStampA_m = (rtInf);
  daic_DW.TimeStampB_c = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative14' */
  daic_DW.TimeStampA_c = (rtInf);
  daic_DW.TimeStampB_j = (rtInf);

  /* InitializeConditions for Delay: '<Root>/Delay30' */
  daic_DW.Delay30_DSTATE = daic_P.Delay30_InitialCondition;

  /* InitializeConditions for Derivative: '<Root>/Derivative21' */
  daic_DW.TimeStampA_e = (rtInf);
  daic_DW.TimeStampB_e = (rtInf);

  /* InitializeConditions for Delay: '<Root>/Delay28' */
  daic_DW.Delay28_DSTATE = daic_P.Delay28_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay29' */
  daic_DW.Delay29_DSTATE = daic_P.Delay29_InitialCondition;

  /* InitializeConditions for Derivative: '<Root>/Derivative20' */
  daic_DW.TimeStampA_h = (rtInf);
  daic_DW.TimeStampB_f = (rtInf);
}

/* Model terminate function */
void daic_terminate(void)
{
  /* (no terminate code required) */
}
