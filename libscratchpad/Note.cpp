//
//  Note.cpp
//  libscratchpad
//
//  Created by Alex Seifert on 26.03.18.
//  Copyright © 2018 Alex Seifert. All rights reserved.
//

#include "Note.h"

void Note::save() {
    
}

void Note::deleteNote() {
    
}


// Getters and setters

void Note::setName(std::string name) {
    this->name = name;
}

std::string Note::getName() {
    return this->name;
}

void Note::setDateCreated(std::string dateCreated) {
    this->dateCreated = dateCreated;
}

std::string Note::getDateCreated() {
    return this->dateCreated;
}

void Note::setContents(std::string contents) {
    this->contents = contents;
}

std::string Note::getContents() {
    return this->contents;
}

void Note::setPageNumber(int pageNumber) {
    this->pageNumber = pageNumber;
}

int Note::getPageNumber() {
    return this->pageNumber;
}
