/**
 * @file add.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef ADD_H
#define ADD_H

#include "word/word.h"

class Add
{
public:
    Word valueA = 0;
    Word valueB = 0;

    bool hasValueA = false;
    bool hasValueB = false;

    Add();

    void setValueA(Word valueA);
    void setValueB(Word valueB);

    void tryExecute();
    void execute() {};

    ~Add();
};

#endif // ADD_H
