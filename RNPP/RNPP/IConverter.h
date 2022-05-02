#pragma once

RNPP_NAMESPACE_BEGIN()

class IDataType;

class IConverter
{
public:
    virtual bool Convert(const void* from, void* to) const = 0;

    virtual const IDataType* From() const = 0;
    virtual const IDataType* To() const = 0;
};

template<typename FromType, typename ToType>
class ITypedConverter : IConverter
{
public:

    virtual bool Convert(const FromType* from, ToType* to) const = 0;
};

RNPP_NAMESPACE_END()
