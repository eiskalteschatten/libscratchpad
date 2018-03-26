//
//  main.cpp
//  libscratchpad
//
//  Created by Alex Seifert on 26.03.18.
//  Copyright © 2018 Alex Seifert. All rights reserved.
//

#include <iostream>

#include "Helper.h"

int main(int argc, const char * argv[]) {
    Helper helper;
    helper.copyFolder("/Users/alexseifert/Downloads", "/Users/alexseifert/Desktop");
    std::cout << "Hello, World!\n";
    return 0;
}
