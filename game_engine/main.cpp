#include <iostream>
#include <cassert>
#include"mat3.h"
#include"vec2.h"
#include"vec3.h"
#include"vec4.h"
#include"mat2.h"
#include"mat3.h"
#include"mat4.h"
#include<glm/mat2x2.hpp>
#include<glm/mat3x3.hpp>
#include<glm/mat4x4.hpp>
#include<glm/vec3.hpp>
#include<glm/vec4.hpp>


void test_vec2() {
    double eps = 1e-7;
    {
        vec2 vec({ 10, 20 });
        glm::vec2 glm_vec(10, 20);
        assert(vec.get_a1() == glm_vec.x);
        assert(vec.get_a2() == glm_vec.y);

        assert(glm::length(glm_vec) == vec.lenght());
        auto normalize_vector = glm::normalize(glm_vec);
        assert(fabs(normalize_vector.x - vec.normal().get_a1()) <= eps);
        assert(fabs(normalize_vector.y - vec.normal().get_a2()) <= eps);

        vec2 vec_2({ 60, 70 });
        glm::vec2 glm_vec_2(60, 70);

        assert((vec + vec_2).get_a1() == (glm_vec + glm_vec_2).x);
        assert((vec + vec_2).get_a2() == (glm_vec + glm_vec_2).y);
        assert((vec - vec_2).get_a1() == (glm_vec - glm_vec_2).x);
        assert((vec - vec_2).get_a2() == (glm_vec - glm_vec_2).y);

    }

    {
        vec2 vec({ 87.0f, 17.4f});
        glm::vec2 glm_vec(87.0f, 17.4f);
        assert(vec.get_a1() == glm_vec.x);
        assert(vec.get_a2() == glm_vec.y);

        assert(glm::length(glm_vec) == vec.lenght());

        auto normalize_vector = glm::normalize(glm_vec);

        assert(fabs(normalize_vector.x - vec.normal().get_a1()) <= eps);
        assert(fabs(normalize_vector.y - vec.normal().get_a2()) <= eps);

        vec2 vec_2({ 111.1f, 24.5f});
        glm::vec2 glm_vec_2(111.1f, 24.5f);

        assert((vec + vec_2).get_a1() == (glm_vec + glm_vec_2).x);
        assert((vec + vec_2).get_a2() == (glm_vec + glm_vec_2).y);
        assert((vec - vec_2).get_a1() == (glm_vec - glm_vec_2).x);
        assert((vec - vec_2).get_a2() == (glm_vec - glm_vec_2).y);
    }


    {
        vec2 vec({ 187.0f, 217.4f });
        glm::vec2 glm_vec(187.0f, 217.4f);
        assert(vec.get_a1() == glm_vec.x);
        assert(vec.get_a2() == glm_vec.y);

        assert(glm::length(glm_vec) == vec.lenght());
        auto normalize_vector = glm::normalize(glm_vec);
        assert(fabs(normalize_vector.x - vec.normal().get_a1()) <= eps);
        assert(fabs(normalize_vector.y - vec.normal().get_a2()) <= eps);

        vec2 vec_2({ 11.1f, 324.5f});
        glm::vec2 glm_vec_2(11.1f, 324.5f);

        assert((vec + vec_2).get_a1() == (glm_vec + glm_vec_2).x);
        assert((vec + vec_2).get_a2() == (glm_vec + glm_vec_2).y);
        assert((vec - vec_2).get_a1() == (glm_vec - glm_vec_2).x);
        assert((vec - vec_2).get_a2() == (glm_vec - glm_vec_2).y);
    }
}


