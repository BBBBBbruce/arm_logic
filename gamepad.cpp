#include "gamepad.h"
#include <iostream>

void print_button(std::string s) {
	std::cout << s << " is pressed" << std::endl;

}

void testing( DWORD dwResult, XINPUT_STATE state) {
	std::cout << "testing the gamepad function" << std::endl;
    std::cout << "press esc to exit! " << std::endl;
    int xmax = 0, xmin = 0, ymax = 0, ymin = 0;
    int up = 0, down = 0, pleft = 0, pright = 0, start = 0, back = 0, leftt = 0, rightt = 0;
    int lt = 0, rt = 0, a = 0, b = 0, c_ = 0, d = 0;
    while (true)
    {   
        std::this_thread::sleep_for(std::chrono::milliseconds(150));//sampling rate: 60 times persecond
        
                                                                //++++++++++++++++++++++++++++++++++++++
        dwResult = XInputGetState(0, &state);
        if (dwResult != ERROR_SUCCESS) {
            std::cout << "Hello? where is your controller" << std::endl;
            break;
        }
        echo_controller(state);
        //_gamepad.gamepad_input(state);
        //testing_thumnbstick(state);
        
        if (state.Gamepad.sThumbLX != 0 || state.Gamepad.sThumbLY != 0) {
            if (state.Gamepad.sThumbLX > xmax)
                xmax = state.Gamepad.sThumbLX;
            if (state.Gamepad.sThumbLX < xmin)
                xmin = state.Gamepad.sThumbLX;
            if (state.Gamepad.sThumbLY > ymax)
                ymax = state.Gamepad.sThumbLY;
            if (state.Gamepad.sThumbLY < ymin)
                ymin = state.Gamepad.sThumbLY;
        }


        if (state.Gamepad.wButtons == 0x0001)
            up+=1;
        if (state.Gamepad.wButtons == 0x0002)
            down+=1;
        if (state.Gamepad.wButtons == 0x0004)
            pleft+=1;
        if (state.Gamepad.wButtons == 0x0008)
            pright+=1;
        if (state.Gamepad.wButtons == 0x0010)
            start+=1;
        if (state.Gamepad.wButtons == 0x0020)
            back+=1;
        if (state.Gamepad.wButtons == 0x0040)
            leftt+=1;
        if (state.Gamepad.wButtons == 0x0080)
            rightt+=1;
        if (state.Gamepad.wButtons == 0x0100)
            lt+=1;
        if (state.Gamepad.wButtons == 0x0200)
            rt+=1; // this button on my controller is broken
        if (state.Gamepad.wButtons == 0x1000)
            a+=1;
        if (state.Gamepad.wButtons == 0x2000)
            b+=1;
        if (state.Gamepad.wButtons == 0x4000)
            c_+=1;
        if (state.Gamepad.wButtons == 0x8000)
            d+=1;
        //std::cout << "hello" << std::endl;
        
        
        //++++++++++++++++++++++++++++++++++++++
        if (GetAsyncKeyState(27))
            break;
    }
    std::cout << "xmax: " << xmax << " xmin: " << xmin << " ymax: " << ymax << " ymin: " << ymin << std::endl;
    std::cout << "pad_up: " << up << std::endl;
    std::cout <<"pad_down: "<< down<< std::endl;
    std::cout <<"pad_left: " <<pleft<< std::endl;
    std::cout << "pad_right: "<<pright << std::endl;
    std::cout << "start: "<<start << std::endl;
    std::cout << "back: "<<back << std::endl;
    std::cout << "Left thumb: " << leftt << std::endl;
    std::cout << "Right thumb: " << rightt << std::endl;
    std::cout <<"LB: "<<lt << std::endl;
    std::cout <<"RB: "<<rt << std::endl;
    std::cout <<"A: " <<a<< std::endl;
    std::cout <<"B: "<<b << std::endl;
    std::cout <<"X: "<<c_ << std::endl;
    std::cout <<"Y: "<<d << std::endl;
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
		std::cout << "Left trigger pressed: " << (int)state.Gamepad.bLeftTrigger  << std::endl;
	if (state.Gamepad.bRightTrigger != 0)
		std::cout << "Right trigger pressed: " << (int) state.Gamepad.bRightTrigger << std::endl;
	if (state.Gamepad.sThumbLX > 4000. || state.Gamepad.sThumbLY > 4000.) {
		std::cout << "Left stick at direction: (" << state.Gamepad.sThumbLX  << "," << state.Gamepad.sThumbLY << ")" << std::endl;
	}
	if (state.Gamepad.sThumbRX > 4000. || state.Gamepad.sThumbRY > 4000.) {
		std::cout << "Right stick at direction: (" << state.Gamepad.sThumbRX  << "," << state.Gamepad.sThumbRY  << ")" << std::endl;
	}
	//std::cout<< state.Gamepad.wButtons <<std::endl;
	
}

control::control(arm arm_collection) {
	mode = 0;
	joint1 = 1;
	joint2 = 2;
	angle1 = 0;
	angle2 = 0;
    armset = arm_collection;
}

