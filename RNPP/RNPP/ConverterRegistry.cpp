#include "pch.h"
#include "ConverterRegistry.h"
#include "IConverter.h"

RNPP_NAMESPACE_BEGIN()

const IConverter* ConverterRegistry::GetConverter(const IDataType* from, const IDataType* to) const
{
    auto fromIt = m_converters.find(from->GetId());
    if (fromIt != m_converters.end())
    {
        auto toIt = fromIt->second.find(to->GetId());
        if(toIt != fromIt->second.end())
        {
            return toIt->second;
        }
    }
    return nullptr;
}

void ConverterRegistry::RegisterConverter(const IConverter* converter)
{
    auto fromId = converter->From()->GetId();
    auto fromIt = m_converters.find(fromId);
    if (fromIt == m_converters.end())
    {
        fromIt = m_converters.emplace(fromId, decltype(fromIt->second)()).first;
    }

    auto toId = converter->To()->GetId();
    assert(fromIt->second.find(toId) == fromIt->second.end() && "Converter already registered for these types");
    fromIt->second[toId] = converter;
}

RNPP_NAMESPACE_END()