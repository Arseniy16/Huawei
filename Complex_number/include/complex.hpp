#ifndef _INCLUDE_COMPLEX_HPP_
#define _INCLUDE_COMPLEX_HPP_

const double ACCURACY = 1e-6;

struct Complex
{
    double real;
    double imagine;

    Complex();
    
    Complex(double x, double y = 0);

    Complex(const Complex &another);

    ~Complex();
    
    Complex operator+ (const Complex &val) const;
    Complex operator- (const Complex &val) const;
    Complex operator* (const Complex &val) const;
    Complex operator/ (const Complex &val) const;

    Complex operator+ (const double num) const;
    Complex operator- (const double num) const;
    Complex operator* (const double num) const;
    Complex operator/ (const double num) const;

    Complex & operator = (const Complex &val);
    Complex & operator+= (const Complex &val);
    Complex & operator-= (const Complex &val);
    Complex & operator*= (const Complex &val);
    Complex & operator/= (const Complex &val);

    bool operator== (const Complex &val) const;
    bool operator!= (const Complex &val) const;

    bool operator== (const double num) const;
    bool operator!= (const double num) const;

    Complex operator- () const;
    Complex operator+ () const;
    
    Complex & operator = (const double num);
    Complex & operator+= (const double num);
    Complex & operator-= (const double num);
    Complex & operator*= (const double num);
    Complex & operator/= (const double num);

    double Module() const;

    double Argument() const;

    Complex Pairing() const;
};

Complex operator+ (const double num, const Complex &val);
Complex operator- (const double num, const Complex &val);
Complex operator* (const double num, const Complex &val);
Complex operator/ (const double num, const Complex &val);

bool operator== (const double num, const Complex &val);
bool operator!= (const double num, const Complex &val);

bool is_zero (const double x);

std::ostream & operator<<(std::ostream &out, const Complex &value);

#endif // _INCLUDE_COMPLEX_HPP_ 