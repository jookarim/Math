#include <iostream>
#include "Vector3.h"
#include "Vector4.h"
#include "VectorUtils.h"
#include "Matrix4.h"

int main()
{
    std::cout << "===== VECTOR DEMO =====\n\n";

    Math::Vector3<float> v1;
    v1.setVectorData(1.f, 2.f, 3.f);

    Math::Vector3<float> v2;
    v2.setVectorData(4.f, 5.f, 6.f);

    std::cout << "v1 = " << v1 << "\n";
    std::cout << "v2 = " << v2 << "\n\n";

    float d = Math::dot(v1, v2);
    std::cout << "dot(v1, v2) = " << d << "\n";

    Math::Vector3<float> c = Math::cross(v1, v2);
    std::cout << "cross(v1, v2) = " << c << "\n";

    Math::Vector3<float> scaled = 2 * v1;
    std::cout << "2 * v1 = " << scaled << "\n\n";


    std::cout << "===== VECTOR4 DEMO =====\n\n";

    Math::Vector4<float> position;
    position.setVectorData(1.f, 2.f, 3.f, 1.f);

    std::cout << "position (homogeneous) = " << position << "\n\n";


    std::cout << "===== MATRIX DEMO =====\n\n";

    Math::Matrix4<float> m1;
    Math::Matrix4<float> m2;

    std::cout << "Matrix m1 (identity):\n";
    std::cout << m1 << "\n\n";

    std::cout << "Matrix m2 (identity):\n";
    std::cout << m2 << "\n\n";


    std::cout << "===== MATRIX MULTIPLICATION =====\n\n";

    Math::Matrix4<float> result = m1 * m2;

    std::cout << "m1 * m2 = \n";
    std::cout << result << "\n\n";


    std::cout << "===== MATRIX ADDITION =====\n\n";

    Math::Matrix4<float> add = m1 + m2;

    std::cout << "m1 + m2 = \n";
    std::cout << add << "\n\n";


    std::cout << "===== MATRIX SUBTRACTION =====\n\n";

    Math::Matrix4<float> sub = m1 - m2;

    std::cout << "m1 - m2 = \n";
    std::cout << sub << "\n\n";


    std::cout << "===== COMPOUND OPERATORS =====\n\n";

    m1 += m2;
    std::cout << "m1 += m2 :\n";
    std::cout << m1 << "\n\n";

    m1 -= m2;
    std::cout << "m1 -= m2 :\n";
    std::cout << m1 << "\n\n";


    std::cout << "===== END DEMO =====\n";

    return 0;
}