bool control::button_pressed(XINPUT_STATE state, WORD button) {
	// count more than 65000 detection as pressed
	// change of state.Gamepad.wButtons stop recording the button
	// less than 25000 detection would be considered as mistaken press
	if (state.Gamepad.wButtons == button) {
		return true;
	}
	else {
		return false;
	}
}

void control::toggle_mode() {
    if (mode == 0) {
        mode = 1;
        std::cout << "selecting mode" << std::endl;
    }
    else {
        mode = 0;
        std::cout << "operating mode" << std::endl;
    }
        
        
}

void control::select_joint(WORD dir) {
    if (mode == 1) {
        if (dir == 0x0004) {// left
            if (joint1 > 1) {
                joint1 -= 1;
                std::cout << "joint1 at: " << joint1 << std::endl;
            }
        }
        else if(dir == 0x0008){//right
            if (joint1 + 1 < joint2) {
                joint1 += 1;
                std::cout << "joint1 at: " << joint1 << std::endl;
            }
        }
        if (dir == 0x4000) {// left
            if (joint2-1> joint1) {
                joint2 -= 1;
                std::cout << "joint2 at: " << joint2 << std::endl;
            }
        }
        else if (dir == 0x2000) {//right
            if (joint2< armset.get_arm_num()+1) {
                joint2 += 1;
                std::cout << "joint2 at: " << joint2 << std::endl;
            }
        }

    }
    else {
        std::cout << "in operating mode" << std::endl;
    }

}

void control::change_angle(point vec, short joint) {
    if (mode == 0) {
        //std::cout << vec << std::endl;
        armset.rotate_arm(joint, vec);
        armset.print();
    }
    else {
        std::cout << "in selecting mode" << std::endl;
    }
}

void control::gamepad_input(DWORD dwResult, XINPUT_STATE state) {
	// Y toggle mode: moving or selection
	// PAD_LEFT & PAD_RIGHT is selection
	// moving left or right thumbstick would lock the control to certian arm
	
    int  pd_left = 0, pd_right = 0, y_button = 0;
    int x_button = 0, b_button = 0;
    point left_vec = { 0,0 };
    point right_vec = { 0,0 };
    // initialise some variables as buffer
    std::cout << "program start" << std::endl;

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(150));//sampling rate: 60 times persecond                    
        dwResult = XInputGetState(0, &state);
        if (dwResult != ERROR_SUCCESS) {
            std::cout << "Hello? where is your controller" << std::endl;
            break;
        }

        //+++++ the program below ++++++++
        //std::cout << "stop" << std::endl;
        if (state.Gamepad.wButtons == 0x0004) {// left
            std::cout << "PAD_LEFT is pressed" << std::endl;
            select_joint(0x0004);
        }
        //std::cout << "stop" << std::endl;
        if (state.Gamepad.wButtons == 0x0008) { // right
            std::cout << "PAD_RIGHT is pressed" << std::endl;
            select_joint(0x0008);
        }
        //std::cout << "stop" << std::endl;
        if (state.Gamepad.wButtons == 0x4000) { // X
            std::cout << "Button X is pressed" << std::endl;
            select_joint(0x4000);
        }
        //std::cout << "stop" << std::endl;
        if (state.Gamepad.wButtons == 0x2000) { // B
            std::cout << "Button B is pressed" << std::endl;
            select_joint(0x2000);
        }
        //std::cout << "stop" << std::endl;
        if (state.Gamepad.wButtons == 0x8000) { // Y
            std::cout << "Button Y is pressed" << std::endl;
            toggle_mode();
        }
        //std::cout << "stop" << std::endl;
		// make it sensitive, did not apply sampling, using 4000 as min deadzone 12.3%

		if (abs(state.Gamepad.sThumbLX) > 4000.){
            left_vec.x = float((state.Gamepad.sThumbLX-4000.) / 28768.);
        }
        else {
            left_vec.x = 0.;
        }
        if (abs(state.Gamepad.sThumbLY) > 4000.) {
            left_vec.y = float((state.Gamepad.sThumbLY - 4000.) / 28768.);
        }
        else {
            left_vec.y = 0.;
        }
        //std::cout << "left vector: " << left_vec << std::endl;
        if(left_vec.magnitude()>0)
            change_angle(left_vec, joint1);

        if (abs(state.Gamepad.sThumbRX) > 4000.) {
            right_vec.x = float((state.Gamepad.sThumbRX - 4000) / 28768);
        }
        else {
            right_vec.x = 0.;
        }
        if (abs(state.Gamepad.sThumbRY) > 4000.) {
            right_vec.y = float((state.Gamepad.sThumbRY - 4000.) / 28768.);
        }
        else {
            right_vec.y = 0.;
        }
        //std::cout << "right vector: " << right_vec << std::endl;
        if(right_vec.magnitude()>0)
            change_angle(right_vec, joint2);
        //+++++ the program above ++++++++


        if (GetAsyncKeyState(27))
            break;
    }

}
