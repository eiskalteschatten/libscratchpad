//
//  Note.cpp
//  libscratchpad
//
//  Created by Alex Seifert on 26.03.18.
//  Copyright © 2018 Alex Seifert. All rights reserved.
//

#include <boost/filesystem.hpp>
#include <fstream>

#include "Note.h"
#include "Helper.h"

namespace fs = boost::filesystem;

Note::Note(std::string ptn, std::string n, std::string c) {
    name = n;
    pathToNote = ptn;
    contents = c;
    noteExtension = ".rtfd";

    fullPathToNote = pathToNote + Helper::filterPathName(name) + noteExtension;

    if (!fs::is_directory(pathToNote)) {
        fs::create_directories(pathToNote);
    }
}

void Note::save() {
    std::ofstream noteFile(fullPathToNote);

    if (!noteFile.good()) {
        throw std::runtime_error("Failed to create note: " + fullPathToNote);
    }

    noteFile << contents;
    noteFile.close();
}

void Note::deleteNote() {
    try {
        fs::remove(fullPathToNote);
    }
    catch(fs::filesystem_error const& e) {
        throw e;
    }
}

void Note::exportNote(std::string destinationStr) {
    Helper::copyFile(fullPathToNote, destinationStr);
}