void test_vec3() {
    double eps = 1e-7;
    {
        vec3 vec({ 10, 20 ,30 });
        glm::vec3 glm_vec(10, 20, 30);
        assert(vec.get_a1() == glm_vec.x);
        assert(vec.get_a2() == glm_vec.y);
        assert(vec.get_a3() == glm_vec.z);

        assert(glm::length(glm_vec) == vec.lenght());
        auto normalize_vector = glm::normalize(glm_vec);
        assert(fabs(normalize_vector.x - vec.normal().get_a1()) <= eps);
        assert(fabs(normalize_vector.y - vec.normal().get_a2()) <= eps);
        assert(fabs(normalize_vector.z - vec.normal().get_a3()) <= eps);

        vec3 vec_2({ 60, 70 ,90 });
        glm::vec3 glm_vec_2(60, 70, 90);
       
        assert((vec + vec_2).get_a1() == (glm_vec + glm_vec_2).x);
        assert((vec + vec_2).get_a2() == (glm_vec + glm_vec_2).y);
        assert((vec + vec_2).get_a3() == (glm_vec + glm_vec_2).z);
        assert((vec - vec_2).get_a1() == (glm_vec - glm_vec_2).x);
        assert((vec - vec_2).get_a2() == (glm_vec - glm_vec_2).y);
        assert((vec - vec_2).get_a3() == (glm_vec - glm_vec_2).z);

        assert(glm::cross(glm_vec, glm_vec_2).x == vec.vector_product(vec_2).get_a1());
        assert(glm::cross(glm_vec, glm_vec_2).y == vec.vector_product(vec_2).get_a2());
        assert(glm::cross(glm_vec, glm_vec_2).z == vec.vector_product(vec_2).get_a3());

    }

    {
        vec3 vec({ 87.0f, 17.4f, 30.9f });
        glm::vec3 glm_vec(87.0f, 17.4f, 30.9f);
        assert(vec.get_a1() == glm_vec.x);
        assert(vec.get_a2() == glm_vec.y);
        assert(vec.get_a3() == glm_vec.z);

        assert(glm::length(glm_vec) == vec.lenght());

        auto normalize_vector = glm::normalize(glm_vec);

        //assert(normalize_vector.x == vec.normal().get_a1());
        //assert(normalize_vector.y == vec.normal().get_a2());
        assert(fabs(normalize_vector.x - vec.normal().get_a1()) <= eps);
        assert(fabs(normalize_vector.y - vec.normal().get_a2()) <= eps);
        assert(fabs(normalize_vector.z - vec.normal().get_a3()) <= eps);
        //assert(normalize_vector.z == vec.normal().get_a3());

        vec3 vec_2({ 111.1f, 24.5f, 33.3f });
        glm::vec3 glm_vec_2(111.1f, 24.5f, 33.3f);

        assert((vec + vec_2).get_a1() == (glm_vec + glm_vec_2).x);
        assert((vec + vec_2).get_a2() == (glm_vec + glm_vec_2).y);
        assert((vec + vec_2).get_a3() == (glm_vec + glm_vec_2).z);
        assert((vec - vec_2).get_a1() == (glm_vec - glm_vec_2).x);
        assert((vec - vec_2).get_a2() == (glm_vec - glm_vec_2).y);
        assert((vec - vec_2).get_a3() == (glm_vec - glm_vec_2).z);

        assert(glm::cross(glm_vec, glm_vec_2).x == vec.vector_product(vec_2).get_a1());
        assert(glm::cross(glm_vec, glm_vec_2).y == vec.vector_product(vec_2).get_a2());
        assert(glm::cross(glm_vec, glm_vec_2).z == vec.vector_product(vec_2).get_a3());

    }


    {
        vec3 vec({ 187.0f, 217.4f, 230.9f });
        glm::vec3 glm_vec(187.0f, 217.4f, 230.9f);
        assert(vec.get_a1() == glm_vec.x);
        assert(vec.get_a2() == glm_vec.y);
        assert(vec.get_a3() == glm_vec.z);

        assert(glm::length(glm_vec) == vec.lenght());
        auto normalize_vector = glm::normalize(glm_vec);
        assert(fabs(normalize_vector.x - vec.normal().get_a1()) <= eps);
        assert(fabs(normalize_vector.y - vec.normal().get_a2()) <= eps);
        assert(fabs(normalize_vector.z - vec.normal().get_a3()) <= eps);

        vec3 vec_2({ 11.1f, 324.5f, 333.3f });
        glm::vec3 glm_vec_2(11.1f, 324.5f, 333.3f);

        assert((vec + vec_2).get_a1() == (glm_vec + glm_vec_2).x);
        assert((vec + vec_2).get_a2() == (glm_vec + glm_vec_2).y);
        assert((vec + vec_2).get_a3() == (glm_vec + glm_vec_2).z);
        assert((vec - vec_2).get_a1() == (glm_vec - glm_vec_2).x);
        assert((vec - vec_2).get_a2() == (glm_vec - glm_vec_2).y);
        assert((vec - vec_2).get_a3() == (glm_vec - glm_vec_2).z);

        assert(glm::cross(glm_vec, glm_vec_2).x == vec.vector_product(vec_2).get_a1());
        assert(glm::cross(glm_vec, glm_vec_2).y == vec.vector_product(vec_2).get_a2());
        assert(glm::cross(glm_vec, glm_vec_2).z == vec.vector_product(vec_2).get_a3());

    }
}

