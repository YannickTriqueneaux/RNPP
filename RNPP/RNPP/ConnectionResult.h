#pragma once


RNPP_NAMESPACE_BEGIN()

class ConnectionResult
{
    int m_code;

public:
    static ConnectionResult success();

    inline ConnectionResult(int code) : m_code(code) {}
    inline bool IsSucceeded() const { return m_code == 0; }
    inline int GetCode() const { return m_code; }
};


RNPP_NAMESPACE_END()

