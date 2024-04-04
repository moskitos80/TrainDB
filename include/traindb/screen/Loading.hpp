#ifndef __LOADING__H__
#define __LOADING__H__

#include "traindb/screen/Key.hpp"
#include "traindb/screen/Base.hpp"
#include "traindb/Context.hpp"

namespace traindb::screen
{
    class Loading : public Base
    {
    public:
        Key execute(Context& ctx) override;
    };
} //traindb::screen

#endif  //!__LOADING__H__