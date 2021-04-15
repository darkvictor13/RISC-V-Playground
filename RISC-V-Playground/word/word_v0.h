/**
 * @file word.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef WORD_H
#define WORD_H

#define DATA_BITS 32

#include <iostream>
#include <vector>
#include <QString>

using namespace std;

class Word : public vector<bool>
{
public:
    Word(int value);
    Word(Word *word);
    Word(bool value = false);
    Word(QString binary, int base = 2);

    int length_of_base(int base);
    int mask(int first, int last);

    void set();
    void set(Word word);
    void set(int position);
    void set(int first, int last);

    void set(int value, int first, int last);
    void set(QString binary, int first, int last, int base = 2);

    void reset();
    void reset(int position);
    void reset(int first, int last);

    void flip();
    void flip(int position);
    void flip(int first, int last);

    bool test(int position);
    int count();
    bool none();
    bool any();
    bool all();

    Word operator=(const int value);

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

    int getInteger();
    int getInteger(int first, int last);

    int to_int(char value);
    char to_char(int value);

    void set_bit_in_integer(int *number, int position, bool value);
    bool test_bit_in_integer(int *value, int position);

    Word integer_to_booleanVector(int value);
    int booleanVector_to_integer(Word word);

    QString getString(int base = 2);
    QString getString(int first, int last, int base = 2);

    ~Word();
};

#endif // WORD_H
