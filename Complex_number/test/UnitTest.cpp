/* ----------------------------------------------------------------------- */
/* ------------------------- UnitTest program ---------------------------- */
/* ----------------------------------------------------------------------- */
/* This program contains all necessary functions to test Complex_program   */
/* ----------------------------------------------------------------------- */

#include <iostream>
#include <cmath>
#include "../include/complex.hpp"

const double real1 = 5.432;
const double imagine1 = -0.91;

const double real2 = -3;
const double imagine2 = 8.43;

static int passed_test = 0, failed_test = 0;

bool is_zero(const double val);

void VERIFY(bool (*func)())
{
    if (func()) passed_test++;
    else failed_test++;
} 

//----------------------------------- init ------------------------------------------
bool init()
{
    Complex obj;
    if (!is_zero(obj.real) || !is_zero(obj.imagine))
    {
        std::cerr << "TEST init : failed" << std::endl;
        return false;
    }   
    else
    {
        std::cerr << "TEST init : passed" << std::endl;
        return true; 
    }
}

bool init_one_arg()
{
    Complex obj(real1, 0);
    if (!is_zero(obj.real - real1) || !is_zero(obj.imagine))
    {
        std::cerr << "TEST init_one_arg : failed" << std::endl;
        return false;
    }   
    else
    {
        std::cerr << "TEST init_one_arg : passed" << std::endl;
        return true; 
    } 

}

bool init_two_arg()
{
    Complex obj(real1, imagine1);
    if (!is_zero(obj.real - real1) || !is_zero(obj.imagine - imagine1))
    {
        std::cerr << "TEST init_two_arg : failed" << std::endl;
        return false;
    }   
    else
    {
        std::cerr << "TEST init_two_arg : passed" << std::endl;
        return true; 
    }    
}

bool copy_init()
{
    Complex obj1(real1, imagine1);
    Complex obj2(obj1);

    if (!is_zero(obj2.real - obj1.real) || !is_zero(obj2.imagine - obj1.imagine))
    {
        std::cerr << "TEST copy_init : failed" << std::endl;
        return false;
    }   
    else
    {
        std::cerr << "TEST copy_init : passed" << std::endl;
        return true; 
    }
}

//----------------------------------- plus ------------------------------------------
bool plus_value()
{
    Complex obj(real1, imagine1);
    Complex new_obj = obj + real2; 

    if (!is_zero(new_obj.real - (obj.real + real2)) || !is_zero(new_obj.imagine - obj.imagine))
    {
        std::cerr << "TEST plus(obj + double) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST plus(obj + double) : passed" << std::endl;
        return true; 
    }
}

bool value_plus()
{
    Complex obj(real1, imagine1);
    Complex new_obj = real2 + obj;

    if (!is_zero(new_obj.real - (real2 + obj.real)) || !is_zero(new_obj.imagine - obj.imagine))
    {
        std::cerr << "TEST plus(double + obj) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST plus(double + obj) : passed" << std::endl;
        return true; 
    }
}

bool plus_objects()
{
    Complex obj1(real1, imagine1);
    Complex obj2(real2, imagine2);
    Complex new_obj = obj1 + obj2;

    if (!is_zero(new_obj.real - (obj1.real + obj2.real)) || !is_zero(new_obj.imagine - (obj1.imagine + obj2.imagine)) )
    {
        std::cerr << "TEST plus(obj1 + obj2) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST plus(obj1 + obj2) : passed" << std::endl;
        return true; 
    }
}

//----------------------------------- minus -----------------------------------------
bool minus_value()
{
    Complex obj(real1, imagine1);
    Complex new_obj = obj - real2; 

    if (!is_zero(new_obj.real - (obj.real - real2)) || !is_zero(new_obj.imagine - obj.imagine))
    {
        std::cerr << "TEST minus(obj - double) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST minus(obj - double) : passed" << std::endl;
        return true; 
    }
}

bool value_minus()
{
    Complex obj(real1, imagine1);
    Complex new_obj = real2 - obj;

    if (!is_zero(new_obj.real - (real2 - obj.real)) || !is_zero(new_obj.imagine + obj.imagine))
    {
        std::cerr << "TEST minus(double - obj) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST minus(double - obj) : passed" << std::endl;
        return true; 
    }
}

bool minus_objects()
{
    Complex obj1(real1, imagine1);
    Complex obj2(real2, imagine2);
    Complex new_obj = obj1 - obj2;

    if (!is_zero(new_obj.real - (obj1.real - obj2.real)) || !is_zero(new_obj.imagine - (obj1.imagine - obj2.imagine)) )
    {
        std::cerr << "TEST minus(obj1 - obj2) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST minus(obj1 - obj2) : passed" << std::endl;
        return true; 
    }
}

