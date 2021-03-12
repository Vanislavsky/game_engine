#include "mat4.h"

mat4::mat4() {
	data.resize(4);
	for (int i = 0; i < 4; i++)
		data[i].resize(4);
}

mat4::mat4(float a11) {
	data.resize(4);
	for (int i = 0; i < 4; i++)
		data[i].resize(4);

	data[0][0] = a11;
}

mat4::mat4(float a11, float a12, float a13, float a21, float a22, float a23, float a31, float a32, float a33) {
	data.resize(4);
	for (int i = 0; i < 4; i++)
		data[i].resize(4);

	data[0][0] = a11;
	data[0][1] = a12;
	data[0][2] = a13;
	data[1][0] = a21;
	data[1][1] = a22;
	data[1][2] = a23;
	data[2][0] = a31;
	data[2][1] = a32;
	data[2][2] = a33;
}

mat4::mat4(const mat4& _mat) {
	data.resize(3);
	for (int i = 0; i < 3; i++)
		data[i].resize(3);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] = _mat.data[i][j];
		}
	}
}

float mat4::get_value(int row, int col) {
	if (row > 4 || col > 4)
		return -1;
	else
		return data[row][col];
}

void mat4::set_value(float value, int row, int col) {
	if (row < 4 || col < 4)
		data[row][col] = value;
}

mat4 mat4::operator+(const mat4& _mat) {
	mat4 res_mat;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res_mat.data[i][j] = data[i][j] + _mat.data[i][j];
		}
	}

	return res_mat;
}

mat4 mat4::operator-(const mat4& _mat) {
	mat4 res_mat;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res_mat.data[i][j] = data[i][j] - _mat.data[i][j];
		}
	}

	return res_mat;
}

mat4 mat4::operator*(const mat4& _mat) {
	mat4 res_mat;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res_mat.data[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				res_mat.data[i][j] += data[i][k] * _mat.data[k][j];
			}
		}
	}

	return res_mat;
}

mat4 mat4::operator*(float value) {
	mat4 res_mat;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res_mat.data[i][j] = data[i][j] * value;
		}
	}

	return res_mat;
}

mat4 mat4::operator*(const vec2& _vec) {
	mat4 res_mat;

	return res_mat;
}

mat4 mat4::operator/(float value) {
	mat4 res_mat;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res_mat.data[i][j] = data[i][j] / value;
		}
	}

	return res_mat;
}

float mat4::determinant() {
	auto det = data[0][0] * data[1][1] * data[2][2] + data[0][1] * data[1][2] * data[2][0] + data[0][2] * data[1][0] * data[2][1];
	auto rev_det = -data[0][2] * data[1][1] * data[2][0] - data[0][1] * data[1][0] * data[2][2] - data[0][0] * data[1][2] * data[2][1];
	return det + rev_det;
}

mat4 mat4::transposed_mat2() {
	mat4 res_mat = *this;

	float temp;
	for (int i = 0; i < 4; ++i) {
		for (int j = i; j < 4; ++j) {
			temp = res_mat.data[i][j];
			res_mat.data[i][j] = res_mat.data[j][i];
			res_mat.data[j][i] = temp;
		}
	}
	return res_mat;
}

//mat3 mat3::algebraic_additions_mat2() {
	//return { data[1][1], -data[0][1], -data[1][0], data[1][1] };
//}

//mat3 mat3::reverse_mat3() {
	//return  algebraic_additions_mat3().transposed_mat3() * (1 / determinant());
//}

bool mat4::operator==(mat4 _mat) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (data[i][j] != _mat.data[i][j]) {
				return false;
			}
		}
	}

	return true;
}
bool mat4::operator!=(mat4 _mat) {
	return !(*this == _mat);
}

mat4 unit_mat4() {
	return { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
}