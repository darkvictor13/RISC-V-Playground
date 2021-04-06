QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arithmeticlogicunit.cpp \
    instruction.cpp \
    instructiontypei.cpp \
    instructiontyper.cpp \
    main.cpp \
    mainwindow.cpp \
    memory.cpp \
    programcounter.cpp \
    registers.cpp \
    simulator.cpp

HEADERS += \
    arithmeticlogicunit.h \
    instruction.h \
    instructiontypei.h \
    instructiontyper.h \
    mainwindow.h \
    memory.h \
    programcounter.h \
    registers.h \
    simulator.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    RISC-V-Playground_pt_BR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    theme.qss