//--------------------------------- multiply ----------------------------------------
bool multiply_value()
{
    Complex obj(real1, imagine1);
    Complex new_obj = obj * real2; 

    if (!is_zero(new_obj.real - (obj.real * real2)) || !is_zero(new_obj.imagine - (obj.imagine * real2)) )
    {
        std::cerr << "TEST multiply(obj * double) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST multiply(obj * double) : passed" << std::endl;
        return true; 
    }
}

bool value_multiply()
{
    Complex obj(real1, imagine1);
    Complex new_obj = real2 * obj; 

    if (!is_zero(new_obj.real - (real2 * obj.real)) || !is_zero(new_obj.imagine - (real2 * obj.imagine)) )
    {
        std::cerr << "TEST multiply(double * obj) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST multiply(double * obj) : passed" << std::endl;
        return true; 
    }
}

bool multiply_objects()
{
    Complex obj1(real1, imagine1);
    Complex obj2(real2, imagine2);    
    Complex new_obj = obj1 * obj2; 

    double new_real = obj1.real * obj2.real - obj1.imagine * obj2.imagine;
    double new_imagine = obj2.real * obj1.imagine + obj1.real * obj2.imagine;

    if (!is_zero(new_obj.real - new_real) || !is_zero(new_obj.imagine - new_imagine))
    {
        std::cerr << "TEST multiply(obj1 * obj2) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST multiply(obj1 * obj2) : passed" << std::endl;
        return true; 
    }
}

//---------------------------------- divide -----------------------------------------
bool divide_value()
{
    Complex obj(real1, imagine1);
    Complex new_obj = obj / real2; 

    if (!is_zero(new_obj.real - (obj.real / real2)) || !is_zero(new_obj.imagine - (obj.imagine / real2)) )
    {
        std::cerr << "TEST divide(obj / double) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST divide(obj / double) : passed" << std::endl;
        return true; 
    }
}

bool value_divide()
{
    Complex obj(real1, imagine1);
    Complex new_obj = real2 / obj; 

    double num1 = real2 * obj.real;
    double num2 = -real2 * obj.imagine;
    double denom = obj.real * obj.real + obj.imagine * obj.imagine;

    double new_real = num1 / denom;
    double new_imagine = num2 / denom;

    if (!is_zero(new_obj.real - new_real) || !is_zero(new_obj.imagine - new_imagine))
    {
        std::cerr << "TEST divide(double / obj) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST divide(double / obj) : passed" << std::endl;
        return true; 
    }
}

bool divide_objects()
{
    Complex obj1(real1, imagine1);
    Complex obj2(real2, imagine2);    
    Complex new_obj = obj1 / obj2; 

    double num1 = obj1.real * obj2.real + obj1.imagine * obj2.imagine;
    double num2 = obj1.imagine * obj2.real - obj1.real * obj2.imagine;
    double denom = obj2.real * obj2.real + obj2.imagine * obj2.imagine;

    double new_real = num1 / denom;
    double new_imagine = num2 / denom;

    if (!is_zero(new_obj.real - new_real) || !is_zero(new_obj.imagine - new_imagine))
    {
        std::cerr << "TEST divide(obj1 / obj2) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST divide(obj1 / obj2) : passed" << std::endl;
        return true; 
    }
}

//---------------------------------- assign -----------------------------------------
bool assign_value()
{
    Complex obj(real1, imagine1);
    obj = real2; 

    if (!is_zero(obj.real - real2) || !is_zero(obj.imagine))
    {
        std::cerr << "TEST assign(obj = double) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST assign(obj = double) : passed" << std::endl;
        return true; 
    }
}

bool assign_object()
{
    Complex obj(real1, imagine1);
    Complex new_obj(real2, imagine2);
    new_obj = obj; 

    if (!is_zero(new_obj.real - obj.real) || !is_zero(new_obj.imagine - obj.imagine))
    {
        std::cerr << "TEST assign(obj = obj) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST assign(obj = obj) : passed" << std::endl;
        return true; 
    }
}

//-------------------------------- plus_assign --------------------------------------
bool plus_assign_value()
{
    Complex obj(real1, imagine1);
    obj += real2; 

    if (!is_zero(obj.real - (real1 + real2)) || !is_zero(obj.imagine - imagine1))
    {
        std::cerr << "TEST plus_assign(obj += double) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST plus_assign(obj += double) : passed" << std::endl;
        return true; 
    }
}

