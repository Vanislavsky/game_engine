#include "mat2.h"


mat2::mat2() {
	data.resize(2);
	for (int i = 0; i < 2; i++)
		data[i].resize(2);
}

mat2::mat2(float el) {
	data.resize(2);
	for (int i = 0; i < 2; i++)
		data[i].resize(2);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			data[i][j] = el;
		}
	}
}

mat2::mat2(const vector<float>& _data) {
	data.resize(2);
	for (int i = 0; i < 2; i++)
		data[i].resize(2);

	int i = 0;
	int j = 0;
	for (auto it = _data.begin(); it != _data.end(); it++) {
		data[i][j] = *_data;
		j++;
		if (j > 2) {
			i++;
			j = 0;
		}
	}
}

mat2::mat2(const mat2& _mat) {
	data.resize(2);
	for (int i = 0; i < 2; i++)
		data[i].resize(2);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			data[i][j] = _mat.data[i][j];
		}
	}
}

float mat2::get_value(int row, int col) {
	if (row > 2 || col > 2)
		return -1;
	else
		return data[row][col];
}

void mat2::set_value(float value, int row, int col) {
	if (row < 2 || col < 2)
		data[row][col] = value;
}

mat2 mat2::operator+(const mat2& _mat) {
	mat2 res_mat;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			res_mat.data[i][j] = data[i][j] + _mat.data[i][j];
		}
	}

	return res_mat;
}

mat2 mat2::operator-(const mat2& _mat) {
	mat2 res_mat;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			res_mat.data[i][j] = data[i][j] - _mat.data[i][j];
		}
	}

	return res_mat;
}

mat2 mat2::operator*(const mat2& _mat) {
	mat2 res_mat;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			res_mat.data[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				res_mat.data[i][j] += data[i][k] * _mat.data[k][j];
			}
		}
	}

	return res_mat;
}

mat2 mat2::operator*(float value) {
	mat2 res_mat;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			res_mat.data[i][j] = data[i][j] * value;
		}
	}

	return res_mat;
}

mat2 mat2::operator*(const vec2& _vec) {
	mat2 res_mat;
	
	return res_mat;
}

mat2 mat2::operator/(float value) {
	mat2 res_mat;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			res_mat.data[i][j] = data[i][j] / value;
		}
	}

	return res_mat;
}

float mat2::determinant() {
	return data[0][0] * data[1][1] - data[1][0] * data[0][1];
}

mat2 mat2::transposed_mat2() {
	return { data[0][0], data[1][0], data[0][1], data[1][1] };
}

mat2 mat2::algebraic_additions_mat2() {
	return { data[1][1], -data[0][1], -data[1][0], data[1][1] };
}

mat2 mat2::reverse_mat2() {
	return  algebraic_additions_mat2().transposed_mat2() * (1 / determinant());
}

bool mat2::operator==(mat2 _mat) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (data[i][j] != _mat.data[i][j]) {
				return false;
			}
		}
	}

	return true;
}
bool mat2::operator!=(mat2 _mat) {
	return !(*this == _mat);
}

mat2 unit_mat2() {
	return { 1, 0, 0, 1 };
}