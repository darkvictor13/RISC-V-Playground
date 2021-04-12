/**
 * @file word.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef WORD_H
#define WORD_H

#define DATA int32_t
#define DATA_BITS 32

#include <iostream>

using namespace std;

class Word
{
private:
    DATA data;

public:
    Word(DATA value);
    Word(Word *word);
    Word(bool set = false);
    Word(string binary, DATA base = 2);

    DATA length_of_base(DATA base);
    DATA mask(DATA first, DATA last);

    void set();
    void set(DATA position);
    void set(DATA first, DATA last);

    void set(DATA value, DATA first, DATA last);
    void set(string binary, DATA first, DATA last, DATA base = 2);

    void reset();
    void reset(DATA position);
    void reset(DATA first, DATA last);

    void flip();
    void flip(DATA position);
    void flip(DATA first, DATA last);

    bool test(DATA position);
    DATA count();
    DATA size();
    bool none();
    bool any();
    bool all();

    DATA getInteger();
    DATA getInteger(DATA first, DATA last);

    int to_int(char value);
    char to_char(DATA value);

    string getString(DATA base = 2);
    string getString(DATA first, DATA last, DATA base = 2);

    ~Word();
};

#endif // WORD_H
