//
//  noteTest.cpp
//  libscratchpad
//
//  Created by Alex Seifert on 27.03.18.
//  Copyright © 2018 Alex Seifert. All rights reserved.
//

#include <boost/filesystem.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <iostream>

#include "../src/Note.h"

BOOST_AUTO_TEST_SUITE(noteSuite);

BOOST_AUTO_TEST_CASE(getters)
{
    std::string pathToNote = "/tmp/libscratchpad/test/";
    std::string noteName = "test note";
    std::string contents = "note contents should go here";
    std::string fullPathToNote = pathToNote + "test_note.rtfd";

    Note note(pathToNote, noteName, contents);

    BOOST_CHECK(note.getPathToNote() == pathToNote);
    BOOST_CHECK(note.getName() == noteName);
    BOOST_CHECK(note.getContents() == contents);
    BOOST_CHECK(note.getFullPathToNote() == fullPathToNote);
}

BOOST_AUTO_TEST_CASE(saveNote)
{
    namespace fs = boost::filesystem;

    std::string tmpPath = "/tmp/libscratchpad/";
    std::string pathToNote = tmpPath + "test/";
    std::string noteName = "test note";
    std::string contents = "note contents should go here";

    // Check if it saved successfully
    Note note(pathToNote, noteName, contents);
    fs::path fullPathToNote = note.getFullPathToNote();

    try {
        note.save();
        BOOST_CHECK(true);
    }
    catch(std::exception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
        BOOST_CHECK(false);
    }

    fs::remove_all(tmpPath);
}

BOOST_AUTO_TEST_SUITE_END();
