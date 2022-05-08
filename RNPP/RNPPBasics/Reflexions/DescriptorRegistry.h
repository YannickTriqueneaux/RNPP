RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflexions{

class DescriptorRegistry{
    typedef std::unordered_map<StringId, Descriptor*> DescriptorListType;
	static DescriptorRegistry & _getInstance();
	DescriptorRegistry();

	DescriptorRegistry(DescriptorRegistry && other){
	}

	void swap(DescriptorRegistry &other){
		std::swap(descriptors,other.descriptors);
	}
	DescriptorRegistry &operator=(DescriptorRegistry && other){
		swap(other);
		return *this;
	}

public:
	DescriptorListType descriptors;
    static Descriptor * _getDescriptor(StringId const & descriptorName);

    template<typename DescriptorType>
    static Descriptor * _createDescriptor() {
        StringId descriptorName = DescriptorType::_getDescriptorName();//voluntary copy
        DescriptorRegistry & registry = _getInstance();
        assert(registry.descriptors.find(descriptorName) == registry.descriptors.end());
        auto pair = registry.descriptors.insert(std::make_pair<StringId, Descriptor*>(std::move(descriptorName), new DescriptorType()));
        return pair.first->second;
    }

	static void _printDescriptorList();
};


};
RNPPBASICS_NAMESPACE_END()