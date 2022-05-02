#pragma once
#include "StringId.h"


RNPP_NAMESPACE_BEGIN()

class IConnection;
class Context; 
class ConnectionResult;
class IInput;
class IOutput;
class IConverter;

class IConnectionType
{
public:
    typedef StringId::id_t id_t;
    virtual StringId GetTypeName() const = 0;
    virtual IConnection* CreateInstance(const Context* context, const IOutput* from, const IInput* to, const IConverter* converter, const ConnectionResult& result) const = 0;
    virtual void DeleteInstance(IConnection* instance, const Context* context) const = 0;


    inline id_t GetId() const { return GetTypeName().GetId(); }
};

RNPP_NAMESPACE_END()

