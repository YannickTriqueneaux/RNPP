#include "pch.h"
#include "ExecutionResult.h"

RNPP_NAMESPACE_BEGIN()

ExecutionResult ExecutionResult::success()
{
    return std::move(ExecutionResult(0, const_string::null()));
}


RNPP_NAMESPACE_END()