void test_vec4() {
    double eps = 1e-5;
    {
        vec4 vec({ 10, 20 ,30, 99 });
        glm::vec4 glm_vec(10, 20, 30, 99);
        assert(vec.get_a1() == glm_vec.x);
        assert(vec.get_a2() == glm_vec.y);
        assert(vec.get_a3() == glm_vec.z);

        assert(fabs(glm::length(glm_vec) - vec.lenght()) <= eps);
        auto normalize_vector = glm::normalize(glm_vec);
        assert(fabs(normalize_vector.x - vec.normal().get_a1()) <= eps);
        assert(fabs(normalize_vector.y - vec.normal().get_a2()) <= eps);
        assert(fabs(normalize_vector.z - vec.normal().get_a3()) <= eps);
        assert(fabs(normalize_vector.w - vec.normal().get_a4()) <= eps);

        vec4 vec_2({ 60, 70 ,90, 12 });
        glm::vec4 glm_vec_2(60, 70, 90, 12);

        assert((vec + vec_2).get_a1() == (glm_vec + glm_vec_2).x);
        assert((vec + vec_2).get_a2() == (glm_vec + glm_vec_2).y);
        assert((vec + vec_2).get_a3() == (glm_vec + glm_vec_2).z);
        assert((vec + vec_2).get_a4() == (glm_vec + glm_vec_2).w);
        assert((vec - vec_2).get_a1() == (glm_vec - glm_vec_2).x);
        assert((vec - vec_2).get_a2() == (glm_vec - glm_vec_2).y);
        assert((vec - vec_2).get_a3() == (glm_vec - glm_vec_2).z);
        assert((vec - vec_2).get_a4() == (glm_vec - glm_vec_2).w);

    }

    {
        vec4 vec({ 87.0f, 17.4f, 30.9f, 411.4f });
        glm::vec4 glm_vec(87.0f, 17.4f, 30.9f, 411.4f);
        assert(vec.get_a1() == glm_vec.x);
        assert(vec.get_a2() == glm_vec.y);
        assert(vec.get_a3() == glm_vec.z);

        //?????????assert(fabs(glm::length(glm_vec) - vec.lenght()) <= eps);
        auto normalize_vector = glm::normalize(glm_vec);
        assert(fabs(normalize_vector.x - vec.normal().get_a1()) <= eps);
        assert(fabs(normalize_vector.y - vec.normal().get_a2()) <= eps);
        assert(fabs(normalize_vector.z - vec.normal().get_a3()) <= eps);
        assert(fabs(normalize_vector.w - vec.normal().get_a4()) <= eps);

        vec4 vec_2({ 111.1f, 24.5f, 33.3f, 99.2f });
        glm::vec4 glm_vec_2(111.1f, 24.5f, 33.3f, 99.2f);

        assert((vec + vec_2).get_a1() == (glm_vec + glm_vec_2).x);
        assert((vec + vec_2).get_a2() == (glm_vec + glm_vec_2).y);
        assert((vec + vec_2).get_a3() == (glm_vec + glm_vec_2).z);
        assert((vec + vec_2).get_a4() == (glm_vec + glm_vec_2).w);
        assert((vec - vec_2).get_a1() == (glm_vec - glm_vec_2).x);
        assert((vec - vec_2).get_a2() == (glm_vec - glm_vec_2).y);
        assert((vec - vec_2).get_a3() == (glm_vec - glm_vec_2).z);
        assert((vec - vec_2).get_a4() == (glm_vec - glm_vec_2).w);

    }


    {
        vec4 vec({ 187.0f, 217.4f, 230.9f, 116.6f });
        glm::vec4 glm_vec(187.0f, 217.4f, 230.9f, 116.6f);
        assert(vec.get_a1() == glm_vec.x);
        assert(vec.get_a2() == glm_vec.y);
        assert(vec.get_a3() == glm_vec.z);

        assert(fabs(glm::length(glm_vec) - vec.lenght()) <= eps);
        auto normalize_vector = glm::normalize(glm_vec);
        assert(fabs(normalize_vector.x - vec.normal().get_a1()) <= eps);
        assert(fabs(normalize_vector.y - vec.normal().get_a2()) <= eps);
        assert(fabs(normalize_vector.z - vec.normal().get_a3()) <= eps);
        assert(fabs(normalize_vector.w - vec.normal().get_a4()) <= eps);

        vec4 vec_2({ 11.1f, 324.5f, 333.3f, 116.6f });
        glm::vec4 glm_vec_2(11.1f, 324.5f, 333.3f, 116.6f);

        assert((vec + vec_2).get_a1() == (glm_vec + glm_vec_2).x);
        assert((vec + vec_2).get_a2() == (glm_vec + glm_vec_2).y);
        assert((vec + vec_2).get_a3() == (glm_vec + glm_vec_2).z);
        assert((vec + vec_2).get_a4() == (glm_vec + glm_vec_2).w);
        assert((vec - vec_2).get_a1() == (glm_vec - glm_vec_2).x);
        assert((vec - vec_2).get_a2() == (glm_vec - glm_vec_2).y);
        assert((vec - vec_2).get_a3() == (glm_vec - glm_vec_2).z);
        assert((vec - vec_2).get_a4() == (glm_vec - glm_vec_2).w);

    }
}

