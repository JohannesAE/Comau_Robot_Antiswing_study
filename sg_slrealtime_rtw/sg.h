/*
 * sg.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "sg".
 *
 * Model version              : 1.182
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Thu Apr 17 17:12:40 2025
 *
 * Target selection: slrealtime.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_sg_h_
#define RTW_HEADER_sg_h_
#include <cmath>
#include <cstring>
#include <cstring>
#include <logsrv.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "verify/verifyIntrf.h"
#include "slrealtime/libsrc/IP/udp.hpp"
#include "sg_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Child system includes */
#include "sg_cal.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
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

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
struct B_sg_T {
  real_T UDPReceive1_o2;               /* '<Root>/UDP Receive1' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T ProportionalGain;             /* '<S45>/Proportional Gain' */
  real_T Integrator;                   /* '<S40>/Integrator' */
  real_T Sum;                          /* '<S49>/Sum' */
  real_T Clock;                        /* '<Root>/Clock' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T ProportionalGain_a;           /* '<S93>/Proportional Gain' */
  real_T Integrator_h;                 /* '<S88>/Integrator' */
  real_T Sum_j;                        /* '<S97>/Sum' */
  real_T RP_measure[2];                /* '<Root>/Vector Concatenate' */
  real_T IntegralGain;                 /* '<S37>/Integral Gain' */
  real_T IntegralGain_l;               /* '<S85>/Integral Gain' */
  real_T UDPReceive_o2;                /* '<Root>/UDP Receive' */
  real_T y;                         /* '<Root>/Vel_input_to_disturb_payload1' */
  real_T y_d;                        /* '<Root>/Vel_input_to_disturb_payload' */
  real_T Wire_Angles[2];               /* '<Root>/EulAngle_to_WireAngle' */
  uint32_T Delay;                      /* '<S1>/Delay' */
  uint32_T Add;                        /* '<S1>/Add' */
  uint32_T ByteUnpacking_o1;           /* '<S2>/Byte Unpacking' */
  real32_T UDP_IMU[4];                 /* '<Root>/Byte_Unpacking' */
  real32_T CastToSingle1;              /* '<Root>/Cast To Single1' */
  real32_T MultiportSwitch1;           /* '<Root>/Multiport Switch1' */
  real32_T Saturation2;                /* '<Root>/Saturation2' */
  real32_T CastToSingle;               /* '<Root>/Cast To Single' */
  real32_T MultiportSwitch;            /* '<Root>/Multiport Switch' */
  real32_T Saturation3;                /* '<Root>/Saturation3' */
  real32_T comau_u[2];                 /* '<Root>/Concat2' */
  real32_T ByteUnpacking_o2;           /* '<S2>/Byte Unpacking' */
  real32_T ByteUnpacking_o3[6];        /* '<S2>/Byte Unpacking' */
  real32_T ByteUnpacking_o4[6];        /* '<S2>/Byte Unpacking' */
  real32_T ByteUnpacking_o5;           /* '<S2>/Byte Unpacking' */
  real32_T ByteUnpacking_o6;           /* '<S2>/Byte Unpacking' */
  real32_T ByteUnpacking_o7[6];        /* '<S2>/Byte Unpacking' */
  real32_T ByteUnpacking_o8[6];        /* '<S2>/Byte Unpacking' */
  real32_T ByteUnpacking_o9[6];        /* '<S2>/Byte Unpacking' */
  real32_T ByteUnpacking_o10[6];       /* '<S2>/Byte Unpacking' */
  real32_T ByteUnpacking_o11[6];       /* '<S2>/Byte Unpacking' */
  real32_T ByteUnpacking_o12[6];       /* '<S2>/Byte Unpacking' */
  real32_T ByteUnpacking_o13[6];       /* '<S2>/Byte Unpacking' */
  real32_T ByteUnpacking_o14[6];       /* '<S2>/Byte Unpacking' */
  real32_T ByteUnpacking_o15[6];       /* '<S2>/Byte Unpacking' */
  real32_T ByteUnpacking_o16[6];       /* '<S2>/Byte Unpacking' */
  real32_T CastToSingle2;              /* '<Root>/Cast To Single2' */
  real32_T CastToSingle3;              /* '<Root>/Cast To Single3' */
  real32_T Eul_XYZ[3];                 /* '<Root>/Quat_To_Eul' */
  int32_T Gain[6];                     /* '<Root>/Gain' */
  int16_T UDP_pos[6];                  /* '<Root>/Byte_Unpacking' */
  uint8_T UDPReceive1_o1[29];          /* '<Root>/UDP Receive1' */
  uint8_T Byte_Unpacking_o2;           /* '<Root>/Byte_Unpacking' */
  uint8_T BytePacking[136];            /* '<S1>/Byte Packing' */
  uint8_T UDPReceive_o1[304];          /* '<Root>/UDP Receive' */
  boolean_T UDP_flag;                  /* '<Root>/Boolean' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_sg_T {
  real_T Integrator_DSTATE;            /* '<S40>/Integrator' */
  real_T Integrator_DSTATE_a;          /* '<S88>/Integrator' */
  real_T t_command_received;        /* '<Root>/Vel_input_to_disturb_payload1' */
  real_T t_start;                    /* '<Root>/Vel_input_to_disturb_payload' */
  void *UDPReceive1_PWORK[2];          /* '<Root>/UDP Receive1' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Byte_;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Byt_g;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Conca;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_EulAn;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Quat_;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Vecto;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Vel_i;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Vel_d;   /* synthesized block */

