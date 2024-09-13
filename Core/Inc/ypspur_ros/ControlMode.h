#ifndef _ROS_ypspur_ros_ControlMode_h
#define _ROS_ypspur_ros_ControlMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ypspur_ros
{

  class ControlMode : public ros::Msg
  {
    public:
      typedef uint8_t _vehicle_control_mode_type;
      _vehicle_control_mode_type vehicle_control_mode;
      enum { OPEN =  0 };
      enum { TORQUE =  1 };
      enum { VELOCITY =  2 };

    ControlMode():
      vehicle_control_mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->vehicle_control_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vehicle_control_mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->vehicle_control_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->vehicle_control_mode);
     return offset;
    }

    virtual const char * getType() override { return "ypspur_ros/ControlMode"; };
    virtual const char * getMD5() override { return "93c0f4fc5070bdb87f70b0914a2708f4"; };

  };

}
#endif
