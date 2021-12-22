#include <iostream>
#include <ElementChimic.hpp>
#include <Metal.hpp>
#include <Nemetal.hpp>
#include <memory>
using namespace std;

ElementChimic* factoryMethod(){
    return (new ElementChimic);
}

//ITEM14
class Eprubeta{
    private:
        int lungime = 100;
        bool plin = false;
    
    public:
    Eprubeta(){
        std::cout<<"CONSTRUCTOR1"<<std::endl;
    }

    Eprubeta(int lungime){
        std::cout<<"CONSTRUCTOR2"<<std::endl;
        this->lungime = lungime;
    }

    Eprubeta(const Eprubeta &e){
        std::cout<<"COPY CONSTRUCTOR"<<std::endl;
        this->lungime = e.lungime;
        this->plin = e.plin;
    }

    ~Eprubeta(){
        std::cout<<"DESTRUCTOR"<<std::endl;
    }

    int getDimensiune(){
        return this->lungime;
    }

    bool getPlin(){
        return this->plin;
    }

    void setPlin(bool plin){
        this->plin = plin;
    }

    void toarnaSubstanta(ElementChimic e){
        if(this->plin == false) 
            std::cout<<"Vom turna elementul chimic "<<e.getNume()<<" in eprubeta"<<std::endl;
        else
            std::cout<<"Eprubeta trebuie curatata"<<std::endl;
    }
};

void lock(Eprubeta &e){
    std::cout<<"Am luat o eprubeta"<<std::endl;
    e.setPlin(true);
}

void unlock(Eprubeta &e){
    std::cout<<"Am curatat o eprubeta"<<std::endl;
    e.setPlin(false);
}

class Chimist{
    private:
        Eprubeta &eprubeta;
    public:
    Chimist(Eprubeta &e):
    eprubeta(e){
        lock(eprubeta);
    }
    ~Chimist(){
        unlock(eprubeta);
    }
};

int main()
{
    // ElementChimic el;
    // Metal m;
    // Nemetal n;

    // ElementChimic el2(12, 24, "Mg");

    // {
    //     ElementChimic el3;
    // }

    // ElementChimic e3 = el;
    // ElementChimic e4(el);

    // el2 = e3;

    // std::cout << m.getMasaAtomica() << m.getNume() << std::endl;
    // el.setMasaAtomica(12);
    // std::cout << el.getMasaAtomica();
    // m.setMasaAtomica(13);
    // std::cout << m.getMasaAtomica();
    // std::cout << el2.getNume() << el2.getNumarNeutroni();

    // //Metal m2 = m; Compile Error

    // // Metal m2; Runtime Error
    // // m2 = m;

    // //ITEM 10
    // ElementChimic e1(8, 16, "O");
    // ElementChimic e2(11, 23, "Na");
    // ElementChimic e3(1, 1, "H");
    // e3 *= e2 += e1;
    // e3.getNumarAtomic();
    // e3.getMasaAtomica();

    // //ITEM 11
    // ElementChimic el1 = e2;
    // el1 = el1;
    // e1 = e2;

    // //ITEM 12
    // Metal m1(1, 2);
    // Metal m2(10, 40);
    // m1.printDuritate();
    // m1.getNumarAtomic();
    // m1 = m2;
    // m1.printDuritate();
    // m1.getNumarAtomic();


    //ITEM 13
    {
        auto_ptr<ElementChimic> hidrogen1(factoryMethod());
        hidrogen1->getNumarAtomic();
        auto_ptr<ElementChimic> hidrogen2(hidrogen1);
        hidrogen2->getNumarAtomic();
        //hidrogen1->getNumarAtomic();  //SEGMENTATION FAULT
    }

    {
        unique_ptr<ElementChimic> hidrogen1(factoryMethod());
        hidrogen1->getNumarAtomic();
        //unique_ptr<ElementChimic> hidrogen2(hidrogen1);
        unique_ptr<ElementChimic> hidrogen2 = move(hidrogen1);
        hidrogen2->getNumarAtomic(); 
    }

    {
        shared_ptr<ElementChimic> hidrogen1(factoryMethod());
        hidrogen1->getNumarAtomic();
        std::cout<<"Hidrogen1 "<<hidrogen1.use_count()<<std::endl;
        shared_ptr<ElementChimic> hidrogen2(hidrogen1);
        hidrogen2->getNumarAtomic(); 
        std::cout<<"Hidrogen1 "<<hidrogen1.use_count()<<std::endl;
        shared_ptr<ElementChimic> hidrogen3 = move(hidrogen1);
        std::cout<<"Hidrogen1 "<<hidrogen1.use_count()<<std::endl;
        std::cout<<"Hidrogen3 "<<hidrogen3.use_count()<<std::endl;
        //hidrogen1->getNumarAtomic();   //SEGMENTATION FAULT
    }


    //ITEM 14
    Eprubeta e(200);
    ElementChimic el(12, 24, "Mg");
    Chimist *chimist = new Chimist(e);
    e.toarnaSubstanta(el);
    delete chimist;
    e.toarnaSubstanta(el);
    lock(e);
    e.toarnaSubstanta(el);
    unlock(e);
    e.toarnaSubstanta(el);
    return 0;
}