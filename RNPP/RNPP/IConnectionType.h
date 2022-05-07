#pragma once


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
    typedef unsigned int id_t;
    virtual IConnection* CreateInstance(const Context* context, const IOutput* from, const IInput* to, const IConverter* converter, const ConnectionResult& result) const = 0;
    virtual void DeleteInstance(IConnection* instance, const Context* context) const = 0;


    virtual id_t GetId() const = 0;
};

RNPP_NAMESPACE_END()

