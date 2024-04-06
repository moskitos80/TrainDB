#ifndef __SEARCH__H__
#define __SEARCH__H__

#include "traindb/view/Key.hpp"
#include "traindb/view/Base.hpp"
#include "traindb/Context.hpp"

namespace traindb::view
{
    class Search : public Base
    {
    public:
        Key execute(Context& ctx) override;
    };
} //traindb::screen

#endif  //!__SEARCH__H__