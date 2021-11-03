#ifndef METAL_HPP
#define METAL_HPP
#include <ElementChimic.hpp>

class Metal : public ElementChimic
{

public:
    Metal();
    ~Metal();
    Metal(const Metal &e) = delete;
    Metal &operator=(const Metal &e);
    void setMasaAtomica(int masa);
};

#endif
