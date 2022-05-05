#pragma once
#include "IConnectable.h"

RNPP_NAMESPACE_BEGIN()


class IOutput : public IConnectable
{
public:
    void RaiseChanged();
};

RNPP_NAMESPACE_END()

