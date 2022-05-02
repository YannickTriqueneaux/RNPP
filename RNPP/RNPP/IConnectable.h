#pragma once

RNPP_NAMESPACE_BEGIN()

class IConnectable
{
public:
    typedef unsigned long long id_t;

    virtual const id_t GetId() const = 0;
    virtual const IDataType* GetType() const = 0;
    virtual bool IsConnected() const = 0;
};

RNPP_NAMESPACE_END()

