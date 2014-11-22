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

template <class container_type, class func_type>
inline auto map(const container_type& container, func_type&& func) -> std::list<decltype(func(*(std::begin(container))))>
{
    typedef decltype(*(std::begin(container))) input_type;
    typedef decltype(func(*(std::begin(container)))) output_type;
    
    std::list<output_type> out;
    
    for(const input_type& x : container)
    {
        out.push_back(func(x));
    }
    
    return out;
}

template <class expr_type, class seq_type, class cond_type>
inline auto comprehension(expr_type&& expr, const seq_type& seq, cond_type&& cond) -> std::list<decltype(expr(*std::begin(seq)))>
{
    typedef decltype(*(std::begin(seq))) input_type;
    typedef decltype(expr(*std::begin(seq))) output_type;
    
    std::list<output_type> out;
    
    for(const input_type& x : seq)
    {
        if(cond(x))
            out.push_back(expr(x));
    }
    
    return out;
}

double test(int i)
{
	return i + i / 2.0;
}

int main(int argc, const char * argv[])
{
    auto nums = {1, 2, 3};
    
    auto list = map(nums, [](int i){return i + 2;});
    
    // Doesn't compile, can't infer type of intializer list... 
    //auto list2 = map({4,5,6}, [](int i){return i + 2;});
	// ... have to specify a concrete type to pass, e.g. vector.
    auto list3 = map<std::vector<int>>({4,5,6}, [](int i){return i + 2;});
    
    // If passing by reference into lambda, has to be a const reference
    auto list4 = map(nums, [](const int& i){return i + 2;});
	
	// Can even use arrays!
	int testarray[3];
	auto list5 = map(testarray, test);
    
    // Comprehension test. Equivalent to:
    // [i * i for i in nums if i == 2]
    // in Python. In C++14 can use auto in the lambdas instead of int.
    auto comp = comprehension([](int i){ return i * i; }, nums, [](int i){return i == 2;} );
    
    for(auto i : comp)
    {
        std::cout << i << std::endl;
    }
    
    return 0;
}
