//
//  Note.h
//  libscratchpad
//
//  Created by Alex Seifert on 26.03.18.
//  Copyright © 2018 Alex Seifert. All rights reserved.
//

#ifndef Note_h
#define Note_h

#include <stdio.h>
#include <string>

class Note {
private:
    std::string name;
    std::string pathToNote;
    std::string fullPathToNote;
    std::string noteExtension;
    std::string contents;
    int pageNumber;

public:
    Note(std::string ptn, std::string n, std::string c);
    void save();
    void deleteNote();

    // Getters
    std::string const& getPathToNote() {return pathToNote;}
    std::string const& getFullPathToNote() {return fullPathToNote;}
    std::string const& getName() {return name;}
    std::string const& getContents() {return contents;}
    int const& getPageNumber() {return pageNumber;}
};

#endif /* Note_h */