  void *UDPSend_PWORK;                 /* '<Root>/UDP Send' */
  void *UDPReceive_PWORK[2];           /* '<Root>/UDP Receive' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_ByteU;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Byt_e;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Byt_m;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Byt_n;   /* synthesized block */

  uint32_T Delay_DSTATE;               /* '<S1>/Delay' */
  int_T UDPReceive1_IWORK;             /* '<Root>/UDP Receive1' */
  int_T Byte_Unpacking_IWORK[6];       /* '<Root>/Byte_Unpacking' */
  int_T BytePacking_IWORK[68];         /* '<S1>/Byte Packing' */
  int_T UDPSend_IWORK[2];              /* '<Root>/UDP Send' */
  int_T UDPReceive_IWORK;              /* '<Root>/UDP Receive' */
  int_T ByteUnpacking_IWORK[32];       /* '<S2>/Byte Unpacking' */
  boolean_T profile_triggered;      /* '<Root>/Vel_input_to_disturb_payload1' */
  boolean_T profile_started;         /* '<Root>/Vel_input_to_disturb_payload' */
};

/* Invariant block signals (default storage) */
struct ConstB_sg_T {
  real_T Width;                        /* '<Root>/Width' */
};

/* External inputs (root inport signals with default storage) */
struct ExtU_sg_T {
  uint32_T Input1[3];                  /* '<Root>/Input1' */
  real32_T Input2[24];                 /* '<Root>/Input2' */
  real32_T Input3[3];                  /* '<Root>/Input3' */
};

/* Real-time Model Data Structure */
struct tag_RTM_sg_T {
  const char_T *errorStatus;
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
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_sg_T sg_B;

#ifdef __cplusplus

}
#endif

/* Block states (default storage) */
extern struct DW_sg_T sg_DW;

#ifdef __cplusplus

extern "C" {

#endif

  /* External inputs (root inport signals with default storage) */
  extern struct ExtU_sg_T sg_U;

#ifdef __cplusplus

}
#endif

extern const ConstB_sg_T sg_ConstB;    /* constant block i/o */

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void sg_initialize(void);
  extern void sg_step(void);
  extern void sg_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_sg_T *const sg_M;

