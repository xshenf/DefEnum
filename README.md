# DefEnum

使用宏定义，生成enum与string相互转换函数`StringOf(Enum)`,`TypeOfEnum(string)`

usage
```c++
#define EM_ARGS1(x) x(a) x(b1) x(b2)
ENUM_CLASS(EMType21, EM_ARGS1)

#define EM_ARGS2(x) x(1, a) x(3, b1) x(5, b2)
ENUM_CLASS(EMType2, char, EM_ARGS2)

#define EM_ARGS3(x) x(2, a, "A") x(4, b1, "B1") x(6, b2, "B2")
ENUM_CLASS(EMType41, int, EM_ARGS1, COUNT)
```