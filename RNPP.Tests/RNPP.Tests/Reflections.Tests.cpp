#include "pch.h"

#include "..\..\RNPP\RNPPBasics\Reflections\ReflectionUser.h"
#include <unordered_map>

namespace MyNameSpace {

    class ParentClass {
        REFLECTED_CLASS
    public:
        int simpleint;
    };

    class ChildClass : public ParentClass {
        REFLECTED_SUPER_CLASS(ParentClass)
    public:
        int secondValue;
        std::string superstring;
    };


    class SuperClass {
        REFLECTED_CLASS
    public:
        SuperClass() {}
        SuperClass(int val) : intvalue(val) {}
        int intvalue = 5;
        float floatvalue = 56.0f;
        int* valuePtr = nullptr;
        std::string stringvalue;
        ChildClass objectvalue;
        std::vector<int> vectorint;
        std::vector<ParentClass> vectorObject;
        std::vector<std::vector<ParentClass>> vector2Object;
        std::vector<std::vector<std::string>> vectorstring;
        std::unordered_map<int, ParentClass> mapObject;
        std::unordered_map<std::string, std::unordered_map<int, ParentClass>> supermapfield;
        std::pair<int, int> superpair;
    };


    template<typename T>
    class TempClass : public ChildClass {
        REFLECTED_SUPER_TEMPLATE_CLASS(ChildClass)
    public:
        TempClass() {}
        T value;
        REFLECT_TEMPLATE_CLASS_BEGIN(MyNameSpace::TempClass, T)
            REFLECT_FIELD(value);
        REFLECT_CLASS_END
    };

    class TemplChild : public TempClass < int > {
        REFLECTED_SUPER_CLASS(TempClass<int>)
    public:
        TemplChild() {}
        std::string souris;
    };

    struct ComposedObject {
        REFLECTED_CLASS
    public:
        ComposedObject() {}

        TemplChild templatedInt;
    };

};

REFLECT_CLASS_BEGIN(MyNameSpace::ChildClass)
REFLECT_FIELD(secondValue);
REFLECT_FIELD(superstring);
REFLECT_CLASS_END

REFLECT_CLASS_BEGIN(MyNameSpace::SuperClass)
REFLECT_FIELD(intvalue);
REFLECT_FIELD(floatvalue);
REFLECT_FIELD(stringvalue);
REFLECT_FIELD(objectvalue);
REFLECT_FIELD(vectorint);
REFLECT_FIELD(vectorObject);
REFLECT_FIELD(vector2Object);
REFLECT_FIELD(vectorstring);
REFLECT_FIELD(mapObject);
REFLECT_FIELD(supermapfield);
REFLECT_FIELD(superpair);
REFLECT_CLASS_END

REFLECT_CLASS_BEGIN(MyNameSpace::ParentClass)
REFLECT_FIELD(simpleint);
REFLECT_CLASS_END
//
////

REFLECT_CLASS_BEGIN(MyNameSpace::TemplChild)
REFLECT_FIELD(souris);
REFLECT_CLASS_END

REFLECT_CLASS_BEGIN(MyNameSpace::ComposedObject)
REFLECT_FIELD(templatedInt);
REFLECT_CLASS_END

//void testDescritporGetting(){
//    std::string tl(_stringize(heyyyeyed));
//    getDescriptorOf<ParentClass>();
//    getDescriptorOf<SuperClass>();
//    getDescriptorOf<ChildClass>();
//    getDescriptorOf<TempClass<SuperClass>>();
//    getDescriptorOf<TemplChild>();
//    DescriptorRegistry::_printDescriptorList();
//}
//
//void testFieldInstanceGetting(){
//    ChildClass child;
//    Instance childInstance(&child);
//    assert(!childInstance.isEmpty());
//
//
//    auto instancePtr = childInstance.get();
//    assert(instancePtr == &child);
//
//    auto instanceDesc = childInstance.getType();
//    assert(instanceDesc == getDescriptorOf(child));
//
//    Field const * secondValueField = instanceDesc->getField("secondValue");
//    assert(secondValueField);
//
//    assert(instanceDesc->containsField(*secondValueField));
//
//    FieldInstance fieldInstance(childInstance, *secondValueField);
//
//    assert(&child.secondValue == fieldInstance.getInstance().get());
//    assert(getDescriptorOf(child.secondValue) == fieldInstance.getInstance().getType());
//
//
//    assert(instanceDesc->containsField(*secondValueField));
//
//    //inherit class field access
//    auto inheritIntValueField = instanceDesc->getField("simpleint");
//    assert(inheritIntValueField);
//
//    assert(inheritIntValueField->getName() == "simpleint");
//
//    FieldInstance inheritFieldInstance(childInstance, *inheritIntValueField);
//
//
//    assert(&child.simpleint == inheritFieldInstance.getInstance().get());
//    assert(getDescriptorOf(child.simpleint) == inheritFieldInstance.getInstance().getType());
//}
//
//
//
//
void testFieldInstanceNavigation(){
//
    MyNameSpace::TempClass<int> test;
//    //check descriptors
//    ComposedObject compObject;
//
//    auto compObjectDesc = compObject.getDescriptor();
//    assert(compObjectDesc);
//
//    Instance compObjectInstance(&compObject);
//    assert(!compObjectInstance.isEmpty());
//
//    compObjectDesc->containsField("templatedInt");
//
//    auto fieldDesc = getDescriptorOf(compObject.templatedInt);
//    assert(fieldDesc);
//
//    assert(fieldDesc->containsField("souris"));
//
//    auto valueField = fieldDesc->getField("value");
//    assert(valueField);
//
//    assert(getDescriptorOf(compObject.templatedInt.value) == &valueField->getType());
//
//
//    //check navigation
//    Field const * templateField = compObjectDesc->getField("templatedInt");
//    assert(templateField);
//    FieldInstance fieldMoverInstance(compObjectInstance, *templateField);
//
//    auto fieldInstance = fieldMoverInstance.getInstance();
//    assert(!fieldInstance.isEmpty());
//
//    FieldInstance fiCopy = fieldMoverInstance;
//    assert(!fiCopy.getInstance().isEmpty());
//    assert(fiCopy == fieldMoverInstance);
//
//    auto superClassField = getDescriptorOf<SuperClass>()->getField("floatvalue");
//    assert(superClassField);
//
//    assert(!fieldMoverInstance.moveToChild(*superClassField));//mus fail
//
//    assert(fiCopy == fieldMoverInstance);//normally fieldMoverInstance does not change because moveToChild has failed 
//
//    auto parentClassField = getDescriptorOf<ParentClass>()->getField("simpleint");
//    assert(parentClassField);
//
//
//    assert(fieldMoverInstance.moveToChild(*parentClassField));//must succeed
//    assert(fiCopy != fieldMoverInstance);
//
//    assert(!fieldMoverInstance.getInstance().isEmpty());
//    assert(fieldMoverInstance.getInstance().get() == &compObject.templatedInt.simpleint);
}
//
//
//void main(){
//
//    testDescritporGetting();
//    Input::_waitKey();
//
//
//    testFieldInstanceGetting();
//    Input::_waitKey();
//
//    testFieldInstanceNavigation();
//    Input::_waitKey();
//}