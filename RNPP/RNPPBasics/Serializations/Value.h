#pragma once
#include "../RNPPBasics.h"
#include <iostream>
#include "..\Reflections\Instance.h"
#include "Element.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Serializations{
    using Reflections::Instance;

    template<typename FORMAT>
    class Value{
    public:
        virtual bool print(std::ostream & streamResult) const = 0;
    };

    template<typename FORMAT>
    class StringValue : public Value<FORMAT>{
    public:

        virtual bool print(std::ostream & streamResult) const ;

        Instance content;
    };

    template<typename FORMAT>
    class NumberValue : public Value < FORMAT > {
    public:

        virtual bool print(std::ostream & streamResult) const;

        Instance content;
    };

    template<typename FORMAT>
    class ArrayValue : public Value < FORMAT > {
    public:

        virtual bool print(std::ostream & streamResult) const ;

        Element<FORMAT> * content;
    };

    template<typename FORMAT>
    class ObjectValue : public Value < FORMAT > {
    public:
        virtual bool print(std::ostream & streamResult) const ;

        Element<FORMAT> * content;
    };


    template<typename FORMAT>
    class BooleanValue : public Value < FORMAT > {
    public:

        virtual bool print(std::ostream & streamResult) const;

        Instance content;
    };

    template<typename FORMAT>
    class NullValue : public Value < FORMAT > {
    public:
        virtual bool print(std::ostream & streamResult) const ;
    };


};
RNPPBASICS_NAMESPACE_END()