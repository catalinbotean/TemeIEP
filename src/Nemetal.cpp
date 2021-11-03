#include <iostream>
#include <Nemetal.hpp>

Nemetal::Nemetal() : ElementChimic(8, 16, "O")
{
}

Nemetal::~Nemetal()
{
    std::cout << "Nemetal sters" << std::endl;
}