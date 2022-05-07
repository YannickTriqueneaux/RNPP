#pragma once
#include "CRC32.h"

RNPPBASICS_NAMESPACE_BEGIN()

class StringId
{
public:
    typedef unsigned int id_t;
private:
    const char* m_str;
    const id_t m_hash;

public:
    inline id_t GetId() const { return m_hash; }

    constexpr StringId(const char* str, id_t hash)
        : m_str(str), m_hash(hash) {}

    constexpr StringId(const char* str)
        : m_str(str), m_hash(string_hash(str)) {}

    constexpr StringId(const StringId& other) 
        : m_str(other.m_str), m_hash(other.m_hash) {}

    bool operator==(const StringId& other) const
    {
        return m_hash == other.m_hash;
    }

    bool operator!=(const StringId& other) const
    {
        return m_hash != other.m_hash;
    }

    //For Binary searches
    bool operator < (const StringId& other) const
    {
        return m_hash < other.m_hash;
    }

    struct hasher_t
    {
        //For HashMaps
        std::size_t operator()(const StringId& other) const
        {
            return other.m_hash;
        }
    };

};

#if defined(_DEBUG)
#define HIDDEN_STRING_ID(str) StringId(str, str ## _hash)
#else
#define HIDDEN_STRING_ID(str) StringId("Hidden", str ## _hash)
#endif



RNPPBASICS_NAMESPACE_END()


