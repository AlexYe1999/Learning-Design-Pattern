
#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Visitor is a design pattern that
// Let you separate algorithms from the object which they operate
class Element; 
class Visitor{
public:
    virtual void Visit(Element const* const element) const{
        std::cout<< "Visitor Base visit \n";
    }
};

class Element{
public:
    Element(std::string const& content) 
        : m_content(content)
    {}
    void Accept(Visitor* visitor){
        visitor->Visit(this);
    }
    std::string m_content;
};

class VisitorA : public Visitor{
public:
    virtual void Visit(Element const* const element) const override{
        std::cout<< "Visitor A visit " << element->m_content <<std::endl;
    }
};

class VisitorB : public Visitor{
public:
    virtual void Visit(Element const* const element) const override{
        std::cout<< "Visitor B visit " << element->m_content <<std::endl;
    }
};

class ElementA : public Element{
public:
    ElementA(std::string const& content) 
        : Element(content)
    {}
};

class ElementB : public Element{
public:
    ElementB(std::string const& content) 
        : Element(content)
    {}
};

class ElementC : public Element{
public:
    ElementC(std::string const& content) 
        : Element(content)
    {}
};

int main(){

    std::vector<std::unique_ptr<Element>> elements;
    std::vector<std::unique_ptr<Visitor>> visitors;

    elements.push_back(std::make_unique<Element>("Base"));
    elements.push_back(std::make_unique<ElementA>("A"));
    elements.push_back(std::make_unique<ElementB>("B"));
    elements.push_back(std::make_unique<ElementC>("C"));

    visitors.push_back(std::make_unique<VisitorA>());
    visitors.push_back(std::make_unique<VisitorB>());

    for(auto const& element : elements){
        for(auto const& visitor : visitors){
            element->Accept(visitor.get());
        }
    }

    return 0;
}