bool plus_assign_object()
{
    Complex obj(real1, imagine1);
    Complex new_obj(real2, imagine2);
    new_obj += obj; 

    if (!is_zero(new_obj.real - (obj.real + real2)) || !is_zero(new_obj.imagine - (obj.imagine + imagine2)) )
    {
        std::cerr << "TEST plus_assign(obj1 += obj2) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST plus_assign(obj1 += obj2) : passed" << std::endl;
        return true; 
    }
}

//-------------------------------- minus_assign -------------------------------------
bool minus_assign_value()
{
    Complex obj(real1, imagine1);
    obj -= real2; 

    if (!is_zero(obj.real - (real1 - real2)) || !is_zero(obj.imagine - imagine1))
    {
        std::cerr << "TEST minus_assign(obj -= double) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST minus_assign(obj -= double) : passed" << std::endl;
        return true; 
    }
}

bool minus_assign_object()
{
    Complex obj(real1, imagine1);
    Complex new_obj(real2, imagine2);
    new_obj -= obj; 

    if (!is_zero(new_obj.real - (real2 - obj.real)) || !is_zero(new_obj.imagine - (imagine2 - obj.imagine)) )
    {
        std::cerr << "TEST minus_assign(obj1 -= obj2) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST minus_assign(obj1 -= obj2) : passed" << std::endl;
        return true; 
    }
}
//------------------------------ multiply_assign ------------------------------------
bool multiply_assign_value()
{
    Complex obj(real1, imagine1);
    obj *= real2; 

    if (!is_zero(obj.real - (real1 * real2)) || !is_zero(obj.imagine - (imagine1 * real2)))
    {
        std::cerr << "TEST multiply_assign(obj *= double) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST multiply_assign(obj *= double) : passed" << std::endl;
        return true; 
    }
}

bool multiply_assign_object()
{
    Complex obj(real1, imagine1);
    Complex new_obj(real2, imagine2);

    double new_real = new_obj.real * obj.real - new_obj.imagine * obj.imagine;
    double new_imagine = obj.real * new_obj.imagine + new_obj.real * obj.imagine;
   
    new_obj *= obj;

    if (!is_zero(new_obj.real - new_real) || !is_zero(new_obj.imagine - new_imagine))
    {
        std::cerr << "TEST multiply_assign(obj1 *= obj2) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST multiply_assign(obj1 *= obj2) : passed" << std::endl;
        return true; 
    }
}
//------------------------------- divide_assign -------------------------------------
bool divide_assign_value()
{
    Complex obj(real1, imagine1);
    Complex new_obj = obj / real2; 

    if (!is_zero(new_obj.real - (obj.real / real2)) || !is_zero(new_obj.imagine - (obj.imagine / real2)) )
    {
        std::cerr << "TEST divide_assign(obj /= double) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST divide_assign(obj /= double) : passed" << std::endl;
        return true; 
    }
}

bool divide_assign_object()
{
    Complex obj(real1, imagine1);
    Complex new_obj(real2, imagine2); 
       
    double num1 = obj.real * new_obj.real + new_obj.imagine * obj.imagine;
    double num2 = new_obj.imagine * obj.real - new_obj.real * obj.imagine;
    double denom = obj.real * obj.real + obj.imagine * obj.imagine;
    double new_real = num1 / denom;
    double new_imagine = num2 / denom;
    
    new_obj /= obj; 

    if (!is_zero(new_obj.real - new_real) || !is_zero(new_obj.imagine - new_imagine))
    {
        std::cerr << "TEST divide_assign(obj1 /= obj2) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST divide_assign(obj1 /= obj2) : passed" << std::endl;
        return true; 
    }
}

//----------------------------------- equal -----------------------------------------
bool equal_object_value()
{
    Complex obj(real1, 0);
    double new_real = real1;  

    if (!(obj.real == new_real) || !(obj.imagine == 0))
    {
        std::cerr << "TEST equal(obj == double) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST equal(obj == double) : passed" << std::endl;
        return true; 
    }
}

bool equal_value_object()
{
    Complex obj(real2, 0);
    double new_real = real2; 

    if (!(new_real == obj.real) || !(0 == obj.imagine))
    {
        std::cerr << "TEST equal(double == obj) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST equal(double == obj) : passed" << std::endl;
        return true; 
    }
}

bool equal_objects()
{
    Complex obj(real1, imagine1);
    Complex new_obj(real2, imagine2); 
    new_obj = obj;

    if (!(new_obj.real == obj.real) || !(new_obj.imagine == obj.imagine))
    {
        std::cerr << "TEST equal(obj == obj) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST equal(obj == obj) : passed" << std::endl;
        return true; 
    }
}

