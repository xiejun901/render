#ifndef _VECTOR3_H_
#define _VECTOR3_H_

template<typename T>
class vector3 {
public:
    vector3(T x, T y, T z=T(0)):x(x), y(y), z(z){}
    vector3() = default;
    vector3(const vector3 &right);

    vector3 &operator+=(const vector3 &right);
    vector3 &operator-=(const vector3 &right);
    vector3 &operator*=(const vector3 &right);
    vector3 &operator*=(const T &right);
    vector3 &operator*=(const float right);
    bool operator==(const vector3 &right) const;

    T getX() const { return x; }
    T getY() const { return y; }
    T getZ() const { return z; }
private:
    T x;
    T y;
    T z;
};

template<typename T>
inline vector3<T>::vector3(const vector3 & right)
{
    x = right.x;
    y = right.y;
    z = right.z;
}

template<typename T>
inline vector3<T> &vector3<T>::operator+=(const vector3<T> &right)
{
    x += right.x;
    y += right.y;
    z += right.z;
    return *this;
}

template<typename T>
inline vector3<T> & vector3<T>::operator-=(const vector3 &right)
{
    x -= right.x;
    y -= right.y;
    z -= right.z;
    return *this;
}

template<typename T>
inline vector3<T> & vector3<T>::operator*=(const vector3 &right)
{
    x *= right.x;
    y *= right.y;
    z *= right.z;
    return *this;
}

template<typename T>
inline vector3<T> & vector3<T>::operator*=(const T &right)
{
    x *= right;
    y *= right;
    z *= right;
    return *this;
}

template<typename T>
inline vector3<T> & vector3<T>::operator*=(const float right)
{
    x = static_cast<int>(static_cast<float>(x)*right);
    y = static_cast<int>(static_cast<float>(y)*right);
    z = static_cast<int>(static_cast<float>(z)*right);
    return *this;
}

template<typename T>
inline bool vector3<T>::operator==(const vector3 &right) const
{
    return x == right.x && y == right.y && z == right.z;
}

template<typename T>
inline bool operator==(const vector3<T> &left, const vector3<T> &right)
{
    return left.operator==(right);
}

template<typename T>
inline vector3<T> operator+(const vector3<T> &left, const vector3<T> &right)
{
    return vector3<T>(left) += right;
}

template<typename T>
inline vector3<T> operator-(const vector3<T> &left, const vector3<T> &right)
{
    return vector3<T>(left) -= right;
}

template<typename T>
inline vector3<T> operator*(const vector3<T> &left, const vector3<T> &right)
{
    return vector3<T>(left) *= right;
}

template<typename T>
inline vector3<T> operator*(const vector3<T> &left, const T &right)
{
    return vector3<T>(left) *= right;
}

template<typename T>
inline vector3<T> operator*(const T &left, const vector3<T> &right)
{
    return vector3<T>(right) *= left;
}

#endif