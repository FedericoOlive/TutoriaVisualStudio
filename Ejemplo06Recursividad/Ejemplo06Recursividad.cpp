// Explicación:
//#define Explicacion
#include <ctime>
#include <iostream>

#ifdef Explicacion
void imprimirDescendente(int number)
{
    if (number > 0)
    {
        std::cout << number << " ";
        imprimirDescendente(number - 1);
    }
}

void main()
{
    srand(time(NULL));
    int number = 3;

    imprimirDescendente(number);
    std::cout << "\n\n";
}

#else

void Factorial(int number, int& value)
{
    if (number > 0)
    {
        value *= (number);
        std::cout << number << " ";
        Factorial(number - 1, value);
    }
}

void main()
{
    srand(time(NULL));
    int number = 5;
    int value = 1;

    Factorial(number, value);

    std::cout << "Result: " << value << "\n\n";
}

// Factoriales!
#endif