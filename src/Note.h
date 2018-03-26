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
    std::string dateCreated;
    std::string contents;
    int pageNumber;
    
public:
    Note(std::string pathToNote);
    void save();
    void deleteNote();
    
    // Getters and setters
    void setName(std::string name);
    std::string getName();
    void setDateCreated(std::string dateCreated);
    std::string getDateCreated();
    void setContents(std::string contents);
    std::string getContents();
    void setPageNumber(int pageNumber);
    int getPageNumber();
};

#endif /* Note_h */
