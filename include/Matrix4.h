#include <cmath>
#include <type_traits>
#include <ostream>

namespace Math
{
    template<typename T>
    class Matrix4
    {
    public:
        T data[4][4];

    private:
        void identity() noexcept
        {
            if constexpr (
                std::is_same_v<T, int> ||
                std::is_same_v<T, unsigned int> ||
                std::is_same_v<T, double>)
            {
                for (int i = 0; i < 4; ++i)
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        if (i == j)
                            data[i][j] = 1;
                        else
                            data[i][j] = 0;
                    }
                }
            }
            else
            {
                for (int i = 0; i < 4; ++i)
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        if (i == j)
                            data[i][j] = 1.f;
                        else
                            data[i][j] = 0.f;
                    }
                }
            }
        }

    public:
        Matrix4()
        {
            identity();
        }

        Matrix4 operator*(const Matrix4& other) const noexcept
        {
            Matrix4 result;

            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    T sum = 0;

                    for (int k = 0; k < 4; ++k)
                    {
                        sum += data[i][k] * other.data[k][j];
                    }

                    result.data[i][j] = sum;
                }
            }

            return result;
        }

        Matrix4 operator+(const Matrix4& other) const noexcept
        {
            Matrix4 result;

            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    result.data[i][j] = data[i][j] + other.data[i][j];
                }
            }

            return result;
        }

        Matrix4 operator-(const Matrix4& other) const noexcept
        {
            Matrix4 result;

            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    result.data[i][j] = data[i][j] - other.data[i][j];
                }
            }

            return result;
        }

        void operator+=(const Matrix4& other) noexcept
        {
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    data[i][j] += other.data[i][j];
                }
            }
        }

        void operator-=(const Matrix4& other) noexcept
        {
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    data[i][j] -= other.data[i][j];
                }
            }
        }

        void operator*=(const Matrix4& other) noexcept
        {
            *this = *this * other;
        }

        template<typename T2>
        friend std::ostream& operator<<(std::ostream& o, const Matrix4<T2>& m) noexcept
        {
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    if (j == 0 && i != 0)
                        o << "\n";

                    o << m.data[i][j] << " ";
                }
            }

            return o;
        }
    };

}