#ifndef __BASE__H__
#define __BASE__H__

#include "traindb/Context.hpp"
#include "traindb/view/Key.hpp"

namespace traindb::view
{
    class Base
    {
    public:
        virtual Key execute(Context& ctx) = 0;
        virtual ~Base() = default;
    };
} // namespace traindb::screen


#endif  //!__BASE__H__