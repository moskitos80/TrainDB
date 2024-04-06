#ifndef __TRAINREPO__H__
#define __TRAINREPO__H__

#include "traindb/persist/Repo.hpp"
#include "traindb/persist/Train.hpp"

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <functional>
#include <optional>

namespace traindb
{
    class TrainRepo :
        public Repository<Train, std::string>
    {
    public:
        TrainRepo(const std::string& path);
    };
} // namespace traindb


#endif  //!__TRAINREPO__H__