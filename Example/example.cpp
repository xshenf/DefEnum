//
// Created by Administrator on 2023/8/4.
//
#include <iostream>
#include "DefEnum/DefEnum.h"

using namespace std;

#define EM_ARGS(x) x(0, a) x(1, b1) x(2, b2)

ENUM_CLASS(EMType, int, EM_ARGS)


int main() {
    EMType t = EMType::a;

    cout << StringOf(t) << endl;
    cout << StringOf(TypeOfEMType("b1")) << endl;

    return 0;
}