//
//  Helper.cpp
//  libscratchpad
//
//  Created by Alex Seifert on 26.03.18.
//  Copyright © 2018 Alex Seifert. All rights reserved.
//

#include <boost/filesystem.hpp>

#include "Helper.h"

namespace bfs = boost::filesystem;

bool Helper::copyFolder(std::string pathToCopy, std::string destination) {

	bfs::copy_directory(bfs::path(pathToCopy), bfs::path(destination));

	return true;
}
