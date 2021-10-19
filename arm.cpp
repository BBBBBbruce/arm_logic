#include "arm.h"
#include <cmath>


#define PI 3.14159265

std::ostream& operator << (std::ostream& o, const point& a)
{
	o << "(" << a.x << "," << a.y << ")";
	return o;
}
point current_vector(float angle, float length) {
	float x, y;
	x = cos(angle * PI / 180);
	//std::cout << x << std::endl;
	y = sin(angle * PI / 180);
	//2d only
	float mag = sqrt(x * x + y * y);
	x /= mag;
	y /= mag;
	point iivector = {x*length,y*length};
	return iivector;
}

arm_single::arm_single() {
	theta_limit = 360;
}

arm_single::arm_single(char type_arm, float rotation_angle, float angle_allow, float l) {
	//default 2d
	if (type_arm == '3d') {
		rotation = true;
		theta_rotation = rotation_angle;
		theta_limit = angle_allow;
		length = l;

	}
	else
		theta_limit = angle_allow;
		length = l;
		end_point = { l,0 };

}

void arm_single::rotate(float angle) {
	if (angle + world_theta < theta_limit) {
		world_theta = angle + world_theta;
		point tmp_vec = current_vector(world_theta, length);
		end_point = start_point + tmp_vec;

	}
	else if (world_theta<theta_limit) {
		float diff = theta_limit - world_theta;
		world_theta = theta_limit;
		point tmp_vec = current_vector(diff, length);
		end_point.x = start_point.x + tmp_vec.x;
		end_point.y = start_point.y + tmp_vec.y;
	}
}

void arm_single::translate(point attach) {
	point tmpvec = end_point - start_point;
	start_point = attach;
	end_point = start_point + tmpvec;

}

point arm_single::getend() {
	return end_point;
}

point arm_single::getstart() {
	return start_point;
}

float arm_single::get_theta() {
	return world_theta;
}

float arm_single::get_len() {
	return length;
}

arm::arm(int num) {
	num_arms = num;
}
void arm::add_arm(arm_single one_arm) {
	if (arm_collection.size() < num_arms) {
		arm_collection.push_back(one_arm);
	}

}

void arm::rotate_arm(int joint, float angle){
	arm_collection[joint-1].rotate(angle);
	for (int i = joint; i < arm_collection.size(); i++) {
		arm_collection[i].translate(arm_collection[i - 1].getend());
		arm_collection[i].rotate(angle);
	}
}

void arm::init() {
	for (int i = 1; i < arm_collection.size(); i++) {
		arm_collection[i].translate(arm_collection[i - 1].getend());
	}
}

void arm::print() {
	for (int i = 0; i < arm_collection.size(); i++) {
		std::cout << "arm " << i + 1 << " : {"<<arm_collection[i].getstart()<<"," << arm_collection[i].getend()<<"}, Angle at "<< arm_collection[i].get_theta()<<" length is: "<<arm_collection[i].get_len() << "\n";
	}
}

float arm::angle_between(int joint) {
	if (joint != 1) {
		return arm_collection[joint - 1].get_theta() + 180 - arm_collection[joint - 2].get_theta();
	}
	else
		return -1;
}
