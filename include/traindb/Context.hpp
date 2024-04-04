#ifndef __APP_CONTEXT__H__
#define __APP_CONTEXT__H__

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

#include "Train.hpp"

namespace traindb
{
    using TrainStorage = std::vector<std::unique_ptr<Train>>;

    struct Context
    {
        std::vector<std::string> Info{};
        std::vector<std::string> Error{};
        TrainStorage Db{};
    };
}

#endif  //!__APP_CONTEXT__H__