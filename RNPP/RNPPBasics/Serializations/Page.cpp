#include "pch.h"
#include "Page.h"
#include "Formats.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Serializations{
    
    using Formats::JSON;

    template<typename FORMAT>
    Page<FORMAT>::Page(){}

    bool Page<JSON>::print(std::ostream & streamResult) const {
        assert(content && "Page::print empty page");
        streamResult << '{' << std::endl;
        auto succeed = content->print(streamResult);
        streamResult << std::endl << '}' << std::endl;
        return succeed;
    }


};
RNPPBASICS_NAMESPACE_END()