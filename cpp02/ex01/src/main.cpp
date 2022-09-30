#include <iostream>
#include <cmath>
#include <cfenv>
#include <climits>
 
// #pragma STDC FENV_ACCESS ON
 
int main()
{
    // round
    std::cout << "round(+2.3) = " << std::round(2.3)
              << "  round(+2.5) = " << std::round(2.5)
              << "  round(+2.7) = " << std::round(2.7) << '\n'
              << "round(-2.3) = " << std::round(-2.3)
              << "  round(-2.5) = " << std::round(-2.5)
              << "  round(-2.7) = " << std::round(-2.7) << '\n';
 
    std::cout << "round(-0.0) = " << std::round(-0.0)  << '\n'
              << "round(-Inf) = " << std::round(-INFINITY) << '\n';   
			   // roundf
    std::cout << "roundf(+2.3) = " << std::roundf(2.3)
              << "  roundf(+2.5) = " << std::roundf(2.5)
              << "  roundf(+2.7) = " << std::roundf(2.7) << '\n'
              << "roundf(-2.3) = " << std::roundf(-2.3)
              << "  roundf(-2.5) = " << std::roundf(-2.5)
              << "  roundf(-2.7) = " << std::roundf(-2.7) << '\n';
 
    std::cout << "roundf(-0.0) = " << std::roundf(-0.0)  << '\n'
              << "roundf(-Inf) = " << std::roundf(-INFINITY) << '\n';
 
   
 
    // error handling
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "std::lround(LONG_MAX+1.5) = "
              << std::lround(LONG_MAX+1.5) << '\n';
    if (std::fetestexcept(FE_INVALID))
              std::cout << "    FE_INVALID was raised\n";
}
