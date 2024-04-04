#ifndef __APP__H__
#define __APP__H__

#include <functional>
#include <map>

#include "traindb/screen/Key.hpp"
#include "traindb/screen/Base.hpp"
#include "traindb/Context.hpp"

namespace traindb
{
    using AppContext = Context;
    using ScreenKey = screen::Key;
    using Screen = screen::Base;

    class App
    {
    public:
        explicit App(Context& ctx)
            : mCtx{ ctx }
        {}

        void AddScreen(ScreenKey k, Screen& s)
        {
            mScreenSet.emplace(k, s);
        }

        void run(ScreenKey start, ScreenKey finish)
        {
            auto state{ start };
            while (true) {
                state = mScreenSet.at(state).execute(mCtx);
                if (state == finish) {
                    return;
                }
            }
        }

        virtual ~App() = default;

    private:
        Context& mCtx;
        std::map<ScreenKey, Screen&> mScreenSet{};
    };
}



#endif  //!__APP__H__