# DefEnum

usage
```c++
#define EM_ARGS1(x) x(a) x(b1) x(b2)
#define EM_ARGS2(x) x(0, a) x(1, b1) x(2, b2)
#define EM_ARGS3(x) x(0, a, "A") x(1, b1, "B1") x(2, b2, "B2")

ENUM_CLASS(EMType21, EM_ARGS1)
ENUM_CLASS(EMType22, EM_ARGS2)
ENUM_CLASS(EMType23, EM_ARGS3)

ENUM_CLASS(EMType1, char, EM_ARGS1)
ENUM_CLASS(EMType2, char, EM_ARGS2)
ENUM_CLASS(EMType3, char, EM_ARGS3)

ENUM_CLASS(EMType41, int, EM_ARGS1, COUNT)
ENUM_CLASS(EMType42, int, EM_ARGS2, COUNT)
ENUM_CLASS(EMType43, int, EM_ARGS3, COUNT)
```