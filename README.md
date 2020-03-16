# AddWithOverflowSupport
 Arithmetic a+b type int Overflow Support and retrieving the correct result (long long type) using custom Overflow exception

1. Integer overflow doesn't throw an exception
2. INT_MIN have a few problematic use cases
3. I've created an Exception class for throwing an Overflow exception and the correct a + b answer
4. I've created Int class with overloaded bitwise + and |.
5. Bitwise "+" overloading for a+b math operation between Int object + integer number
6. BitWise "|" overloading does an aarithmetic+ calculation and check whether overflow or underflow have occurred. If overflow has occurred, then a OverFlowException (custom exception) is thrown
      with the correct answer using long long type
7. In OverFlowException correct e.result of a+b type long long is returned
8. Test cases Positive int a + b, Negative -a + - b where a+b and (-a)+(-b) result are in range and then where a = 2,147,483,647 and b > 0 or a = -2,147,483,647 and b < 0
    
    
  How to use this code with overflow test case:
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