//--------------------------------- not equal ---------------------------------------
bool not_equal_object_value()
{
    Complex obj(real1, 0);
    double new_real = real1;  

    if ((obj.real != new_real) || (obj.imagine != 0))
    {
        std::cerr << "TEST not_equal(obj != double) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST not_equal(obj != double) : passed" << std::endl;
        return true; 
    }
}

bool not_equal_value_object()
{
    Complex obj(real2, 0);
    double new_real = real2;  

    if ((new_real != obj.real) || (0 != obj.imagine))
    {
        std::cerr << "TEST not_equal(double != obj) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST not_equal(double != obj) : passed" << std::endl;
        return true; 
    }
}

bool not_equal_objects()
{
    Complex obj(real1, imagine1);
    Complex new_obj(real2, imagine2);
    new_obj = obj;

    if ((new_obj.real != obj.real) || (new_obj.imagine != obj.imagine))
    {
        std::cerr << "TEST not_equal(obj != obj) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST not_equal(obj != obj) : passed" << std::endl;
        return true; 
    }
}

//------------------------------ other_functions ------------------------------------
bool unary_minus()
{
    Complex obj(real1, imagine1);
    Complex new_obj = -obj;

    if (!is_zero(new_obj.real + obj.real) || !is_zero(new_obj.imagine + obj.imagine))
    {
        std::cerr << "TEST unary_minus(obj1 = -obj2) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST unary_minus(obj1 = -obj2) : passed" << std::endl;
        return true; 
    }
}

bool unary_plus()
{
    Complex obj(real1, imagine1);
    Complex new_obj = +obj;

    if (!is_zero(new_obj.real - obj.real) || !is_zero(new_obj.imagine - obj.imagine))
    {
        std::cerr << "TEST unary_plus(obj1 = +obj2) : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST unary_plus(obj1 = +obj2) : passed" << std::endl;
        return true; 
    }
}

bool module()
{
    Complex obj(real1, imagine1);
    double module = std::sqrt(obj.real * obj.real + obj.imagine * obj.imagine); 

    if (!is_zero(obj.Module() - module))
    {
        std::cerr << "TEST module : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST module : passed" << std::endl;
        return true; 
    }
}

bool argument()
{
    Complex obj(real1, imagine1);
    double arg = std::atan(obj.imagine / obj.real);

    if (!is_zero(obj.Argument() - arg))
    {
        std::cerr << "TEST argumet : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST argument : passed" << std::endl;
        return true; 
    }
}

bool pairing()
{
    Complex obj(real1, imagine1);

    if (!is_zero(obj.Pairing().real - obj.real) || !is_zero(obj.Pairing().imagine + obj.imagine))
    {
        std::cerr << "TEST pairing : failed" << std::endl;
        return false; 
    }
    else 
    {
        std::cerr << "TEST pairing : passed" << std::endl;
        return true; 
    }
}

int main ()
{
    VERIFY(&init);
    VERIFY(&init_one_arg);
    VERIFY(&init_two_arg);
    VERIFY(&copy_init);

    VERIFY(&plus_value);
    VERIFY(&value_plus);
    VERIFY(&plus_objects);

    VERIFY(&minus_value);
    VERIFY(&value_minus);
    VERIFY(&minus_objects);

    VERIFY(&multiply_value);
    VERIFY(&value_multiply);
    VERIFY(&multiply_objects);

    VERIFY(&divide_value);
    VERIFY(&value_divide);
    VERIFY(&divide_objects);

    VERIFY(&assign_value);
    VERIFY(&assign_object);

    VERIFY(&plus_assign_value);
    VERIFY(&plus_assign_object);

    VERIFY(&minus_assign_value);
    VERIFY(&minus_assign_object);

    VERIFY(&multiply_assign_value);
    VERIFY(&multiply_assign_object);

    VERIFY(&divide_assign_value);
    VERIFY(&divide_assign_object);

    VERIFY(&equal_object_value);
    VERIFY(&equal_value_object);
    VERIFY(&equal_objects);

    VERIFY(&not_equal_object_value);
    VERIFY(&not_equal_value_object);
    VERIFY(&not_equal_objects);

    VERIFY(&unary_minus);

    VERIFY(&unary_plus);

    VERIFY(&module);

    VERIFY(&argument);

    VERIFY(&pairing);

    std::cout << "Count passed tests = " << passed_test << std::endl;
    std::cout << "Count failed tests = " << failed_test << std::endl;
    
    return 0;
}