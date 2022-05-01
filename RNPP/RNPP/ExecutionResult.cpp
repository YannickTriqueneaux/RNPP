#include "pch.h"
#include "ExecutionResult.h"

ExecutionResult ExecutionResult::success()
{
    return std::move(ExecutionResult(0, const_string::null()));
}
