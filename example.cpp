//
// Created by Administrator on 2023/8/4.
//
#include "include/def_enum/def_enum.h"
#include <cstring>
#include <iostream>

using namespace std;

#define EM_ARGS1(x) x(a) x(b1) x(b2)
#define EM_ARGS2(x) x(1, a) x(3, b1) x(5, b2)
#define EM_ARGS3(x) x(2, a, "A") x(4, b1, "B1") x(6, b2, "B2")

ENUM_CLASS(EMType21, EM_ARGS1)
ENUM_CLASS(EMType22, EM_ARGS2)
ENUM_CLASS(EMType23, EM_ARGS3)

ENUM_CLASS(EMType1, char, EM_ARGS1)
ENUM_CLASS(EMType2, char, EM_ARGS2)
ENUM_CLASS(EMType3, char, EM_ARGS3)

ENUM_CLASS(EMType41, int, EM_ARGS1, COUNT)
ENUM_CLASS(EMType42, int, EM_ARGS2, COUNT)
ENUM_CLASS(EMType43, int, EM_ARGS3, COUNT)

#define TEST(type, name)                                             \
    if (strcmp(StringOf(CONCAT(TypeOf, type)(name)), (name)) != 0) { \
        cout << "failed: line " << __LINE__ << endl;                 \
        return 1;                                                    \
    }

int main() {
    TEST(EMType1, "b1")
    TEST(EMType2, "b1")
    TEST(EMType3, "B1")
    TEST(EMType21, "b1")
    TEST(EMType22, "b1")
    TEST(EMType23, "B1")
    TEST(EMType41, "b1")
    TEST(EMType42, "b1")
    TEST(EMType43, "B1")

    cout << "success" << endl;
    return 0;
}