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
auto map(const container& c, func&& f) -> std::list<decltype(f(*(c.begin())))>
{
    typedef decltype(*(c.begin())) input_type;
    typedef decltype(f(*(c.begin()))) output_type;
    
    std::list<output_type> out;
    
    std::cout << "A";
    
    for(auto& x : c)
    {
        std::cout << "B";
        out.push_back(f(x));
        std::cout << "C";
    }
    
    return out;
}

class test_class
{
public:
    test_class()
    {
        std::cout << "Normal constructor" << std::endl;
    }
    test_class(const test_class& x)
    {
        std::cout << "Copy constructor" << std::endl;
    }
    test_class(test_class&& x)
    {
        std::cout << "Move constructor" << std::endl;
    }
};

template<class func>
inline std::list<int> maptest(std::vector<test_class> c, func f)
{
    std::list<int> out;
    
    for(test_class x : c)
    {
        out.push_back(f(x));
    }
    
    return out;
}

/*
template <typename T, class func>
auto map(std::initializer_list<T> c, func f) -> std::list<decltype(f(*(c.begin())))>
{
    typedef decltype(f(*(c.begin()))) output_type;
    std::list<output_type> out;
    std::cout << "Uh..." << std::endl;
    return out;
}
*/

int main(int argc, const char * argv[]) {
    
    auto nums = {1, 2, 3};
    std::list<test_class> v(2);
    
    std::cout << "Boom" << std::endl;
    
    auto testfunc = [](const test_class& i) { return 0; };
    testfunc(*(v.begin()));
    
    auto test = map(v, testfunc);
    
    auto list = map(nums, [](int i){return i + 2;});
    auto list2 = map<std::initializer_list<int>>({4,5,6}, [](int i){return i + 2;});
    
    for(auto i : list)
    {
        std::cout << i << std::endl;
    }
    
    for(auto i : list2)
    {
        std::cout << i << std::endl;
    }
    
    std::cout << [](int i){return i;}(-2) << std::endl;
    
    return 0;
}
