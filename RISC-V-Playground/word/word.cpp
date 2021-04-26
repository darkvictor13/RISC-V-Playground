/**
 * @file word.cpp
 * @brief Arquivo responsável por implementar a classe Word
 * @author mGuerra
 * @version 0.1
*/

#include "word.h"

/**
 * @brief Word::Word: Construtor da classe Word
 *
 * Inicializa todos os bits ligados ou desligados
 * @param bool set: liga todos os bits da palavra quando true
 */
Word::Word(bool set)
{
    if(set) {
        data = -1;
    }else{
        data = 0;
    }
}

/**
 * @brief Word::Word Construtor da classe Word
 *
 * Inicializa a nova palavra a partir de uma antiga
 * @param Word word: Local de memória de outra Word
 */
Word::Word(Word *word) {
    this->data = word->data;
}

/**
 * @brief Word::Word Construtor da classe Word
 *
 * Inicializa  a partir de um valor inteiro
 * @param DATA value: um valor inteiro
 */
Word::Word(DATA value)
{
    data = value;
}

/**
 * @brief Word::Word Construtor da classe Word
 *
 * Inicializa a partir de uma string que representa
 * um número em determinada base
 * @param QString binary: representação textual de um número
 * @param DATA base: base do número representado na string
 */
Word::Word(QString binary, DATA base)
{
    set(binary, 0, DATA_BITS - 1, base);
}

/**
 * @brief Word::length_of_base: Indica o tamanho da base
 * @param base: número inteiro
 * @return DATA tamanho da base
 */
DATA Word::length_of_base(DATA base) {
    DATA i = 0;

    while( (1 << i) < base ) {
        i++;
    }

    return i;
}

/**
 * @brief Word::mask: Gera uma máscara de bits ligados entre as posições
 * passadas como parâmetro
 * @param DATA first: posição incial da máscara
 * @param DATA last: posição incial da máscara
 * @return DATA: A máscara gerada
 */
DATA Word::mask(DATA first, DATA last) {
    return (-1 << first) & ~(-1 << (last + 1));
}
/**
 * @brief Word::set: Altera o valor contido na Word
 *
 * Sempre coloca o valor em -1
 */
void Word::set()
{
    data = -1;
}

/**
 * @brief Word::set: Altera o valor contido na Word
 *
 * Copia o valor contido em uma palavra para a atual
 * @param Word word
 */
void Word::set(Word word)
{
    this->data = word.data;
}

/**
 * @brief Word::set: Altera o valor contido na Word
 *
 * Altera o valor do bit na posição passada por referência
 * @param DATA position
 */
void Word::set(DATA position)
{
    data |= 1 << position;
}

/**
 * @brief Word::set: Altera o valor contido na Word
 *
 * Altera os bits de uma posição incial até a final
 * @param DATA first: posição incial para alterar
 * @param DATA last: posição incial para alterar
 */
void Word::set(DATA first, DATA last)
{
    data |= mask(first, last);
}

/**
 * @brief Word::set: Altera o valor contido na Word
 *
 * Coloca o valor binário contido em value dentro dos bits
 * passados por parâmetro
 * @param DATA value: valor a ser escrito na palavra
 * @param DATA first: posição incial para alterar
 * @param DATA last: posição incial para alterar
 */
void Word::set(DATA value, DATA first, DATA last)
{
    value = value & mask(0, last - first);

    data = (data & ~mask(first, last)) | value << first;
}

/**
 * @brief Word::set: Altera o valor contido na Word
 *
 * Coloca o valor de uma base qualquer dentro dos bits
 * passados por parâmetro
 * @param QString binary: representação textual do valor a ser escrito
 * @param DATA first: posição incial para alterar
 * @param DATA last: posição incial para alterar
 * @param base: Em qual base está a QString
 */
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

/**
 * @brief Word::reset: Zera todos os bits da Word
 *
 * Valor da Word fica zerado
 */
void Word::reset()
{
    data = 0;
}

/**
 * @brief Word::reset: Zera o bit da Word em determinada posição
 *
 * Altera um unico bit
 * @param position: bit a ser zerado
 */
void Word::reset(DATA position)
{
    data &= ~(1 << position);
}

/**
 * @brief Word::reset: Zera os bits da Word de um bit até outro
 *
 * Altera do bit first até o bit last
 * @param DATA first: posição incial para alterar
 * @param DATA last: posição incial para alterar
 */
void Word::reset(DATA first, DATA last)
{
    data &= ~mask(first, last);
}

/**
 * @brief Word::flip: Inverte todos os bits da palavra
 *
 * Cada bit da palavra é negado
 */
void Word::flip()
{
    data ^= -1;
}

