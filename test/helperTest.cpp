//
//  helperTest.cpp
//  libscratchpad
//
//  Created by Alex Seifert on 26.03.18.
//  Copyright © 2018 Alex Seifert. All rights reserved.
//

#define BOOST_TEST_MODULE Helper

#include <boost/filesystem.hpp>
#include <boost/test/unit_test.hpp>
#include <string>

#include "../src/Helper.h"

BOOST_AUTO_TEST_SUITE(helperSuite);

BOOST_AUTO_TEST_CASE(copyFolder)
{
    namespace bfs = boost::filesystem;

    std::string tmpPath = "/tmp/folder-to-copy";
    std::string testFile = "test.txt";

    bfs::path pathToCopy = bfs::current_path();
    pathToCopy /= "test/data/folder-to-copy";

    if (bfs::is_directory(tmpPath))
    {
        bfs::remove_all(tmpPath);
    }

    bool folderCopied = Helper::copyFolder(pathToCopy.string(), tmpPath);
    BOOST_CHECK(folderCopied == true);

    BOOST_CHECK(bfs::is_directory(tmpPath) == true);
    BOOST_CHECK(bfs::exists(tmpPath + "/" + testFile) == true);

    bfs::remove_all(tmpPath);
}

BOOST_AUTO_TEST_SUITE_END();
