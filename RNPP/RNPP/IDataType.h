#pragma once
#include "StringId.h"
class IDataType
{
public:
    typedef StringId::id_t id_t;
    virtual StringId GetTypeName() const = 0;
    inline id_t GetId() const { return GetTypeName().GetId(); }
};