/**
 * @brief Word::flip: Inverte o bit de determinada posição
 *
 * Somente um bit da palavra é negado
 * @param DATA position: bit a ser invertido
 */
void Word::flip(DATA position)
{
    data ^= 1 << position;
}

/**
 * @brief Word::flip: Inverte os bits de um trecho da Word
 *
 * Somente (last - first) bits da palavra são negados
 * @param DATA first: posição incial para alterar
 * @param DATA last: posição incial para alterar
 */
void Word::flip(DATA first, DATA last)
{
    data ^= mask(first, last);
}

/**
 * @brief Word::count: Conta quantos bits da palavra
 * estão ligados
 * @return DATA: Quantidade de de bits ligados
 */
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

/**
 * @brief Word::size: Indica o tamanho da palavra
 * @return DATA: Quantidade de bits da palavra
 */
DATA Word::size()
{
    return DATA_BITS;
}

/**
 * @brief Word::test: Testa se determinado bit da palavra está ligado
 * @param DATA position: Posição do bit a ser testado
 * @return
 */
bool Word::test(DATA position)
{
    return (data >> position) & 1;
}

/**
 * @brief Word::any: Testa se algum bit da palavra está ligado
 * @return bool: Verdadeiro quando todos os bits estão ligados
 */
bool Word::any()
{
    for(int i = 0; i < DATA_BITS; i++) {
        if(test(i)) {
            return true;
        }
    }

    return false;
}
/**
 * @brief Word::none: Testa se algum bit da palavra está desligado
 * @return bool: Verdadeiro quando todos os bits estão desligados
 */
bool Word::none()
{
    return !any();
}

/**
 * @brief Word::all: Testa se todos os bits da palavra estão ligados
 * @return bool: Verdadeiro quando todos os bits da palavra estão ligados
 */
bool Word::all()
{
    if(data == -1) {
        return true;
    }

    return false;
}

/**
 * @brief Word::operator =: Sobrecarga do operador =
 *
 * Carrega uma palavra
 * @param const int value: valor a ser colocado na palavra
 * @return Word: uma palavra com o valor correto
 */
Word Word::operator=(const int value)
{
    this->data = value;

    return this;
}

/**
 * @brief Word::operator +: Sobrecarga do operador +
 *
 * Soma duas palavras
 * @param const Word word: Constante a ser somada
 * @return Word: uma palavra com o valor correto
 */
Word Word::operator+(const Word &word)
{
    Word newWord = this->data + word.data;

    return newWord;
}

/**
 * @brief Word::operator -: Sobrecarga do operador   -
 *
 * Subtração da palavra atual com constante
 * @param const Word word: Constante a ser subtraída
 * @return Word: uma palavra com o valor correto
 */
Word Word::operator-(const Word &word)
{
    Word newWord = this->data - word.data;

    return newWord;
}

/**
 * @brief Word::operator *: Sobrecarga do operador *
 *
 * Multiplica duas palavras
 * @param const Word word: Constante a ser multiplicada
 * @return Word: uma palavra com o valor correto
 */
Word Word::operator*(const Word &word)
{
    Word newWord = this->data * word.data;

    return newWord;
}

/**
 * @brief Word::operator /: Sobrecarga do operador /
 *
 * Divide a palavra por uma constante
 * @param const int word: Constante utilizada como divisor
 * @return Word: uma palavra com o valor correto
 */
Word Word::operator/(const int &word)
{
    Word newWord = (this->data / word);

    return newWord;
}

/**
 * @brief Word::operator /: Sobrecarga do operador /
 *
 * Divide a palavra por outra
 * @param const Word word: Constante utilizada como divisor
 * @return Word: uma palavra com o valor correto
 */
Word Word::operator/(const Word &word)
{
    Word newWord = (this->data / word.data);

    return newWord;
}

/**
 * @brief Word::operator &: Sobrecarga do operador &
 *
 * Realiza o and bit a bit com duas palavras
 * @param const Word word: palavra de referência para a operação
 * @return Word: uma palavra com o valor correto
 */
Word Word::operator&(const Word &word)
{
    Word newWord = this->data & word.data;

    return newWord;
}

/**
 * @brief Word::operator |: Sobrecarga do operador |
 *
 * Realiza o or bit a bit com duas palavras
 * @param const Word word: palavra de referência para a operação
 * @return Word: uma palavra com o valor correto
 */
Word Word::operator|(const Word &word)
{
    Word newWord = this->data | word.data;

    return newWord;
}

/**
 * @brief Word::operator &&: Sobrecarga do operador &&
 *
 * Realiza o and lógico com duas palavras
 * @param const Word word: palavra de referência para a operação
 * @return Word: uma palavra com o valor correto
 */
