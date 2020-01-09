#include "SimpleCalculator.h"
#include <stdexcept>

int SimpleCalculator::add(int a, int b){
 return a+b;
}

int SimpleCalculator::sub(int a, int b){
 return a-b;
}

int SimpleCalculator::mul(int a, int b){
 return a*b;
}

int SimpleCalculator::div(int a, int b) {
    if(b==0) {
        throw std::overflow_error("Divide by zero exception");
    }
 return a/b;
}
