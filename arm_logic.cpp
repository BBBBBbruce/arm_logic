//rotation reference always x-axis
#include"arm.h"
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
    A.rotate_arm(2, 45);
    A.rotate_arm(3, 45);
    A.print();
    std::cout << "===================================" << "\n";

    

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
