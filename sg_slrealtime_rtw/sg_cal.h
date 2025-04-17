#ifndef RTW_HEADER_sg_cal_h_
#define RTW_HEADER_sg_cal_h_
#include "rtwtypes.h"
#include "sg_types.h"

/* Storage class 'PageSwitching', for system '<Root>' */
struct sg_cal_type {
  real_T PID1_I;                       /* Mask Parameter: PID1_I
                                        * Referenced by: '<S37>/Integral Gain'
                                        */
  real_T PID2_I;                       /* Mask Parameter: PID2_I
                                        * Referenced by: '<S85>/Integral Gain'
                                        */
  real_T PID1_InitialConditionForIntegra;
                              /* Mask Parameter: PID1_InitialConditionForIntegra
                               * Referenced by: '<S40>/Integrator'
                               */
  real_T PID2_InitialConditionForIntegra;
                              /* Mask Parameter: PID2_InitialConditionForIntegra
                               * Referenced by: '<S88>/Integrator'
                               */
  real_T PID1_P;                       /* Mask Parameter: PID1_P
                                        * Referenced by: '<S45>/Proportional Gain'
                                        */
  real_T PID2_P;                       /* Mask Parameter: PID2_P
                                        * Referenced by: '<S93>/Proportional Gain'
                                        */
  real_T Constant2_Value;              /* Expression: 3
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S40>/Integrator'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Integrator_gainval_f;       /* Computed Parameter: Integrator_gainval_f
                                      * Referenced by: '<S88>/Integrator'
                                      */
  real32_T Zero_Value;                 /* Expression: single(0)
                                        * Referenced by: '<Root>/Zero'
                                        */
  real32_T Saturation2_UpperSat;     /* Computed Parameter: Saturation2_UpperSat
                                      * Referenced by: '<Root>/Saturation2'
                                      */
  real32_T Saturation2_LowerSat;     /* Computed Parameter: Saturation2_LowerSat
                                      * Referenced by: '<Root>/Saturation2'
                                      */
  real32_T Saturation3_UpperSat;     /* Computed Parameter: Saturation3_UpperSat
                                      * Referenced by: '<Root>/Saturation3'
                                      */
  real32_T Saturation3_LowerSat;     /* Computed Parameter: Saturation3_LowerSat
                                      * Referenced by: '<Root>/Saturation3'
                                      */
  real32_T Constant_Value_i;           /* Expression: single(0)
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T Constant2_Value_b;          /* Expression: single(0)
                                        * Referenced by: '<S1>/Constant2'
                                        */
  uint32_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S1>/Delay'
                                    */
  uint32_T Constant1_Value_o;          /* Computed Parameter: Constant1_Value_o
                                        * Referenced by: '<S1>/Constant1'
                                        */
  int16_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  uint16_T UDPSend_toPort;             /* Computed Parameter: UDPSend_toPort
                                        * Referenced by: '<Root>/UDP Send'
                                        */
  uint8_T UDPReceive1_fmAddress[4]; /* Computed Parameter: UDPReceive1_fmAddress
                                     * Referenced by: '<Root>/UDP Receive1'
                                     */
  uint8_T UDPSend_toAddress[4];        /* Computed Parameter: UDPSend_toAddress
                                        * Referenced by: '<Root>/UDP Send'
                                        */
  uint8_T UDPReceive_fmAddress[4];   /* Computed Parameter: UDPReceive_fmAddress
                                      * Referenced by: '<Root>/UDP Receive'
                                      */
};

/* Storage class 'PageSwitching' */
extern sg_cal_type sg_cal_impl;
extern sg_cal_type *sg_cal;

#endif                                 /* RTW_HEADER_sg_cal_h_ */
