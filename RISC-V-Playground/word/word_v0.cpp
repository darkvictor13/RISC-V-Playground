/**
 * @file word.cpp
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#include "word.h"

Word::Word(bool value)
{
    if(value) {
        set();
    }else{
        reset();
    }
}

Word::Word(Word *word) {
    (*this) = word;
}

Word::Word(int value)
{
    (*this) = integer_to_booleanVector(value);
}

Word::Word(QString binary, int base)
{
    set(binary, 0, DATA_BITS - 1, base);
}

int Word::length_of_base(int base) {
    int i = 0;

    while( (1 << i) < base ) {
        i++;
    }

    return i;
}

int Word::mask(int first, int last) {
    return (-1 << first) & ~(-1 << (last + 1));
}

void Word::set()
{
    int i = 0;
    int last = size();

    while(i < last) {
        (*this)[i] = true;
        i++;
    }
}

void Word::set(Word word)
{
    (*this) = word;
}

void Word::set(int position)
{
    (*this)[position] = true;
}

void Word::set(int first, int last)
{
    while(first <= last) {
        (*this)[first] = true;
        first++;
    }
}

void Word::set(int value, int first, int last)
{
    value = value & mask(0, last - first);

    data = (data & ~mask(first, last)) | value << first;
}

void Word::set(QString binary, int first, int last, int base)
{
    base = length_of_base(base);

    if((int) binary.length() * base > last - first) {
        // error
    }

    last = binary.length();;

    for(int i = 0, j = first; i < last; i++) {
        set(to_int(binary.at(i).toLatin1()), j, j + base - 1);
        j += base;
    }
}

void Word::reset()
{
    int i = 0;
    int last = size();

    while(i < last) {
        (*this)[i] = false;
        i++;
    }
}

void Word::reset(int position)
{
    (*this)[position] = false;
}

void Word::reset(int first, int last)
{
    while(first <= last) {
        (*this)[first] = false;
        first++;
    }
}

void Word::flip(int position)
{
    (*this)[position] = !(*this).at(position);
}

void Word::flip(int first, int last)
{
    while(first <= last) {
        (*this)[first] = !(*this)[first];
        first++;
    }
}

int Word::count()
{
    int count = 0;
    int length = size();

    for(int i = 0; i < length; i++) {
        if(test(i)) {
            count++;
        }
    }

    return count;
}

bool Word::test(int position)
{
    return this->at(position);
}

bool Word::any()
{
    for(int i = 0; i < DATA_BITS; i++) {
        if(test(i)) {
            return true;
        }
    }

    return false;
}

bool Word::none()
{
    return !any();
}

bool Word::all()
{
    if(count() == ((int) size() - 1)) {
        return true;
    }

    return false;
}

Word Word::operator=(const int value)
{
    (*this) = integer_to_booleanVector(value);
}

Word Word::operator+(const Word &word)
{
    Word newWord = booleanVector_to_integer(this) + booleanVector_to_integer(word);

    return newWord;
}

Word Word::operator-(const Word &word)
{
    Word newWord = booleanVector_to_integer(this) - booleanVector_to_integer(word);

    return newWord;
}

Word Word::operator*(const Word &word)
{
    Word newWord = booleanVector_to_integer(this) * booleanVector_to_integer(word);

    return newWord;
}

Word Word::operator/(const Word &word)
{
    Word newWord = booleanVector_to_integer(this) / booleanVector_to_integer(word);

    return newWord;
}

Word Word::operator&(const Word &word)
{
    Word newWord = booleanVector_to_integer(this) & booleanVector_to_integer(word);

    return newWord;
}

Word Word::operator|(const Word &word)
{
    Word newWord = booleanVector_to_integer(this) | booleanVector_to_integer(word);

    return newWord;
}

bool Word::operator&&(const Word &word)
{
    bool result = booleanVector_to_integer(this) && booleanVector_to_integer(word);

    return result;
}

bool Word::operator||(const Word &word)
{
    bool result = booleanVector_to_integer(this) || booleanVector_to_integer(word);

    return result;
}

Word Word::operator~()
{
    Word newWord = ~booleanVector_to_integer(this);

    return newWord;
}

Word Word::operator!()
{
    Word newWord = !booleanVector_to_integer(this);

    return newWord;
}

bool Word::operator==(const Word &word)
{
    return (*this) == word;
}

int Word::getInteger()
{
    return booleanVector_to_integer(this);
}

int Word::getInteger(int first, int last)
{
    Word word;

    while(first <= last) {
        word.push_back(this->test(first));
        first++;
    }

    return booleanVector_to_integer(word);
}

int Word::to_int(char value)
{
    if(value >= 'a') {
        return value - 'a' + 10;
    }else{
        return value - '0';
    }
}

char Word::to_char(int value)
{
    if(value < 10) {
        return '0' + value;
    }else{
        return 'a' + value - 10;
    }
}

void set_bit_in_integer(int *number, int position, bool value)
{
    if(value) {
        *number = (*number) | ( 1 << position);
    }else{
        *number = (*number) & ~( 1 << position);
    }
}

bool test_bit_in_integer(int *value, int position)
{
    return (*value) >> position & 1;
}

Word Word::integer_to_booleanVector(int value)
{
    Word word;

    for(int i = 0; i < DATA_BITS; i++) {
        if(test_bit_in_integer(&value, i)) {
            word.set(i);
        }else{
            word.reset(i);
        }
    }

    return word;
}

int Word::booleanVector_to_integer(Word word)
{
    int value = 0;

    for(int i = 0; i < DATA_BITS; i++) {
        set_bit_in_integer(&value, i, word.test(i));
    }

    return value;
}

QString Word::getString(int base)
{
    return getString(0, DATA_BITS - 1, base);
}

QString Word::getString(int first, int last, int base)
{
    base = length_of_base(base);

    if(base == 0) {
        //error
    }

    QString binary;

    int j = last - (last - first + 1) % base;

    for(int i = first; i <= j; i += base) {
        binary += to_char(getInteger(i, i + base - 1));
    }

    if(j != last) {
        binary += to_char(getInteger(j + 1, last));
    }

    return binary;
}

Word::~Word()
{

}
