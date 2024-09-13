#ifndef _ROS_ypspur_ros_JointPositionControl_h
#define _ROS_ypspur_ros_JointPositionControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ypspur_ros
{

  class JointPositionControl : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t joint_names_length;
      typedef char* _joint_names_type;
      _joint_names_type st_joint_names;
      _joint_names_type * joint_names;
      uint32_t positions_length;
      typedef double _positions_type;
      _positions_type st_positions;
      _positions_type * positions;
      uint32_t velocities_length;
      typedef double _velocities_type;
      _velocities_type st_velocities;
      _velocities_type * velocities;
      uint32_t accelerations_length;
      typedef double _accelerations_type;
      _accelerations_type st_accelerations;
      _accelerations_type * accelerations;

    JointPositionControl():
      header(),
      joint_names_length(0), st_joint_names(), joint_names(nullptr),
      positions_length(0), st_positions(), positions(nullptr),
      velocities_length(0), st_velocities(), velocities(nullptr),
      accelerations_length(0), st_accelerations(), accelerations(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->joint_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->joint_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->joint_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->joint_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->joint_names_length);
      for( uint32_t i = 0; i < joint_names_length; i++){
      uint32_t length_joint_namesi = strlen(this->joint_names[i]);
      varToArr(outbuffer + offset, length_joint_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->joint_names[i], length_joint_namesi);
      offset += length_joint_namesi;
      }
      *(outbuffer + offset + 0) = (this->positions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->positions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->positions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->positions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->positions_length);
      for( uint32_t i = 0; i < positions_length; i++){
      union {
        double real;
        uint64_t base;
      } u_positionsi;
      u_positionsi.real = this->positions[i];
      *(outbuffer + offset + 0) = (u_positionsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_positionsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_positionsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_positionsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_positionsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_positionsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_positionsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_positionsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->positions[i]);
      }
      *(outbuffer + offset + 0) = (this->velocities_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocities_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocities_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocities_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocities_length);
      for( uint32_t i = 0; i < velocities_length; i++){
      union {
        double real;
        uint64_t base;
      } u_velocitiesi;
      u_velocitiesi.real = this->velocities[i];
      *(outbuffer + offset + 0) = (u_velocitiesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocitiesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocitiesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocitiesi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_velocitiesi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_velocitiesi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_velocitiesi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_velocitiesi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->velocities[i]);
      }
      *(outbuffer + offset + 0) = (this->accelerations_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->accelerations_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->accelerations_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->accelerations_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accelerations_length);
      for( uint32_t i = 0; i < accelerations_length; i++){
      union {
        double real;
        uint64_t base;
      } u_accelerationsi;
      u_accelerationsi.real = this->accelerations[i];
      *(outbuffer + offset + 0) = (u_accelerationsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accelerationsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_accelerationsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_accelerationsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_accelerationsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_accelerationsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_accelerationsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_accelerationsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->accelerations[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t joint_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->joint_names_length);
      if(joint_names_lengthT > joint_names_length)
        this->joint_names = (char**)realloc(this->joint_names, joint_names_lengthT * sizeof(char*));
      joint_names_length = joint_names_lengthT;
      for( uint32_t i = 0; i < joint_names_length; i++){
      uint32_t length_st_joint_names;
      arrToVar(length_st_joint_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_joint_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_joint_names-1]=0;
      this->st_joint_names = (char *)(inbuffer + offset-1);
      offset += length_st_joint_names;
        memcpy( &(this->joint_names[i]), &(this->st_joint_names), sizeof(char*));
      }
      uint32_t positions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->positions_length);
      if(positions_lengthT > positions_length)
        this->positions = (double*)realloc(this->positions, positions_lengthT * sizeof(double));
      positions_length = positions_lengthT;
      for( uint32_t i = 0; i < positions_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_positions;
      u_st_positions.base = 0;
      u_st_positions.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_positions.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_positions.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_positions.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_positions.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_positions.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_positions.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_positions.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_positions = u_st_positions.real;
      offset += sizeof(this->st_positions);
        memcpy( &(this->positions[i]), &(this->st_positions), sizeof(double));
      }
      uint32_t velocities_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->velocities_length);
      if(velocities_lengthT > velocities_length)
        this->velocities = (double*)realloc(this->velocities, velocities_lengthT * sizeof(double));
      velocities_length = velocities_lengthT;
      for( uint32_t i = 0; i < velocities_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_velocities;
      u_st_velocities.base = 0;
      u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_velocities = u_st_velocities.real;
      offset += sizeof(this->st_velocities);
        memcpy( &(this->velocities[i]), &(this->st_velocities), sizeof(double));
      }
      uint32_t accelerations_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      accelerations_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      accelerations_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      accelerations_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->accelerations_length);
      if(accelerations_lengthT > accelerations_length)
        this->accelerations = (double*)realloc(this->accelerations, accelerations_lengthT * sizeof(double));
      accelerations_length = accelerations_lengthT;
      for( uint32_t i = 0; i < accelerations_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_accelerations;
      u_st_accelerations.base = 0;
      u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_accelerations = u_st_accelerations.real;
      offset += sizeof(this->st_accelerations);
        memcpy( &(this->accelerations[i]), &(this->st_accelerations), sizeof(double));
      }
     return offset;
    }

    virtual const char * getType() override { return "ypspur_ros/JointPositionControl"; };
    virtual const char * getMD5() override { return "2ff21d2400d71a236d035d99166b594d"; };

  };

}
#endif
