#include <fstream>

#include "traindb/persist/TrainRepo.hpp"

namespace traindb
{
    explicit TrainRepo::TrainRepo(const std::string& filePath)
        try {

        std::ifstream in{ filePath };
        if (!in) {
            throw TrainRepo::OpenError{
                "Cant't open file " + filePath };
        }


    } catch (const std::exception& e) {
        throw TrainRepo::OpenError{ e.what() };
    }
}