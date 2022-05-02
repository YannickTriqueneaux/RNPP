#pragma once
#include "pch.h"
#include "ExecutionResult.h"

RNPP_NAMESPACE_BEGIN()

class IConnectable;
class INodeType;
class IInput;
class IOutput;

class INode
{
public:
    typedef unsigned long long id_t;

    virtual id_t GetId() const = 0;
    virtual const INodeType* GetType() const = 0;

    virtual unsigned int GetInputCount() const = 0;
    virtual unsigned int GetOutputCount() const = 0;

    virtual IInput* GetInput(unsigned int index) const = 0;
    virtual IOutput* GetOutput(unsigned int index) const = 0;

    virtual void OnInputConnected(unsigned int intputIndex, const IOutput* output) const = 0;
    virtual void OnInputDisconnected(unsigned int intputIndex, const IOutput* output) const = 0;

    virtual ExecutionResult Execute() = 0;
};

RNPP_NAMESPACE_END()

