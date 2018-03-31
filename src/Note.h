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
    void exportNote(std::string destinationStr);

    // Getters
    std::string const& getPathToNote() const {return pathToNote;}
    std::string const& getFullPathToNote() const {return fullPathToNote;}
    std::string const& getName() const {return name;}
    std::string const& getContents() const {return contents;}
    int const& getPageNumber() const {return pageNumber;}
};

#endif /* Note_h */
