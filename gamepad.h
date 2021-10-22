#pragma once
#pragma comment(lib, "xinput") 

#include <Windows.h>
#include <Xinput.h>
#include <string>


void echo_controller(XINPUT_STATE state);
void print_button(std::string s);
void testing_thumnbstick(XINPUT_STATE state);
void testing_trigger(XINPUT_STATE state);

class control {
private:
	short mode; // 0 for moving, 1 for selection
	short joint1;
	short joint2;
	float angle1;
	float angle2;

public:
	control();
	void gamepad_input(XINPUT_STATE state);

};


