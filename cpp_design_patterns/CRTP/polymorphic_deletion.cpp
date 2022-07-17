#include <iostream>

template<typename D>
class B{
public:
    ~B(){
        std::cout<< "delete type BE\n";
    }
};

template<typename D>
void Destroy(B<D>* p){
    delete static_cast<D*>(p);
}

class D : public B<D>{
public:
    ~D(){
        std::cout<< "delete type DE\n";
    }
};

int main(){

    // delete with correct destructor
    B<D>* b = new D; 
    Destroy(b);

    return 0;
}