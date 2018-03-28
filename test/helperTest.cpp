//
//  helperTest.cpp
//  libscratchpad
//
//  Created by Alex Seifert on 26.03.18.
//  Copyright © 2018 Alex Seifert. All rights reserved.
//

#include <boost/filesystem.hpp>
#include <boost/test/unit_test.hpp>
#include <string>

#include "../src/Helper.h"

BOOST_AUTO_TEST_SUITE(helperSuite);

BOOST_AUTO_TEST_CASE(copyFolder) {
    namespace fs = boost::filesystem;

    std::string tmpPath = "/tmp/folder-to-copy";
    std::string testFile = "test.txt";

    fs::path pathToCopy = fs::current_path();
    pathToCopy /= "test/data/folder-to-copy";

    if (fs::is_directory(tmpPath))
    {
        fs::remove_all(tmpPath);
    }

    bool folderCopied = Helper::copyFolder(pathToCopy.string(), tmpPath);
    BOOST_CHECK(folderCopied == true);

    BOOST_CHECK(fs::is_directory(tmpPath) == true);
    BOOST_CHECK(fs::exists(tmpPath + "/" + testFile) == true);

    fs::remove_all(tmpPath);
}

BOOST_AUTO_TEST_SUITE_END();
