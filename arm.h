#ifndef ARM_H
#define ARM_H 

#include<vector>
#include<iostream>
using namespace std;

struct point {
	float x;
	float y;
	//float z; // left for 3D case;

	point operator+(const point& a) const
	{
		return point{a.x + x, a.y + y};
	}
	
	point operator-(const point& a) const
	{
		return point{ x - a.x  , y - a.y  };
	}

	float magnitude() {
		return sqrt(x * x + y * y);
	}

};
std::ostream& operator << (std::ostream& o, const point& a);

class arm_single {
private:
	bool rotation = false;//2d
	float theta_rotation = 0;
	float theta_limit; //360 max, in degree
	float length = 20;
	float world_theta = 0;

protected:
	point start_point = {0,0};
	point end_point = {20,0};
	
public:
	arm_single();
	arm_single(char type_arm, float rotation_angle, float angle_allow, float l);
	~arm_single() {};
	void rotate(float angle, float current_angle);
	void translate(point attach);
	point getstart();
	point getend();
	float get_theta();
	float get_len();
};

class arm : arm_single {
private:
	int num_arms =0 ;
	vector<arm_single> arm_collection;
public:
	arm();
	arm(int num);
	arm(const arm &arm1);
	void add_arm(arm_single one_arm);
	void init();
	void rotate_arm(int joint, point vec);
	void print();
	float angle_between(int joint);
	int get_arm_num() const;
	vector<arm_single> get_arm_collection()const;
	~arm() {};
	
};

#endif