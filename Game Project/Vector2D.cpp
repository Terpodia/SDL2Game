#include "Vector2D.hpp"

Vector2D::Vector2D()
{
    x = 0.0f;
    y = 0.0f;
}

Vector2D::Vector2D(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Vector2D::magnitude()
{
    float x = this->x;
    float y = this->y;

    return sqrt(x*x + y*y);
}

Vector2D& Vector2D::add(const Vector2D &vec)
{
    this->x += vec.x;
    this->y += vec.y;
    
    return *this;
}

Vector2D& Vector2D::substract(const Vector2D &vec)
{
    this->x -= vec.x;
    this->y -= vec.y;
    
    return *this;
}

Vector2D& Vector2D::multiply(const Vector2D &vec)
{
    this->x *= vec.x;
    this->y *= vec.y;
    
    return *this;
}

Vector2D& Vector2D::divide(const Vector2D &vec)
{
    this->x /= vec.x;
    this->y /= vec.y;
    
    return *this;
}

Vector2D& operator+(Vector2D& v1, Vector2D& v2)
{
    return v1.add(v2);
}

Vector2D& operator-(Vector2D& v1, Vector2D& v2)
{
    return v1.substract(v2);
}

Vector2D& operator*(Vector2D& v1, Vector2D& v2)
{
    return v1.multiply(v2);
}

Vector2D& operator/(Vector2D& v1, Vector2D& v2)
{
    return v1.divide(v2);
}

Vector2D& Vector2D::operator+=(const Vector2D& vec)
{
    return this->add(vec);
}

Vector2D& Vector2D::operator-=(const Vector2D& vec)
{
    return this->substract(vec);
}

Vector2D& Vector2D::operator*=(const Vector2D& vec)
{
    return this->multiply(vec);
}

Vector2D& Vector2D::operator/=(const Vector2D& vec)
{
    return this->divide(vec);
}

Vector2D& Vector2D::operator*(const float& i)
{
    this->x *= i;
    this->y *= i;
    
    return *this;
}

Vector2D& Vector2D::zero()
{
    this->x = 0;
    this->y = 0;
    
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vector2D vec)
{
    stream << "(" << vec.x << ", " << vec.y << ")";
    return stream;
}
