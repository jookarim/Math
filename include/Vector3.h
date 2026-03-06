#include <cmath>
#include <ostream>

namespace Math
{
    template<typename T>
    class Vector3
    {
    public:
        T x, y, z;

        Vector3() = default;
        ~Vector3() = default;

        void setVectorData(const T& x, const T& y, const T& z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        Vector3(const T& x, const T& y, const T& z)
        {
            setVectorData(x, y, z);
        }

        Vector3(const Vector3& other) noexcept
        {
            x = other.x;
            y = other.y;
            z = other.z;
        }

        Vector3& operator=(const Vector3& other) noexcept
        {
            if (this == &other)
            {
                return *this;
            }

            setVectorData(other.x, other.y, other.z);
            return *this;
        }

        Vector3(Vector3&& other) noexcept
        {
            x = other.x;
            y = other.y;
            z = other.z;
        }

        Vector3& operator=(Vector3&& other) noexcept
        {
            if (this == &other)
            {
                return *this;
            }

            x = other.x;
            y = other.y;
            z = other.z;

            other.x = 0;
            other.y = 0;
            other.z = 0;

            return *this;
        }

        float length() const
        {
            return std::sqrt(x * x + y * y + z * z);
        }

        void normalize()
        {
            float len = length();

            x /= len;
            y /= len;
            z /= len;
        }
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& o, const Vector3<T>& v)
    {
        o << v.x << " " << v.y << " " << v.z;
        return o;
    }
}
