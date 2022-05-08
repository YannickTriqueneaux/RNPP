
RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflexions{

class Instance;
class Descriptor;
class Field{
public:
    Field(int pOffset, Descriptor const & descriptor, StringId const & name);

    /**
    *  return the instance of this field form his parent
    * @param parent instance
    * @return an empty Instance of the filed is not found into the given parent
    */
    Instance getInstance(Instance const & parent) const;

    /**
    * @return the name of the field
    */
    StringId const & getName() const;

    /**
    * @return the name of the field
    */
    Descriptor const & getType() const;
private:
    Descriptor const * descriptor;
    StringId const fieldName;
    unsigned int offset;

private:
    Field();
    friend class Descriptor;
};

};
RNPPBASICS_NAMESPACE_END()