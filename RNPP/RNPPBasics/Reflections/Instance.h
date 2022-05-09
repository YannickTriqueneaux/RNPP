#pragma once
#include "DescriptorGetter.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflections
{

    class Descriptor;

    class Instance{
    public:
	    Instance();
	    Instance(void * instance, Descriptor const * descriptor);
	    template<typename T>
        inline Instance(T const * instance);

	    void * get() const ;
	    Descriptor const * getType() const ;
        bool isEmpty() const ;


        /**
        * @return true if given Instances are equivalent
        */
        friend bool operator==(Instance const & first, Instance const & second);
        /**
        * @return true if given Instances are different
        */
        friend bool operator!=(Instance const & first, Instance const & second);
    private:
	    void * instance;
	    Descriptor const * descriptor;
    };

    template<typename T>
    inline Instance::Instance(T const * instance) : instance(const_cast<T*>(instance)), descriptor(getDescriptorOf<T>())
    {
    }

};
RNPPBASICS_NAMESPACE_END()