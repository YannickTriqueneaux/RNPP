#include "pch.h"
#include "ConnectionResult.h"

RNPP_NAMESPACE_BEGIN()

ConnectionResult ConnectionResult::success()
{
    return std::move(ConnectionResult(0));
}


RNPP_NAMESPACE_END()