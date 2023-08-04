//
// Created by Administrator on 2023/8/4.
//

#ifndef DEFENUM_DEFENUM_H
#define DEFENUM_DEFENUM_H

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
    ENUM_NAME(enumType, valueType, argsDef, defaultEnum)       \
    ENUM_TYPE(enumType, valueType, argsDef, defaultEnum)

#define ENUM_NAME(enumType, valueType, argsDef, defaultEnum)        \
    const char *StringOf(enumType type) {                           \
        const char *names[] = {argsDef(ENUM_VALUE_NAME) "DEFAULT"}; \
        return names[static_cast<int>(type)];                       \
    }

#define ENUM_TYPE(enumType, valueType, argsDef, defaultEnum)                                                                  \
    enumType TypeOf##enumType(const std::string &name) {                                                                      \
        valueType id = 0;                                                                                                     \
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
#define ENUM_VALUE_NAME2(id, value) #value,
#define ENUM_VALUE_NAME3(id, value, name) name,

#define CONCAT(a, b) CONCAT_IMPL(a, b)
#define CONCAT_IMPL(a, b) a##b
#define ARGS_COUNT(...) ARGS_COUNT_HELPER(__VA_ARGS__, 5, 4, 3, 2, 1)
#define ARGS_COUNT_HELPER(c5, c4, c3, c2, c1, n, ...) n

#endif//DEFENUM_DEFENUM_H
