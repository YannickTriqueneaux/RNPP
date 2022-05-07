#pragma once
#include "ConnectionResult.h"

RNPP_NAMESPACE_BEGIN()

class IConnectable;
class IConverter;
class IOutput;
class IInput;
class IConnectionType;

class IConnection
{
    public:
        typedef unsigned long long id_t;

        virtual id_t GetId() const = 0;
        virtual bool IsConnected() const = 0;
        virtual IOutput* From() const = 0;
        virtual IInput* To() const = 0;
        virtual const IConnectionType* GetType() const = 0;

        virtual const ConnectionResult& GetConnectionResult() const = 0;
        virtual void SetOutputAsLost() = 0;
        virtual void SetInputAsLost() = 0;

        virtual IConverter* GetConverter() const = 0;
};

RNPP_NAMESPACE_END()

