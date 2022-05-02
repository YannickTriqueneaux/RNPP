#pragma once
#include "const_string.h"


RNPP_NAMESPACE_BEGIN()

class ConnectionResult
{
    int m_code;
    const_string m_description;

public:
    static ConnectionResult success();

    inline ConnectionResult(int code, const char* description) : m_code(code), m_description(description) {}
    inline ConnectionResult(int code, const const_string& description) : m_code(code), m_description(description) {}

    inline bool IsSucceeded() const { return m_code == 0; }
    inline const const_string& GetDescription() const { return m_description; }
    inline int GetCode() const { return m_code; }
};


RNPP_NAMESPACE_END()

