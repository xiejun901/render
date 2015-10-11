#ifndef _COLOR_H_
#define _COLOR_H_
template<typename T>
class Color{
public:
	Color() = default;
	Color(T r, T g, T b) :red(r), green(g), blue(b){}
    Color &operator+=(const Color &right);
    Color &operator-=(const Color &right);
    Color &operator*=(const Color &right);
    Color &operator*=(const T &right);
    Color &operator/=(const T &right);
    Color &operator*=(const float righg);
	T red, green, blue;
};

template<typename T>
Color<T> operator+(const Color<T> &lhs, const Color<T> &rhs)
{
    return Color<T>(lhs) += rhs;
}
template<typename T>
Color<T> operator-(const Color<T> &lhs, const Color<T> &rhs)
{
    return Color<T>(lhs) -= rhs;
}
template<typename T>
Color<T> operator*(const Color<T> &lhs, const Color<T> &rhs)
{
    return Color<T>(lhs) *= rhs;
}
template<typename T>
Color<T> operator*(const Color<T> &lhs, T var)
{
    return Color<T>(lhs) *= var;
}
template<typename T>
Color<T> operator*(T var, const Color<T> &rhs)
{
    return Color<T>(rhs) *= var;
}

template<typename T>
Color<T> operator/(const Color<T> &lhs, T var)
{
    return Color<T>(lhs) /= var;
}

template<typename T>
inline Color<T> &Color<T>::operator+=(const Color & right)
{
    red +=right.red;
    green += right.green;
    blue += right.blue;
    return *this;
}

template<typename T>
inline Color<T> &Color<T>::operator-=(const Color & right)
{
    red -= right.red;
    green -= right.green;
    blue -= right.blue;
    return *this;
}

template<typename T>
inline Color<T> &Color<T>::operator*=(const Color & right)
{
    red *= right.red;
    green *= right.green;
    blue *= right.blue;
    return *this;
}

template<typename T>
inline Color<T> &Color<T>::operator*=(const T & right)
{
    red *= right;
    green *= right;
    blue *= right;
    return *this;
}

template<typename T>
inline Color<T> & Color<T>::operator/=(const T & right)
{
    red /= right;
    green /= right;
    blue /= right;
    return *this;
}

template<typename T>
inline Color<T> & Color<T>::operator*=(const float right)
{
    red = static_cast<int>(static_cast<float>(red)*right);
    green = static_cast<int>(static_cast<float>(green)*right);
    blue = static_cast<int>(static_cast<float>(blue)*right);
    return *this;
}

#endif