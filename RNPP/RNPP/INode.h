#pragma once
#include "pch.h"

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

    virtual void OnInputConnected(const IInput* input, const IOutput* output) const = 0;
    virtual void OnInputDisconnected(const IInput* input, const IOutput* output) const = 0;

    //Returns true if this change must make the Node being executed on next step
    virtual bool InputChanged(const IInput* input, const IOutput* byOUtput) const = 0;

    virtual int Execute() = 0;
};

RNPP_NAMESPACE_END()

