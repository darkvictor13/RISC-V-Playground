#ifndef MUX_H
#define MUX_H

#include <QObject>

#include "word/word.h"

class Mux : public QObject
{
    Q_OBJECT

public:
    Word valueA = 0;
    Word valueB = 0;
    Word selection = 0;

    bool hasValueA = false;
    bool hasValueB = false;
    bool hasSelection = false;

    Mux();

    void setValueA(Word valueA);
    void setValueB(Word valueB);
    void setSelection(Word selection);

    void tryExecute();
    void virtual execute() = 0;

    ~Mux();

signals:
    void receivedValueA(Word valueA);
    void receivedValueB(Word valueB);
    void receivedSelection(Word selection);

    void executed();

};

#endif // MUX_H
