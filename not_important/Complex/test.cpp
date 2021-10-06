#include <iostream>
// using namespace std;

template <class T>
class Repository
{
private:
    T m_value;
public:
    Repository(T value)
    {
         m_value = value;
    }
 
    ~Repository()
    {
    }
 
    void print(Repository<T> &value)
    {
        std::cout << value.m_value << '\n';
    }
};

int main()
{
    // Инициализируем объекты класса
    Repository<int> nValue(7);
    Repository<int> nSec(9);
    Repository<double> dValue(8.4);
 
    // Выводим значения объектов класса
    nValue.print(nSec);
    //nValue.print();
    //dValue.print();

    return 0;
}