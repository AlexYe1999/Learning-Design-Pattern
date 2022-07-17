
#include <iostream>

// Expand interface
template<typename D>
struct NotEqual{
    friend bool operator != (D const& lhs, D const& rhs) {
        return !(lhs == rhs); 
    }
};

class C final : public NotEqual<C>{
public:
    C(int i = 0) : m_i(i){}

    friend bool operator == (C const& lhs, C const& rhs) {
        return lhs.m_i == rhs.m_i; 
    }

private:    
    int m_i;
};

// Make base class aware of derived class
template<typename D>
class Register{
public:
    Register(){
        count++;
    }

    ~Register(){
        count--;
    }

    static int GetInstanceNum() { return count; } 

private:
    inline static int count = 0;
};

class A : public Register<A>{
public:
    A(){
        std::cout<< "Construct A \n";
    }
    ~A(){
        std::cout<< "Destruct  A \n";  
    }
};

class B : public Register<B>{
public:
    B(){
        std::cout<< "Construct B \n";
    }
    ~B(){
        std::cout<< "Destruct  B \n";  
    }
};

int main(){

    // Expand interface
    C c1(0), c2(1);
    std::cout << "0 " << (c1 != c2 ? "not equal" : "equal") << " \n";

    // Make base class aware of derived class   
    A* a1 = new A;
    std::cout << "A : " << A::GetInstanceNum() << std::endl;

    A* a2 = new A;
    std::cout << "A : " << A::GetInstanceNum() << std::endl;

    delete a1;
    delete a2;

    B* b1 = new B;
    std::cout << "A : " << A::GetInstanceNum() << std::endl;
    std::cout << "B : " << B::GetInstanceNum() << std::endl;

    return 0;
}