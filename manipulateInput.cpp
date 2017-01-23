//
//  manipulateInput.cpp
//  chatbot
//
//  Created by Govindan Vedanarayanan on 22/01/17.
//  Copyright © 2017 Govindan Vedanarayanan. All rights reserved.
//

#include "manipulateInput.hpp"

void removeSplChars(string &input)
{
    string t = "";
    for (int i = 0; i < input.length(); i++)
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || input[i] == ' ')
            t += input[i];
    input = t;
}

void removeExtSpaces(string &input)
{
    string t = "";
    int i;
    for (i = 0; input[i] == ' '; i++);
    for (; i < input.length(); i++)
    {
        if (input[i] == ' ' && ((input[i+1] >= 'a' && input[i+1] <= 'z') || (input[i+1] >= 'A' && input[i+1] <= 'Z')))
            t += " ";
        else if (input[i] != ' ') t += input[i];
    }
    input = t;
}

void makeCaps(string &input)
{
    for (int i = 0; i < input.length(); i++)
        if (input[i] >= 'a' && input[i] <= 'z')
            input[i] -= 32;
}

void getResponses(string str[], vecStr &responses)
{
    for (int i = 0; i < max_response; i++)
        responses.push_back(str[i]);                            // might need change
}