#ifndef _ROS_ublox_msgs_EsfALG_h
#define _ROS_ublox_msgs_EsfALG_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ublox_msgs
{

  class EsfALG : public ros::Msg
  {
    public:
      typedef uint32_t _iTOW_type;
      _iTOW_type iTOW;
      typedef uint8_t _version_type;
      _version_type version;
      typedef uint8_t _flags_type;
      _flags_type flags;
      typedef uint8_t _errors_type;
      _errors_type errors;
      typedef uint8_t _reserved0_type;
      _reserved0_type reserved0;
      typedef uint32_t _yaw_type;
      _yaw_type yaw;
      typedef int16_t _pitch_type;
      _pitch_type pitch;
      typedef int16_t _roll_type;
      _roll_type roll;
      enum { CLASS_ID =  16 };
      enum { MESSAGE_ID =  20 };
      enum { FLAGS_AUTO_MNT_ALG_ON =  0 };
      enum { FLAGS_STATUS =  14 };
      enum { FLAGS_STATUS_USER_FIXED_ANGLES_USED =  0 };
      enum { FLAGS_STATUS_ROLL_PITCH_ANGLES_ALIGNEMENT_ONGOING =  1 };
      enum { FLAGS_STATUS_ROLL_PITCH_YAW_ANGLES_ALIGNEMENT_ONGOING =  2 };
      enum { FLAGS_STATUS_COARSE_ALIGNMENT_USED =  3 };
      enum { FLAGS_STATUS_FINE_ALIGNEMENT_USED =  4 };
      enum { ERROR_TILT_ARG_ERROR =  1 };
      enum { ERROR_YAW_ARG_ERROR =  2 };
      enum { ERROR_ANGLE_ERROR =  3 };

    EsfALG():
      iTOW(0),
      version(0),
      flags(0),
      errors(0),
      reserved0(0),
      yaw(0),
      pitch(0),
      roll(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->iTOW >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->iTOW >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->iTOW >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->iTOW >> (8 * 3)) & 0xFF;
      offset += sizeof(this->iTOW);
      *(outbuffer + offset + 0) = (this->version >> (8 * 0)) & 0xFF;
      offset += sizeof(this->version);
      *(outbuffer + offset + 0) = (this->flags >> (8 * 0)) & 0xFF;
      offset += sizeof(this->flags);
      *(outbuffer + offset + 0) = (this->errors >> (8 * 0)) & 0xFF;
      offset += sizeof(this->errors);
      *(outbuffer + offset + 0) = (this->reserved0 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reserved0);
      *(outbuffer + offset + 0) = (this->yaw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->yaw >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->yaw >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->yaw >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw);
      union {
        int16_t real;
        uint16_t base;
      } u_pitch;
      u_pitch.real = this->pitch;
      *(outbuffer + offset + 0) = (u_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pitch);
      union {
        int16_t real;
        uint16_t base;
      } u_roll;
      u_roll.real = this->roll;
      *(outbuffer + offset + 0) = (u_roll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->roll);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->iTOW =  ((uint32_t) (*(inbuffer + offset)));
      this->iTOW |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->iTOW |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->iTOW |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->iTOW);
      this->version =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->version);
      this->flags =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->flags);
      this->errors =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->errors);
      this->reserved0 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->reserved0);
      this->yaw =  ((uint32_t) (*(inbuffer + offset)));
      this->yaw |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->yaw |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->yaw |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->yaw);
      union {
        int16_t real;
        uint16_t base;
      } u_pitch;
      u_pitch.base = 0;
      u_pitch.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pitch = u_pitch.real;
      offset += sizeof(this->pitch);
      union {
        int16_t real;
        uint16_t base;
      } u_roll;
      u_roll.base = 0;
      u_roll.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->roll = u_roll.real;
      offset += sizeof(this->roll);
     return offset;
    }

    virtual const char * getType() override { return "ublox_msgs/EsfALG"; };
    virtual const char * getMD5() override { return "9a16c82ca78b0658bd506bfde3a1b262"; };

  };

}
#endif
