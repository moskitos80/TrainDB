#ifndef __MAIN__H__
#define __MAIN__H__

#include "traindb/screen/Key.hpp"
#include "traindb/screen/Base.hpp"
#include "traindb/Context.hpp"

namespace traindb::screen
{
    class Main : public Base
    {
    public:
        Key execute(Context& ctx) override;
    };
} //traindb::screen

#endif  //!__MAIN__H__