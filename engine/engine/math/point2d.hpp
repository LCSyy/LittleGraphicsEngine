#ifndef POINT2D_HPP
#define POINT2D_HPP

#include <cfloat>
#include <cmath>

struct Point2D
{
    float x{0.0f};
    float y{0.0f};

    Point2D() {}
    Point2D(const Point2D &other): x(other.x),y(other.y) {}
    Point2D(float _x, float _y): x(_x), y(_y) {}
    Point2D &operator=(const Point2D &rhs) { x = rhs.x; y = rhs.y; return *this; }
    Point2D operator+(const Point2D &rhs) const { return Point2D(x+rhs.x,y+rhs.y); }
    Point2D operator-(const Point2D &rhs) const { return Point2D(x-rhs.x,y-rhs.y); }
    Point2D operator*(const Point2D &rhs) const { return Point2D(x*rhs.x,y*rhs.y); }
    Point2D operator/(const Point2D &rhs) const {
        float _x = FLT_MAX; float _y = FLT_MAX;
        if(rhs.x != 0.0f) { _x = x / rhs.x; }
        if(rhs.y != 0.0f) { _y = y / rhs.y; }
        return Point2D(_x,_y);
    }

    Point2D &operator+=(const Point2D &rhs) {x += rhs.x; y += rhs.y; return *this; }
    Point2D &operator-=(const Point2D &rhs) { x -= rhs.x; y-=rhs.y; return *this; }
    Point2D &operator*=(const Point2D &rhs) { x *= rhs.x; y*=rhs.y; return *this; }
    Point2D &operator/=(const Point2D &rhs) {
        x= FLT_MAX; y = FLT_MAX;
        if(rhs.x != 0.0f) { x /= rhs.x; }
        if(rhs.y != 0.0f) { y-=rhs.y; }
        return *this;
    }

    float length() const { return std::sqrt(x*x+y*y); }

    friend bool operator==(const Point2D &lhs, const Point2D &rhs) {
        if(std::fabs(lhs.x - rhs.x) < FLOAT_PRECISE) { return true; }
        return false;
    }

    // constructor
    // operator + - * /
    // to vector2d
    // from vector2d
    // info
    // rotate? scale? translate?
};

#endif // POINT2D_HPP
