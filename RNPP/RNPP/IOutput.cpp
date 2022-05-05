#include "pch.h"
#include "IOutput.h"
#include "Context.h"

RNPP_NAMESPACE_BEGIN()



void IOutput::RaiseChanged()
{
    const_cast<Context*>(GetContext())->OutputChanged(GetId());
}

RNPP_NAMESPACE_END()

