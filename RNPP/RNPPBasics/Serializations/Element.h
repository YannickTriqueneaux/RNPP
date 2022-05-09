#pragma once

RNPPBASICS_NAMESPACE_BEGIN()
namespace Serializations{


    template<typename FORMAT>
    class Element{
    public:
        virtual ~Element(){}
        virtual bool print(std::ostream & streamResult)  const = 0;
    };

};
RNPPBASICS_NAMESPACE_END()