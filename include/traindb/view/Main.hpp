#ifndef __MAIN__H__
#define __MAIN__H__

#include "traindb/view/Key.hpp"
#include "traindb/view/Base.hpp"
#include "traindb/Context.hpp"

namespace traindb::view
{
    class Main : public Base
    {
    public:
        Key execute(Context& ctx) override;
    };
} //traindb::screen

#endif  //!__MAIN__H__