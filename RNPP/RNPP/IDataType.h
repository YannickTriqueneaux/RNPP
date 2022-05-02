#pragma once
#include "StringId.h"
RNPP_NAMESPACE_BEGIN()

class IVariable;
class Context;

class IDataType
{
public:
    typedef StringId::id_t id_t;
    virtual StringId GetTypeName() const = 0;
    virtual IVariable* CreateInstance(const Context* context) = 0;
    virtual void DeleteInstance(IVariable* instance, const Context* context) = 0;


    inline id_t GetId() const { return GetTypeName().GetId(); }
};

RNPP_NAMESPACE_END()