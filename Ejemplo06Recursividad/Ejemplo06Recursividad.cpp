// Explicación:
//#define Explicacion
#include <ctime>
#include <iostream>

#ifdef Explicacion
void ImprimirDescendente(int number)
{
    if (number > 0)
    {
        std::cout << number << " ";
        ImprimirDescendente(number - 1);
    }
}

void main()
{
    srand(time(nullptr));
    int number = 3;

    ImprimirDescendente(number);
    std::cout << "\n\n";
}

#else

void Factorial(int number, int& result)
{
    if (number > 0)
    {
        result *= (number);
        std::cout << number << " ";
        Factorial(number - 1, result);
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