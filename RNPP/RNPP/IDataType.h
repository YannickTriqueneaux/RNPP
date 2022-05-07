#pragma once
RNPP_NAMESPACE_BEGIN()

class IVariable;
class Context;

class IDataType
{
public:
    typedef unsigned int id_t;
    virtual IVariable* CreateInstance(const Context* context) = 0;
    virtual void DeleteInstance(IVariable* instance, const Context* context) = 0;


    virtual id_t GetId() const = 0;
};

RNPP_NAMESPACE_END()