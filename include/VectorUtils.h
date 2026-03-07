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
            if constexpr (std::is_same_v<T, Vector4<float>> || std::is_same_v<T, Vector4<int>> || std::is_same_v<T, Vector4<double>>)
            {
                return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
            }
            else
            {
                return a.x * b.x + a.y * b.y + a.z * b.z;
            }
        }
    }

    template class Vector4<float>;
    template class Vector4<int>;
    template class Vector4<double>;

    template class Vector3<float>;
    template class Vector3<int>;
    template class Vector3<double>;

}