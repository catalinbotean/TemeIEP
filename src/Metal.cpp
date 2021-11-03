#include <iostream>
#include <Metal.hpp>

Metal::Metal() : ElementChimic(13, 27, "Al")
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