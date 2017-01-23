//
//  bot.cpp
//  chatbot
//
//  Created by Govindan Vedanarayanan on 22/01/17.
//  Copyright © 2017 Govindan Vedanarayanan. All rights reserved.
//

#include "bot.h"

info dataBase[] = {
    {"WHAT IS YOUR NAME",
        {"MY NAME IS CHATTERBOT.",
            "YOU CAN CALL ME CHATTERBOT.",
            "WHY DO YOU WANT TO KNOW MY NAME?"}
    },
    
    {"HELLO",
        {"HI THERE!"}
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
            "I THINK YOU KNOW WHO I'M.",
            "WHY ARE YOU ASKING?"}
    },
    
    {"ARE YOU INTELLIGENT",
        {"YES, OFCOURSE.",
            "WHAT DO YOU THINK?",
            "ACTUALY, I'M VERY INTELLIENT!"}
    },
    
    {"ARE YOU REAL",
        {"DOES THAT QUESTION REALLY MATTER TO YOU?",
            "WHAT DO YOU MEAN BY THAT?",
            "I'M AS REAL AS ONE CAN BE."}
    },
    
    {"REPETITION T1**",
        {"YOU ARE REPEATING YOURSELF.",
            "USER, PLEASE STOP REPEATING YOURSELF.",
            "THIS CONVERSATION IS GETING BORING.",
            "DON'T YOU HAVE ANY THING ELSE TO SAY?"}
    },
    
    {"REPETITION T2**",
        {"YOU'VE ALREADY SAID THAT.",
            "I THINK YOU JUST SAID THE SAME THING BEFORE.",
            "DIDN'T YOU ALREADY SAY THAT?",
            "I'M GETING THE IMPRESSION THAT YOU ARE REPEATING THE SAME THING."}
    },
    
    {"BOT DONT UNDERSTAND**",
        {"I HAVE NO IDEA WHAT YOU ARE TALKING ABOUT.",
            "I'M NOT SURE IF I UNDERSTAND WHAT YOU ARE TALKING ABOUT.",
            "CONTINUE, I'M LISTENING...",
            "VERY GOOD CONVERSATION!"}
    },
    
    {"NULL INPUT**",
        {"HUH?",
            "WHAT IS THAT SUPPOSED TO MEAN?",
            "AT LEAST TAKE SOME TIME TO ENTER SOMETHING MEANINGFUL.",
            "HOW CAN I SPEAK TO YOU IF YOU DONT WANT TO SAY ANYTHING?"}
    },
    
    {"NULL INPUT REPETITION**",
        {"WHAT ARE YOU DOING??",
            "PLEASE STOP DOING THIS IT IS VERY ANNOYING.",
            "WHAT'S WRONG WITH YOU?",
            "THIS IS NOT FUNNY."}
    },
    
    {"BYE",
        {"IT WAS NICE TALKING TO YOU USER, SEE YOU NEXT TIME!",
            "BYE USER!",
            "OK, BYE!"}
    },
    
    {"ARE YOU A HUMAN BEING",
        {"WHY DO YOU WANT TO KNOW?",
            "IS THIS REALLY RELEVENT?"}
    },
    
    {"YOU ARE VERY INTELLIGENT",
        {"THANKS FOR THE COMPLIMENT USER, I THINK THAT YOU ARE INTELLIGENT TOO!",
            "YOU ARE A VERY GENTLE PERSON!",
            "SO, YOU THINK THAT I'M INTELLIGENT."}
    },
    
    {"ARE YOU SURE",
        {"OFCORSE I'M.",
            "DOES THAT MEAN YOU ARE NOT CONVINCED?",
            "YES, OFCOURSE!"}
    },
    
    {"WHO IS",
        {"I DONT THINK I KNOW WHO.",
            "DID YOU ASK SOMEONE ELSE ABOUT IT?",
            "WOULD THAT CHANGE ANYTHING AT ALL IF I TOLD YOU WHO."}
    },
    
    {"WHAT",
        {"I DON'T KNOW.",
            "I DON'T THINK I KNOW.",
            "I HAVE NO IDEA."}
    },
    
    {"WHERE",
        {"WHERE? WELL,I REALLY DON'T KNOW.",
            "DOES THAT MATTER TO YOU TO KNOW WHERE?",
            "PERHAPS, SOMEONE ELSE KNOWS WHERE."}
    },
    
    {"WHY",
        {"I DON'T THINK I KNOW WHY.",
            "WHY ARE YOU ASKING ME THIS?",
            "SHOULD I KNOW WHY.",
            "THIS WOULD BE DIFFICULT TO ANSWER."}
    },
    
    {"DO YOU",
        {"I DONT THINK I DO",
            "I WOULDN'T THINK SO.",
            "WHY DO YOU WANT TO KNOW?"}
    },
    
    {"CAN YOU",
        {"I THINK NOT.",
            "I'M NOT SURE.",
            "I DON'T THINK THAT I CAN DO THAT."}
    },
    
    {"YOU ARE",
        {"WHAT MAKES YOU THINK THAT?",
            "IS THIS A COMPLIMENT?",
            "ARE YOU MAKING FUN OF ME?"}
    },
    
    {"DID YOU",
        {"I DON'T THINK SO.",
            "ANYWAY, I WOULDN'T REMEMBER EVEN IF I DID."}
    },
    
    {"COULD YOU",
        {"ARE YOU ASKING ME FOR A FAVOUR?",
            "WELL,LET ME THINK ABOUT IT.",
            "SORRY, I DON'T THINK I CAN DO THIS."}
    },
    
    {"WOULD YOU",
        {"IS THAT AN INVITATION?",
            "I WOULD HAVE TO THINK ABOUT IT FIRST."}
    },
    
    {"HOW",
        {"I DON'T THINK I KNOW HOW."}
    },
    
    {"WHICH ONE",
        {"I DON'T THINK I KNOW WHICH ONE IT IS.",
            "THIS LOOKS LIKE A TRICKY QUESTION TO ME."}
    },
    
    {"PERHAPS",
        {"WHY ARE YOU SO UNCERTAIN?",
            "YOU SEEM UNCERTAIN."}
    },
    
    {"YES",
        {"SO,IT IS YES.",
            "OH, REALLY?",
            "OK THEN."}
    },
    
    {"I DONT KNOW",
        {"ARE YOU SURE?",
            "ARE YOU REALLY TELLING ME THE TRUTH?",
            "SO, YOU DONT KNOW?"}
    },
    
    {"NOT REALLY",
        {"OK I SEE.",
            "YOU DON'T SEEM PRETTY CERTAIN.",
            "SO, THAT WOULD BE A \"NO\"."}
    },
    
    {"IS THAT TRUE",
        {"I CAN'T BE QUITE SURE ABOUT THIS.",
            "CAN'T TELL YOU FOR SURE.",
            "DOES THAT REALLY MATTER TO YOU?"}
    },
    
    {"YOU",
        {"SO, YOU ARE TALKING ABOUT ME.",
            "WHY DONT WE TALK ABOUT YOU INSTEAD?",
            "ARE YOU TRYING TO MAKE FUN OF ME?"}
    },
    
    {"THANKS",
        {"YOU ARE WELCOME!",
            "NO PROBLEM!"}
    },
    
    {"WHAT ELSE",
        {"WELL, I DONT KNOW.",
            "WHAT ELSE SHOULD THERE BE?",
            "THIS LOOKS LIKE A COMPLICATED QUESTION TO ME."}
    },
    
    {"SORRY",
        {"YOU DONT NEED TO BE SORRY USER.",
            "IT'S OK.",
            "NO NEED TO APOLOGIZE."}
    },
    
    {"NOT EXACTLY",
        {"WHAT DO YOU MEAN NOT EXACTLY?",
            "ARE YOU SURE?"}
    },
    
    {"EXACTLY",
        {"SO, I WAS RIGHT.",
            "OK THEN."}
    },
    
    {"ALRIGHT",
        {"ALRIGHT THEN.",
            "OK THEN."}
    },
    
    {"I DONT",
        {"WHY NOT?",
            "AND WHAT WOULD BE THE REASON FOR THIS?"}
    },
    
    {"REALLY",
        {"WELL, I CAN'T TELL YOU FOR SURE.",
            "ARE YOU TRYING TO CONFUSE ME?",
            "PLEASE DONT ASK ME SUCH QUESTIONS, IT GIVES ME HEADACHES."}
    }
};

