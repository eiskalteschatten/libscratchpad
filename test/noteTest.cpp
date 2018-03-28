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
#include "../src/Helper.h"

namespace fs = boost::filesystem;

BOOST_AUTO_TEST_SUITE(noteSuite);

BOOST_AUTO_TEST_CASE(getters) {
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

BOOST_AUTO_TEST_CASE(saveNote) {
    std::string tmpPath = "/tmp/libscratchpad/";
    std::string pathToNote = tmpPath + "test/";
    std::string noteName = "test note save";
    std::string contents = "note contents should go here";

    Note note(pathToNote, noteName, contents);
    fs::path fullPathToNote = note.getFullPathToNote();

    try {
        note.save();
        BOOST_CHECK(true);
    }
    catch(std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        BOOST_CHECK(false);
    }

    fs::remove_all(tmpPath);
}

BOOST_AUTO_TEST_CASE(deleteNote) {
    std::string tmpPath = "/tmp/libscratchpad/";
    std::string pathToNote = tmpPath + "test/";
    std::string noteName = "test note delete";
    std::string contents = "note contents should go here";

    Note note(pathToNote, noteName, contents);
    fs::path fullPathToNote = note.getFullPathToNote();

    try {
        note.save();
        note.deleteNote();
    }
    catch(std::exception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
        BOOST_CHECK(false);
    }

    BOOST_CHECK(fs::exists(fullPathToNote) == false);

    fs::remove_all(tmpPath);
}

BOOST_AUTO_TEST_CASE(exportNote) {
    std::string tmpPath = "/tmp/libscratchpad/";
    std::string pathToNote = tmpPath + "test/";
    std::string noteName = "test note copy";
    std::string contents = "note contents should go here";
    std::string copyDestination = pathToNote + Helper::filterPathName("copy of test note copy.rtfd");

    Note note(pathToNote, noteName, contents);
    fs::path fullPathToNote = note.getFullPathToNote();

    try {
        note.save();
        note.exportNote(copyDestination);
    }
    catch(std::exception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
        BOOST_CHECK(false);
    }

    BOOST_CHECK(fs::exists(copyDestination) == true);

    fs::remove_all(tmpPath);
}

BOOST_AUTO_TEST_SUITE_END();
