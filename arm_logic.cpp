//rotation reference always x-axis
#define GLFW_INCLUDE_VULKAN
#include"arm.h"
#include "gamepad.h"
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>


int main()
{   
   
    std::cout << "run a test" << std::endl;
    arm_single arm1('2d', 180, 360, 20);
    arm_single arm2('2d', 180, 360, 30);
    arm_single arm3('2d', 180, 360, 20);
    arm A(3);
    A.add_arm(arm1);
    A.add_arm(arm2);
    A.add_arm(arm3);
    A.init();
    A.print();
    std::cout << "===================================" << "\n";
    //A.rotate_arm(2, 45);
    //A.rotate_arm(3, 45);
    //A.print();
    //std::cout << "===================================" << "\n";
    
    char c;
    DWORD dwResult;
    XINPUT_STATE state;
    dwResult = XInputGetState(0, &state);
    control _gamepad(A);
    //testing( dwResult, state);
    _gamepad.gamepad_input(dwResult, state);
    /*
    std::cout << "testing the gamepad function" << std::endl;
    std::cout << "press esc to exit! " << std::endl;
    int xmax = 0, xmin = 0, ymax = 0, ymin = 0;
    int up = 0, down = 0, pleft = 0, pright = 0, start = 0, back = 0, leftt = 0, rightt = 0;
    int lt = 0, rt = 0, a = 0, b = 0, c_ = 0, d = 0;
    while (true)
    {   
        std::this_thread::sleep_for(std::chrono::seconds(1/15));//sampling rate: 60 times persecond
        
                                                                //++++++++++++++++++++++++++++++++++++++
        dwResult = XInputGetState(0, &state);
        if (dwResult != ERROR_SUCCESS) {
            std::cout << "Hello? where is your controller" << std::endl;
            break;
        }
        //echo_controller(state);
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

    */
    return 0;
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
