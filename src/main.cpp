#include <iostream>
#include "Vector3.h"
#include "Vector4.h"
#include "VectorUtils.h"

int main()
{
    Math::Vector3<float> v;
    v.setVectorData(1.f, 2.f, 0.f);

    Math::Vector4<float> v4;
    v4.setVectorData(1.f, 2.f, 3.f, 1.f);

    Math::Vector3<float> v2(v);
    std::cout << "v2 (copy of v): " << v2 << "\n";

    Math::Vector3<float> division = 2 * v;
    std::cout << "2 * v = " << division << "\n";

    try
    {
        division /= v;
    }
    catch (const std::runtime_error& r)
    {
        std::cout << r.what() << "\n";
    }
    
    float dot = Math::dot(v, v2);
    std::cout << "dot(v, v2) = " << dot << "\n";

    std::cout << "v4 = " << v4 << "\n";

    std::cout << "division = " << division << "\n";

    return 0;
}