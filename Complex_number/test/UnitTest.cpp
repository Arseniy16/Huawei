/* ----------------------------------------------------------------------- */
/* ------------------------- UnitTest program ---------------------------- */
/* ----------------------------------------------------------------------- */
/* This program contains all nessecary functions to test Complex_program   */
/* ----------------------------------------------------------------------- */

#include <iostream>
#include <cmath>
#include "../include/complex.hpp"

//------------------------------------------------
//--------------- const variables ----------------
//------------------------------------------------
const double real1 = 5.432;
const double imagine1 = -0.91;

const double real2 = -3;
const double imagine2 = 8.43;
//------------------------------------------------

//----------------------------------- init ------------------------------------------
//-----------------------------------------------------------------------------------
bool init()
{
    Complex obj;
    if (!is_zero(obj.real) || !is_zero(obj.imagine))
    {
        std::cerr << "TEST init : failed\n";
        return false;
    }   
    else
    {
        std::cerr << "TEST init : passed\n";
        return true; 
    }
}

bool init_one_arg()
{
    Complex obj(real1);
    if (!is_zero(obj.real - real1) || !is_zero(obj.imagine))
    {
        std::cerr << "TEST init_one_arg : failed\n";
        return false;
    }   
    else
    {
        std::cerr << "TEST init_one_arg : passed\n";
        return true; 
    } 

}

bool init_two_arg()
{
    Complex obj(real1, imagine1);
    if (!is_zero(obj.real - real1) || !is_zero(obj.imagine - imagine1))
    {
        std::cerr << "TEST init_two_arg : failed\n";
        return false;
    }   
    else
    {
        std::cerr << "TEST init_two_arg : passed\n";
        return true; 
    }    
}

bool copy_init()
{
    Complex obj1(real1, imagine1);
    Complex obj2(obj1);

    if (!is_zero(obj2.real - obj1.real) || !is_zero(obj2.imagine - obj1.imagine))
    {
        std::cerr << "TEST copy_init : failed\n";
        return false;
    }   
    else
    {
        std::cerr << "TEST copy_init : passed\n";
        return true; 
    }
}

//----------------------------------- plus ------------------------------------------
//-----------------------------------------------------------------------------------
bool plus_value()
{
    Complex obj(real1, imagine1);
    Complex new_obj = obj + real2; 

    if (!is_zero(new_obj.real - (obj.real + real2)) || !is_zero(new_obj.imagine - obj.imagine))
    {
        std::cerr << "TEST plus(obj + double) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST plus(obj + double) : passed\n";
        return true; 
    }
}

bool value_plus()
{
    Complex obj(real1, imagine1);
    Complex new_obj = real2 + obj;

    if (!is_zero(new_obj.real - (real2 + obj.real)) || !is_zero(new_obj.imagine - obj.imagine))
    {
        std::cerr << "TEST plus(double + obj) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST plus(double + obj) : passed\n";
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
        std::cerr << "TEST plus(obj1 + obj2) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST plus(obj1 + obj2) : passed\n";
        return true; 
    }
}

//----------------------------------- minus -----------------------------------------
//-----------------------------------------------------------------------------------
bool minus_value()
{
    Complex obj(real1, imagine1);
    Complex new_obj = obj - real2; 

    if (!is_zero(new_obj.real - (obj.real - real2)) || !is_zero(new_obj.imagine - obj.imagine))
    {
        std::cerr << "TEST minus(obj - double) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST minus(obj - double) : passed\n";
        return true; 
    }
}

bool value_minus()
{
    Complex obj(real1, imagine1);
    Complex new_obj = real2 - obj;

    if (!is_zero(new_obj.real - (real2 - obj.real)) || !is_zero(new_obj.imagine + obj.imagine))
    {
        std::cerr << "TEST minus(double - obj) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST minus(double - obj) : passed\n";
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
        std::cerr << "TEST minus(obj1 - obj2) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST minus(obj1 - obj2) : passed\n";
        return true; 
    }
}

//--------------------------------- multiply ----------------------------------------
//-----------------------------------------------------------------------------------
bool multiply_value()
{
    Complex obj(real1, imagine1);
    Complex new_obj = obj * real2; 

    if (!is_zero(new_obj.real - (obj.real * real2)) || !is_zero(new_obj.imagine - (obj.imagine * real2)) )
    {
        std::cerr << "TEST multiply(obj * double) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST multiply(obj * double) : passed\n";
        return true; 
    }
}

