#ifndef __SEARCH__H__
#define __SEARCH__H__

#include "traindb/screen/Key.hpp"
#include "traindb/screen/Base.hpp"
#include "traindb/Context.hpp"

namespace traindb::screen
{
    class Search : public Base
    {
    public:
        Key execute(Context& ctx) override;
    };
} //traindb::screen

#endif  //!__SEARCH__H__