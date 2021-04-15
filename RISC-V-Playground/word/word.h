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
#include <QString>

using namespace std;

class Word
{
private:
    DATA data;

public:
    Word(DATA value);
    Word(Word *word);
    Word(bool set = false);
    Word(QString binary, DATA base = 2);

    DATA length_of_base(DATA base);
    DATA mask(DATA first, DATA last);

    void set();
    void set(Word word);
    void set(DATA position);
    void set(DATA first, DATA last);

    void set(DATA value, DATA first, DATA last);
    void set(QString binary, DATA first, DATA last, DATA base = 2);

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

    Word operator+(const Word &word);
    Word operator-(const Word &word);

    Word operator*(const Word &word);
    Word operator/(const Word &word);

    Word operator&(const Word &word);
    Word operator|(const Word &word);

    bool operator&&(const Word &word);
    bool operator||(const Word &word);

    Word operator~();
    Word operator!();

    bool operator==(const Word &word);

    DATA getInteger();
    DATA getInteger(DATA first, DATA last);

    int to_int(char value);
    char to_char(DATA value);

    QString getString(DATA base = 2);
    QString getString(DATA first, DATA last, DATA base = 2);

    ~Word();
};

#endif // WORD_H
