//
// Created by matteoverz on 6/2/25.
//

#include "../include/vector.h"
#include "tests/test_vector.cpp"

int main() {
    test_vector::default_allocator();
    test_vector::sized_allocator();
    test_vector::random_access();
    test_vector::sized_value_allocator();
    test_vector::front_back();
    test_vector::front_back_const();
    test_vector::print_vector();
    test_vector::begin_end();
    test_vector::push_back();
    test_vector::pop_back();
    test_vector::clear();
    test_vector::resize();
    test_vector::reserve();
    test_vector::shrink_to_fit();

    // testez push_back()
    Vector<int> v;
    v.push_back(5);
    v.push_back(3);
    std::cout << "front: " << v.front() << std::endl;
    std::cout << "back: " << v.back() << std::endl;
    v.front() = 7;
    std::cout << "new front: " << v.front() << std::endl;
    return 0;
}
