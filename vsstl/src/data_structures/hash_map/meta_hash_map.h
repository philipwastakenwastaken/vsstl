#pragma once
#include "vsstlpch.h"



namespace vsstl {


    class MetaHashMap {

    public:


        inline std::size_t size() {return elements;}
        inline std::size_t allocation_size() {return capacity;}


    private:

        std::size_t elements;
        std::size_t capacity;


    };







}