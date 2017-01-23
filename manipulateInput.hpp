//
//  manipulateInput.hpp
//  chatbot
//
//  Created by Govindan Vedanarayanan on 22/01/17.
//  Copyright © 2017 Govindan Vedanarayanan. All rights reserved.
//

#ifndef manipulateInput_hpp
#define manipulateInput_hpp

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> vecStr;
const int max_response = 3;

void removeSplChars(string &);
void removeExtSpaces(string &);
void makeCaps(string &);
void getResponses(string str[], vecStr &);

template<typename T>
void shuffle(T &array, size_t size) {
    for(int i = 0; i < size; ++i) {
        int index = rand() % size;
        std::swap(array[i], array[index]);
    }
}

#endif /* manipulateInput_hpp */
