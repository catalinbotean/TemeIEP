#ifndef METAL_HPP
#define METAL_HPP
#include <ElementChimic.hpp>

class Metal : public ElementChimic
{
private:
    int duritate;

public:
    Metal();
    Metal(int numarAtomic, int masaAtomica);
    ~Metal();
    Metal(const Metal &e) = delete;
    Metal &operator=(const Metal &e);
    void setMasaAtomica(int masa);
    void printDuritate();
};

#endif
