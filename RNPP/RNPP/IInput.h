#pragma once
#include "IConnectable.h"
#include "ConnectionResult.h"

RNPP_NAMESPACE_BEGIN()

class INode;
class IOutput;
class IConverter;

class IInput : public IConnectable
{
public:
    virtual ConnectionResult CanConnect(const IOutput* from, const IConverter* converter) const = 0;
};


RNPP_NAMESPACE_END()
