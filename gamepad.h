#pragma once
#pragma comment(lib, "xinput") 

#include <Windows.h>
#include <Xinput.h>
#include <string>
#include <thread>
#include <chrono>
#include <winuser.h>
#include "arm.h"

void echo_controller(XINPUT_STATE state);
void print_button(std::string s);
void testing( DWORD dwResult, XINPUT_STATE state);

class control {
private:
	short mode; // 0 for moving, 1 for selection
	short joint1;
	short joint2;
	float angle1;
	float angle2;
	arm armset;

public:
	control(arm arm_collection);
	void gamepad_input(DWORD dwResult, XINPUT_STATE state);
	bool button_pressed(XINPUT_STATE state, WORD button);
	void toggle_mode();
	void select_joint(WORD dir);
	void change_angle(point vec, short joint);

};


