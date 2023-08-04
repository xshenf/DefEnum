//
// Created by Administrator on 2023/8/4.
//

#ifndef DEFENUM_DEFENUM_H
#define DEFENUM_DEFENUM_H

#include <map>
#include <string>

#define ENUM_CLASS(enumType, valueType, argsDef) \
    enum class enumType : valueType {            \
        argsDef(ENUM_VALUE)                      \
                DEFAULT                          \
    };                                           \
    ENUM_NAME(enumType, valueType, argsDef)      \
    ENUM_TYPE(enumType, valueType, argsDef)

#define ENUM_NAME(enumType, valueType, argsDef)     \
    const char *StringOf(enumType type) {           \
        switch (static_cast<valueType>(type)) {     \
            argsDef(ENUM_CASE) default : return ""; \
        }                                           \
    }

#define ENUM_TYPE(enumType, valueType, argsDef)                                                                           \
    enumType TypeOf##enumType(const std::string &name) {                                                                  \
        std::map<std::string, valueType> name2Type = {argsDef(ENUM_PAIR){"", static_cast<valueType>(enumType::DEFAULT)}}; \
        auto it = name2Type.find(name);                                                                                   \
        if (it != name2Type.end()) {                                                                                      \
            return static_cast<enumType>(it->second);                                                                     \
        }                                                                                                                 \
        return enumType::DEFAULT;                                                                                         \
    }

#define ENUM_VALUE(...) ENUM_VALUE2(__VA_ARGS__)
#define ENUM_PAIR(...) ENUM_PAIR2(__VA_ARGS__)
#define ENUM_CASE(...) ENUM_CASE2(__VA_ARGS__)

#define ENUM_VALUE1(value) value,
#define ENUM_VALUE2(id, value) value = id,
#define ENUM_VALUE3(id, value, name) value = id,

#define ENUM_PAIR2(id, value) {#value, id},

#define ENUM_CASE2(id, value) \
    case id:                  \
        return #value;

#endif//DEFENUM_DEFENUM_H
