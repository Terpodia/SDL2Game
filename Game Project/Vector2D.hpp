#ifndef Vector2D_hpp
#define Vector2D_hpp

#include <iostream>
#include <math.h>

class Vector2D
{
public:

    float x, y;
    
    Vector2D();
    Vector2D(float x, float y);
    
    Vector2D& add (const Vector2D& vec);
    Vector2D& substract (const Vector2D& vec);
    Vector2D& multiply (const Vector2D& vec);
    Vector2D& divide (const Vector2D& vec);
    
    friend Vector2D& operator+(Vector2D& v1, Vector2D& v2);
    friend Vector2D& operator-(Vector2D& v1, Vector2D& v2);
    friend Vector2D& operator*(Vector2D& v1, Vector2D& v2);
    friend Vector2D& operator/(Vector2D& v1, Vector2D& v2);
    
    Vector2D& operator+=(const Vector2D& vec);
    Vector2D& operator-=(const Vector2D& vec);
    Vector2D& operator*=(const Vector2D& vec);
    Vector2D& operator/=(const Vector2D& vec);
    
    Vector2D& operator*(const float& i);
    
    Vector2D& zero();
    
    float magnitude();

    friend std::ostream& operator<<(std::ostream& stream, const Vector2D vec);
};


#endif /* Vector2D_hpp */
