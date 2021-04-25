/**
 * @file add.h
 * @brief Arquivo responsável por definir a classe
 * @author mGuerra
 * @version 0.1
*/

#ifndef ADD_H
#define ADD_H

#include <QObject>

#include "word/word.h"

/**
 * @brief A classe Add:
 */
class Add : public QObject
{
    Q_OBJECT

public:
    Word valueA = 0;
    Word valueB = 0;

    bool hasValueA = false;
    bool hasValueB = false;

    Add();

    void setValueA(Word valueA);
    void setValueB(Word valueB);

    void tryExecute();
    void virtual execute() = 0;

    ~Add();

signals:
    void receivedValueA(Word valueA);
    void receivedValueB(Word valueB);

    void executed();

};

#endif // ADD_H
