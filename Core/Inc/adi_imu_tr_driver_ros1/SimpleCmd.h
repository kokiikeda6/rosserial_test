#ifndef _ROS_SERVICE_SimpleCmd_h
#define _ROS_SERVICE_SimpleCmd_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace adi_imu_tr_driver_ros1
{

static const char SIMPLECMD[] = "adi_imu_tr_driver_ros1/SimpleCmd";

  class SimpleCmdRequest : public ros::Msg
  {
    public:
      typedef const char* _cmd_type;
      _cmd_type cmd;
      uint32_t args_length;
      typedef char* _args_type;
      _args_type st_args;
      _args_type * args;

    SimpleCmdRequest():
      cmd(""),
      args_length(0), st_args(), args(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_cmd = strlen(this->cmd);
      varToArr(outbuffer + offset, length_cmd);
      offset += 4;
      memcpy(outbuffer + offset, this->cmd, length_cmd);
      offset += length_cmd;
      *(outbuffer + offset + 0) = (this->args_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->args_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->args_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->args_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->args_length);
      for( uint32_t i = 0; i < args_length; i++){
      uint32_t length_argsi = strlen(this->args[i]);
      varToArr(outbuffer + offset, length_argsi);
      offset += 4;
      memcpy(outbuffer + offset, this->args[i], length_argsi);
      offset += length_argsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_cmd;
      arrToVar(length_cmd, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_cmd; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_cmd-1]=0;
      this->cmd = (char *)(inbuffer + offset-1);
      offset += length_cmd;
      uint32_t args_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      args_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      args_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      args_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->args_length);
      if(args_lengthT > args_length)
        this->args = (char**)realloc(this->args, args_lengthT * sizeof(char*));
      args_length = args_lengthT;
      for( uint32_t i = 0; i < args_length; i++){
      uint32_t length_st_args;
      arrToVar(length_st_args, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_args; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_args-1]=0;
      this->st_args = (char *)(inbuffer + offset-1);
      offset += length_st_args;
        memcpy( &(this->args[i]), &(this->st_args), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return SIMPLECMD; };
    virtual const char * getMD5() override { return "1eade9dccb44732e77de8f8c7d444995"; };

  };

  class SimpleCmdResponse : public ros::Msg
  {
    public:
      typedef const char* _msg_type;
      _msg_type msg;
      typedef bool _is_ok_type;
      _is_ok_type is_ok;

    SimpleCmdResponse():
      msg(""),
      is_ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_msg = strlen(this->msg);
      varToArr(outbuffer + offset, length_msg);
      offset += 4;
      memcpy(outbuffer + offset, this->msg, length_msg);
      offset += length_msg;
      union {
        bool real;
        uint8_t base;
      } u_is_ok;
      u_is_ok.real = this->is_ok;
      *(outbuffer + offset + 0) = (u_is_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_msg;
      arrToVar(length_msg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_msg-1]=0;
      this->msg = (char *)(inbuffer + offset-1);
      offset += length_msg;
      union {
        bool real;
        uint8_t base;
      } u_is_ok;
      u_is_ok.base = 0;
      u_is_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_ok = u_is_ok.real;
      offset += sizeof(this->is_ok);
     return offset;
    }

    virtual const char * getType() override { return SIMPLECMD; };
    virtual const char * getMD5() override { return "6552ebbe66387833a46f5b0e8f801f97"; };

  };

  class SimpleCmd {
    public:
    typedef SimpleCmdRequest Request;
    typedef SimpleCmdResponse Response;
  };

}
#endif
