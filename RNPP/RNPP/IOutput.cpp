#include "pch.h"
#include "IOutput.h"
#include "Context.h"

RNPP_NAMESPACE_BEGIN()



void IOutput::RaiseChanged()
{
    m_context->OutputChanged(GetId());
}


#if defined(RNPP_INTERNAL)
void IOutput::SetContext(IOutput* instance, Context* context)
{
    assert(instance->m_context == nullptr && "Context already set");
    instance->m_context = context;
}
#endif

RNPP_NAMESPACE_END()

