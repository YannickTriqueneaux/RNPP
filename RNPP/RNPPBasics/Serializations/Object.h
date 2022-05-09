#pragma once
#include "../RNPPBasics.h"
#include "Element.h"
#include <iostream>
#include <string>
#include <unordered_map>

RNPPBASICS_NAMESPACE_BEGIN()
namespace Serializations{

    template<typename FORMAT>
    class Object : public Element<FORMAT>{
    public:
        typedef std::unordered_map<std::string, Element<FORMAT> const *> ContentType;


        Object(std::string const & objectname, int indentrange);
        virtual ~Object();

        virtual bool print(std::ostream & streamResult) const ;

        ContentType members;
        int getIndent() const;
    private:
        int indentRange = 0;
        std::string name;
    };
};
RNPPBASICS_NAMESPACE_END()