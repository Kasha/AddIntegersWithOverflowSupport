//Arithmetic a+b type int Overflow Support and retrieving the correct result (long long type) using custom Overflow exception
#include<stdio.h> 
#include<string>
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
////////////////////////////////////////
      /*
      1. Integer overflow doesn't throw an exception
      2. INT_MIN have a few problematic use cases
      3. I've created an Exception class for throwing an Overflow exception and the correct a + b answer
      4. I've created Int class with overloaded bitwise + and |.
      5. Bitwise "+" overloading for a+b math operation between Int object + integer number
      6. BitWise "|" overloading does an arithmetic+ calculation and check whether overflow or underflow have occurred. If overflow has occurred, then an OverFlowException (custom exception) is thrown with the correct answer using long long type.
      7. In OverFlowException correct e.result of a+b type long long is returned
      8.Test cases Positive int a + b, Negative -a + - b where a+b and (-a)+(-b) result are in range and then where a = 2,147,483,647 and b > 0 or a = -2,147,483,647 and b < 0
      */
struct OverFlowException : public exception {
    OverFlowException(const string& reason, const long long& result) :m_reason(reason), m_result(result)
    {
    }

    const char* what() const throw ()
    {
        return m_reason.c_str();
    }

    long long fixedResult() const throw ()
    {
        return m_result;
    }

private:
    string m_reason;
    long long m_result;
};

// This is automatically called when '+' is used with 
// between two Complex objects 
class Int
{
public:
    Int(int num) : m_a(num)
    {
    }

    int operator+ (int b)
    {
        return *this | b;
    }

    int operator| (int b)
    {
        int res = m_a + b;
        //If both integers positive numbers and res is negetive or if boft inegers are negetive and res is positive then overflow has occured
        if ((m_a > 0 && b > 0 && res < 0) || (m_a < 0 && b < 0 && res > 0))
        {
            long long lA = m_a, lB = b;

            throw OverFlowException("Integer Add Overflow", lA + lB);
        }
        //Time Complexity : O(1)
        //Space Complexity : O(1)
        return res;
    }

    // This operator overloading enables calling 
    // operator function () on objects of increment 
    int operator () ()
    {
        return m_a;
    }
private:
    int m_a;

};

int add(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else if (a == 0)
    {
        return b;
    }

    return Int(a) + b;
}
////////////////////////////
int main()
{
     try
    {
       int a = 0x7fffffff;

       cout << "5+2= " << add(5, 2) << std::endl;
       cout << a << "+2= ";
       cout << add(a, 2) << std::endl; //Cause an overflow
    }
    catch (OverFlowException & e)
    {
        std::cout << "\nOverflow exception";
        std::cout << "\nReason:" << e.what() << std::endl;
        std::cout << "Fixed Result:" << e.fixedResult() << std::endl;//Display the right results using lomg long
    }
    catch (std::exception & e) {
        std::cout << "Reason General:" << e.what() << std::endl;
    }

    return 0;
}