bool Word::operator&&(const Word &word)
{
    bool result = this->data && word.data;

    return result;
}

/**
 * @brief Word::operator ||: Sobrecarga do operador ||
 *
 * Realiza o or lógico com duas palavras
 * @param const Word word: palavra de referência para a operação
 * @return Word: uma palavra com o valor correto
 */
bool Word::operator||(const Word &word)
{
    bool result = this->data || word.data;

    return result;
}

/**
 * @brief Word::operator ~: Sobrecarga do operador ~
 *
 * Negação bit a bit da palavra
 * @return Word: uma palavra com o valor correto
 */
Word Word::operator~()
{
    Word newWord = ~this->data;

    return newWord;
}

/**
 * @brief Word::operator !: Sobrecarga do operador !
 *
 * Negação lógica os bits da palavra
 * @return Word: uma palavra com o valor correto
 */
Word Word::operator!()
{
    Word newWord = !this->data;

    return newWord;
}

/**
 * @brief Word::operator ==: Sobrecarga do operador ==
 *
 * Verifica se uma constante é igual a palavra
 * @param const int value: valor a ser comparado
 * @return bool: Se a palavra é igual ao valor passado por referência
 */
bool Word::operator==(const int &value)
{
    return this->data == value;
}

/**
 * @brief Word::operator ==: Sobrecarga do operador ==
 *
 * Verifica se duas palavras são iguais
 * @param const Word word: valor a ser comparado
 * @return bool: Se a palavra é igual ao valor passado por referência
 */
bool Word::operator==(const Word &word)
{
    return this->data == word.data;
}

/**
 * @brief Word::operator !=: Sobrecarga do operador !=
 *
 * Verifica se duas palavras são diferentes
 * @param const int value: valor a ser comparado
 * @return bool: Se a palavra é igual ao valor passado por referência
 */
bool Word::operator!=(const int &value)
{
    return !(this->data == value);
}

/**
 * @brief Word::extendInt: transforma um número com poucos bits em
 * um número de 32 bits
 *
 * Copia o último bit para todos os de mais alta ordem
 * @param position: último bit carregado
 */
void Word::extendInt(int position)
{
    if(this->test(position)) {
        this->set(-1, position, DATA_BITS - 1);
    }
}

/**
 * @brief Word::getInteger: Indica o valor decimal da palavra
 *
 * Valor da palavra completa
 * @return DATA: Valor decimal da palavra
 */
DATA Word::getInteger()
{
    return data;
}

/**
 * @brief Word::getInteger: Indica o valor decimal da palavra
 *
 * Valor dos bits delimitados pelos parâmetros
 * @param DATA first: posição incial
 * @param DATA last: posição incial
 * @return DATA: Valor inteiro da posição delimitada
 */
DATA Word::getInteger(DATA first, DATA last)
{
    return (data >> first) & ~(-1 << (last - first + 1));
}

/**
 * @brief Word::to_int: Converte um caractere numérico
 * para seu valor decimal
 * @param char value: Caractere ASCII representando um dígito decimal
 * @return int: Valor numérico do caractere
 */
int Word::to_int(char value)
{
    if(value >= 'a') {
        return value - 'a' + 10;
    }else{
        return value - '0';
    }
}

/**
  * @overload int Word::to_int(QChar value)
 */
int Word::to_int(QChar value)
{
    return value.digitValue();
}

/**
 * @brief Word::to_char: Converte um dígito decimal
 * para um caractere
 * @param char value
 * @return char: Caractere que representa um dígito decimal
 */
char Word::to_char(DATA value)
{
    if(value < 10) {
        return '0' + value;
    }else{
        return 'a' + value - 10;
    }
}

/**
 * @brief Word::getString: Obtém o número decimal
 * que representa a palavra no formato de string
 *
 * Sempre pega o valor de toda a palavra
 * @param DATA base
 * @return
 */
QString Word::getString(DATA base)
{
    return getString(0, DATA_BITS - 1, base);
}

/**
 * @brief Word::getString: Obtém o número decimal
 * que representa a palavra no formato de string
 *
 * Pega o valor apenas de um trecho da palavra
 * @param DATA first: posição incial
 * @param DATA last: posição incial
 * @param DATA base: Base do número
 * @return
 */
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

/**
 * @brief Word::getDecimal: Obtém o número decimal
 * que representa a palavra no formato de QString
 * @return QString: Representação do número da palavra
 */
QString Word::getDecimal()
{
    return QString::number(this->getInteger());
}

/**
 * @brief Word::~Word: Destrutor da classe Word
 */
Word::~Word()
{

}
