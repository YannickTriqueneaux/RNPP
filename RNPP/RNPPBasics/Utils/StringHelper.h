
#include "..\RNPPBasics.h"
#include <iostream>
#include <string>

RNPPBASICS_NAMESPACE_BEGIN()

namespace StringHelper{

    std::wstring stringToWString(std::string const & str);
    std::string wstringToString(std::wstring const & wstr);

    const std::string EmptyString = "";

    struct Tab{
        static std::string _put(int nbTab);
    };

};

RNPPBASICS_NAMESPACE_END()