#ifdef __cplusplus

}
#endif

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
 * '<Root>' : 'sg'
 * '<S1>'   : 'sg/BytePackingBlock'
 * '<S2>'   : 'sg/ByteUnpackBlock'
 * '<S3>'   : 'sg/EulAngle_to_WireAngle'
 * '<S4>'   : 'sg/PID1'
 * '<S5>'   : 'sg/PID2'
 * '<S6>'   : 'sg/Quat_To_Eul'
 * '<S7>'   : 'sg/Vel_input_to_disturb_payload'
 * '<S8>'   : 'sg/Vel_input_to_disturb_payload1'
 * '<S9>'   : 'sg/PID1/Anti-windup'
 * '<S10>'  : 'sg/PID1/D Gain'
 * '<S11>'  : 'sg/PID1/Filter'
 * '<S12>'  : 'sg/PID1/Filter ICs'
 * '<S13>'  : 'sg/PID1/I Gain'
 * '<S14>'  : 'sg/PID1/Ideal P Gain'
 * '<S15>'  : 'sg/PID1/Ideal P Gain Fdbk'
 * '<S16>'  : 'sg/PID1/Integrator'
 * '<S17>'  : 'sg/PID1/Integrator ICs'
 * '<S18>'  : 'sg/PID1/N Copy'
 * '<S19>'  : 'sg/PID1/N Gain'
 * '<S20>'  : 'sg/PID1/P Copy'
 * '<S21>'  : 'sg/PID1/Parallel P Gain'
 * '<S22>'  : 'sg/PID1/Reset Signal'
 * '<S23>'  : 'sg/PID1/Saturation'
 * '<S24>'  : 'sg/PID1/Saturation Fdbk'
 * '<S25>'  : 'sg/PID1/Sum'
 * '<S26>'  : 'sg/PID1/Sum Fdbk'
 * '<S27>'  : 'sg/PID1/Tracking Mode'
 * '<S28>'  : 'sg/PID1/Tracking Mode Sum'
 * '<S29>'  : 'sg/PID1/Tsamp - Integral'
 * '<S30>'  : 'sg/PID1/Tsamp - Ngain'
 * '<S31>'  : 'sg/PID1/postSat Signal'
 * '<S32>'  : 'sg/PID1/preSat Signal'
 * '<S33>'  : 'sg/PID1/Anti-windup/Passthrough'
 * '<S34>'  : 'sg/PID1/D Gain/Disabled'
 * '<S35>'  : 'sg/PID1/Filter/Disabled'
 * '<S36>'  : 'sg/PID1/Filter ICs/Disabled'
 * '<S37>'  : 'sg/PID1/I Gain/Internal Parameters'
 * '<S38>'  : 'sg/PID1/Ideal P Gain/Passthrough'
 * '<S39>'  : 'sg/PID1/Ideal P Gain Fdbk/Disabled'
 * '<S40>'  : 'sg/PID1/Integrator/Discrete'
 * '<S41>'  : 'sg/PID1/Integrator ICs/Internal IC'
 * '<S42>'  : 'sg/PID1/N Copy/Disabled wSignal Specification'
 * '<S43>'  : 'sg/PID1/N Gain/Disabled'
 * '<S44>'  : 'sg/PID1/P Copy/Disabled'
 * '<S45>'  : 'sg/PID1/Parallel P Gain/Internal Parameters'
 * '<S46>'  : 'sg/PID1/Reset Signal/Disabled'
 * '<S47>'  : 'sg/PID1/Saturation/Passthrough'
 * '<S48>'  : 'sg/PID1/Saturation Fdbk/Disabled'
 * '<S49>'  : 'sg/PID1/Sum/Sum_PI'
 * '<S50>'  : 'sg/PID1/Sum Fdbk/Disabled'
 * '<S51>'  : 'sg/PID1/Tracking Mode/Disabled'
 * '<S52>'  : 'sg/PID1/Tracking Mode Sum/Passthrough'
 * '<S53>'  : 'sg/PID1/Tsamp - Integral/Passthrough'
 * '<S54>'  : 'sg/PID1/Tsamp - Ngain/Passthrough'
 * '<S55>'  : 'sg/PID1/postSat Signal/Forward_Path'
 * '<S56>'  : 'sg/PID1/preSat Signal/Forward_Path'
 * '<S57>'  : 'sg/PID2/Anti-windup'
 * '<S58>'  : 'sg/PID2/D Gain'
 * '<S59>'  : 'sg/PID2/Filter'
 * '<S60>'  : 'sg/PID2/Filter ICs'
 * '<S61>'  : 'sg/PID2/I Gain'
 * '<S62>'  : 'sg/PID2/Ideal P Gain'
 * '<S63>'  : 'sg/PID2/Ideal P Gain Fdbk'
 * '<S64>'  : 'sg/PID2/Integrator'
 * '<S65>'  : 'sg/PID2/Integrator ICs'
 * '<S66>'  : 'sg/PID2/N Copy'
 * '<S67>'  : 'sg/PID2/N Gain'
 * '<S68>'  : 'sg/PID2/P Copy'
 * '<S69>'  : 'sg/PID2/Parallel P Gain'
 * '<S70>'  : 'sg/PID2/Reset Signal'
 * '<S71>'  : 'sg/PID2/Saturation'
 * '<S72>'  : 'sg/PID2/Saturation Fdbk'
 * '<S73>'  : 'sg/PID2/Sum'
 * '<S74>'  : 'sg/PID2/Sum Fdbk'
 * '<S75>'  : 'sg/PID2/Tracking Mode'
 * '<S76>'  : 'sg/PID2/Tracking Mode Sum'
 * '<S77>'  : 'sg/PID2/Tsamp - Integral'
 * '<S78>'  : 'sg/PID2/Tsamp - Ngain'
 * '<S79>'  : 'sg/PID2/postSat Signal'
 * '<S80>'  : 'sg/PID2/preSat Signal'
 * '<S81>'  : 'sg/PID2/Anti-windup/Passthrough'
 * '<S82>'  : 'sg/PID2/D Gain/Disabled'
 * '<S83>'  : 'sg/PID2/Filter/Disabled'
 * '<S84>'  : 'sg/PID2/Filter ICs/Disabled'
 * '<S85>'  : 'sg/PID2/I Gain/Internal Parameters'
 * '<S86>'  : 'sg/PID2/Ideal P Gain/Passthrough'
 * '<S87>'  : 'sg/PID2/Ideal P Gain Fdbk/Disabled'
 * '<S88>'  : 'sg/PID2/Integrator/Discrete'
 * '<S89>'  : 'sg/PID2/Integrator ICs/Internal IC'
 * '<S90>'  : 'sg/PID2/N Copy/Disabled wSignal Specification'
 * '<S91>'  : 'sg/PID2/N Gain/Disabled'
 * '<S92>'  : 'sg/PID2/P Copy/Disabled'
 * '<S93>'  : 'sg/PID2/Parallel P Gain/Internal Parameters'
 * '<S94>'  : 'sg/PID2/Reset Signal/Disabled'
 * '<S95>'  : 'sg/PID2/Saturation/Passthrough'
 * '<S96>'  : 'sg/PID2/Saturation Fdbk/Disabled'
 * '<S97>'  : 'sg/PID2/Sum/Sum_PI'
 * '<S98>'  : 'sg/PID2/Sum Fdbk/Disabled'
 * '<S99>'  : 'sg/PID2/Tracking Mode/Disabled'
 * '<S100>' : 'sg/PID2/Tracking Mode Sum/Passthrough'
 * '<S101>' : 'sg/PID2/Tsamp - Integral/Passthrough'
 * '<S102>' : 'sg/PID2/Tsamp - Ngain/Passthrough'
 * '<S103>' : 'sg/PID2/postSat Signal/Forward_Path'
 * '<S104>' : 'sg/PID2/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_sg_h_ */
