#include "core/log.h"
#include "vsstlpch.h"


namespace vsstl {


    struct Adder {
        int a, b;

        int add() {
            VSSTL_CORE_INFO("hey {0}", a + b);
            VSSTL_INFO("heyd");

            return a + b;
        }
    };






}