size_t dataBaseSize = sizeof(dataBase)/sizeof(dataBase[0]);

void Chatbot::get_input()
{
    cout << "> ";
    save_prevInput();
    getline(cin,input);
    process();
}

void Chatbot::search()
{
    responses.clear();
    for (int i = 0; i < dataBaseSize; i++)
    {
        string key(dataBase[i].userInput);
        if (key.find(input) != string::npos)
        {
            getResponses(dataBase[i].botResponses,responses);
            break;
        }
    }
}

void Chatbot::respond()
{
    save_prevResponse();
    setEvent("BOT UNDERSTAND**");
    if (nullInput())
    {
        handle_event("NULL INPUT**");
    }
    else if (nullInputRepeat())
    {
        handle_event("NULL INPUT REPETITION**");
    }
    else if (userRepeat())
    {
        handle_user_repetiton();
    }
    else
    {
        search();
    }
    if (userQuit())
    {
        quitChat = 0;
    }
    if (!botUnderstand())
    {
        handle_event("BOT DONT UNDERSTAND**");
    }
    if (responses.size() > 0)
    {
        choose_response();
        if (botRepeat())
        {
            handle_repetition();
        }
        print_response();
    }
}

void Chatbot::handle_repetition()
{
    if(responses.size() > 0)
    {
        responses.erase(responses.begin());
    }
    if(noResponse())
    {
        saveInput();
        setInput(event);
        search();
        restoreInput();
    }
    choose_response();
}

void Chatbot::handle_user_repetiton()
{
    if(sameInput())
    {
        handle_event("REPETITION T1**");
    }
    else if(similarInput())
    {
        handle_event("REPETITION T2**");
    }
}

void Chatbot::handle_event(string str)
{
    save_prevEvent();
    setEvent(str);
    saveInput();
    setInput(str);
    if(!sameEvent())
    {
        search();
    }
    restoreInput();
}

int main()
{
    Chatbot bot("Chatter Bot");
    
    while(bot.quit())
    {
        bot.get_input();
        bot.respond();
    }
    return 0;
}