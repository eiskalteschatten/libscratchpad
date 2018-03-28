//
//  Helper.cpp
//  libscratchpad
//
//  Created by Alex Seifert on 26.03.18.
//  Copyright © 2018 Alex Seifert. All rights reserved.
//

#include <boost/filesystem.hpp>
#include <iostream>
#include <regex>

#include "Helper.h"

namespace fs = boost::filesystem;

void Helper::copyFolder(std::string pathToCopy, std::string destinationStr) {
    fs::path source = fs::path(pathToCopy);
    fs::path destination = fs::path(destinationStr);

    if (!fs::exists(source) || !fs::is_directory(source)) {
        throw std::runtime_error("Source directory " + source.string() + " does not exist or is not a directory.");
    }

    if(fs::exists(destination)) {
        throw std::runtime_error("Destination directory " + destination.string() + " already exists.");
    }

    if(!fs::create_directory(destination)) {
        throw std::runtime_error("Unable to create destination directory " + destination.string());
    }

    for(fs::directory_iterator file(source); file != fs::directory_iterator(); ++file) {
        fs::path current(file->path());

        if(fs::is_directory(current)) {
            try {
                Helper::copyFolder(current.string(), (destination / current.filename()).string());
            }
            catch(std::exception const& e) {
                throw e;
            }
        }
        else {
            fs::copy_file(current, destination / current.filename());
        }
    }
}

void Helper::copyFile(std::string pathToCopy, std::string destinationStr) {
    fs::copy_file(pathToCopy, destinationStr);
}

std::string Helper::filterPathName(std::string name) {
    std::regex pathFilter("[^A-Za-z0-9.-]");
    return std::regex_replace(name, pathFilter, "_");
}
