#pragma once
#include "StringId.h"


RNPP_NAMESPACE_BEGIN()

class Context;

class INodeType
{
public:
    typedef StringId::id_t id_t;
    virtual StringId GetTypeName() const = 0;
    virtual INode* CreateInstance(const Context* context) const = 0;
    virtual void DeleteInstance(INode* instance, const Context* context) const = 0;


    inline id_t GetId() const { return GetTypeName().GetId(); }
};

RNPP_NAMESPACE_END()

