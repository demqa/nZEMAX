#include <iostream>
#include "vector/vector.h"

#include <SFML/Graphics.hpp>

int main(int argc, char *argv[])
{
    vector_t vec1{2, 3};
    vector_t vec2{4, 6};

    vector_t vec3{};

    vector_t vec4 = vec1 + vec2;

    // vec4.draw();

    return 0;
}
