//
//  Helper.h
//  libscratchpad
//
//  Created by Alex Seifert on 26.03.18.
//  Copyright © 2018 Alex Seifert. All rights reserved.
//

#ifndef Helper_h
#define Helper_h

#include <stdio.h>
#include <string>

class Helper {
public:
    static void copyFolder(std::string pathToCopy, std::string destinationStr);
    static void copyFile(std::string pathToCopy, std::string destinationStr);
    static std::string filterPathName(std::string name);
};

#endif /* Helper_h */
