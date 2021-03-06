/**
 * @file word.h
 * @brief Arquivo responsável por definir a classe Word
 * @author mGuerra
 * @version 0.1
*/

#ifndef WORD_H
#define WORD_H

/**
  * @brief Indica a quantidade de bits da instrução
  */
#define DATA int32_t

/**
  * @brief Indica a quantidade de bits da instrução
  */
#define DATA_BITS 32

#include <iostream>
#include <QString>

using namespace std;

/**
 * @brief A classe Word: Representação de uma palavra de 32 bits
 * e suas operações
 */
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

    Word operator=(const int value);

    Word operator+(const Word &word);
    Word operator-(const Word &word);

    Word operator*(const Word &word);
    Word operator/(const Word &word);
    Word operator/(const int &word);

    Word operator&(const Word &word);
    Word operator|(const Word &word);

    bool operator&&(const Word &word);
    bool operator||(const Word &word);

    Word operator~();
    Word operator!();

    bool operator==(const Word &word);
    bool operator==(const int &value);
    bool operator!=(const int &value);

    void extendInt(int position);

    DATA getInteger();
    DATA getInteger(DATA first, DATA last);

    int to_int(char value);
    int to_int(QChar value);
    char to_char(DATA value);

    QString getString(DATA base = 2);
    QString getString(DATA first, DATA last, DATA base = 2);

    QString getDecimal();

    ~Word();
};

#endif // WORD_H