bool value_multiply()
{
    Complex obj(real1, imagine1);
    Complex new_obj = real2 * obj; 

    if (!is_zero(new_obj.real - (real2 * obj.real)) || !is_zero(new_obj.imagine - (real2 * obj.imagine)) )
    {
        std::cerr << "TEST multiply(double * obj) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST multiply(double * obj) : passed\n";
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
        std::cerr << "TEST multiply(obj1 * obj2) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST multiply(obj1 * obj2) : passed\n";
        return true; 
    }
}

//---------------------------------- divide -----------------------------------------
//-----------------------------------------------------------------------------------
bool divide_value()
{
    Complex obj(real1, imagine1);
    Complex new_obj = obj / real2; 

    if (!is_zero(new_obj.real - (obj.real / real2)) || !is_zero(new_obj.imagine - (obj.imagine / real2)) )
    {
        std::cerr << "TEST divide(obj / double) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST divide(obj / double) : passed\n";
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
        std::cerr << "TEST divide(double / obj) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST divide(double / obj) : passed\n";
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
        std::cerr << "TEST divide(obj1 / obj2) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST divide(obj1 / obj2) : passed\n";
        return true; 
    }
}

//---------------------------------- assign -----------------------------------------
//-----------------------------------------------------------------------------------

bool assign_value()
{
    Complex obj(real1, imagine1);
    obj = real2; 

    if (!is_zero(obj.real - real2) || !is_zero(obj.imagine))
    {
        std::cerr << "TEST assign(obj = double) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST assign(obj = double) : passed\n";
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
        std::cerr << "TEST assign(obj = obj) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST assign(obj = obj) : passed\n";
        return true; 
    }
}

//-------------------------------- plus_assign --------------------------------------
//-----------------------------------------------------------------------------------
bool plus_assign_value()
{
    Complex obj(real1, imagine1);
    obj += real2; 

    if (!is_zero(obj.real - (real1 + real2)) || !is_zero(obj.imagine - imagine1))
    {
        std::cerr << "TEST plus_assign(obj += double) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST plus_assign(obj += double) : passed\n";
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
        std::cerr << "TEST plus_assign(obj1 += obj2) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST plus_assign(obj1 += obj2) : passed\n";
        return true; 
    }
}

//-------------------------------- minus_assign -------------------------------------
//-----------------------------------------------------------------------------------
bool minus_assign_value()
{
    Complex obj(real1, imagine1);
    obj -= real2; 

    if (!is_zero(obj.real - (real1 - real2)) || !is_zero(obj.imagine - imagine1))
    {
        std::cerr << "TEST minus_assign(obj -= double) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST minus_assign(obj -= double) : passed\n";
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
        std::cerr << "TEST minus_assign(obj1 -= obj2) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST minus_assign(obj1 -= obj2) : passed\n";
        return true; 
    }
}
//------------------------------ multiply_assign ------------------------------------
//-----------------------------------------------------------------------------------
bool multiply_assign_value()
{
    Complex obj(real1, imagine1);
    obj *= real2; 

    if (!is_zero(obj.real - (real1 * real2)) || !is_zero(obj.imagine - (imagine1 * real2)))
    {
        std::cerr << "TEST multiply_assign(obj *= double) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST multiply_assign(obj *= double) : passed\n";
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
        std::cerr << "TEST multiply_assign(obj1 *= obj2) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST multiply_assign(obj1 *= obj2) : passed\n";
        return true; 
    }
}
//------------------------------- divide_assign -------------------------------------
//-----------------------------------------------------------------------------------
bool divide_assign_value()
{
    Complex obj(real1, imagine1);
    Complex new_obj = obj / real2; 

    if (!is_zero(new_obj.real - (obj.real / real2)) || !is_zero(new_obj.imagine - (obj.imagine / real2)) )
    {
        std::cerr << "TEST divide_assign(obj /= double) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST divide_assign(obj /= double) : passed\n";
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
        std::cerr << "TEST divide_assign(obj1 /= obj2) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST divide_assign(obj1 /= obj2) : passed\n";
        return true; 
    }
}

