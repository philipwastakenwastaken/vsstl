#include <iostream>

#include "vsstl/vsstl.h"

int main() {

    vsstl::Log::init();
    vsstl::Adder adder;
    adder.a = 5;
    adder.b = 10;
    adder.add();

    VSSTL_ERROR("Heyo");


    return 0;
}