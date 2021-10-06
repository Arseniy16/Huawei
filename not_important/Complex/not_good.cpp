/**
 * TODO:
 * -Complex()
 * -~Complex()
 * -IsEqual()
 * -Operator()
 *      +, -, *, /
 * -Exponentiation of a number
 * -Input()
 * -Output()
 * -Module()
 * -Degree()
 */

#include <iostream>
#include <сmath>

using namespace std; 

template <typename Type>
class Complex
{
private:
    Type real;
    Type imagine;

public:
    //Complex() { real = 0, imagine = 0; }

    // need int and double
    Complex();

    Complex(Type x = 0, Type y = 0) : real{x}, imagine{y} {} // { real = x, imagine = y; }

    Complex(const Complex & another)
    {
        real = another.real;
        imagine = another.imagine;
    }

    ~Complex();

    //~Complex();

    Type GetReal () const { return real; }

    Type GetImagine () const { return imagine; }

    //void Input(Type x, Type y);
    /*
    void Print() 
    {
        std::cout << "real = " << real << ", imagine = " << imagine << std::endl;
    }
    */
    
    Complex<Type> operator+(const Complex<Type> &value);

    Complex<Type> operator-(const Complex<Type> &value);

    Complex<Type> operator*(const Complex<Type> &value);

    Complex<Type> operator/(const Complex<Type> &value);

    bool IsEqual(const Complex &x, const Complex &y);

    double Module();

    double Radians();

};


template<typename Type>
Complex<Type> operator+(const Complex<Type> &x, const Complex<Type> &y)
{
    Type real = x.GetReal() + y.GetReal();

    Type imagine = x.GetImagine() + y.GetImagine();

    return Complex<Type>(real, imagine);
}

template<typename Type>
Complex<Type> operator-(const Complex<Type> &x, const Complex<Type> &y)
{
    Type real = x.GetReal() - y.GetReal();

    Type imagine = x.GetImagine() - y.GetImagine();

    return Complex<Type>(real, imagine);
}

template<typename Type>
Complex<Type> operator*(const Complex<Type> &x, const Complex<Type> &y)
{
    Type real = x.GetReal() * y.GetReal() - x.GetImagine() * y.GetImagine();

    Type imagine = y.GetReal() * x.GetImagine() + x.GetReal() * y.GetImagine();

    return Complex<Type>(real, imagine);
}

template<typename Type>
Complex<Type> operator/(const Complex<Type> &x, const Complex<Type> &y)
{
    Type num1 = x.GetReal()* y.GetReal() + x.GetImagine() * y.GetImagine();

    Type denom = y.GetReal() * y.GetReal() + y.GetImagine() * y.GetImagine();

    double real = num1 / denom ;

    Type num2 = x.GetImagine() * y.GetReal() - x.GetReal() * y.GetImagine();

    double imagine = num2 / denom ;

    return Complex<Type>(real, imagine);
}

template<typename Type>
std::ostream& operator<<(std::ostream &out, const Complex<Type> &value)
{
    out << "real = " << value.GetReal() << ", imagine = " << value.GetImagine() << "\n";
 
    return out;
}

//------------------------------------------------------------------
template<typename Type>
Complex<Type> operator+=(const Complex<Type> &x, const Complex<Type> &y)
{
    Type x. = x.GetReal() + y.GetReal();

    Type imagine = x.GetImagine() + y.GetImagine();

    return Complex<Type>(real, imagine);
}





/*
template<typename Type>
bool IsEqual(const Complex<Type> &x, const Complex<Type> &y)
{
    if ( x.real == y.real && x.imagine == y.imagine)
        return true;
    else
        return false;
}
/*
    if ( ( x.GetReal() == y.GetReal() ) && ( x.GetImagine() == y.GetImagine() ))
        return true;
    else 
        return false;
*/


template<typename Type>
double Complex<Type>::Module()
{
    // verify to cast <double>
    double module = sqrt(real * real + imagine * imagine);
    //double module = sqrt(GetReal() * GetReal() + GetImagine() * GetImagine());
    return module;
}

template<typename Type>
double Complex<Type>::Radians()
{
    double radians = 0;

    if (real == 0)
    {
        if (imagine > 0) radians = M_PI / 2;
        else radians = -M_PI / 2 ;
    }
    else if (real > 0)
        radians = atan(imagine / real);
    else
        radians = atan(imagine / real) + M_PI;

    return radians;
}

int main()
{
    Complex<int> num(3, 1);
    Complex<int> first(2, 3);
    Complex<double> second(3.1, 2.0);
    Complex<double> third(2.9, 1.0);
    
    //Complex<int> one = first / num;
    Complex<int> two = first - num;
    cout << "two: " << two;

    Complex<double> value1 = second / third;
    //Complex<double> two = first - num;

    //cout << "One = " << one.Module() << endl;
    
    cout << "two = " << two.Module() << endl;
    cout << "value1 = " << value1.Module() << endl;

    cout << "Module_first = " << first.Module() << ", Module_second = "<< second.Module() << endl;
    cout << "Radians_first = " << first.Radians() << ", Radians_second = "<< second.Radians() << endl;
    // /cout << "IsEqual = " << IsEqual(first, second); 
    return 0;

}