#include "text.h"

//making the text constructor
Text::Text(const char * charArray){
    
    //getting the length of input character array (charArray)
    textLength = strlen(charArray);

    //dynamically allocating a new character array the size of input
    char * tempArray = new char [textLength];

    //copying the input array to the temporary dynamic array
    strcpy(tempArray, charArray);

    //copying the contents of the temp array to textArray
    textArray = tempArray;

}

//making the text destructor
Text::~Text(){

    //deleting dynamically allocated character array via textArray
    delete [] textArray;

    cout << "Text destructor: Released memory for textArray" << endl;
}

void Text::displayText(){

    //displaying the contents of textArray
    cout << this->textArray;

}

const char * Text::getText(){

    //returning the textArray
    return this->textArray;

}

int Text::getLength(){

    //accessing the length of the textArray
    return this->textLength;
    
}