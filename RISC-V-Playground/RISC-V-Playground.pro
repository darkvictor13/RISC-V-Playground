QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    assembler/assembler.cpp \
    instructions/instruction.cpp \
    instructions/instructiontypei.cpp \
    instructions/instructiontyper.cpp \
    instructions/instructiontypes.cpp \
    instructions/instructiontypesb.cpp \
    main.cpp \
    simulator/add.cpp \
    simulator/addbranch.cpp \
    simulator/addnext.cpp \
    simulator/alu.cpp \
    simulator/alucontrol.cpp \
    simulator/andgate.cpp \
    simulator/control.cpp \
    simulator/datamemory.cpp \
    simulator/immgen.cpp \
    simulator/instructionmemory.cpp \
    simulator/memory.cpp \
    simulator/mux.cpp \
    simulator/muxtypea.cpp \
    simulator/muxtypeb.cpp \
    simulator/muxtypec.cpp \
    simulator/pc.cpp \
    simulator/registers.cpp \
    simulator/simulator.cpp \
    view/viewmainwindow.cpp \
    word/word.cpp

HEADERS += \
    assembler/assembler.h \
    instructions/instruction.h \
    instructions/instructiontypei.h \
    instructions/instructiontyper.h \
    instructions/instructiontypes.h \
    instructions/instructiontypesb.h \
    simulator/add.h \
    simulator/addbranch.h \
    simulator/addnext.h \
    simulator/alu.h \
    simulator/alucontrol.h \
    simulator/andgate.h \
    simulator/control.h \
    simulator/datamemory.h \
    simulator/immgen.h \
    simulator/instructionmemory.h \
    simulator/memory.h \
    simulator/mux.h \
    simulator/muxtypea.h \
    simulator/muxtypeb.h \
    simulator/muxtypec.h \
    simulator/pc.h \
    simulator/registers.h \
    simulator/simulator.h \
    view/viewmainwindow.h \
    word/word.h

TRANSLATIONS += \
    RISC-V-Playground_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    view/viewmainwindow.ui

RESOURCES +=
