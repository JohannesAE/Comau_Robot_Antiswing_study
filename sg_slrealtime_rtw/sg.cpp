/*
 * sg.cpp
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

#include "sg.h"
#include "sg_private.h"

/* Block signals (default storage) */
B_sg_T sg_B;

/* Block states (default storage) */
DW_sg_T sg_DW;

/* External inputs (root inport signals with default storage) */
ExtU_sg_T sg_U;

/* Real-time model */
RT_MODEL_sg_T sg_M_ = RT_MODEL_sg_T();
RT_MODEL_sg_T *const sg_M = &sg_M_;
real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u1 > 0.0F) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u0 > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = std::atan2(static_cast<real32_T>(tmp_0), static_cast<real32_T>(tmp));
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = std::atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void sg_step(void)
{
  real_T t_elapsed;
  int32_T e_size_idx_1;
  int32_T i;
  real32_T aSinInput;
  real32_T d_data_idx_0;
  real32_T matrix_idx_0;
  real32_T matrix_idx_1;
  real32_T matrix_idx_2;
  real32_T matrix_idx_3;
  real32_T x_data_idx_0;
  real32_T y_idx_0;
  real32_T y_idx_1;
  real32_T y_idx_2;
  real32_T y_idx_3;
  int8_T csz_idx_0;
  boolean_T mask1;
  boolean_T mask2;

  /* S-Function (slrealtimeUDPReceive): '<Root>/UDP Receive1' */
  {
    try {
      slrealtime::ip::udp::Socket *udpSock = reinterpret_cast<slrealtime::ip::
        udp::Socket*>(sg_DW.UDPReceive1_PWORK[0]);
      char *buffer = (char *)sg_DW.UDPReceive1_PWORK[1];
      memset(buffer,0,29);
      void *dataPort = &sg_B.UDPReceive1_o1[0];
      int_T numBytesAvail = (int_T)(udpSock->bytesToRead());
      if (numBytesAvail > 0) {
        uint8_t* fmAddArg = (uint8_t *)sg_cal->UDPReceive1_fmAddress;
        size_t num_bytesRcvd = (size_t)(udpSock->receive(buffer,( numBytesAvail<
          65504 )? numBytesAvail:65504, !1,fmAddArg));
        if (num_bytesRcvd == 0) {
          sg_B.UDPReceive1_o2 = 0;
        } else {
          sg_B.UDPReceive1_o2 = (double)num_bytesRcvd;
          memcpy(dataPort,(void*)buffer,29);
        }
      } else {
        sg_B.UDPReceive1_o2 = 0;
      }
    } catch (std::exception& e) {
      std::string tmp = std::string(e.what());
      static std::string eMsg = tmp;
      rtmSetErrorStatus(sg_M, eMsg.c_str());
      rtmSetStopRequested(sg_M, 1);
      ;
    }
  }

  /* S-Function (slrealtimebytepacking): '<Root>/Byte_Unpacking' */

  /* Byte Unpacking: <Root>/Byte_Unpacking */
  (void)memcpy((uint8_T*)&sg_B.UDP_pos[0], (uint8_T*)&sg_B.UDPReceive1_o1[0] + 0,
               12);
  (void)memcpy((uint8_T*)&sg_B.Byte_Unpacking_o2, (uint8_T*)
               &sg_B.UDPReceive1_o1[0] + 12, 1);
  (void)memcpy((uint8_T*)&sg_B.UDP_IMU[0], (uint8_T*)&sg_B.UDPReceive1_o1[0] +
               13, 16);

  /* MATLAB Function: '<Root>/Quat_To_Eul' */
  /* MATLAB Function 'Quat_To_Eul': '<S6>:1' */
  /* '<S6>:1:4' */
  matrix_idx_0 = sg_B.UDP_IMU[3];
  matrix_idx_1 = sg_B.UDP_IMU[0];
  matrix_idx_2 = sg_B.UDP_IMU[1];
  matrix_idx_3 = sg_B.UDP_IMU[2];

  /* '<S6>:1:6' */
  aSinInput = matrix_idx_0;
  y_idx_0 = aSinInput * aSinInput;
  aSinInput = matrix_idx_1;
  y_idx_1 = aSinInput * aSinInput;
  aSinInput = matrix_idx_2;
  y_idx_2 = aSinInput * aSinInput;
  aSinInput = matrix_idx_3;
  y_idx_3 = aSinInput * aSinInput;
  aSinInput = y_idx_0;
  aSinInput += y_idx_1;
  aSinInput += y_idx_2;
  aSinInput += y_idx_3;
  aSinInput = 1.0F / std::sqrt(aSinInput);
  y_idx_0 = matrix_idx_0 * aSinInput;
  y_idx_1 = matrix_idx_1 * aSinInput;
  y_idx_2 = matrix_idx_2 * aSinInput;
  y_idx_3 = matrix_idx_3 * aSinInput;
  aSinInput = (y_idx_1 * y_idx_3 - y_idx_0 * y_idx_2) * -2.0F;
  mask1 = (aSinInput >= 0.999998808F);
  mask2 = (aSinInput <= -0.999998808F);
  if (aSinInput >= 0.999998808F) {
    aSinInput = 1.0F;
  }

  if (mask2) {
    aSinInput = -1.0F;
  }

  matrix_idx_0 = rt_atan2f_snf((y_idx_1 * y_idx_2 + y_idx_0 * y_idx_3) * 2.0F,
    ((y_idx_0 * y_idx_0 + y_idx_1 * y_idx_1) - y_idx_2 * y_idx_2) - y_idx_3 *
    y_idx_3);
  matrix_idx_1 = std::asin(aSinInput);
  y_idx_2 = rt_atan2f_snf((y_idx_2 * y_idx_3 + y_idx_0 * y_idx_1) * 2.0F,
    ((y_idx_0 * y_idx_0 - y_idx_1 * y_idx_1) - y_idx_2 * y_idx_2) + y_idx_3 *
    y_idx_3);
  sg_B.Eul_XYZ[0] = matrix_idx_0;
  sg_B.Eul_XYZ[1] = matrix_idx_1;
  sg_B.Eul_XYZ[2] = y_idx_2;
  i = 0;
  if (mask1 || mask2) {
    i = 1;
  }

  e_size_idx_1 = i;
  if (0 <= i - 1) {
    x_data_idx_0 = aSinInput;
  }

  i = 0;
  while (i <= e_size_idx_1 - 1) {
    y_idx_2 = x_data_idx_0;
    if (y_idx_2 < 0.0F) {
      y_idx_2 = -1.0F;
    } else if (y_idx_2 > 0.0F) {
      y_idx_2 = 1.0F;
    } else if (y_idx_2 == 0.0F) {
      y_idx_2 = 0.0F;
    } else {
      y_idx_2 = (rtNaNF);
    }

    x_data_idx_0 = y_idx_2;
    i = 1;
  }

  i = 0;
  if (mask1 || mask2) {
    i = 1;
  }

  csz_idx_0 = static_cast<int8_T>(i);
  i = csz_idx_0;
  if (0 <= i - 1) {
    d_data_idx_0 = rt_atan2f_snf(y_idx_1, y_idx_0);
  }

  i = e_size_idx_1;
  if (0 <= i - 1) {
    sg_B.Eul_XYZ[0] = -x_data_idx_0 * 2.0F * d_data_idx_0;
  }

  i = 0;
  if (mask1 || mask2) {
    i = 1;
  }

  if (0 <= i - 1) {
    sg_B.Eul_XYZ[2] = 0.0F;
  }

  /* '<S6>:1:7' */
  sg_B.Eul_XYZ[0] *= 57.2957802F;
  sg_B.Eul_XYZ[1] *= 57.2957802F;
  sg_B.Eul_XYZ[2] *= 57.2957802F;

  /* End of MATLAB Function: '<Root>/Quat_To_Eul' */

  /* MATLAB Function: '<Root>/EulAngle_to_WireAngle' */
  /* MATLAB Function 'EulAngle_to_WireAngle': '<S3>:1' */
  /* '<S3>:1:4' */
  /* '<S3>:1:5' */
  /* '<S3>:1:8' */
  /* '<S3>:1:9' */
  /* '<S3>:1:10' */
  /* '<S3>:1:11' */
  /* '<S3>:1:14' */
  /* '<S3>:1:15' */
  if ((sg_B.Eul_XYZ[2] >= -0.95) && (sg_B.Eul_XYZ[2] <= -0.7)) {
    /* '<S3>:1:23' */
    /* '<S3>:1:25' */
    sg_B.Wire_Angles[0] = 0.0;
  } else {
    /* '<S3>:1:28' */
    sg_B.Wire_Angles[0] = sg_B.Eul_XYZ[2] - -0.827F;
  }

  if ((sg_B.Eul_XYZ[1] >= -9.5F) && (sg_B.Eul_XYZ[1] <= -9.0F)) {
    /* '<S3>:1:32' */
    /* '<S3>:1:34' */
    sg_B.Wire_Angles[1] = 0.0;
  } else {
    /* '<S3>:1:37' */
    sg_B.Wire_Angles[1] = sg_B.Eul_XYZ[1] - -9.2933F;
  }

  /* End of MATLAB Function: '<Root>/EulAngle_to_WireAngle' */

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  sg_B.Sum1 = sg_cal->Constant_Value - sg_B.Wire_Angles[0];

  /* Gain: '<S45>/Proportional Gain' */
  sg_B.ProportionalGain = sg_cal->PID1_P * sg_B.Sum1;

  /* DiscreteIntegrator: '<S40>/Integrator' */
  sg_B.Integrator = sg_DW.Integrator_DSTATE;

  /* Sum: '<S49>/Sum' */
  sg_B.Sum = sg_B.ProportionalGain + sg_B.Integrator;

  /* DataTypeConversion: '<Root>/Cast To Single1' */
  sg_B.CastToSingle1 = static_cast<real32_T>(sg_B.Sum);

  /* Clock: '<Root>/Clock' */
  sg_B.Clock = sg_M->Timing.t[0];

  /* MATLAB Function: '<Root>/Vel_input_to_disturb_payload1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  /* MATLAB Function 'Vel_input_to_disturb_payload1': '<S8>:1' */
  /* '<S8>:1:14' */
  /* '<S8>:1:15' */
  /* '<S8>:1:16' */
  /* '<S8>:1:17' */
  /* '<S8>:1:20' */
  sg_B.y = 0.0;
  if ((sg_cal->Constant2_Value == 2.0) && (!sg_DW.profile_triggered)) {
    /* '<S8>:1:24' */
    /* '<S8>:1:25' */
    sg_DW.t_command_received = sg_B.Clock;

    /* '<S8>:1:26' */
    sg_DW.profile_triggered = true;
  }

  if (sg_DW.profile_triggered) {
    /* '<S8>:1:31' */
    /* '<S8>:1:33' */
    if (sg_B.Clock >= sg_DW.t_command_received + 2.0) {
      /* '<S8>:1:36' */
      /* '<S8>:1:39' */
      t_elapsed = sg_B.Clock - (sg_DW.t_command_received + 2.0);
      if ((t_elapsed >= 0.0) && (t_elapsed < 0.5)) {
        /* '<S8>:1:42' */
        /* '<S8>:1:44' */
        /* '<S8>:1:45' */
        sg_B.y = 0.8 * t_elapsed;
      } else if ((t_elapsed >= 0.5) && (t_elapsed < 1.0)) {
        /* '<S8>:1:47' */
        /* '<S8>:1:49' */
        /* '<S8>:1:50' */
        /* '<S8>:1:51' */
        sg_B.y = (t_elapsed - 0.5) * -0.8 + 0.4;
      } else if ((t_elapsed >= 1.0) && (t_elapsed < 1.5)) {
        /* '<S8>:1:53' */
        /* '<S8>:1:55' */
        /* '<S8>:1:56' */
        /* '<S8>:1:57' */
        sg_B.y = (t_elapsed - 1.0) * -0.8;
      } else if ((t_elapsed >= 1.5) && (t_elapsed <= 2.0)) {
        /* '<S8>:1:59' */
        /* '<S8>:1:61' */
        /* '<S8>:1:62' */
        /* '<S8>:1:63' */
        sg_B.y = (t_elapsed - 1.5) * 0.8 + -0.4;
      } else if (t_elapsed > 2.0) {
        /* '<S8>:1:65' */
        /* '<S8>:1:67' */
        sg_B.y = 0.0;
      } else {
        /* '<S8>:1:75' */
        sg_B.y = 0.0;
      }
    } else {
      /* '<S8>:1:82' */
      sg_B.y = 0.0;
    }
  }

  /* End of MATLAB Function: '<Root>/Vel_input_to_disturb_payload1' */

  /* MultiPortSwitch: '<Root>/Multiport Switch1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  switch (static_cast<int32_T>(sg_cal->Constant2_Value)) {
   case 1:
    /* MultiPortSwitch: '<Root>/Multiport Switch1' */
    sg_B.MultiportSwitch1 = sg_B.CastToSingle1;
    break;

   case 2:
    /* DataTypeConversion: '<Root>/Cast To Single3' */
    sg_B.CastToSingle3 = static_cast<real32_T>(sg_B.y);

    /* MultiPortSwitch: '<Root>/Multiport Switch1' */
    sg_B.MultiportSwitch1 = sg_B.CastToSingle3;
    break;

   default:
    /* MultiPortSwitch: '<Root>/Multiport Switch1' incorporates:
     *  Constant: '<Root>/Zero'
     */
    sg_B.MultiportSwitch1 = sg_cal->Zero_Value;
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch1' */

  /* Saturate: '<Root>/Saturation2' */
  y_idx_0 = sg_B.MultiportSwitch1;
  y_idx_1 = sg_cal->Saturation2_LowerSat;
  y_idx_2 = sg_cal->Saturation2_UpperSat;
  if (y_idx_0 > y_idx_2) {
    /* Saturate: '<Root>/Saturation2' */
    sg_B.Saturation2 = y_idx_2;
  } else if (y_idx_0 < y_idx_1) {
    /* Saturate: '<Root>/Saturation2' */
    sg_B.Saturation2 = y_idx_1;
  } else {
    /* Saturate: '<Root>/Saturation2' */
    sg_B.Saturation2 = y_idx_0;
  }

  /* End of Saturate: '<Root>/Saturation2' */

  /* SignalConversion generated from: '<Root>/Concat2' incorporates:
   *  Concatenate: '<Root>/Concat2'
   */
  sg_B.comau_u[0] = sg_B.Saturation2;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  sg_B.Sum2 = sg_cal->Constant1_Value - sg_B.Wire_Angles[1];

  /* Gain: '<S93>/Proportional Gain' */
  sg_B.ProportionalGain_a = sg_cal->PID2_P * sg_B.Sum2;

  /* DiscreteIntegrator: '<S88>/Integrator' */
  sg_B.Integrator_h = sg_DW.Integrator_DSTATE_a;

  /* Sum: '<S97>/Sum' */
  sg_B.Sum_j = sg_B.ProportionalGain_a + sg_B.Integrator_h;

  /* DataTypeConversion: '<Root>/Cast To Single' */
  sg_B.CastToSingle = static_cast<real32_T>(sg_B.Sum_j);

  /* MATLAB Function: '<Root>/Vel_input_to_disturb_payload' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  /* MATLAB Function 'Vel_input_to_disturb_payload': '<S7>:1' */
  /* '<S7>:1:14' */
  /* '<S7>:1:15' */
  /* '<S7>:1:16' */
  /* '<S7>:1:19' */
  sg_B.y_d = 0.0;
  if ((sg_cal->Constant2_Value == 2.0) && (!sg_DW.profile_started)) {
    /* '<S7>:1:23' */
    /* '<S7>:1:24' */
    sg_DW.t_start = sg_B.Clock;

    /* '<S7>:1:25' */
    sg_DW.profile_started = true;
  }

  if (sg_DW.profile_started) {
    /* '<S7>:1:29' */
    /* '<S7>:1:30' */
    t_elapsed = sg_B.Clock - sg_DW.t_start;
    if ((t_elapsed >= 0.0) && (t_elapsed < 0.5)) {
      /* '<S7>:1:33' */
      /* '<S7>:1:35' */
      /* '<S7>:1:36' */
      sg_B.y_d = 0.2 * t_elapsed;
    } else if ((t_elapsed >= 0.5) && (t_elapsed < 1.0)) {
      /* '<S7>:1:38' */
      /* '<S7>:1:40' */
      /* '<S7>:1:41' */
      /* '<S7>:1:42' */
      sg_B.y_d = (t_elapsed - 0.5) * -0.2 + 0.1;
    } else if ((t_elapsed >= 1.0) && (t_elapsed < 1.5)) {
      /* '<S7>:1:44' */
      /* '<S7>:1:46' */
      /* '<S7>:1:47' */
      /* '<S7>:1:48' */
      sg_B.y_d = (t_elapsed - 1.0) * -0.2;
    } else if ((t_elapsed >= 1.5) && (t_elapsed <= 2.0)) {
      /* '<S7>:1:50' */
      /* '<S7>:1:52' */
      /* '<S7>:1:53' */
      /* '<S7>:1:54' */
      sg_B.y_d = (t_elapsed - 1.5) * 0.2 + -0.1;
    } else if (t_elapsed > 2.0) {
      /* '<S7>:1:56' */
      /* '<S7>:1:58' */
      sg_B.y_d = 0.0;
    } else {
      /* '<S7>:1:64' */
      sg_B.y_d = 0.0;
    }
  }

  /* End of MATLAB Function: '<Root>/Vel_input_to_disturb_payload' */

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  switch (static_cast<int32_T>(sg_cal->Constant2_Value)) {
   case 1:
    /* MultiPortSwitch: '<Root>/Multiport Switch' */
    sg_B.MultiportSwitch = sg_B.CastToSingle;
    break;

   case 2:
    /* DataTypeConversion: '<Root>/Cast To Single2' */
    sg_B.CastToSingle2 = static_cast<real32_T>(sg_B.y_d);

    /* MultiPortSwitch: '<Root>/Multiport Switch' */
    sg_B.MultiportSwitch = sg_B.CastToSingle2;
    break;

   default:
    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Constant: '<Root>/Zero'
     */
    sg_B.MultiportSwitch = sg_cal->Zero_Value;
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* Saturate: '<Root>/Saturation3' */
  y_idx_0 = sg_B.MultiportSwitch;
  y_idx_1 = sg_cal->Saturation3_LowerSat;
  y_idx_2 = sg_cal->Saturation3_UpperSat;
  if (y_idx_0 > y_idx_2) {
    /* Saturate: '<Root>/Saturation3' */
    sg_B.Saturation3 = y_idx_2;
  } else if (y_idx_0 < y_idx_1) {
    /* Saturate: '<Root>/Saturation3' */
    sg_B.Saturation3 = y_idx_1;
  } else {
    /* Saturate: '<Root>/Saturation3' */
    sg_B.Saturation3 = y_idx_0;
  }

  /* End of Saturate: '<Root>/Saturation3' */

  /* SignalConversion generated from: '<Root>/Concat2' incorporates:
   *  Concatenate: '<Root>/Concat2'
   */
  sg_B.comau_u[1] = sg_B.Saturation3;

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   */
  sg_B.RP_measure[0] = sg_B.Wire_Angles[0];

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   */
  sg_B.RP_measure[1] = sg_B.Wire_Angles[1];

  /* Delay: '<S1>/Delay' */
  sg_B.Delay = sg_DW.Delay_DSTATE;

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  sg_B.Add = sg_B.Delay + sg_cal->Constant1_Value_o;

  /* S-Function (slrealtimebytepacking): '<S1>/Byte Packing' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant2'
   *  Inport: '<Root>/Input1'
   *  Inport: '<Root>/Input2'
   *  Inport: '<Root>/Input3'
   */

  /* Byte Packing: <S1>/Byte Packing */
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 0, (uint8_T*)&sg_U.Input1[0], 4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 4, (uint8_T*)&sg_B.Add, 4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 8, (uint8_T*)&sg_U.Input1[2], 4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 12, (uint8_T*)&sg_U.Input2[0], 4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 16, (uint8_T*)&sg_U.Input2[1], 4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 20, (uint8_T*)&sg_U.Input2[2], 4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 24, (uint8_T*)&sg_U.Input2[3], 4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 28, (uint8_T*)&sg_U.Input2[4], 4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 32, (uint8_T*)&sg_U.Input2[5], 4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 36, (uint8_T*)&sg_U.Input2[6], 4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 40, (uint8_T*)&sg_U.Input2[7], 4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 44, (uint8_T*)&sg_U.Input2[8], 4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 48, (uint8_T*)&sg_U.Input2[9], 4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 52, (uint8_T*)&sg_U.Input2[10],
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 56, (uint8_T*)&sg_U.Input2[11],
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 60, (uint8_T*)&sg_U.Input2[12],
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 64, (uint8_T*)&sg_U.Input2[13],
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 68, (uint8_T*)&sg_U.Input2[14],
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 72, (uint8_T*)&sg_U.Input2[15],
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 76, (uint8_T*)&sg_U.Input2[16],
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 80, (uint8_T*)&sg_U.Input2[17],
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 84, (uint8_T*)&sg_U.Input2[18],
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 88, (uint8_T*)&sg_U.Input2[19],
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 92, (uint8_T*)&sg_U.Input2[20],
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 96, (uint8_T*)&sg_U.Input2[21],
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 100, (uint8_T*)&sg_U.Input2[22],
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 104, (uint8_T*)&sg_U.Input2[23],
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 108, (uint8_T*)&sg_B.Saturation2,
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 112, (uint8_T*)&sg_B.Saturation3,
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 116, (uint8_T*)
               &sg_cal->Constant_Value_i, 4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 120, (uint8_T*)&sg_U.Input3[0],
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 124, (uint8_T*)&sg_U.Input3[1],
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 128, (uint8_T*)&sg_U.Input3[2],
               4);
  (void)memcpy((uint8_T*)&sg_B.BytePacking[0] + 132, (uint8_T*)
               &sg_cal->Constant2_Value_b, 4);

  /* S-Function (slrealtimeUDPSend): '<Root>/UDP Send' */
  {
    try {
      slrealtime::ip::udp::Socket *udpSock = reinterpret_cast<slrealtime::ip::
        udp::Socket*>(sg_DW.UDPSend_PWORK);
      uint8_t *remoteAddress = (uint8_t *)sg_cal->UDPSend_toAddress;
      uint16_t *remotePort = (uint16_t *)&sg_cal->UDPSend_toPort;
      udpSock->resetRemoteEndpoint(remoteAddress, remotePort);
      int dataLen = sg_ConstB.Width;
      dataLen = (dataLen <= sg_DW.UDPSend_IWORK[0]) ? dataLen :
        sg_DW.UDPSend_IWORK[0];
      dataLen = (dataLen <= -1) ? 0 : dataLen;
      void *dataPort = &sg_B.BytePacking[0];
      size_t numBytesSend = udpSock->send((const char*)dataPort,dataLen);
    } catch (std::exception& e) {
      std::string tmp = std::string(e.what());
      static std::string eMsg = tmp;
      rtmSetErrorStatus(sg_M, eMsg.c_str());
      rtmSetStopRequested(sg_M, 1);
      ;
    }
  }

  /* DataTypeConversion: '<Root>/Boolean' */
  sg_B.UDP_flag = (sg_B.Byte_Unpacking_o2 != 0);
  for (i = 0; i < 6; i++) {
    /* Gain: '<Root>/Gain' */
    sg_B.Gain[i] = sg_cal->Gain_Gain * sg_B.UDP_pos[i];
  }

  /* Gain: '<S37>/Integral Gain' */
  sg_B.IntegralGain = sg_cal->PID1_I * sg_B.Sum1;

  /* Gain: '<S85>/Integral Gain' */
  sg_B.IntegralGain_l = sg_cal->PID2_I * sg_B.Sum2;

  /* S-Function (slrealtimeUDPReceive): '<Root>/UDP Receive' */
  {
    try {
      slrealtime::ip::udp::Socket *udpSock = reinterpret_cast<slrealtime::ip::
        udp::Socket*>(sg_DW.UDPReceive_PWORK[0]);
      char *buffer = (char *)sg_DW.UDPReceive_PWORK[1];
      memset(buffer,0,304);
      void *dataPort = &sg_B.UDPReceive_o1[0];
      int_T numBytesAvail = (int_T)(udpSock->bytesToRead());
      if (numBytesAvail > 0) {
        uint8_t* fmAddArg = (uint8_t *)sg_cal->UDPReceive_fmAddress;
        size_t num_bytesRcvd = (size_t)(udpSock->receive(buffer,( numBytesAvail<
          65504 )? numBytesAvail:65504, !1,fmAddArg));
        if (num_bytesRcvd == 0) {
          sg_B.UDPReceive_o2 = 0;
        } else {
          sg_B.UDPReceive_o2 = (double)num_bytesRcvd;
          memcpy(dataPort,(void*)buffer,304);
        }
      } else {
        sg_B.UDPReceive_o2 = 0;
      }
    } catch (std::exception& e) {
      std::string tmp = std::string(e.what());
      static std::string eMsg = tmp;
      rtmSetErrorStatus(sg_M, eMsg.c_str());
      rtmSetStopRequested(sg_M, 1);
      ;
    }
  }

  /* S-Function (slrealtimebytepacking): '<S2>/Byte Unpacking' */

  /* Byte Unpacking: <S2>/Byte Unpacking */
  (void)memcpy((uint8_T*)&sg_B.ByteUnpacking_o1, (uint8_T*)&sg_B.UDPReceive_o1[0]
               + 0, 4);
  (void)memcpy((uint8_T*)&sg_B.ByteUnpacking_o2, (uint8_T*)&sg_B.UDPReceive_o1[0]
               + 4, 4);
  (void)memcpy((uint8_T*)&sg_B.ByteUnpacking_o3[0], (uint8_T*)
               &sg_B.UDPReceive_o1[0] + 8, 24);
  (void)memcpy((uint8_T*)&sg_B.ByteUnpacking_o4[0], (uint8_T*)
               &sg_B.UDPReceive_o1[0] + 32, 24);
  (void)memcpy((uint8_T*)&sg_B.ByteUnpacking_o5, (uint8_T*)&sg_B.UDPReceive_o1[0]
               + 56, 4);
  (void)memcpy((uint8_T*)&sg_B.ByteUnpacking_o6, (uint8_T*)&sg_B.UDPReceive_o1[0]
               + 60, 4);
  (void)memcpy((uint8_T*)&sg_B.ByteUnpacking_o7[0], (uint8_T*)
               &sg_B.UDPReceive_o1[0] + 64, 24);
  (void)memcpy((uint8_T*)&sg_B.ByteUnpacking_o8[0], (uint8_T*)
               &sg_B.UDPReceive_o1[0] + 88, 24);
  (void)memcpy((uint8_T*)&sg_B.ByteUnpacking_o9[0], (uint8_T*)
               &sg_B.UDPReceive_o1[0] + 112, 24);
  (void)memcpy((uint8_T*)&sg_B.ByteUnpacking_o10[0], (uint8_T*)
               &sg_B.UDPReceive_o1[0] + 136, 24);
  (void)memcpy((uint8_T*)&sg_B.ByteUnpacking_o11[0], (uint8_T*)
               &sg_B.UDPReceive_o1[0] + 160, 24);
  (void)memcpy((uint8_T*)&sg_B.ByteUnpacking_o12[0], (uint8_T*)
               &sg_B.UDPReceive_o1[0] + 184, 24);
  (void)memcpy((uint8_T*)&sg_B.ByteUnpacking_o13[0], (uint8_T*)
               &sg_B.UDPReceive_o1[0] + 208, 24);
  (void)memcpy((uint8_T*)&sg_B.ByteUnpacking_o14[0], (uint8_T*)
               &sg_B.UDPReceive_o1[0] + 232, 24);
  (void)memcpy((uint8_T*)&sg_B.ByteUnpacking_o15[0], (uint8_T*)
               &sg_B.UDPReceive_o1[0] + 256, 24);
  (void)memcpy((uint8_T*)&sg_B.ByteUnpacking_o16[0], (uint8_T*)
               &sg_B.UDPReceive_o1[0] + 280, 24);

  /* Update for DiscreteIntegrator: '<S40>/Integrator' */
  sg_DW.Integrator_DSTATE += sg_cal->Integrator_gainval * sg_B.IntegralGain;

  /* Update for DiscreteIntegrator: '<S88>/Integrator' */
  sg_DW.Integrator_DSTATE_a += sg_cal->Integrator_gainval_f *
    sg_B.IntegralGain_l;

  /* Update for Delay: '<S1>/Delay' */
  sg_DW.Delay_DSTATE = sg_B.Add;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++sg_M->Timing.clockTick0)) {
    ++sg_M->Timing.clockTickH0;
  }

  sg_M->Timing.t[0] = sg_M->Timing.clockTick0 * sg_M->Timing.stepSize0 +
    sg_M->Timing.clockTickH0 * sg_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    sg_M->Timing.clockTick1++;
    if (!sg_M->Timing.clockTick1) {
      sg_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void sg_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&sg_M->solverInfo, &sg_M->Timing.simTimeStep);
    rtsiSetTPtr(&sg_M->solverInfo, &rtmGetTPtr(sg_M));
    rtsiSetStepSizePtr(&sg_M->solverInfo, &sg_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&sg_M->solverInfo, (&rtmGetErrorStatus(sg_M)));
    rtsiSetRTModelPtr(&sg_M->solverInfo, sg_M);
  }

  rtsiSetSimTimeStep(&sg_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&sg_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(sg_M, &sg_M->Timing.tArray[0]);
  sg_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) std::memset((static_cast<void *>(&sg_B)), 0,
                     sizeof(B_sg_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      sg_B.ByteUnpacking_o3[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_B.ByteUnpacking_o4[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_B.ByteUnpacking_o7[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_B.ByteUnpacking_o8[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_B.ByteUnpacking_o9[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_B.ByteUnpacking_o10[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_B.ByteUnpacking_o11[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_B.ByteUnpacking_o12[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_B.ByteUnpacking_o13[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_B.ByteUnpacking_o14[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_B.ByteUnpacking_o15[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_B.ByteUnpacking_o16[i] = 0.0F;
    }

    sg_B.UDPReceive1_o2 = 0.0;
    sg_B.Sum1 = 0.0;
    sg_B.ProportionalGain = 0.0;
    sg_B.Integrator = 0.0;
    sg_B.Sum = 0.0;
    sg_B.Clock = 0.0;
    sg_B.Sum2 = 0.0;
    sg_B.ProportionalGain_a = 0.0;
    sg_B.Integrator_h = 0.0;
    sg_B.Sum_j = 0.0;
    sg_B.RP_measure[0] = 0.0;
    sg_B.RP_measure[1] = 0.0;
    sg_B.IntegralGain = 0.0;
    sg_B.IntegralGain_l = 0.0;
    sg_B.UDPReceive_o2 = 0.0;
    sg_B.y = 0.0;
    sg_B.y_d = 0.0;
    sg_B.Wire_Angles[0] = 0.0;
    sg_B.Wire_Angles[1] = 0.0;
    sg_B.UDP_IMU[0] = 0.0F;
    sg_B.UDP_IMU[1] = 0.0F;
    sg_B.UDP_IMU[2] = 0.0F;
    sg_B.UDP_IMU[3] = 0.0F;
    sg_B.CastToSingle1 = 0.0F;
    sg_B.MultiportSwitch1 = 0.0F;
    sg_B.Saturation2 = 0.0F;
    sg_B.CastToSingle = 0.0F;
    sg_B.MultiportSwitch = 0.0F;
    sg_B.Saturation3 = 0.0F;
    sg_B.comau_u[0] = 0.0F;
    sg_B.comau_u[1] = 0.0F;
    sg_B.ByteUnpacking_o2 = 0.0F;
    sg_B.ByteUnpacking_o5 = 0.0F;
    sg_B.ByteUnpacking_o6 = 0.0F;
    sg_B.CastToSingle2 = 0.0F;
    sg_B.CastToSingle3 = 0.0F;
    sg_B.Eul_XYZ[0] = 0.0F;
    sg_B.Eul_XYZ[1] = 0.0F;
    sg_B.Eul_XYZ[2] = 0.0F;
  }

  /* states (dwork) */
  (void) std::memset(static_cast<void *>(&sg_DW), 0,
                     sizeof(DW_sg_T));
  sg_DW.Integrator_DSTATE = 0.0;
  sg_DW.Integrator_DSTATE_a = 0.0;
  sg_DW.t_command_received = 0.0;
  sg_DW.t_start = 0.0;

  /* external inputs */
  (void)std::memset(&sg_U, 0, sizeof(ExtU_sg_T));
  for (int32_T i = 0; i < 24; i++) {
    sg_U.Input2[i] = 0.0F;
  }

  sg_U.Input3[0] = 0.0F;
  sg_U.Input3[1] = 0.0F;
  sg_U.Input3[2] = 0.0F;

  /* Start for S-Function (slrealtimeUDPReceive): '<Root>/UDP Receive1' */
  {
    try {
      uint8_t *tempAddr = nullptr;
      uint8_t *tempInterface = nullptr;
      slrealtime::ip::udp::Socket *udpSock = getUDPSocket("0.0.0.0",5008U);
      if (tempAddr)
        delete tempAddr;
      if (tempInterface)
        delete tempInterface;
      sg_DW.UDPReceive1_IWORK = 29;
      sg_DW.UDPReceive1_PWORK[0] = reinterpret_cast<void*>(udpSock);
      char *buffer = (char *)calloc(65504,sizeof(char));
      sg_DW.UDPReceive1_PWORK[1] = (void*)buffer;
    } catch (std::exception& e) {
      std::string tmp = std::string(e.what());
      static std::string eMsg = tmp;
      rtmSetErrorStatus(sg_M, eMsg.c_str());
      rtmSetStopRequested(sg_M, 1);
      ;
    }
  }

  /* Start for S-Function (slrealtimeUDPSend): '<Root>/UDP Send' */
  {
    try {
      slrealtime::ip::udp::Socket *udpSock = getUDPSocket("0.0.0.0",11000U);
      uint8_t *remoteAddress = (uint8_t *)sg_cal->UDPSend_toAddress;
      uint16_t *remotePort = (uint16_t *)&sg_cal->UDPSend_toPort;
      udpSock->setRemoteEndpoint(remoteAddress, remotePort[0]);
      sg_DW.UDPSend_IWORK[0] = 136;
      sg_DW.UDPSend_IWORK[1] = 11000U;
      sg_DW.UDPSend_PWORK = reinterpret_cast<void*>(udpSock);
    } catch (std::exception& e) {
      std::string tmp = std::string(e.what());
      static std::string eMsg = tmp;
      rtmSetErrorStatus(sg_M, eMsg.c_str());
      rtmSetStopRequested(sg_M, 1);
      ;
    }
  }

  /* Start for S-Function (slrealtimeUDPReceive): '<Root>/UDP Receive' */
  {
    try {
      uint8_t *tempAddr = nullptr;
      uint8_t *tempInterface = nullptr;
      slrealtime::ip::udp::Socket *udpSock = getUDPSocket("0.0.0.0",50060U);
      if (tempAddr)
        delete tempAddr;
      if (tempInterface)
        delete tempInterface;
      sg_DW.UDPReceive_IWORK = 304;
      sg_DW.UDPReceive_PWORK[0] = reinterpret_cast<void*>(udpSock);
      char *buffer = (char *)calloc(65504,sizeof(char));
      sg_DW.UDPReceive_PWORK[1] = (void*)buffer;
    } catch (std::exception& e) {
      std::string tmp = std::string(e.what());
      static std::string eMsg = tmp;
      rtmSetErrorStatus(sg_M, eMsg.c_str());
      rtmSetStopRequested(sg_M, 1);
      ;
    }
  }

  /* InitializeConditions for DiscreteIntegrator: '<S40>/Integrator' */
  sg_DW.Integrator_DSTATE = sg_cal->PID1_InitialConditionForIntegra;

  /* InitializeConditions for DiscreteIntegrator: '<S88>/Integrator' */
  sg_DW.Integrator_DSTATE_a = sg_cal->PID2_InitialConditionForIntegra;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  sg_DW.Delay_DSTATE = sg_cal->Delay_InitialCondition;

  /* SystemInitialize for MATLAB Function: '<Root>/Vel_input_to_disturb_payload1' */
  sg_DW.t_command_received = -1.0;
  sg_DW.profile_triggered = false;

  /* SystemInitialize for MATLAB Function: '<Root>/Vel_input_to_disturb_payload' */
  sg_DW.t_start = 0.0;
  sg_DW.profile_started = false;
}

/* Model terminate function */
void sg_terminate(void)
{
  /* Terminate for S-Function (slrealtimeUDPReceive): '<Root>/UDP Receive1' */
  {
    slrealtime::ip::udp::Socket *udpSock = getUDPSocket("0.0.0.0",5008U);
    if (udpSock)
      delete udpSock;
    char *buffer = (char *)sg_DW.UDPReceive1_PWORK[1];
    if (buffer)
      free(buffer);
  }

  /* Terminate for S-Function (slrealtimeUDPSend): '<Root>/UDP Send' */
  {
    slrealtime::ip::udp::Socket *udpSock = getUDPSocket("0.0.0.0",11000U);
    if (udpSock)
      delete udpSock;
  }

  /* Terminate for S-Function (slrealtimeUDPReceive): '<Root>/UDP Receive' */
  {
    slrealtime::ip::udp::Socket *udpSock = getUDPSocket("0.0.0.0",50060U);
    if (udpSock)
      delete udpSock;
    char *buffer = (char *)sg_DW.UDPReceive_PWORK[1];
    if (buffer)
      free(buffer);
  }
}
