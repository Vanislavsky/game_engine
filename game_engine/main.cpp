#include <iostream>
#include"mat3.h"


int main(int argc, char* argv[]) {
    mat3 mat(25, 13, 14, 55, 33, 31, 31, 45, 71);
    mat3 t = mat.transposed_mat2();
    int a;
    return 0;
}