void test_mat2() {
    {
        mat2 mat({ 10, 20, 30, 40 });
        glm::mat2x2 glm_mat(10, 20, 30, 40);

        assert(mat.get_value(0, 0) == glm_mat[0][0]);
        assert(mat.get_value(0, 1) == glm_mat[0][1]);
        assert(mat.get_value(1, 0) == glm_mat[1][0]);
        assert(mat.get_value(1, 1) == glm_mat[1][1]);

        mat2 mat_2({ 50, 21, 9, 30 });
        glm::mat2x2 glm_mat_2(50, 21, 9, 30);

        {
            auto res_mat = mat + mat_2;
            auto glm_res_mat = glm_mat + glm_mat_2;

            assert(res_mat.get_value(0, 0) == glm_res_mat[0][0]);
            assert(res_mat.get_value(0, 1) == glm_res_mat[0][1]);
            assert(res_mat.get_value(1, 0) == glm_res_mat[1][0]);
            assert(res_mat.get_value(1, 1) == glm_res_mat[1][1]);
        }

        {
            auto res_mat = mat - mat_2;
            auto glm_res_mat = glm_mat - glm_mat_2;

            assert(res_mat.get_value(0, 0) == glm_res_mat[0][0]);
            assert(res_mat.get_value(0, 1) == glm_res_mat[0][1]);
            assert(res_mat.get_value(1, 0) == glm_res_mat[1][0]);
            assert(res_mat.get_value(1, 1) == glm_res_mat[1][1]);
        }

        {
            auto res_mat = mat * mat_2;
            auto glm_res_mat = glm_mat * glm_mat_2;
            std::cout << res_mat.get_value(0, 0) << " " << glm_res_mat[0][0];
            assert(res_mat.get_value(0, 0) == glm_res_mat[0][0]);
            assert(res_mat.get_value(0, 1) == glm_res_mat[0][1]);
            assert(res_mat.get_value(1, 0) == glm_res_mat[1][0]);
            assert(res_mat.get_value(1, 1) == glm_res_mat[1][1]);
        }

        {
            //vec2  vec({ 66, 77 });
             //glm::vec2 glm_vec(66, 77);
             //auto res_mat = mat * vec;
             //auto glm_res_mat = glm_mat * glm_vec;

             //assert(res_mat.get_a1() == glm_res_mat.x);
             //assert(res_mat.get_a2() == glm_res_mat.y);
        }
    }

    {
        mat2 mat({ 110.6f, 20.22f, 320.1f, 99.2f });
        glm::mat2x2 glm_mat(110.6f, 20.22f, 320.1f, 99.2f);

        assert(mat.get_value(0, 0) == glm_mat[0][0]);
        assert(mat.get_value(0, 1) == glm_mat[0][1]);
        assert(mat.get_value(1, 0) == glm_mat[1][0]);
        assert(mat.get_value(1, 1) == glm_mat[1][1]);

        mat2 mat_2({ 70.7f, 80.0f, 37.7f, 41.88f });
        glm::mat2x2 glm_mat_2(70.7f, 80.0f, 37.7f, 41.88f);

        {
            auto res_mat = mat + mat_2;
            auto glm_res_mat = glm_mat + glm_mat_2;

            assert(res_mat.get_value(0, 0) == glm_res_mat[0][0]);
            assert(res_mat.get_value(0, 1) == glm_res_mat[0][1]);
            assert(res_mat.get_value(1, 0) == glm_res_mat[1][0]);
            assert(res_mat.get_value(1, 1) == glm_res_mat[1][1]);
        }

        {
            auto res_mat = mat - mat_2;
            auto glm_res_mat = glm_mat - glm_mat_2;

            assert(res_mat.get_value(0, 0) == glm_res_mat[0][0]);
            assert(res_mat.get_value(0, 1) == glm_res_mat[0][1]);
            assert(res_mat.get_value(1, 0) == glm_res_mat[1][0]);
            assert(res_mat.get_value(1, 1) == glm_res_mat[1][1]);
        }

        {
            auto res_mat = mat * mat_2;
            auto glm_res_mat = glm_mat * glm_mat_2;

            assert(res_mat.get_value(0, 0) == glm_res_mat[0][0]);
            assert(res_mat.get_value(0, 1) == glm_res_mat[0][1]);
            assert(res_mat.get_value(1, 0) == glm_res_mat[1][0]);
            assert(res_mat.get_value(1, 1) == glm_res_mat[1][1]);
        }

        {
            //vec2  vec({ 66, 77 });
            //glm::vec2 glm_vec(66, 77);
            //auto res_mat = mat * vec;
            //auto glm_res_mat = glm_mat * glm_vec;

            //assert(res_mat.get_a1() == glm_res_mat.x);
            //assert(res_mat.get_a2() == glm_res_mat.y);
        }
    }
}

void test() {
    test_vec2();
    test_vec3();
    test_vec4();
    test_mat2();
}

int main(int argc, char* argv[]) {
    test();
    return 0;
}