//----------------------------------- equal -----------------------------------------
//-----------------------------------------------------------------------------------
bool equal_object_value()
{
    Complex obj(real1, 0);
    double new_real = real1;  

    if (!(obj.real == new_real) || !(obj.imagine == 0))
    {
        std::cerr << "TEST equal(obj == double) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST equal(obj == double) : passed\n";
        return true; 
    }
}

bool equal_value_object()
{
    Complex obj(real2, 0);
    double new_real = real2; 

    if (!(new_real == obj.real) || !(0 == obj.imagine))
    {
        std::cerr << "TEST equal(double == obj) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST equal(double == obj) : passed\n";
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
        std::cerr << "TEST equal(obj == obj) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST equal(obj == obj) : passed\n";
        return true; 
    }
}

//--------------------------------- not equal ---------------------------------------
//-----------------------------------------------------------------------------------
bool not_equal_object_value()
{
    Complex obj(real1, 0);
    double new_real = real1;  

    if ((obj.real != new_real) || (obj.imagine != 0))
    {
        std::cerr << "TEST not_equal(obj != double) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST not_equal(obj != double) : passed\n";
        return true; 
    }
}

bool not_equal_value_object()
{
    Complex obj(real2, 0);
    double new_real = real2;  

    if ((new_real != obj.real) || (0 != obj.imagine))
    {
        std::cerr << "TEST not_equal(double != obj) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST not_equal(double != obj) : passed\n";
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
        std::cerr << "TEST not_equal(obj != obj) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST not_equal(obj != obj) : passed\n";
        return true; 
    }
}

//------------------------------ other_functions ------------------------------------
//-----------------------------------------------------------------------------------
bool unary_minus()
{
    Complex obj(real1, imagine1);
    Complex new_obj = -obj;

    if (!is_zero(new_obj.real + obj.real) || !is_zero(new_obj.imagine + obj.imagine))
    {
        std::cerr << "TEST unary_minus(obj1 = -obj2) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST unary_minus(obj1 = -obj2) : passed\n";
        return true; 
    }
}

bool unary_plus()
{
    Complex obj(real1, imagine1);
    Complex new_obj = +obj;

    if (!is_zero(new_obj.real - obj.real) || !is_zero(new_obj.imagine - obj.imagine))
    {
        std::cerr << "TEST unary_plus(obj1 = +obj2) : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST unary_plus(obj1 = +obj2) : passed\n";
        return true; 
    }
}

bool module()
{
    Complex obj(real1, imagine1);
    double module = std::sqrt(obj.real * obj.real + obj.imagine * obj.imagine); 

    if (!is_zero(obj.Module() - module))
    {
        std::cerr << "TEST module : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST module : passed\n";
        return true; 
    }
}

bool argument()
{
    Complex obj(real1, imagine1);
    double arg = std::atan(obj.imagine / obj.real);

    if (!is_zero(obj.Argument() - arg))
    {
        std::cerr << "TEST argumet : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST argument : passed\n";
        return true; 
    }
}

bool pairing()
{
    Complex obj(real1, imagine1);

    if (!is_zero(obj.Pairing().real - obj.real) || !is_zero(obj.Pairing().imagine + obj.imagine))
    {
        std::cerr << "TEST pairing : failed\n";
        return false; 
    }
    else 
    {
        std::cerr << "TEST pairing : passed\n";
        return true; 
    }
}

/**
 * The main function to test all sub_functions
 */
void UnitTest()
{
    init();
    init_one_arg();
    init_two_arg();
    copy_init();

    plus_value();
    value_plus();
    plus_objects();

    minus_value();
    value_minus();
    minus_objects();

    multiply_value();
    value_multiply();
    multiply_objects();

    divide_value();
    value_divide();
    divide_objects();

    assign_value();
    assign_object();

    plus_assign_value();
    plus_assign_object();

    minus_assign_value();
    minus_assign_object();

    multiply_assign_value();
    multiply_assign_object();

    divide_assign_value();
    divide_assign_object();

    equal_object_value();
    equal_value_object();
    equal_objects();

    not_equal_object_value();
    not_equal_value_object();
    not_equal_objects();

    unary_minus();

    unary_plus();

    module();

    argument();

    pairing();
}