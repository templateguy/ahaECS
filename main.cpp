//
//  main.cpp
//  ECS
//
//  Created by Priyanshi Thakur on 24/07/18.
//  Copyright © 2018 Priyanshi Thakur. All rights reserved.
//

#include <iostream>
#include "Entity.hpp"


struct Foo
{
    virtual void print() const
    {
        std::cout << "Function Called!";
    }
};

struct Bar : public Foo
{
    Bar()
    {
        entity.add <int> (20);
    }
    
    void print() const override
    {
        std::cout << entity.get <int> ();
    }
    
    aha::Entity entity;
};

int main(int argc, const char * argv[])
{
    aha::Entity entity;
    entity.add <Foo> ();
    //entity.add <int> (20);
    //std::cout << entity.get <int> () << std::endl;
    //entity.get <int> () = 10;
    //std::cout << entity.get <int> () << std::endl;
    entity.get <Foo> ().print();
    
    entity.add <Foo*> (new Bar());
    entity.get <Foo*> ()->print();
    
    //Bar bar;
    //bar.print();
    return 0;
}
