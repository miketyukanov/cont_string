//
//  main.cpp
//  cont_string
//
//  Created by Mike Tyukanov on 27.01.2023.

//  A collection of comments to VT's course, cpp part


#include <iostream>
#include "cont_string.hpp"

using namespace std;


template <typename T> string cont_2_string(const T& cont)
{
    return string(begin(cont), end(cont));
}


int main(void)
{
    cont_string_test();
    
    return 0;
 }
