#include <iostream>

template<typename D>
class B{
public:
    B() = default;

    void Func() { static_cast<D*>(this)->Func(); }
    int Get() const { return m_i; }

    int m_i = 0;
    
};

class D : public B<D>{
public:
    void Func() { m_i += 1; }
};

template<typename D>
void apply_ptr(B<D>* p){
    p->Func();
    std::cout<<p->Get()<<std::endl;
}

template<typename D>
void apply_ref(B<D>& ref){
    ref.Func();
    std::cout<<ref.Get()<<std::endl;
}

template<typename D>
void apply_val(B<D> val){
    val.Func();
    std::cout<<val.Get()<<std::endl;
}

int main(){

    D base;
    B<D>* base_ptr = &base;

    // apply by passing ptr
    apply_ptr(base_ptr);

    // apply by passing ref
    apply_ref(base);

    // apply by passing val
    apply_val(base);    
    
    return 0;
}