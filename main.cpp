//
//  main.cpp
//  My Chatbot
//
//  Created by Govindan Vedanarayanan on 22/01/17.
//  Copyright © 2017 Govindan Vedanarayanan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> vecStr;

typedef struct
{
    string userInput;
    string botResponses[5];
}info;

const int max_response = 3;

info dataBase[] = {
    {"WHAT IS YOUR NAME",
        {"MY NAME IS CHATTERBOT.",
            "YOU CAN CALL ME CHATTERBOT.",
            "WHY DO YOU WANT TO KNOW MY NAME?"}
    },
    
    {"HI",
        {"HI THERE!",
            "HOW ARE YOU?",
            "HI!"}
    },
    
    {"HOW ARE YOU",
        {"I'M DOING FINE!",
            "I'M DOING WELL AND YOU?",
            "WHY DO YOU WANT TO KNOW HOW I AM DOING?"}
    },
    
    {"WHO ARE YOU",
        {"I'M AN A.I PROGRAM.",
            "I THINK THAT YOU KNOW WHO I'M.",
            "WHY ARE YOU ASKING?"}
    },
    
    {"ARE YOU INTELLIGENT",
        {"YES, OFCOURSE.",
            "WHAT DO YOU THINK?",
            "ACTUALY,I'M VERY INTELLIENT!"}
    },
    
    {"ARE YOU REAL",
        {"DOES THAT QUESTION REALLY MATTER TO YOU?",
            "WHAT DO YOU MEAN BY THAT?",
            "I'M AS REAL AS ONE CAN BE."}
    }
};

size_t dataBaseSize = sizeof(dataBase)/sizeof(dataBase[0]);

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
    for (i; i < input.length(); i++)
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

void process(string &input)
{
    removeSplChars(input);
    removeExtSpaces(input);
    makeCaps(input);
}

void getResponses(string str[], vecStr &responses)
{
    for (int i = 0; i < max_response; i++)
        responses.push_back(str[i]);
}

vecStr search(string input)
{
    vecStr responses;
    for (int i = 0; i < dataBaseSize; i++)
    {
        string key(dataBase[i].userInput);
        if (key.find(input) != string::npos)
        {
            getResponses(&dataBase[i].userInput,responses);
            return responses;
        }
    }
    return responses;
}

int main()
{
    srand((unsigned int)time(NULL));
    string input = "";
    string prevInput = "";
    string response = "";
    string prevResponse = "";
    while (8)
    {
        cout << "> ";
        prevInput = input;
        prevResponse = response;
        getline(cin,input);
        process(input);
        vecStr responses = search(input);
        if (input == prevInput && input.length() > 0) cout << "Stop repeating yourself!\n";
        else if (input == "BYE")
        {
            cout << "Bye! Until next time!\n";
            break;
        }
        else if (responses.size() == 0) cout << "I'm sorry I don't understand!\n";
        else
        {
            int randomSelection = rand() % max_response;
            response = responses[randomSelection];
            if (response == prevResponse)
            {
                responses.erase(responses.begin()+randomSelection);
                randomSelection = rand() % responses.size();
                response = responses[randomSelection];
            }
            cout << response << endl;
        }
    }
    return 0;
}
