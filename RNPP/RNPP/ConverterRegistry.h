#pragma once
#include "pch.h"
#include "IDataType.h"

RNPP_NAMESPACE_BEGIN()

class IConverter;

class ConverterRegistry
{

    std::unordered_map<IDataType::id_t, std::unordered_map<IDataType::id_t, const IConverter*>> m_converters;
public:
    const IConverter* GetConverter(const IDataType* from, const IDataType* to) const;

    void RegisterConverter(const IConverter* converter);
};

RNPP_NAMESPACE_END()
