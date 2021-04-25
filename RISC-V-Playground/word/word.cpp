/**
 * @file word.cpp
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#include "word.h"

Word::Word(bool set)
{
    if(set) {
        data = -1;
    }else{
        data = 0;
    }
}

Word::Word(Word *word) {
    this->data = word->data;
}

Word::Word(DATA value)
{
    data = value;
}

Word::Word(QString binary, DATA base)
{
    set(binary, 0, DATA_BITS - 1, base);
}

DATA Word::length_of_base(DATA base) {
    DATA i = 0;

    while( (1 << i) < base ) {
        i++;
    }

    return i;
}

DATA Word::mask(DATA first, DATA last) {
    return (-1 << first) & ~(-1 << (last + 1));
}

void Word::set()
{
    data = -1;
}

void Word::set(Word word)
{
    this->data = word.data;
}

void Word::set(DATA position)
{
    data |= 1 << position;
}

void Word::set(DATA first, DATA last)
{
    data |= mask(first, last);
}

void Word::set(DATA value, DATA first, DATA last)
{
    value = value & mask(0, last - first);

    data = (data & ~mask(first, last)) | value << first;
}

void Word::set(QString binary, DATA first, DATA last, DATA base)
{
    base = length_of_base(base);

    reverse(binary.begin(), binary.end());

    if((DATA) binary.length() * base > last - first) {
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
    data = 0;
}

void Word::reset(DATA position)
{
    data &= ~(1 << position);
}

void Word::reset(DATA first, DATA last)
{
    data &= ~mask(first, last);
}

void Word::flip()
{
    data ^= -1;
}

void Word::flip(DATA position)
{
    data ^= 1 << position;
}

void Word::flip(DATA first, DATA last)
{
    data ^= mask(first, last);
}

DATA Word::count()
{
    DATA count = 0;

    for(int i = 0; i < DATA_BITS; i++) {
        if(test(i)) {
            count++;
        }
    }

    return count;
}

DATA Word::size()
{
    return DATA_BITS;
}

bool Word::test(DATA position)
{
    return (data >> position) & 1;
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
    if(data == -1) {
        return true;
    }

    return false;
}

Word Word::operator=(const int value)
{
    this->data = value;

    return this;
}

Word Word::operator+(const Word &word)
{
    Word newWord = this->data + word.data;

    return newWord;
}

Word Word::operator-(const Word &word)
{
    Word newWord = this->data - word.data;

    return newWord;
}

Word Word::operator*(const Word &word)
{
    Word newWord = this->data * word.data;

    return newWord;
}

Word Word::operator/(const int &word)
{
    Word newWord = (this->data / word);

    return newWord;
}

Word Word::operator/(const Word &word)
{
    Word newWord = (this->data / word.data);

    return newWord;
}

Word Word::operator&(const Word &word)
{
    Word newWord = this->data & word.data;

    return newWord;
}

Word Word::operator|(const Word &word)
{
    Word newWord = this->data | word.data;

    return newWord;
}

bool Word::operator&&(const Word &word)
{
    bool result = this->data && word.data;

    return result;
}

bool Word::operator||(const Word &word)
{
    bool result = this->data || word.data;

    return result;
}

Word Word::operator~()
{
    Word newWord = ~this->data;

    return newWord;
}

Word Word::operator!()
{
    Word newWord = !this->data;

    return newWord;
}

bool Word::operator==(const int &value)
{
    return this->data == value;
}

bool Word::operator==(const Word &word)
{
    return this->data == word.data;
}

void Word::extendInt(int position)
{
    if(this->test(position)) {
        this->set(-1, position, DATA_BITS - 1);
    }
}

DATA Word::getInteger()
{
    return data;
}

DATA Word::getInteger(DATA first, DATA last)
{
    return (data >> first) & ~(-1 << (last - first + 1));
}

int Word::to_int(char value)
{
    if(value >= 'a') {
        return value - 'a' + 10;
    }else{
        return value - '0';
    }
}

int Word::to_int(QChar value)
{
    return value.digitValue();
}


char Word::to_char(DATA value)
{
    if(value < 10) {
        return '0' + value;
    }else{
        return 'a' + value - 10;
    }
}

QString Word::getString(DATA base)
{
    return getString(0, DATA_BITS - 1, base);
}

QString Word::getString(DATA first, DATA last, DATA base)
{
    base = length_of_base(base);

    if(base == 0) {
        //error
    }

    QString binary;

    DATA j = last - (last - first + 1) % base;

    for(int i = first; i <= j; i += base) {
        binary += to_char(getInteger(i, i + base - 1));
    }

    if(j != last) {
        binary += to_char(getInteger(j + 1, last));
    }

    reverse(binary.begin(), binary.end());

    return binary;
}


QString Word::getDecimal()
{
    return QString::number(this->getInteger());
}

Word::~Word()
{

}
