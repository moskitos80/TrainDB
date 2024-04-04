#ifndef __BASE__H__
#define __BASE__H__

#include "traindb/Context.hpp"
#include "traindb/screen/Key.hpp"

namespace traindb::screen
{
    class Base
    {
    public:
        virtual Key execute(Context& ctx) = 0;
        virtual ~Base() = default;
    };
} // namespace traindb::screen


#endif  //!__BASE__H__