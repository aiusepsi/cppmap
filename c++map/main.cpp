//
//  main.cpp
//  c++map
//
//  Created by Andrew Simpson on 26/10/2014.
//  Copyright (c) 2014 Andrew Simpson. All rights reserved.
//

#include <iostream>
#include <list>

#include <iostream>
#include <vector>

template <class container, class func>
inline auto map(const container& c, func&& f) -> std::list<decltype(f(*(c.begin())))>
{
    typedef decltype(*(c.begin())) input_type;
    typedef decltype(f(*(c.begin()))) output_type;
    
    std::list<output_type> out;
    
    for(const auto& x : c)
    {
        out.push_back(f(x));
    }
    
    return out;
}

int main(int argc, const char * argv[])
{
    auto nums = {1, 2, 3};
    
    auto list = map(nums, [](int i){return i + 2;});
    
    // Doesn't compile, can't infer type of intializer list, have to specify it:
    //auto list2 = map({4,5,6}, [](int i){return i + 2;});
    auto list3 = map<std::initializer_list<int>>({4,5,6}, [](int i){return i + 2;});
    
    // If passing by reference into lambda, has to be a const reference
    auto list4 = map(nums, [](const int& i){return i + 2;});
    
    return 0;
}
