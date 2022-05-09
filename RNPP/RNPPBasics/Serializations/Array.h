#pragma once
#include "../RNPPBasics.h"
#include <string>
#include "Element.h"
#include <iosfwd>

RNPPBASICS_NAMESPACE_BEGIN()
namespace Serializations{


    template<typename FORMAT>
    class Array : public Element<FORMAT>{
    public:
        typedef std::vector<Element<FORMAT> const *> ContentType;


        Array(std::string const & arrayname, int indentrange);
        ~Array();

        virtual bool print(std::ostream & streamResult)  const ;


        ContentType elements;
        int getIndent() const ;
    private:
        int indentRange = 0;
        std::string name;
    };
    
};
RNPPBASICS_NAMESPACE_END()