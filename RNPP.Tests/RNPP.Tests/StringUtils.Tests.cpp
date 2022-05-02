#include "pch.h"


#include "..\..\RNPP\RNPP\CRC32.h"
#include "..\..\RNPP\RNPP\StringId.h"
#include "..\..\RNPP\RNPP\const_string.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace RNPP_NAMESPACE;

namespace RNPPTests
{


    TEST_CLASS(RNPPTests_StringHash)
    {
    public:

        TEST_METHOD(RuntimeVSCompileTime)
        {
            constexpr auto h = "Hello I'm Yannick"_hash;
            Assert::AreEqual(""_hash, string_hash(""));
            Assert::AreEqual("u"_hash, string_hash("u"));
            Assert::AreEqual(h, string_hash("Hello I'm Yannick"));
            Assert::AreEqual("Microsoft::VisualStudio::CppUnitTestFramework"_hash, string_hash("Microsoft::VisualStudio::CppUnitTestFramework"));

            constexpr StringId compiltime_strId = HIDDEN_STRING_ID("MyStr");
            StringId strId = StringId("MyStr");
            Assert::IsTrue(compiltime_strId == strId);

            std::unordered_map<StringId, int, StringId::hasher_t> hashMapTest;
            hashMapTest.emplace(HIDDEN_STRING_ID("Hey"), 1);
            hashMapTest.emplace(HIDDEN_STRING_ID("Hey"), 1);
            hashMapTest.emplace(HIDDEN_STRING_ID("Hey2"), 2);
        }
    };


    TEST_CLASS(RNPPTests_const_string)
    {
    public:

        TEST_METHOD(const_string_lifetime)
        {
            std::string modifiableStr;
            const_string test2 = const_string::null();
            const_string test1("Microsoft::VisualStudio::CppUnitTestFramework");
            {
                Assert::AreEqual(1l, test1.use_count());
                test2 = test1;
                Assert::AreEqual(2l, test1.use_count());
                Assert::IsTrue(test1 == test2);
                Assert::IsTrue(test1.ref_equals(test2));

                modifiableStr = test2.str();
                Assert::IsTrue(modifiableStr == test2.str());
                modifiableStr.erase(0, 1);
                Assert::IsFalse(modifiableStr == test2.str());

                auto test3 = test2;
                Assert::AreEqual(3l, test1.use_count());
                test2 = "Hey";
                Assert::AreEqual(2l, test1.use_count());
                Assert::IsTrue(test1.ref_equals(test3));
                test3 = test2;
                Assert::AreEqual(2l, test2.use_count());
            }
            Assert::AreEqual(1l, test1.use_count());
            Assert::AreEqual(1l, test2.use_count());
        }


        TEST_METHOD(const_string_performances_compare)
        {
            using namespace std::chrono;
            const_string const1("Microsoft::VisualStudio::CppUnitTestFramework Microsoft::VisualStudio::CppUnitTestFramework");
            const_string const2 = const1;
            bool isSame = false;
            duration<double> const_span;
            {

                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                for (int i = 0; i < 100000; ++i)
                    isSame = const1 == const2;
                high_resolution_clock::time_point t2 = high_resolution_clock::now();

                const_span = duration_cast<duration<double>>(t2 - t1);
            }


            std::cout << "const string perf: " << const_span.count() << " seconds.";

            std::string str1("Microsoft::VisualStudio::CppUnitTestFramework Microsoft::VisualStudio::CppUnitTestFramework");
            std::string str2 = str1;
            duration<double> str_span;
            {
                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                for (int i = 0; i < 100000; ++i)
                    isSame = str1 == str2;
                high_resolution_clock::time_point t2 = high_resolution_clock::now();

                str_span = duration_cast<duration<double>>(t2 - t1);
            }

            std::cout << "string perf: " << str_span.count() << " seconds.";


            Assert::IsTrue(const_span < str_span);
        }


        TEST_METHOD(const_string_performances_assign)
        {
            using namespace std::chrono;
            const_string const1("Microsoft::VisualStudio::CppUnitTestFramework Microsoft::VisualStudio::CppUnitTestFramework");
            const_string const2 = "Hey";

            duration<double> const_span;
            {

                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                for (int i = 0; i < 100000; ++i)
                {
                    const2 = const1;
                }
                high_resolution_clock::time_point t2 = high_resolution_clock::now();

                const_span = duration_cast<duration<double>>(t2 - t1);
            }


            std::cout << "const string perf: " << const_span.count() << " seconds.";

            std::string str1("Microsoft::VisualStudio::CppUnitTestFramework Microsoft::VisualStudio::CppUnitTestFramework");
            std::string str2 = "Hey";
            duration<double> str_span;
            {
                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                for (int i = 0; i < 100000; ++i)
                {
                    str2 = str1;
                }
                high_resolution_clock::time_point t2 = high_resolution_clock::now();

                str_span = duration_cast<duration<double>>(t2 - t1);
            }

            std::cout << "string perf: " << str_span.count() << " seconds.";


            Assert::IsTrue(std::abs( const_span.count() - str_span.count()) < 0.005);//mostly the same  but const_string does no dynamic allocations
        }
    };
}
