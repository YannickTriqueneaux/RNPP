#include "pch.h"

//
//
//namespace MyNameSpace{
//
//    class ParentClass{
//        REFLECTED_CLASS
//    public:
//        ParentClass(){}
//        ParentClass(int val) : simpleint(val){}
//        int simpleint = 0;;
//    };
//    class SuperClass{
//        REFLECTED_CLASS
//    public:
//        SuperClass(int val) : intvalue(val){}
//        int intvalue = 5;
//        float floatvalue = 56.0f;
//        int * valuePtr = nullptr;
//        std::string stringvalue;
//        std::vector<int> vectorint;
//        std::vector<ParentClass> vectorObject;
//        std::vector<std::vector<ParentClass>> vector2Object;
//        std::vector<std::vector<std::string>> vectorstring;
//        std::map<std::string, std::map<int, ParentClass>> supermapfield;
//        std::pair<int, int> superpair;
//
//        SuperClass() : 
//            stringvalue("strVal"){
//
//            vectorint << 4 << 159 << 8844 << 0516;
//            vectorObject << 789 << 156 << 74 << 12;
//            vector2Object << vectorObject << vectorObject;
//
//            vectorstring << (std::vector<std::string>() << "toto" << "tata") << (std::vector<std::string>() << "toto2" << stringvalue);
//
//            std::map<int, ParentClass> intParentMap;
//            intParentMap.emplace(156, ParentClass(456));
//
//            supermapfield.emplace("indexOne", intParentMap);
//        }
//    };
//    //
//    class ChildClass : public ParentClass {
//        REFLECTED_SUPER_CLASS(ParentClass)
//    public:
//        int secondValue;
//        std::string superstring;
//    };
//    //
//    template<typename T>
//    class TempClass : public ChildClass {
//        REFLECTED_SUPER_TEMPLATE_CLASS(ChildClass)
//    public:
//        TempClass(){}
//        T value;
//        REFLECT_TEMPLATE_CLASS_BEGIN(MyNameSpace::TempClass, T)
//            REFLECT_FIELD(value);
//        REFLECT_CLASS_END
//    };
//
//    class TemplChild : public TempClass < int > {
//        REFLECTED_SUPER_CLASS(TempClass<int>)
//    public:
//        TemplChild(){}
//        std::string souris;
//    };
//
//
//    struct ComposedObject{
//        REFLECTED_CLASS
//    public:
//        ComposedObject(){}
//
//        TemplChild templatedInt;
//    };
//
//};
//
//REFLECT_CLASS_BEGIN(MyNameSpace::SuperClass)
//REFLECT_FIELD(intvalue);
//REFLECT_FIELD(floatvalue);
//REFLECT_FIELD(stringvalue);
//REFLECT_FIELD(vectorint);
//REFLECT_FIELD(vectorObject);
//REFLECT_FIELD(vector2Object);
//REFLECT_FIELD(vectorstring);
//REFLECT_FIELD(supermapfield);
//REFLECT_FIELD(superpair);
//REFLECT_CLASS_END
//
//REFLECT_CLASS_BEGIN(MyNameSpace::ParentClass)
//REFLECT_FIELD(simpleint);
//REFLECT_CLASS_END
////
//REFLECT_CLASS_BEGIN(MyNameSpace::ChildClass)
//REFLECT_FIELD(secondValue);
//REFLECT_FIELD(superstring);
//REFLECT_CLASS_END
//
//REFLECT_CLASS_BEGIN(MyNameSpace::TemplChild)
//REFLECT_FIELD(souris);
//REFLECT_CLASS_END
//
//REFLECT_CLASS_BEGIN(MyNameSpace::ComposedObject)
//REFLECT_FIELD(templatedInt);
//REFLECT_CLASS_END
//
//
//using namespace MyNameSpace;
//using namespace TrustEngine::System;
//using namespace TrustEngine::Reflexion;
//using namespace TrustEngine::Serialization;
//
//
//void testValuesCases(){
//    std::stringstream stream;
//
//    //integer
//    int intvalue = 456487;
//
//    InstanceSerializer<Formats::JSON> serializerInt(&intvalue);
//    assert(serializerInt.serialize(stream));
//
//    std::cout << std::endl << std::endl << stream.str();
//    stream.str(StringHelper::EmptyString);
//    stream.clear();
//
//
//    //string
//    std::string string("super string");
//
//    InstanceSerializer<Formats::JSON> serializerString(&string);
//    assert(serializerString.serialize(stream));
//
//    std::cout << std::endl << std::endl << stream.str();
//    stream.str(StringHelper::EmptyString);
//    stream.clear();
//}
//
//
//void testArrayCases(){
//
//    std::stringstream stream;
//
//    //vector
//    std::vector<std::string> nameListe;
//    nameListe << "yann" << "mick" << "sandra";
//
//    InstanceSerializer<Formats::JSON> serializerVector(&nameListe);
//    assert(serializerVector.serialize(stream));
//
//    std::cout << std::endl << std::endl << stream.str();
//    stream.str(StringHelper::EmptyString);
//    stream.clear();
//
//
//    //pair
//    std::pair<int, int> intpair(12,56);
//
//    InstanceSerializer<Formats::JSON> serializerIntPair(&intpair);
//    assert(serializerIntPair.serialize(stream));
//
//    std::cout << std::endl << std::endl << stream.str();
//    stream.str(StringHelper::EmptyString);
//    stream.clear();
//
//
//    //map
//    std::map<double, std::string> doubleStringPair;
//    doubleStringPair[50.6] = "string -506";
//    doubleStringPair[59] = "string -59";
//    doubleStringPair[1895.2] = "string -18952";
//    InstanceSerializer<Formats::JSON> serializerMap(&doubleStringPair);
//    assert(serializerMap.serialize(stream));
//
//    std::cout << std::endl << std::endl << stream.str();
//    stream.str(StringHelper::EmptyString);
//    stream.clear();
//}
//void testObjectCases(){
//    std::stringstream stream;
//
//    //ParentClass
//    ParentClass parent;
//
//    InstanceSerializer<Formats::JSON> serializerParent(&parent);
//    assert(serializerParent.serialize(stream));
//
//    std::cout << std::endl << std::endl << stream.str();
//    stream.str(StringHelper::EmptyString);
//    stream.clear();
//
//    //inherited class
//    ChildClass child;
//
//    InstanceSerializer<Formats::JSON> serializerChild(&child);
//    assert(serializerChild.serialize(stream));
//
//    std::cout << std::endl << std::endl << stream.str();
//    stream.str(StringHelper::EmptyString);
//    stream.clear();
//
//
//    //templated inherited class 
//    TempClass<int> templated;
//
//    InstanceSerializer<Formats::JSON> serializerTemplated(&templated);
//    assert(serializerTemplated.serialize(stream));
//
//    std::cout << std::endl << std::endl << stream.str();
//    stream.str(StringHelper::EmptyString);
//    stream.clear();
//
//
//    //inherited by template class
//    TemplChild templateChild;
//
//    InstanceSerializer<Formats::JSON> serializerTemplatedChild(&templateChild);
//    assert(serializerTemplatedChild.serialize(stream));
//
//    std::cout << std::endl << std::endl << stream.str();
//    stream.str(StringHelper::EmptyString);
//    stream.clear();
//
//
//}
//
//void main(){
//    testValuesCases();
//    testArrayCases();
//    testObjectCases();
//
//    std::cout << std::endl;
//    std::cout << std::endl;
//
//    std::stringstream stream;
//    //Complex Object 
//    SuperClass superobject;
//
//    InstanceSerializer<Formats::JSON> serializerSuperObject(&superobject);
//    assert(serializerSuperObject.serialize(stream));
//
//
//    std::cout << std::endl << std::endl << stream.str();
//    stream.str(StringHelper::EmptyString);
//    stream.clear();
//
//
//
//    //in a file
//    std::ofstream fileStream("superObject.txt", std::ostream::out);
//    assert(serializerSuperObject.serialize(fileStream));
//    fileStream.close();
//
//
//
//    Input::_waitKey();
//}
//
