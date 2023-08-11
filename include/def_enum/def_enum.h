//
// Created by Administrator on 2023/8/4.
//

#ifndef DEFENUM_DEF_ENUM_H
#define DEFENUM_DEF_ENUM_H

#include <map>
#include <string>

#define ENUM_CLASS(...) CONCAT(ENUM_CLASS, ARGS_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define ENUM_CLASS2(enumType, argsDef) ENUM_CLASS3(enumType, int, argsDef)
#define ENUM_CLASS3(enumType, valueType, argsDef) ENUM_CLASS4(enumType, int, argsDef, DEFAULT)
#define ENUM_CLASS4(enumType, valueType, argsDef, defaultEnum) \
    enum class enumType : valueType {                          \
        argsDef(ENUM_VALUE)                                    \
                defaultEnum                                    \
    };                                                         \
    CONCAT(ENUM_NAME, FIRST_ARG(argsDef(ENUM_ARGS_COUNT)))(enumType, valueType, argsDef, defaultEnum)       \
    ENUM_TYPE(enumType, valueType, argsDef, defaultEnum)

#define ENUM_NAME1(enumType, valueType, argsDef, defaultEnum)        \
    const char *StringOf(enumType type) {                            \
        const char *names[] = {argsDef(ENUM_VALUE_NAME) "DEFAULT"};  \
        return names[static_cast<int>(type)];                        \
    }

#define ENUM_NAME2(enumType, valueType, argsDef, defaultEnum) \
    const char *StringOf(enumType type) {                     \
        switch(static_cast<valueType>(type)) {                \
            argsDef(ENUM_CASE)                                \
            default: return #defaultEnum;                     \
        }                                                     \
    }
#define ENUM_NAME3 ENUM_NAME2

#define ENUM_TYPE(enumType, valueType, argsDef, defaultEnum)                                                                  \
    enumType TypeOf##enumType(const std::string &name) {                                                                      \
        CONCAT(EXTRA_ID, FIRST_ARG(argsDef(ENUM_ARGS_COUNT)))(valueType)                                                      \
        std::map<std::string, valueType> name2Type = {argsDef(ENUM_PAIR){"", static_cast<valueType>(enumType::defaultEnum)}}; \
        auto it = name2Type.find(name);                                                                                       \
        if (it != name2Type.end()) {                                                                                          \
            return static_cast<enumType>(it->second);                                                                         \
        }                                                                                                                     \
        return enumType::defaultEnum;                                                                                         \
    }

#define ENUM_VALUE(...) CONCAT(ENUM_VALUE, ARGS_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define ENUM_PAIR(...) CONCAT(ENUM_PAIR, ARGS_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define ENUM_CASE(...) CONCAT(ENUM_CASE, ARGS_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define ENUM_VALUE_NAME(...) CONCAT(ENUM_VALUE_NAME, ARGS_COUNT(__VA_ARGS__))(__VA_ARGS__)

#define ENUM_VALUE1(value) value,
#define ENUM_VALUE2(id, value) value = id,
#define ENUM_VALUE3(id, value, name) value = id,

#define ENUM_PAIR1(value) {#value, id++},
#define ENUM_PAIR2(id, value) {#value, id},
#define ENUM_PAIR3(id, value, name) {name, id},

#define ENUM_VALUE_NAME1(value) #value,
#define ENUM_CASE2(id, value)  case id: return #value;
#define ENUM_CASE3(id, value, name)  case id: return name;

#define ENUM_ARGS_COUNT(...) ARGS_COUNT(__VA_ARGS__),

#define FIRST_ARG(...) FIRST_ARG_IMPL(__VA_ARGS__)
#define FIRST_ARG_IMPL(x1, ...) x1

#define EXTRA_ID1(valueType) valueType id = 0;
#define EXTRA_ID2(valueType)
#define EXTRA_ID3(valueType)

#define CONCAT(a, b) CONCAT_IMPL(a, b)
#define CONCAT_IMPL(a, b) a##b
#define ARGS_COUNT(...) ARGS_COUNT_HELPER(__VA_ARGS__, 5, 4, 3, 2, 1)
#define ARGS_COUNT_HELPER(c5, c4, c3, c2, c1, n, ...) n

#endif//DEFENUM_DEF_ENUM_H
