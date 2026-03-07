#pragma once

#include <cmath>
#include <ostream>
#include <stdexcept>

namespace Math
{
    template<typename T>
    class Vector3
    {
    private:
        static constexpr const char* VECTOR3_ERROR = "Error: Vector3 divide by 0";

    public:
        T x, y, z;

        Vector3() = default;
        ~Vector3() = default;

        void setVectorData(const T& x, const T& y, const T& z) noexcept
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        Vector3(const T& x, const T& y, const T& z)
        {
            setVectorData(x, y, z);
        }

        Vector3(const Vector3& other) = default;

        Vector3& operator=(const Vector3& other) noexcept
        {
            if (this == &other)
            {
                return *this;
            }

            setVectorData(other.x, other.y, other.z);
            return *this;
        }

        Vector3 operator*(const Vector3& other) const noexcept
        {
            return {
                x * other.x,
                y * other.y,
                z * other.z
            };
        }

        Vector3 operator/(const Vector3& other) const
        {
            if (other.x != 0 && other.y != 0 && other.z != 0)
            {
                return {
                    x / other.x,
                    y / other.y,
                    z / other.z
                };
            }

            throw std::runtime_error(VECTOR3_ERROR);
        }

        Vector3 operator*(const T& scaler) const noexcept
        {
            return {
                x * scaler,
                y * scaler,
                z * scaler
            };
        }

        Vector3 operator/(const T& scaler) const
        {
            if (scaler != 0)
            {
                return {
                    x / scaler,
                    y / scaler,
                    z / scaler
                };
            }

            throw std::runtime_error(VECTOR3_ERROR);
        }

        void operator/=(const Vector3& other)
        {
            if (other.x != 0 && other.y != 0 && other.z != 0)
            {
                x /= other.x;
                y /= other.y;
                z /= other.z;
                return;
            }

            throw std::runtime_error(VECTOR3_ERROR);
        }

        void operator*=(const Vector3& other) noexcept
        {
            x *= other.x;
            y *= other.y;
            z *= other.z;
        }

        void operator*=(const T& scaler) noexcept
        {
            x *= scaler;
            y *= scaler;
            z *= scaler;
        }

        void operator/=(const T& scaler)
        {
            if (scaler != 0)
            {
                x /= scaler;
                y /= scaler;
                z /= scaler;
                return;
            }

            throw std::runtime_error(VECTOR3_ERROR);
        }

        Vector3 operator+(const Vector3& other) const noexcept
        {
            return {
                x + other.x,
                y + other.y,
                z + other.z
            };
        }

        Vector3 operator-(const Vector3& other) const noexcept
        {
            return
            {
                x - other.x,
                y - other.y,
                z - other.z
            };
        }

        void operator+=(const Vector3& other) noexcept
        {
            x += other.x;
            y += other.y;
            z += other.z;
        }

        void operator-=(const Vector3& other) noexcept
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
        }

        Vector3 operator+(const T& scaler) const noexcept
        {
            return {
                x + scaler,
                y + scaler,
                z + scaler
            };
        }

        Vector3 operator-(const T& scaler) const noexcept
        {
            return {
                x - scaler,
                y - scaler,
                z - scaler
            };
        }

        void operator+=(const T& scaler) noexcept
        {
            x += scaler;
            y += scaler;
            z += scaler;
        }

        void operator-=(const T& scaler) noexcept
        {
            x -= scaler;
            y -= scaler;
            z -= scaler;
        }

        T length() const
        {
            return std::sqrt(x * x + y * y + z * z);
        }

        void normalize()
        {
            T len = length();

            if (len != 0)
            {
                x /= len;
                y /= len;
                z /= len;
                return;
            }

            throw std::runtime_error(VECTOR3_ERROR);
        }

        
        friend Vector3 operator*(const T& value, const Vector3& vec) noexcept
        {
            return {
                vec.x * value,
                vec.y * value,
                vec.z * value
            };
        }
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& o, const Vector3<T>& v) noexcept
    {
        o << v.x << " " << v.y << " " << v.z;
        return o;
    }

    template class Vector3<float>;
    template class Vector3<int>;
    template class Vector3<double>;
}