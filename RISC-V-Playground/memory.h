#ifndef MEMORY_H
#define MEMORY_H

#define MEMORY_SIZE 1024

/**
 * @brief A classe Memory:
 */
class Memory
{
private:
    int vector[MEMORY_SIZE];

public:
    Memory();

    int get(int position);
    void set(int position, int value);

    ~Memory();
};

#endif // MEMORY_H
