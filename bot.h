//
//  bot.h
//  chatbot
//
//  Created by Govindan Vedanarayanan on 22/01/17.
//  Copyright © 2017 Govindan Vedanarayanan. All rights reserved.
//

#ifndef bot_h
#define bot_h

#include "manipulateInput.hpp"
#include <string>
#include <iostream>
using namespace std;

typedef struct
{
    string userInput;
    string botResponses[5];
}info;

class Chatbot
{
    string botName;
    string input;
    string prevInput;
    string altInput;
    string response;
    string prevResponse;
    string event;
    string prevEvent;
    bool quitChat;
    vecStr responses;
public:
    Chatbot(string str): botName(str), input(""), quitChat(1)           //////
    {
        seed_random();
    }
    ~Chatbot() {}
    bool quit() const
    {
        return quitChat;
    }
    void get_input();
    void respond();
private:
    void search();
    void handle_event(string str);
    void handle_repetition();
    void handle_user_repetiton();
    void seed_random()
    {
        srand((unsigned int)time(NULL));
    }
    void choose_response()
    {
        shuffle(responses,responses.size());
        response = responses[0];
    }
    void save_prevInput()
    {
        prevInput = input;
    }
    void save_prevResponse()
    {
        prevResponse = response;
    }
    void save_prevEvent()
    {
        prevEvent = event;
    }
    void setEvent(string str)
    {
        event = str;
    }
    void saveInput()
    {
        altInput = input;
    }
    void setInput(string str)
    {
        input = str;
    }
    void restoreInput()
    {
        input = altInput;
    }
    void print_response() const
    {
        if (response.length() > 0)
        {
            cout << response << endl;
        }
    }
    void process()
    {
        removeSplChars(input);
        removeExtSpaces(input);
        makeCaps(input);
    }
    bool botRepeat() const
    {
        return (prevResponse.length() > 0 && prevResponse == response);
    }
    bool userRepeat() const
    {
        return (prevInput.length() > 0 && ((prevInput == input) || (input.find(prevInput) != string::npos) || (prevInput.find(input) != string::npos)));
    }
    bool botUnderstand() const
    {
        return responses.size() > 0;
    }
    bool nullInput() const
    {
        return (input.length() == 0 && prevInput.length() != 0);
    }
    bool nullInputRepeat() const
    {
        return (input.length() == 0 && prevInput.length() == 0);
    }
    bool userQuit() const
    {
        return input.find("BYE") != string::npos;
    }
    bool sameEvent() const
    {
        return (event.length() > 0 && event == prevEvent);
    }
    bool noResponse() const
    {
        return responses.size() == 0;
    }
    bool sameInput() const
    {
        return (input.length() > 0 && input == prevInput);
    }
    bool similarInput() const
    {
        return (input.length() > 0 && ((input.find(prevInput) != string::npos) || (prevInput.find(input) != string::npos)));
    }
};

#endif /* bot_h */
