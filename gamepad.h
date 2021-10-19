#pragma once
#pragma comment(lib, "xinput") 

#include <Windows.h>
#include <Xinput.h>
#include <string>


void echo_controller(XINPUT_STATE state);
void print_button(std::string s);




