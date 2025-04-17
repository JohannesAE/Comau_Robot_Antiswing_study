#include "sg.h"

/* Storage class 'PageSwitching' */
sg_cal_type sg_cal_impl = {
  /* Mask Parameter: PID1_I
   * Referenced by: '<S37>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PID2_I
   * Referenced by: '<S85>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PID1_InitialConditionForIntegra
   * Referenced by: '<S40>/Integrator'
   */
  0.0,

  /* Mask Parameter: PID2_InitialConditionForIntegra
   * Referenced by: '<S88>/Integrator'
   */
  0.0,

  /* Mask Parameter: PID1_P
   * Referenced by: '<S45>/Proportional Gain'
   */
  0.01,

  /* Mask Parameter: PID2_P
   * Referenced by: '<S93>/Proportional Gain'
   */
  0.01,

  /* Expression: 3
   * Referenced by: '<Root>/Constant2'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S40>/Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_f
   * Referenced by: '<S88>/Integrator'
   */
  0.001,

  /* Expression: single(0)
   * Referenced by: '<Root>/Zero'
   */
  0.0F,

  /* Computed Parameter: Saturation2_UpperSat
   * Referenced by: '<Root>/Saturation2'
   */
  0.4F,

  /* Computed Parameter: Saturation2_LowerSat
   * Referenced by: '<Root>/Saturation2'
   */
  -0.4F,

  /* Computed Parameter: Saturation3_UpperSat
   * Referenced by: '<Root>/Saturation3'
   */
  0.4F,

  /* Computed Parameter: Saturation3_LowerSat
   * Referenced by: '<Root>/Saturation3'
   */
  -0.4F,

  /* Expression: single(0)
   * Referenced by: '<S1>/Constant'
   */
  0.0F,

  /* Expression: single(0)
   * Referenced by: '<S1>/Constant2'
   */
  0.0F,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<S1>/Delay'
   */
  0U,

  /* Computed Parameter: Constant1_Value_o
   * Referenced by: '<S1>/Constant1'
   */
  1U,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<Root>/Gain'
   */
  16777,

  /* Computed Parameter: UDPSend_toPort
   * Referenced by: '<Root>/UDP Send'
   */
  50050U,

  /* Computed Parameter: UDPReceive1_fmAddress
   * Referenced by: '<Root>/UDP Receive1'
   */
  { 192U, 168U, 80U, 10U },

  /* Computed Parameter: UDPSend_toAddress
   * Referenced by: '<Root>/UDP Send'
   */
  { 192U, 168U, 90U, 50U },

  /* Computed Parameter: UDPReceive_fmAddress
   * Referenced by: '<Root>/UDP Receive'
   */
  { 192U, 168U, 90U, 50U }
};

sg_cal_type *sg_cal = &sg_cal_impl;
