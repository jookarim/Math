#pragma once

#include <cmath>
#include <ostream>
#include <stdexcept>

namespace Math
{
    template<typename T>
    class Vector4
    {
    private:
        static constexpr const char* VECTOR4_ERROR = "Error: Vector4 divide by 0";

    public:
        T x, y, z, w;

        Vector4() = default;
        ~Vector4() = default;

        void setVectorData(const T& x, const T& y, const T& z, const T& w) noexcept
        {
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
        }

        Vector4(const T& x, const T& y, const T& z, const T& w)
        {
            setVectorData(x, y, z, w);
        }

        Vector4(const Vector4& other) = default;

        Vector4& operator=(const Vector4& other) noexcept
        {
            if (this == &other)
            {
                return *this;
            }

            setVectorData(other.x, other.y, other.z, other.w);
            return *this;
        }

        Vector4 operator*(const Vector4& other) const noexcept
        {
            return {
                x * other.x,
                y * other.y,
                z * other.z,
                w * other.w
            };
        }

        Vector4 operator/(const Vector4& other) const
        {
            if (other.x != 0 && other.y != 0 && other.z != 0 && other.w != 0)
            {
                return {
                    x / other.x,
                    y / other.y,
                    z / other.z,
                    w / other.w
                };
            }

            throw std::runtime_error(VECTOR4_ERROR);
        }

        Vector4 operator*(const T& scaler) const noexcept
        {
            return {
                x * scaler,
                y * scaler,
                z * scaler,
                w * scaler
            };
        }

        Vector4 operator/(const T& scaler) const
        {
            if (scaler != 0)
            {
                return {
                    x / scaler,
                    y / scaler,
                    z / scaler,
                    w / scaler
                };
            }

            throw std::runtime_error(VECTOR4_ERROR);
        }

        void operator/=(const Vector4& other)
        {
            if (other.x != 0 && other.y != 0 && other.z != 0 && other.w != 0)
            {
                x /= other.x;
                y /= other.y;
                z /= other.z;
                w /= other.w;
                return;
            }

            throw std::runtime_error(VECTOR4_ERROR);
        }

        void operator*=(const Vector4& other) noexcept
        {
            x *= other.x;
            y *= other.y;
            z *= other.z;
            w *= other.w;
        }

        void operator*=(const T& scaler) noexcept
        {
            x *= scaler;
            y *= scaler;
            z *= scaler;
            w *= scaler;
        }

        void operator/=(const T& scaler)
        {
            if (scaler != 0)
            {
                x /= scaler;
                y /= scaler;
                z /= scaler;
                w /= scaler;
                return;
            }

            throw std::runtime_error(VECTOR4_ERROR);
        }

        Vector4 operator+(const Vector4& other) const noexcept
        {
            return {
                x + other.x,
                y + other.y,
                z + other.z,
                w + other.w
            };
        }

        Vector4 operator-(const Vector4& other) const noexcept
        {
            return {
                x - other.x,
                y - other.y,
                z - other.z,
                w - other.w
            };
        }

        void operator+=(const Vector4& other) noexcept
        {
            x += other.x;
            y += other.y;
            z += other.z;
            w += other.w;
        }

        void operator-=(const Vector4& other) noexcept
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            w -= other.w;
        }

        Vector4 operator+(const T& scaler) const noexcept
        {
            return {
                x + scaler,
                y + scaler,
                z + scaler,
                w + scaler
            };
        }

        Vector4 operator-(const T& scaler) const noexcept
        {
            return {
                x - scaler,
                y - scaler,
                z - scaler,
                w - scaler
            };
        }

        void operator+=(const T& scaler) noexcept
        {
            x += scaler;
            y += scaler;
            z += scaler;
            w += scaler;
        }

        void operator-=(const T& scaler) noexcept
        {
            x -= scaler;
            y -= scaler;
            z -= scaler;
            w -= scaler;
        }

        T length() const
        {
            return std::sqrt(x * x + y * y + z * z + w * w);
        }

        void normalize()
        {
            T len = length();

            if (len != 0)
            {
                x /= len;
                y /= len;
                z /= len;
                w /= len;
                return;
            }

            throw std::runtime_error(VECTOR4_ERROR);
        }

        friend Vector4 operator*(const T& value, const Vector4& vec) noexcept
        {
            return {
                vec.x * value,
                vec.y * value,
                vec.z * value,
                vec.w * value
            };
        }
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& o, const Vector4<T>& v) noexcept
    {
        o << v.x << " " << v.y << " " << v.z << " " << v.w;
        return o;
    }

    template class Vector4<float>;
    template class Vector4<int>;
    template class Vector4<double>;

}