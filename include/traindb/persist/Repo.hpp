#ifndef __REPO__H__
#define __REPO__H__

#include <functional>
#include <algorithm>
#include <optional>
#include <memory>
#include <vector>
#include <string>

namespace traindb
{
    template<typename ItemType, typename ItemKeyType>
    class Repository
    {
    public:

        using ItemPtr = std::shared_ptr<ItemType>;
        using Collection = std::vector<ItemPtr>;
        using Criteria = std::function<bool(ItemPtr)>;

        class OpenError : public std::runtime_error
        {
        public:
            using std::runtime_error::runtime_error;
        };

        class SaveError : public std::runtime_error
        {
        public:
            using std::runtime_error::runtime_error;
        };

        virtual ~Repository() = default;

        void Add(ItemPtr ent)
        {
            mCollect.push_back(ent);
        }

        std::optional<ItemPtr> Get(const ItemKeyType& key)
        {
            auto res{ std::find(
                mCollect.begin(),
                mCollect.end(), key) };

            if (res == std::end(mCollect)) {
                return std::nullopt;
            }

            return *res;
        }

        Collection Find(const Criteria criteria)
        {
            Collection result{};
            std::copy_if(
                mCollect.begin(),
                mCollect.end(),
                std::back_inserter(result), criteria);
            return result;
        }

        bool Del(const ItemKeyType& key)
        {
            auto res{ std::find(
                mCollect.begin(),
                mCollect.end(), key) };

            if (res == std::end(mCollect)) {
                return false;
            }

            mCollect.erase(res);
            return true;
        }

    private:
        Collection mCollect{};
    };
}

#endif  //!__REPO__H__