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
#include <iostream>

#include "../src/Helper.h"

namespace fs = boost::filesystem;

BOOST_AUTO_TEST_SUITE(helperSuite);

BOOST_AUTO_TEST_CASE(copyFolder) {
    std::string tmpPath = "/tmp/libscratchpad/";
    std::string testFile = "test.txt";

    fs::path pathToCopy = fs::current_path();
    pathToCopy /= "test/data/folder-to-copy";

    try {
        Helper::copyFolder(pathToCopy.string(), tmpPath);
        BOOST_CHECK(true);
    }
    catch(std::exception const& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        BOOST_CHECK(false);
    }

    BOOST_CHECK(fs::is_directory(tmpPath) == true);
    BOOST_CHECK(fs::exists(tmpPath + testFile) == true);

    fs::remove_all(tmpPath);
}

BOOST_AUTO_TEST_CASE(copyFile) {
    std::string tmpPath = "/tmp/libscratchpad/";
    std::string testFile = "test.txt";
    std::string tmpFile = tmpPath + testFile;

    fs::path pathToCopy = fs::current_path();
    pathToCopy /= "test/data/folder-to-copy";
    pathToCopy /= testFile;

    if (!fs::is_directory(tmpPath)) {
        fs::create_directories(tmpPath);
    }

    try {
        Helper::copyFile(pathToCopy.string(), tmpFile);
        BOOST_CHECK(true);
    }
    catch(std::exception const& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        BOOST_CHECK(false);
    }

    BOOST_CHECK(fs::exists(tmpFile) == true);

    fs::remove_all(tmpPath);
}

BOOST_AUTO_TEST_CASE(filterPathName) {
    std::string nameToFilter = "some name with spaces";
    std::string filteredName = Helper::filterPathName(nameToFilter);

    BOOST_CHECK(filteredName == "some_name_with_spaces");
}

BOOST_AUTO_TEST_SUITE_END();
