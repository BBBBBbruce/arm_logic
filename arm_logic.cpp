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
    arm_single arm1('2d', 180., 360., 20.);
    arm_single arm2('2d', 180., 360., 30.);
    arm_single arm3('2d', 180., 360., 20.);
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
    
    return 0;
    
}
