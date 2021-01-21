//
//  main.cpp
//  HW2
//
//  Created by Sushmitha on 1/20/21.
//  Copyright © 2021 Sushmitha. All rights reserved.
//

#include <iostream>
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    if(argc>1 && argv[1] == std::string("--test")){
        if(Catch::Session().run(1, argv))
            exit(1);
    }
    return 0;
}
