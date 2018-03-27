//
//  noteTest.cpp
//  libscratchpad
//
//  Created by Alex Seifert on 27.03.18.
//  Copyright © 2018 Alex Seifert. All rights reserved.
//

#include <boost/test/unit_test.hpp>
#include <string>

#include "../src/Note.h"

BOOST_AUTO_TEST_SUITE(noteSuite);

BOOST_AUTO_TEST_CASE(getters)
{
    std::string pathToNote = "/path/to/note.txt";
    //std::string noteName = "test note";

    Note note(pathToNote);
    BOOST_CHECK(note.getPathToNote() == pathToNote);
}

BOOST_AUTO_TEST_SUITE_END();
