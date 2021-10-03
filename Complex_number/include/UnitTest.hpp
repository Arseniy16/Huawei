#ifndef _UnitTest_HPP_
#define _UnitTest_HPP_
//------------------------------------------------
//--------------- const variables ----------------
//------------------------------------------------
const double real1 = 5.432;
const double imagine1 = -0.91;

const double real2 = -3;
const double imagine2 = 8.43;
//------------------------------------------------
void UnitTest();

bool init();
bool init_one_arg();
bool init_two_arg();
bool copy_init();
bool destructor();

bool plus_value();
bool value_plus();
bool plus_objects();

bool minus_value();
bool value_minus();
bool minus_objects();

bool multiply_value();
bool value_multiply();
bool multiply_objects();

bool divide_value();
bool value_divide();
bool divide_objects();

bool assign_value();
bool assign_object();

bool plus_assign_value();
bool plus_assign_object();

bool minus_assign_value();
bool minus_assign_object();

bool multiply_assign_value();
bool multiply_assign_object();

bool divide_assign_value();
bool divide_assign_object();

bool equal_object_value();
bool equal_value_object();
bool equal_objects();

bool not_equal_object_value();
bool not_equal_value_object();
bool not_equal_objects();

bool unary_minus();

bool unary_plus();

bool module();

bool argument();

bool pairing();

#endif // _UnitTest_HPP_