#include "pch.h"
#include "Value.h"
#include "Formats.h"
#include "../Reflections/NativeDescriptor.h"
#include "../Reflections/Instance.h"
#include "Stringizer.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Serializations{
    
    using Formats::JSON; 
    using namespace Reflections;

    template<>
    bool ArrayValue< JSON >::print(std::ostream & streamResult)  const {
        return content->print(streamResult);
    }

    template<>
    bool ObjectValue< JSON >::print(std::ostream & streamResult) const {
        return content->print(streamResult);
    }

    template<>
    bool BooleanValue< JSON >::print(std::ostream & streamResult) const {
        auto boolean = static_cast<BooleanBaseDescriptor const *>(content.getType())->instanceToBoolean(content);
        if (boolean){
            streamResult << "true";
        }
        else{
            streamResult << "false";
        }
        return true;
    }

    template<>
    bool NullValue< JSON >::print(std::ostream & streamResult) const {
        streamResult << "null";
        return true;
    }


    template<>
    bool StringValue< JSON >::print(std::ostream & streamResult) const {
        streamResult << '"';
        Stringizer::instanceToString(streamResult, content);
        streamResult << '"';
        return true;
    }

    template<>
    bool NumberValue< JSON >::print(std::ostream & streamResult) const {
        Stringizer::instanceToString(streamResult, content);
        return true;
    }

};
RNPPBASICS_NAMESPACE_END()