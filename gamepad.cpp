#include "gamepad.h"
#include <iostream>
void print_button(std::string s) {
	std::cout << s << " is pressed" << std::endl;
}


void print_thumbstick() {

}

void echo_controller(XINPUT_STATE state) {
	
	if (state.Gamepad.wButtons == 0x0001)
		print_button("PAD_UP");
	if (state.Gamepad.wButtons == 0x0002)
		print_button("PAD_DOWN");
	if (state.Gamepad.wButtons == 0x0004)
		print_button("PAD_LEFT");
	if (state.Gamepad.wButtons == 0x0008)
		print_button("PAD_RIGHT");
	if (state.Gamepad.wButtons == 0x0010)
		print_button("START");
	if (state.Gamepad.wButtons == 0x0020)
		print_button("BACK");
	if (state.Gamepad.wButtons == 0x0040)
		print_button("LEFT_THUMB");
	if (state.Gamepad.wButtons == 0x0080)
		print_button("RIGHT_THUMB");
	if (state.Gamepad.wButtons == 0x0100)
		print_button("LEFT_SHOULDER");
	if (state.Gamepad.wButtons == 0x0200)
		print_button("RIGHT_SHOULDER"); // this button on my controller is broken
	if (state.Gamepad.wButtons == 0x1000)
		print_button("A");
	if (state.Gamepad.wButtons == 0x2000)
		print_button("B");
	if (state.Gamepad.wButtons == 0x4000)
		print_button("X");
	if (state.Gamepad.wButtons == 0x8000)
		print_button("Y");
	if (state.Gamepad.bLeftTrigger != 0)
		std::cout << "Left trigger pressed: " << (int)state.Gamepad.bLeftTrigger << std::endl;
	if (state.Gamepad.bRightTrigger != 0)
		std::cout << "Right trigger pressed: " << (int)state.Gamepad.bRightTrigger  << std::endl;
	if (state.Gamepad.sThumbLX != 0 || state.Gamepad.sThumbLY != 0) {
		std::cout << "Left stick at direction: (" << state.Gamepad.sThumbLX  << "," << state.Gamepad.sThumbLY << ")" << std::endl;
	}
	if (state.Gamepad.sThumbRX != 0 || state.Gamepad.sThumbRY != 0) {
		std::cout << "Right stick at direction: (" << state.Gamepad.sThumbRX  << "," << state.Gamepad.sThumbRY  << ")" << std::endl;
	}
	//std::cout<< state.Gamepad.wButtons <<std::endl;

}