//
//  Entity.hpp
//  ECS
//
//  Created by Priyanshi Thakur on 24/07/18.
//  Copyright © 2018 Priyanshi Thakur. All rights reserved.
//

#pragma once


#include <typeindex>
#include "any.hpp"
#include <map>


#define nm linb

namespace aha
{
    class Entity
    {
    public:
        template <typename T, typename... Types>
        void add(Types... types)
        {
            auto id{getComponentId_ <T> ()};
            components_[id] = std::move(T{types...});
        }
        
        template <typename T>
        auto& get()
        {
            auto i{components_.find(getComponentId_ <T> ())};
            return nm::any_cast <T&> (i->second);
        }
        
        template <typename T>
        const auto& get() const
        {
            auto i{components_.find(getComponentId_ <T> ())};
            return nm::any_cast <const T&> (i->second);
        }
        
        template <typename T>
        bool has() const
        {
            auto i{components_.find(getComponentId_ <T> ())};
            return i != components_.end();
        }
        
    private:
        template <typename T>
        static auto getComponentId_()
        {
            return std::type_index(typeid(T));
        }
        
        std::map <std::type_index, nm::any> components_;
    };
}
