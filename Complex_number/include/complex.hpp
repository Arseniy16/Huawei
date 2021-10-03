#ifndef _Complex_HPP_
#define _Complex_HPP_

const double ACCURACY = 1e-6;

struct Complex
{
    double real;
    double imagine;

    Complex()
    {
        real = 0;
        imagine = 0;
    }

    Complex(double x, double y = 0)
    {
        real = x;
        imagine = y;
    }

    Complex(const Complex& another)
    {
        real = another.real;
        imagine = another.imagine;
    }

    ~Complex() 
    {
        if (real == 0xBAD0BAD)
            std::cerr << "TEST destructor : passed\n";
        
        real = 0;
        imagine = 0;
    }
    
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

    void Print () const;

};

Complex operator+ (const double num, Complex &val);
Complex operator- (const double num, Complex &val);
Complex operator* (const double num, Complex &val);
Complex operator/ (const double num, Complex &val);

bool operator== (const double num, const Complex &val);
bool operator!= (const double num, const Complex &val);

bool is_zero (const double x);

std::ostream & operator<<(std::ostream &out, const Complex &value);

#endif // _Complex_HPP_ 