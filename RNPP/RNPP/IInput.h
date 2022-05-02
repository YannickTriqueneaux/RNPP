#pragma once
#include "IConnectable.h"
#include "ConnectionResult.h"

RNPP_NAMESPACE_BEGIN()

class INode;
class IOutput;
class IConverter;
class Context;

class IInput : public IConnectable
{
    const INode* m_node = nullptr;
public:
    virtual ConnectionResult CanConnect(const IOutput* from, const IConverter* converter, const Context* context) const = 0;

#if defined(RNPP_INTERNAL)
    static const INode* GetNode(const IInput* instance);
    static void SetNode(IInput* instance, INode* node);
#endif
};


RNPP_NAMESPACE_END()
