/* -------------------------------------------------------------------------- */
/* ---------------------------- Complex program ----------------------------- */
/* -------------------------------------------------------------------------- */
/* This program contains all necessary functions and methods of class Complex */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <cmath>
#include "../include/complex.hpp"

Complex::Complex() : real{0}, imagine{0} {}

Complex::Complex(double x, double y) : real{x}, imagine{y} {}

Complex::Complex(const Complex& obj) : real{obj.real}, imagine{obj.imagine} {}

Complex::~Complex() {} 

Complex Complex::operator+ (const Complex &val) const
{
    return Complex(real + val.real, imagine + val.imagine);
}

Complex Complex::operator- (const Complex &val) const
{
    return Complex(real - val.real, imagine - val.imagine);
}

Complex Complex::operator* (const Complex &val) const
{
    double new_real = real * val.real - imagine * val.imagine;
    double new_imagine = val.real * imagine + real * val.imagine;
    return Complex(new_real, new_imagine);
}

Complex Complex::operator/ (const Complex &val) const
{   
    double num1 = real * val.real + imagine * val.imagine;
    double num2 = imagine * val.real - real * val.imagine;
    double denom = val.real * val.real + val.imagine * val.imagine;

    double new_real = num1 / denom;
    double new_imagine = num2 / denom;
    
    return Complex(new_real, new_imagine);
}

Complex Complex::operator+ (const double num) const
{
    return Complex(real + num, imagine);
}

Complex Complex::operator- (const double num) const
{
    return Complex(real - num, imagine);
}

Complex Complex::operator* (const double num) const
{
    return Complex(real * num, imagine * num);
}

Complex Complex::operator/ (const double num) const
{   
    return Complex(real / num, imagine / num);
}

Complex & Complex::operator= (const Complex &val)
{
    real = val.real;
    imagine = val.imagine;
    return *this;
}

Complex & Complex::operator+= (const Complex &val)
{
    real += val.real;
    imagine += val.imagine;
    return *this;
}

Complex & Complex::operator-= (const Complex &val)
{
    real -= val.real;
    imagine -= val.imagine;
    return *this;
}

Complex & Complex::operator*= (const Complex &val)
{

    double new_real = real * val.real - imagine * val.imagine;
    double new_imagine = imagine * val.real + real * val.imagine;
    real = new_real;
    imagine = new_imagine;
    return *this;
}

Complex & Complex::operator/= (const Complex &val)
{
    double num1 = real * val.real + imagine * val.imagine;
    double num2 = imagine * val.real - real * val.imagine;
    double denom = val.real * val.real + val.imagine * val.imagine;

    real = num1 / denom;
    imagine = num2 / denom;
    return *this;
}

bool Complex::operator== (const Complex &val) const
{
    if (is_zero(real - val.real) && is_zero(imagine - val.imagine))
        return true;
    return false;
}

bool Complex::operator!= (const Complex &val) const
{
    if (!is_zero(real - val.real) || !is_zero(imagine - val.imagine))
        return true;
    return false;
}

bool Complex::operator== (const double num) const
{
    if (is_zero(real - num) && is_zero(imagine))
        return true; 
    return false;
}

bool Complex::operator!= (const double num) const
{
    if (!is_zero(real - num) || !is_zero(imagine))
        return true; 
    return false;
}

Complex Complex::operator- () const
{
    return Complex(-real, -imagine);
}

Complex Complex::operator+ () const
{
    return Complex(real, imagine);
}

Complex & Complex::operator= (const double num)
{
    real = num;
    imagine = 0;
    return *this;
}

Complex & Complex::operator+= (const double num)
{
    real += num;
    return *this;
}

Complex & Complex::operator-= (const double num)
{
    real -= num;
    return *this;
}

Complex & Complex::operator*= (const double num)
{
    real *= num;
    imagine *= num;
    return *this;
}

Complex & Complex::operator/= (const double num)
{
    real /= num;
    imagine /= num;
    return *this;
}

double Complex::Module() const
{
    return std::sqrt(real * real + imagine * imagine); 
}

double Complex::Argument() const
{
    return std::atan(imagine / real);
}

Complex Complex::Pairing() const
{
    return Complex(real, -imagine);
}

//-------------------------------- functions ----------------------------------------
//-----------------------------------------------------------------------------------
Complex operator+ (const double num, const Complex &val)
{
    return Complex(num + val.real, val.imagine);
}

Complex operator- (const double num, const Complex &val)
{
    return Complex(num - val.real, -val.imagine);
}

Complex operator* (const double num, const Complex &val)
{
    return Complex(num * val.real, num * val.imagine);
}

Complex operator/ (const double num, const Complex &val)
{
    double num1 = num * val.real;
    double num2 = -num * val.imagine;
    double denom = val.real * val.real + val.imagine * val.imagine;

    double new_real = num1 / denom;
    double new_imagine = num2 / denom;

    return Complex(new_real, new_imagine);
}

bool operator== (const double num, const Complex &val)
{
    if (is_zero(num - val.real) && is_zero(val.imagine))
        return true; 
    return false;
}

bool operator!= (const double num, const Complex &val)
{
    if (!is_zero(num - val.real) || !is_zero(val.imagine))
        return true; 
    return false;
}

std::ostream & operator<<(std::ostream &out, const Complex &value)
{
    if (is_zero(value.imagine))
        out << value.real;
    else
    {
        char sign = '+';
        if (value.imagine < 0) sign = '-';

        if (is_zero(value.real))
            out << sign << " i " << fabs(value.imagine);
        else
            out << value.real << " " << sign << " i " << fabs(value.imagine);
    }

    return out;
}

bool is_zero (const double val)
{
    return (fabs(val) < ACCURACY); 
}
