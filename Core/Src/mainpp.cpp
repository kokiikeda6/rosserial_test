/*
 * main.cpp

 *
 *  Created on: 2018/01/17
 *      Author: yoneken
 */
#include <mainpp.h>
#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;

void messageCb(const std_msgs::String& msg){
    if (strcmp(msg.data, "ON") == 0) {
        // LEDを点灯
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
    } else if (strcmp(msg.data, "OFF") == 0) {
        // LEDを消灯
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
    }
}

//std_msgs::String str_msg;
//ros::Publisher chatter("/chatter", &str_msg);
//char hello[] = "Hello world!";
ros::Subscriber<std_msgs::String> sub("led_control", &messageCb);


void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->reset_rbuf();
}

void setup(void)
{
  nh.initNode();
  nh.subscribe(sub); //サブスクライバを登録
//  nh.advertise(chatter);
}

void loop(void)
{
//#ifdef STM32F4xx
//  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
//#endif
//
//#ifdef STM32F3xx
//  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0);
//#endif

//  str_msg.data = hello;
//  chatter.publish(&str_msg);
  nh.spinOnce();
  HAL_Delay(10);
}
