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

};


class arm_single {
private:
	bool rotation = false;//2d
	float theta_rotation = 0;
	float theta_limit; //360 max, in degree
	float length = 20;
	float current_theta = 0;

protected:
	point start_point = {0,0};
	point end_point = {20,0};
	
public:
	arm_single();
	arm_single(char type_arm, float rotation_angle, float angle_allow, float l);
	~arm_single() {};
	void rotate(float angle);
	void translate(point attach);
	point getstart();
	point getend();
	float get_theta();
	float get_len();
};

class arm : arm_single {
private:
	int num_arms;
	vector<arm_single> arm_collection;
public:
	arm(int num);
	void add_arm(arm_single one_arm);
	void init();
	void rotate_arm(int joint, float angle);
	void print();
	~arm() {};
	
};