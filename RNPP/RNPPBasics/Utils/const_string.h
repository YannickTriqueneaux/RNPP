#pragma once

#include "pch.h"

RNPPBASICS_NAMESPACE_BEGIN()

class const_string
{
    std::shared_ptr<StringId> m_sharedStr;
    const_string() {}
public:
    static const_string null();
    const_string(const char* str) : m_sharedStr(std::make_shared<StringId>(str)) { }
    const_string(const StringId& str) : m_sharedStr(std::make_shared<StringId>(str)) { }
    const_string(const const_string& other) : m_sharedStr(other.m_sharedStr) {}
    const_string(const const_string&& other) noexcept : m_sharedStr(other.m_sharedStr) {}
    inline const_string& operator=(const const_string& other) { m_sharedStr = other.m_sharedStr; return *this; }
    inline bool operator==(const const_string& other) const { return m_sharedStr.get() == other.m_sharedStr.get() || *m_sharedStr == *other.m_sharedStr; }
    inline bool operator!=(const const_string& other) const { return !(*this == other); }

    inline StringId str() const { return *m_sharedStr; }
    inline const char* c_str() const { return m_sharedStr->c_str(); }

    inline bool ref_equals(const const_string& other) const { return m_sharedStr.get() == other.m_sharedStr.get(); }
    inline auto use_count() const { return m_sharedStr.use_count(); }
};


RNPPBASICS_NAMESPACE_END()
