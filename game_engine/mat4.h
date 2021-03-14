#pragma once
#pragma once

#include<vector>
#include"vec2.h"
#include"vec3.h"
#include"vec4.h"

class mat4
{
public:
	mat4();
	mat4(float);
	mat4(const std::vector<float>&);
	mat4(const mat4&);

	float get_value(int, int);
	void set_value(float, int, int);

	mat4 operator+(const mat4&);
	mat4 operator-(const mat4&);
	mat4 operator*(const mat4&);
	mat4 operator*(float);
	vec4 operator*(vec4&);
	mat4 operator/(float);

	float determinant();
	mat4 transposed_mat4();
	float algebraic_addition(int, int);
	mat4 algebraic_additions_mat4();
	mat4 reverse_mat4();

	bool operator==(mat4);
	bool operator!=(mat4);

private:
	std::vector<std::vector<float>> data;
};


mat4 unit_mat4();
mat4 offset_matrix(float, float, float);
mat4 zoom_matrix(float, float, float);
mat4 rotate_matrix(float, const vec3&);


