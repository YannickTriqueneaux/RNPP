#pragma once

RNPP_NAMESPACE_BEGIN()

class Context;
class INode;

class INodeType
{
public:
    typedef unsigned int id_t;
    virtual INode* CreateInstance(const Context* context) const = 0;
    virtual void DeleteInstance(INode* instance, const Context* context) const = 0;
    virtual id_t GetId() const = 0;
};

RNPP_NAMESPACE_END()

