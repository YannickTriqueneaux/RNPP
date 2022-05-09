#pragma once
#include "../RNPPBasics.h"
#include "Value.h"
#include "Element.h"
#include <iostream>

RNPPBASICS_NAMESPACE_BEGIN()

namespace Serializations{

    template<typename FORMAT>
    class Stringizable : public Element<FORMAT>{
    public:
        typedef Value<FORMAT>* ContentType;


        Stringizable(std::string const & objectname, int indentrange);
        ~Stringizable();

        virtual bool print(std::ostream & streamResult) const;

        ContentType value = nullptr;
    private:
        int indentRange = 0;
        std::string name;
    };
};
RNPPBASICS_NAMESPACE_END()