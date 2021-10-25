# include "arm.h"
#include <cmath>


#define PI 3.14159265

float force(point vec, float world_theta) {
	std::cout << vec << " " << world_theta << std::endl;

	point current_vec = { cos(world_theta * PI / 180),sin(world_theta * PI / 180) };

	float dotproduct = vec.x * current_vec.x + vec.y * current_vec.y;
	float theta_tmp = acos(dotproduct / (vec.magnitude() * current_vec.magnitude()));
	//std::cout << dotproduct << " " << acos(0) << std::endl;
	return vec.magnitude() * sin(theta_tmp);
}

std::ostream& operator << (std::ostream& o, const point& a)
{
	o << "(" << a.x << "," << a.y << ")";
	return o;
}

point current_vector(float angle, float length) {
	// return 2d vector of x and y;
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

void arm_single::rotate(float angle,float current_angle) {
	if (angle + current_angle < theta_limit) {
		world_theta += angle;
		point tmp_vec = current_vector(world_theta, length);
		end_point = start_point + tmp_vec;

	}
	else if (current_angle <theta_limit) {
		world_theta = theta_limit;
		point tmp_vec = current_vector(world_theta, length);
		end_point = start_point + tmp_vec;
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

arm::arm() {
	num_arms = 0;
}

arm::arm(int num) {
	num_arms = num;
}

arm::arm(const arm &arm1) {
	num_arms = arm1.get_arm_num();
	arm_collection = arm1.get_arm_collection();
}

vector<arm_single> arm::get_arm_collection() const{
	return arm_collection;
}

void arm::add_arm(arm_single one_arm) {
	if (arm_collection.size() < num_arms) {
		arm_collection.push_back(one_arm);
	}

}

void arm::rotate_arm(int joint, point vec){
	//std::cout << vec << std::endl;
	//speed = 0.00025 dgree per input
	//std::cout << "echo" << std::endl;
	//std::cout << "joint" << std::endl;
	float angle = 0;
	float current_theta;
	//std::cout << "echo" << std::endl;
	if (joint == 1) {
		current_theta = arm_collection[0].get_theta();
	}
	else {
		current_theta = angle_between(joint - 1);
	}
	//std::cout << "echo" << std::endl;
	angle = force(vec, arm_collection[joint - 1].get_theta())*0.025;//test for later

	arm_collection[joint-1].rotate(angle, current_theta);
	
	//std::cout << "stop" << std::endl;
	for (int i = joint+1; i < arm_collection.size(); i++) {
		current_theta = angle_between(i - 1);
		arm_collection[i].translate(arm_collection[i - 1].getend());
		arm_collection[i].rotate(angle, current_theta);
	}
	//std::cout << "probem" << std::endl;
}

void arm::init() {
	for (int i = 1; i < arm_collection.size(); i++) {
		arm_collection[i].translate(arm_collection[i - 1].getend());
	}
}

int arm::get_arm_num() const {
	return num_arms;
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
