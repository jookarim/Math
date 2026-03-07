#include "Vector3.h"
#include "Vector4.h"
#include <type_traits>
#include <stdexcept>

namespace Math
{

    template<typename T>
    float dot(const T& a, const T& b)
    {
        if constexpr (!std::is_same_v<T, T>)
        {
            throw std::runtime_error("the 2 vectors must have the same type");
        }
        else
        {
            if constexpr (
                std::is_same_v<T, Vector4<float>> ||
                std::is_same_v<T, Vector4<int>> ||
                std::is_same_v<T, Vector4<double>>
                )
            {
                return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
            }
            else
            {
                return a.x * b.x + a.y * b.y + a.z * b.z;
            }
        }
    }


    template<typename T>
    Vector3<T> cross(const Vector3<T>& a, const Vector3<T>& b)
    {
        return Vector3<T>(
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        );
    }

    template class Vector4<float>;
    template class Vector4<int>;
    template class Vector4<double>;

    template class Vector3<float>;
    template class Vector3<int>;
    template class Vector3<double>;

}