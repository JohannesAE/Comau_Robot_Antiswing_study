#include "rte_sg_parameters.h"
#include "sg.h"
#include "sg_cal.h"

extern sg_cal_type sg_cal_impl;
namespace slrealtime
{
  /* Description of SEGMENTS */
  SegmentVector segmentInfo {
    { (void*)&sg_cal_impl, (void**)&sg_cal, sizeof(sg_cal_type), 2 }
  };

  SegmentVector &getSegmentVector(void)
  {
    return segmentInfo;
  }
}                                      // slrealtime
