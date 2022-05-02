#pragma once
#include "pch.h"
#include "ExecutionResult.h"

RNPP_NAMESPACE_BEGIN()

class IConnectable;

class INode
{
public:
    typedef unsigned long long id_t;

    virtual id_t GetId() const = 0;

    virtual unsigned int GetInputConnectableCount() const = 0;
    virtual unsigned int GetOutputConnectableCount() const = 0;

    virtual IConnectable* GetInput(unsigned int index) const = 0;
    virtual IConnectable* GetOutput(unsigned int index) const = 0;

    virtual ExecutionResult Execute() = 0;
};

RNPP_NAMESPACE_END()

