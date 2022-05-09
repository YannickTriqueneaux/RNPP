#pragma once
#include "StringizableDescriptor.h"
#include "Descriptor.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflections {

    class StringizableDescriptor : public Descriptor {
    public:
        virtual bool isStringizable() const {
            return true;
        };
        virtual bool isABoolean() const {
            return false;
        }
        virtual bool isANumber() const {
            return false;
        }
        virtual bool isAString() const {
            return false;
        }

        virtual void ToString(std::ostream& streamResult, Instance const& instance) const = 0;
    };
};
RNPPBASICS_NAMESPACE_END()