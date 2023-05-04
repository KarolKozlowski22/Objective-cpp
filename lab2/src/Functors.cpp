#include "Functors.h"

bool DivisibleBy::operator()(const int x){
    return x%_divisor==0;
}

bool GreaterThan::operator()(const int x){
    return x>_threshold;
}