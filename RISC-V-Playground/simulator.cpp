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

void Simulator::assembly(string filename)
{
    string name;
    string extension;
    string output_filename;

    int separator = filename.find_last_of(".");

    name = filename.substr(0, separator);
    extension = filename.substr(separator + 1);
    output_filename = name + ".bin";

}

/**
 * @brief Destrutor da classe Simulator
 */
Simulator::~Simulator()
{
    cout << "Destruindo classe simulador" << endl;
}
