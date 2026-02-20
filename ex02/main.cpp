#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <exception>


Base *generate(void)
{
    int n = std::rand() % 3;
    if (n == 0)
        return new(A);
    else if (n == 1)
        return new(B);
    else
        return new(C);
}

void identify(Base *p)
{
    try
    {
        if (dynamic_cast<A*>(p))
            std::cout << "A" << std::endl;
        else if (dynamic_cast<B*>(p))
            std::cout << "B" << std::endl;
        else if (dynamic_cast<C*>(p))
            std::cout << "C" << std::endl;
        else
            std::cout << "Unknown" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void identify(Base &p)
{
    try
    {
        if (dynamic_cast<A*>(&p))
            std::cout << "A" << std::endl;
        else if (dynamic_cast<B*>(&p))
            std::cout << "B" << std::endl;
        else if (dynamic_cast<C*>(&p))
            std::cout << "C" << std::endl;
        else
            std::cout << "Unknown" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main(void)
{
	Base *b1 = new A;
	Base *b2 = new B;
	Base *b3 = new C;
	
	identify(b1);
	identify(*b1);
	
	identify(b2);
	identify(*b2);
	
	identify(b3);
	identify(*b3);
    
	delete b1;
	delete b2;
	delete b3;
	return (0);
}
