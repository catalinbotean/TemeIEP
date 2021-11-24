#include <iostream>
#include <Metal.hpp>

Metal::Metal() : ElementChimic(13, 27, "Al"), duritate(3)
{
}

Metal::Metal(int numarAtomic, int masaAtomica) : ElementChimic(numarAtomic, masaAtomica, "Al"), duritate(3)
{
}

Metal::~Metal()
{
    std::cout << "Metal sters" << std::endl;
}

void Metal::setMasaAtomica(int masa)
{
    std::cout << "S-a apelat metoda din subclasa Metal: " << masa;
}

Metal &Metal::operator=(const Metal &e)
{
    if (this == &e)
    {
        std::cout << "Same object" << std::endl;
        return *this;
    }
    std::cout << "Copy Assignment Operator" << std::endl;
    ElementChimic::operator=(e);
    this->duritate = e.duritate * 3;
    return *this;
}

void Metal::printDuritate()
{
    std::cout << this->duritate << std::endl;
}