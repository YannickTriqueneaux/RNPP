#include "pch.h"
#include "StringHelper.h"
#include <xutility>
#include <codecvt>

RNPPBASICS_NAMESPACE_BEGIN()

namespace StringHelper{

    std::wstring stringToWString(std::string const & str)
    {
        typedef std::codecvt_utf8<wchar_t> convert_type;
        std::wstring_convert<convert_type, wchar_t> converterX;

        return std::move(converterX.from_bytes(str));
    }

    std::string wstringToString(std::wstring const & wstr)
    {
        typedef std::codecvt_utf8<wchar_t> convert_type;
        std::wstring_convert<convert_type, wchar_t> converterX;

        return std::move(converterX.to_bytes(wstr));
    }

    //Tabulation

    std::string Tab::_put(int nbTab){
        std::string result;
        result.reserve(nbTab);
        result.resize(nbTab);
        for (auto i = 0; i < nbTab; ++i){
            result[i] = '\t';
        }
        return std::move(result);
    }
};

RNPPBASICS_NAMESPACE_END()