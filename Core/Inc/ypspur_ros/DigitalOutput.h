#ifndef _ROS_ypspur_ros_DigitalOutput_h
#define _ROS_ypspur_ros_DigitalOutput_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace ypspur_ros
{

  class DigitalOutput : public ros::Msg
  {
    public:
      typedef uint8_t _output_type;
      _output_type output;
      typedef ros::Duration _toggle_time_type;
      _toggle_time_type toggle_time;
      enum { HIGH_IMPEDANCE = 0 };
      enum { LOW = 1 };
      enum { HIGH = 2 };
      enum { PULL_UP = 3 };
      enum { PULL_DOWN = 4 };

    DigitalOutput():
      output(0),
      toggle_time()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->output >> (8 * 0)) & 0xFF;
      offset += sizeof(this->output);
      *(outbuffer + offset + 0) = (this->toggle_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->toggle_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->toggle_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->toggle_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->toggle_time.sec);
      *(outbuffer + offset + 0) = (this->toggle_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->toggle_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->toggle_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->toggle_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->toggle_time.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->output =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->output);
      this->toggle_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->toggle_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->toggle_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->toggle_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->toggle_time.sec);
      this->toggle_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->toggle_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->toggle_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->toggle_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->toggle_time.nsec);
     return offset;
    }

    virtual const char * getType() override { return "ypspur_ros/DigitalOutput"; };
    virtual const char * getMD5() override { return "019a9291acebccdd82910cc6e11634c7"; };

  };

}
#endif
