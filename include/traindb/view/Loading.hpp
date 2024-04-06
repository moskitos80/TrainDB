#ifndef __LOADING__H__
#define __LOADING__H__

#include "traindb/view/Key.hpp"
#include "traindb/view/Base.hpp"
#include "traindb/Context.hpp"

namespace traindb::view
{
    class Loading : public Base
    {
    public:
        Key execute(Context& ctx) override;
    };
} //traindb::screen

#endif  //!__LOADING__H__