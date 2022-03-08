#include <iostream>

class Foo
{
public:
    Foo();
    void SetName(std::string name);
    std::string GetName();
    void IncreaseId();

private:
    std::string name_;
    int id_;
};

Foo::Foo()
{
    name_ = "";
    id_ = 0;
}

void Foo::SetName(std::string name)
{
    name_ = name;
}

std::string Foo::GetName()
{
    return name_;
}

void Foo::IncreaseId()
{
    id_++;
}