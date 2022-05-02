#pragma once
#include "IConnectable.h"

RNPP_NAMESPACE_BEGIN()

class Context;

class IOutput : public IConnectable
{
    Context* m_context = nullptr;
public:
    void RaiseChanged();

#if defined(RNPP_INTERNAL)
    static void SetContext(IOutput* instance, Context* context);
#endif
};

RNPP_NAMESPACE_END()

