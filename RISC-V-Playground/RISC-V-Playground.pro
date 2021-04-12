QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    assembler.cpp \
    instruction.cpp \
    instructiontypei.cpp \
    instructiontyper.cpp \
    instructiontypes.cpp \
    instructiontypesb.cpp \
    main.cpp \
    memory.cpp \
    registers.cpp \
    simulator.cpp \
    viewmainwindow.cpp \
    word.cpp

HEADERS += \
    assembler.h \
    instruction.h \
    instructiontypei.h \
    instructiontyper.h \
    instructiontypes.h \
    instructiontypesb.h \
    memory.h \
    registers.h \
    simulator.h \
    viewmainwindow.h \
    word.h

FORMS += \
    viewmainwindow.ui

TRANSLATIONS += \
    RISC-V-Playground_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
