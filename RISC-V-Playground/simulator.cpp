/**
  @file simulator.cpp
  @brief Arquivo que implementa os métodos da classe Simulator
  @author Victor Emanuel Almeida
  @version 0.1
*/

#include "simulator.h"

/**
 * @brief Construtor da classe Simulator
 */
Simulator::Simulator()
{
    cout << "Criando classe simulador" << endl;
}


void Simulator::writeFileClear(QString filename)
{
    QFile read(filename);
    if (read.open(QFile::ReadOnly | QFile::Text)) {
        cout << "Falha ao abrir arquivo assembly .s";
    }
    QTextStream in(&read);
    QString linha;
    QStringRef name(&filename, 0, filename.lastIndexOf("."));
    QFile write(name + ".clear");
    QTextStream out(&write);
    write.open(QFile::WriteOnly | QFile::Text);
    while(!in.atEnd()) {
        linha = in.readLine();
    }
}

void Simulator::assembly(string filename)
{
    string name;
    string extension;
    string output_filename;

    int separator = filename.find_last_of(".");

    name = filename.substr(0, separator);
    extension = filename.substr(separator + 1);
    output_filename = name + ".bin";

    cout << filename << endl;
    cout << name << endl;
    cout << extension << endl;
    cout << output_filename << endl;

}

/**
 * @brief Destrutor da classe Simulator
 */
Simulator::~Simulator()
{
    cout << "Destruindo classe simulador" << endl;
}
