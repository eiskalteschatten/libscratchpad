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
    std::string pathToNote;
    std::string name;
    std::string dateCreated;
    std::string contents;
    int pageNumber;

public:
    Note(std::string ptn);
    void save();
    void deleteNote();

    // Getters
    std::string const& getPathToNote() {return pathToNote;}
    std::string const& getName() {return name;}
    std::string const& getDateCreated() {return dateCreated;}
    std::string const& getContents() {return contents;}
    int const& getPageNumber() {return pageNumber;}
};

#endif /* Note_h */
