//
//  Helper.cpp
//  libscratchpad
//
//  Created by Alex Seifert on 26.03.18.
//  Copyright © 2018 Alex Seifert. All rights reserved.
//

#include <iostream>
#include <boost/filesystem.hpp>

#include "Helper.h"

namespace fs = boost::filesystem;

bool Helper::copyFolder(std::string pathToCopy, std::string destinationStr) {
    fs::path source = fs::path(pathToCopy);
    fs::path destination = fs::path(destinationStr);

    try {
        if (!fs::exists(source) || !fs::is_directory(source)) {
            std::cerr << "Source directory " << source.string() << " does not exist or is not a directory." << '\n';
            return false;
        }

        if(fs::exists(destination)) {
            std::cerr << "Destination directory " << destination.string() << " already exists." << '\n';
            return false;
        }

        if(!fs::create_directory(destination)) {
            std::cerr << "Unable to create destination directory" << destination.string() << '\n';
            return false;
        }
    }
    catch(fs::filesystem_error const & e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    for(fs::directory_iterator file(source); file != fs::directory_iterator(); ++file) {
        try {
            fs::path current(file->path());

            if(fs::is_directory(current)) {
                if(!Helper::copyFolder(current.string(), (destination / current.filename()).string())) {
                    return false;
                }
            }
            else {
                fs::copy_file(current, destination / current.filename());
            }
        }
        catch(fs::filesystem_error const& e) {
            std:: cerr << e.what() << '\n';
        }
    }

    return true;
}

void Helper::copyFile(std::string pathToCopy, std::string destinationStr) {
    try {
        fs::copy_file(pathToCopy, destinationStr);
    }
    catch(fs::filesystem_error const& e) {
        throw e;
    }
}
