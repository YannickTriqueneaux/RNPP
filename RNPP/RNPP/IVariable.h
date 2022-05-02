#pragma once

RNPP_NAMESPACE_BEGIN()

class IDataType;

class IVariable
{
public:
    typedef unsigned long long id_t;

    virtual bool HasChanged() const = 0;
    virtual const IDataType* GetType() const = 0;
    virtual void* AccessValue() const = 0;
};

RNPP_NAMESPACE_END()

