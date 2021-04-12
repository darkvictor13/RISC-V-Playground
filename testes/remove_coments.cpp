#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

int main (int argc, char *argv[]) {
    string linha;
    ifstream input;
    ofstream output;
    input.open("../files/test.s");
    output.open("../files/test.clear");
    while(getline(input, linha)) {
        if (linha.size()) {
            if (linha[0] != '#') {
                output << linha << endl;
            }
        }
        
    }
    input.close();
    output.close();
    return 0;
}
