#pragma once
#pragma once

#include<vector>
#include"vec2.h"
#include"vec3.h"

class mat4
{
public:
	mat4();
	mat4(float);
	mat4(float, float, float, float, float, float, float, float, float);
	mat4(const mat4&);

	float get_value(int, int);
	void set_value(float, int, int);

	mat4 operator+(const mat4&);
	mat4 operator-(const mat4&);
	mat4 operator*(const mat4&);
	mat4 operator*(float);
	mat4 operator*(const vec2&);
	mat4 operator/(float);

	float determinant();
	mat4 transposed_mat2();
	mat4 algebraic_additions_mat2();
	mat4 reverse_mat2();

	bool operator==(mat4);
	bool operator!=(mat4);

private:
	std::vector<std::vector<float>> data;
};


mat4 unit_mat4();
mat4 offset_matrix(float, float, float);
mat4 zoom_matrix(float, float, float);
mat4 rotate_matrix(float, const vec3&);


