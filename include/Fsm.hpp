#ifndef __FSM__H__
#define __FSM__H__

#include <functional>
#include <map>

template<typename Key, typename Context>
class FsmState
{
public:
    virtual Key execute(Context& ctx) = 0;
    virtual ~FsmState() = default;
};

template<typename Key, typename Context>
class Fsm
{
public:
    using State = FsmState<Key, Context>;

    explicit Fsm(Context& ctx)
        : mCtx{ ctx }
    {}

    void AddState(Key k, State& state)
    {
        mStateSet.emplace(k, state);
    }

    void run(Key start, Key finish)
    {
        auto state{ start };
        while (true) {
            state = mStateSet.at(state).execute(mCtx);
            if (state == finish) {
                return;
            }
        }
    }

    virtual ~Fsm() = default;

private:
    Context& mCtx;
    std::map<Key, State&> mStateSet{};
};

#endif  //!__FSM__H__