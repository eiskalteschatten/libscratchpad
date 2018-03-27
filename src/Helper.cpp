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

namespace bfs = boost::filesystem;

bool Helper::copyFolder(std::string pathToCopy, std::string destinationStr) {
    bfs::path source = bfs::path(pathToCopy);
    bfs::path destination = bfs::path(destinationStr);

    try
    {
        if (!bfs::exists(source) || !bfs::is_directory(source))
        {
            std::cerr << "Source directory " << source.string() << " does not exist or is not a directory." << '\n';
            return false;
        }
        if(bfs::exists(destination))
        {
            std::cerr << "Destination directory " << destination.string() << " already exists." << '\n';
            return false;
        }
        if(!bfs::create_directory(destination))
        {
            std::cerr << "Unable to create destination directory" << destination.string() << '\n';
            return false;
        }
    }
    catch(bfs::filesystem_error const & e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    for(bfs::directory_iterator file(source); file != bfs::directory_iterator(); ++file)
    {
        try
        {
            bfs::path current(file->path());
            if(bfs::is_directory(current))
            {
                if(!Helper::copyFolder(current.string(), (destination / current.filename()).string()))
                {
                    return false;
                }
            }
            else
            {
                bfs::copy_file(current, destination / current.filename());
            }
        }
        catch(bfs::filesystem_error const& e)
        {
            std:: cerr << e.what() << '\n';
        }
    }

    return true;
}
