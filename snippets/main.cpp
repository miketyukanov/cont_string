//
//  main.cpp
//  snippets
//
//  Created by Mike Tyukanov on 09.02.2023.
//
#include "test_templates.hpp"
#include "cont_string.hpp"
#include "member_calls_ctor.hpp"

int main(int argc, const char * argv[]) {
    test_swaps();
    cont_string_test();
    member_calls_ctor();
    
    return 0;
}
