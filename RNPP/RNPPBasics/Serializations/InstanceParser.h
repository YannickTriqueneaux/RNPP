#pragma once
#include "../RNPPBasics.h"
#include "Page.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Serializations{

    template<typename FORMAT>
    class InstanceParser{
    public:
        InstanceParser(Page<FORMAT> & pagetofill, Instance const & instancetoparse) :
            instance(instancetoparse),
            page(pagetofill){}

        bool parse();

    private:
        Instance const & instance;
        Page<FORMAT> & page;
    };

};
RNPPBASICS_NAMESPACE_END()