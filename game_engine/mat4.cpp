#include "mat4.h"
#include "mat3.h"
#include<cmath>
#include<vector>

mat4::mat4() {
	data.resize(4);
	for (int i = 0; i < 4; i++)
		data[i].resize(4);
}

mat4::mat4(float el) {
	data.resize(4);
	for (int i = 0; i < 4; i++)
		data[i].resize(4);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] = el;
		}
	}
}

mat4::mat4(const std::vector<float>& _data) {
	data.resize(4);
	for (int i = 0; i < 4; i++)
		data[i].resize(4);
	
	int i = 0;
	int j = 0;
	for (auto it = _data.begin(); it != _data.end(); it++) {
		data[i][j] = *it;
		j++;
		if (j > 4) {
			i++;
			j = 0;
		}
	}
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

vec4 mat4::operator*(vec4& _vec) {
	float temp_a1 = data[0][0] * _vec.get_a1() + data[0][1] * _vec.get_a2() + data[0][2] * _vec.get_a3() + data[0][3] * _vec.get_a4();
	float temp_a2 = data[1][0] * _vec.get_a1() + data[1][1] * _vec.get_a2() + data[1][2] * _vec.get_a3() + data[1][3] * _vec.get_a4();
	float temp_a3 = data[2][0] * _vec.get_a1() + data[2][1] * _vec.get_a2() + data[2][2] * _vec.get_a3() + data[2][3] * _vec.get_a4();
	float temp_a4 = data[3][0] * _vec.get_a1() + data[3][1] * _vec.get_a2() + data[3][2] * _vec.get_a3() + data[3][3] * _vec.get_a4();

	return { temp_a1, temp_a2, temp_a3, temp_a4 };
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

mat4 mat4::transposed_mat4() {
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

float mat4::algebraic_addition(int row_index, int col_index) {
	mat3 minor_mat;
	int r = 0;
	int c = 0;
	for (int i = 0; i < 3; i++) {
		if (i == row_index)
			break;
		for (int j = 0; j < 3; j++) {
			if (j == col_index)
				break;
			minor_mat.set_value(data[i][j], r, c);
			c++;
			if (c == 3) {
				c = 0;
				r++;
			}
		}
	}

	return minor_mat.determinant() * pow(-1, row_index + col_index);
}

mat4 mat4::algebraic_additions_mat4() {
	std::vector<float> algebraic_additions_vector{ algebraic_addition(0, 0), algebraic_addition(0, 1), algebraic_addition(0, 2), algebraic_addition(0, 3),
					algebraic_addition(1, 0), algebraic_addition(1, 1), algebraic_addition(1, 2), algebraic_addition(1, 3), algebraic_addition(2, 0),
					algebraic_addition(2, 1), algebraic_addition(2, 2), algebraic_addition(2, 3), algebraic_addition(3, 0),
					algebraic_addition(3, 1), algebraic_addition(3, 2), algebraic_addition(3, 3)};
	return { algebraic_additions_vector };
}

mat4 mat4::reverse_mat4() {
	return  algebraic_additions_mat4().transposed_mat4() * (1 / determinant());
}

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
	mat4 unit_mat4;
	unit_mat4.set_value(1, 0, 0);
	unit_mat4.set_value(1, 1, 1);
	unit_mat4.set_value(1, 2, 2);
	unit_mat4.set_value(1, 3, 3);
	return unit_mat4;
}

mat4 offset_matrix(float x, float y, float z) {
	mat4 off_mat4;
	off_mat4.set_value(1,1,1);
	off_mat4.set_value(1, 2, 2);
	off_mat4.set_value(1, 3, 3);
	off_mat4.set_value(1, 4, 4);
	off_mat4.set_value(x, 1, 4);
	off_mat4.set_value(y, 2, 4);
	off_mat4.set_value(z, 3, 4);
	return off_mat4;
}

mat4 zoom_matrix(float s1, float s2, float s3) {
	mat4 zoom_mat4;
	zoom_mat4.set_value(s1, 1, 1);
	zoom_mat4.set_value(s2, 2, 2);
	zoom_mat4.set_value(s3, 3, 3);
	zoom_mat4.set_value(1, 4, 4);
	return zoom_mat4;
}

mat4 rotate_matrix(float angle, vec3& arbitrary_axis) {
	mat4 rotate_mat4;
	rotate_mat4.set_value(cos(angle) + pow(arbitrary_axis.get_a1(), 2) * (1 - cos(angle)), 1, 1);
	rotate_mat4.set_value(arbitrary_axis.get_a1() * arbitrary_axis.get_a2() * (1 - cos(angle)) - arbitrary_axis.get_a3() * sin(angle), 1, 2);
	rotate_mat4.set_value(arbitrary_axis.get_a1() * arbitrary_axis.get_a3() * (1 - cos(angle)) + arbitrary_axis.get_a2() * sin(angle), 1, 3);
	rotate_mat4.set_value(arbitrary_axis.get_a2() * arbitrary_axis.get_a1() * (1 - cos(angle)) + arbitrary_axis.get_a3() * sin(angle), 2, 1);
	rotate_mat4.set_value(cos(angle) + pow(arbitrary_axis.get_a2(), 2) * (1 - cos(angle)), 2, 2);
	rotate_mat4.set_value(arbitrary_axis.get_a2() * arbitrary_axis.get_a3() * (1 - cos(angle)) - arbitrary_axis.get_a1() * sin(angle), 2, 3);
	rotate_mat4.set_value(arbitrary_axis.get_a3() * arbitrary_axis.get_a1() * (1 - cos(angle)) - arbitrary_axis.get_a2() * sin(angle), 3, 1);
	rotate_mat4.set_value(arbitrary_axis.get_a3() * arbitrary_axis.get_a2() * (1 - cos(angle)) + arbitrary_axis.get_a1() * sin(angle), 3, 2);
	rotate_mat4.set_value(cos(angle) + pow(arbitrary_axis.get_a3(), 2) * (1 - cos(angle)), 3, 3);
	rotate_mat4.set_value(1, 4, 4);

	return rotate_mat4;

}