﻿#pragma once

#include "tools.hpp"
#include <string>
#include <array>
// #include "driver/gpio.h"
#include "espIO.hpp"

namespace config {

	using std::string;

	struct motor {
		gpio_num_t forward = GPIO_NUM_NC;
		gpio_num_t backward = GPIO_NUM_NC;

		motor() = default;
		motor(gpio_num_t f,gpio_num_t b) :forward(f),backward(b) {}
	};//motor


	//**********************用户配置区开始******************************
	//**********************用户配置区开始******************************
	//**********************用户配置区开始******************************

	inline const string WIFI_SSID = "wifi_ssid";
	inline const string WIFI_PASS = "wifi_pass";


	inline const string ip = "192.168.1.1";//打印机ip

	inline const string mqtt_pass = "00000000";//mqtt密码

	inline const string device_serial = "XXXXXXXXXXXXXXX";//设备序列号

	inline const auto uload_time = 5s;//退料运转时间
	inline const auto load_time = 6s;//进料运转时间,时间要比退料久一些

	inline const auto forward_click = GPIO_NUM_NC;//进料微动
	inline const auto back_click = GPIO_NUM_NC;//退料微动


	inline std::array<motor,16> motors{//电机要使用的GPIO
		 motor{GPIO_NUM_3,GPIO_NUM_2}//通道1,前向GPIO,后向GPIO
		,motor{GPIO_NUM_5,GPIO_NUM_4}//通道2
		,motor{GPIO_NUM_NC,GPIO_NUM_NC}//通道3
		,motor{GPIO_NUM_NC,GPIO_NUM_NC}//通道4
	};//motors
	//小白用户自定义电机使用GPIO时
	//请仔细查询你开发板的针脚定义
	//像合众esp32C3,应该避开usb使用的18,19,LED灯的12,13
	//GPIO_NUM_NC表示不使用


	//**********************用户配置区结束******************************
	//**********************用户配置区结束******************************
	//**********************用户配置区结束******************************



	inline const string mqtt_server = "mqtts://" + ip + ":8883";
	inline const string mqtt_username = "bblp";
	inline const string topic_subscribe = "device/" + device_serial + "/report";
	inline const string topic_publish = "device/" + device_serial + "/request";

}//config