#include <iostream>
#include <ElementChimic.hpp>

ElementChimic::ElementChimic() : masaAtomica(1),
                                 numarAtomic(1),
                                 nume("H")
{
}

ElementChimic::ElementChimic(int masa, int numar, std::string simbol) : masaAtomica(masa),
                                                                        numarAtomic(numar),
                                                                        nume(simbol)
{
}

ElementChimic::ElementChimic(const ElementChimic &e)
{
    std::cout << "Copy Constructor" << std::endl;
    this->masaAtomica = e.masaAtomica;
    this->numarAtomic = e.numarAtomic;
    this->nume = e.nume;
}

ElementChimic &ElementChimic::operator=(const ElementChimic &e)
{
    std::cout << "Copy Assignment Operator" << std::endl;
    this->masaAtomica = e.masaAtomica;
    this->numarAtomic = e.numarAtomic;
    this->nume = e.nume;
    return *this;
}

ElementChimic::~ElementChimic()
{
    std::cout << "Element Chimic sters" << std::endl;
}

void ElementChimic::setMasaAtomica(int masa)
{
    masaAtomica = masa;
}

int ElementChimic::getMasaAtomica()
{
    return masaAtomica;
}

void ElementChimic::setNumarAtomic(int numar)
{
    numarAtomic = numar;
}

int ElementChimic::getNumarAtomic()
{
    return numarAtomic;
}

void ElementChimic::setNume(std::string simbol)
{
    nume = simbol;
}

std::string ElementChimic::getNume()
{
    return nume;
}

int ElementChimic::getNumarProtoni()
{
    return numarAtomic;
}

int ElementChimic::getNumarElectroni()
{
    return numarAtomic;
}

int ElementChimic::getNumarNeutroni()
{
    return masaAtomica - numarAtomic;
}