#ifndef TEXT_H // include guards
#define TEXT_H

#include<iostream> // necessary include statements
#include<iomanip>
#include<string>
#include<cstring>

using namespace std; //the namespace of std declaration


//declaring class
class Text
{
    private: // private members

    const char * textArray;     //pointer to constant character array
    int textLength;     //num of characters in textArray

    public: // public members

    Text(const char *);     //constructor
    ~Text();    //destructor

    void displayText();     //prints textArray to the screen
    const char * getText();     //accessor function
    int getLength();    //returns length



};

#endif