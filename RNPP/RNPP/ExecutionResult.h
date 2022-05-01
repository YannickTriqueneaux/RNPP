#pragma once
#include "pch.h"
#include "const_string.h"

class ExecutionResult
{
    int m_code;
    const_string m_description;
public:
    static ExecutionResult success();

    inline ExecutionResult(int code, const char* description) : m_code(code), m_description(description) {}
    inline ExecutionResult(int code, const const_string& description) : m_code(code), m_description(description) {}

    inline bool IsSucceeded() const { return m_code == 0; }
    inline const const_string& GetDescription() const { return m_description; }
    inline int GetCode() const { return m_code; }
};

