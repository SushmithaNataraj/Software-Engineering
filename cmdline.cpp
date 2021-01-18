//
//  cmdline.cpp
//  HW1
//
//  Created by Sushmitha on 1/18/21.
//  Copyright © 2021 Sushmitha. All rights reserved.
//
#include <iostream>
#include "cmdline.hpp"
#include <string.h>

void use_arguments(int argc, const char** argv){
    int seen = 0;
    /* If there are no command line arguments! */
    if(argc <= 1){
        std::cout<<"Please enter an argument!";
        exit(0);
    }
    
    for(int i = 0; i <= argc - 1; i++){
        /* If the command line argument is '--help' and it is the first argument, no need to inspect
         * additional arguments
         */
        if(i+1 == 1 && strcmp(argv[i+1], "--help") == 0){
            std::cout<<"Print some text that describes how to run program!\n";
            exit(0);
        }
        /* If the argument is '-test' ! */
        else if(strcmp(argv[i+1], "--test") == 0){
            /* if --test is not seen before print and continue*/
            if(!seen){
                std::cout<<"Tests passed\n";
                seen = 1;
            }
            else{
                /* if --test is already seen before, print error and exit */
                std::cerr<<"Duplicate arguments\n";
                exit(1);
            }
        }
        /* if the argument is some other string, print error and exit */
        else{
            std::cerr<<"Invalid arguments!\n";
            exit(1);
        }
    }
    
}
