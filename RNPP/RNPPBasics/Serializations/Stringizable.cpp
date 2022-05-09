#include "pch.h"
#include "Stringizable.h"
#include "Formats.h"
#include "../Utils/StringHelper.h"

RNPPBASICS_NAMESPACE_BEGIN()

namespace Serializations{

    template<typename FORMAT>
    Stringizable<FORMAT>::Stringizable(std::string const & objectname, int indentrange) :
        indentRange(indentrange),
        name(objectname)
    {}
    template<typename FORMAT>
    Stringizable<FORMAT>::~Stringizable(){
        delete value;
    }

    template<>
    bool Stringizable<Formats::JSON>::print(std::ostream & streamResult) const {
        streamResult << StringHelper::Tab::_put(indentRange);
        if (!name.empty()){
            streamResult << '"' << name << '"' << ": ";
        }
        value->print(streamResult);
        return true;
    }
};
RNPPBASICS_NAMESPACE_END()