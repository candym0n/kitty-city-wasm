#pragma once
#include <cmath>

template<typename T>
class Vector2 {
public:
    T x, y;

    // Constructors
    constexpr Vector2() : x(0), y(0) {}
    constexpr Vector2(T x, T y) : x(x), y(y) {}
    
    // Copy constructor
    constexpr Vector2(const Vector2& other) = default;
    
    // Type conversion constructor
    template<typename U>
    constexpr explicit Vector2(const Vector2<U>& other)
        : x(static_cast<T>(other.x))
        , y(static_cast<T>(other.y)) {}

    // Operators
    constexpr Vector2 operator+(const Vector2& rhs) const {
        return Vector2(x + rhs.x, y + rhs.y);
    }
    
    constexpr Vector2 operator-(const Vector2& rhs) const {
        return Vector2(x - rhs.x, y - rhs.y);
    }
    
    constexpr Vector2 operator*(T scalar) const {
        return Vector2(x * scalar, y * scalar);
    }
    
    constexpr Vector2 operator/(T scalar) const {
        return Vector2(x / scalar, y / scalar);
    }

    // Compound assignment operators
    constexpr Vector2& operator+=(const Vector2& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    
    constexpr Vector2& operator-=(const Vector2& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }
    
    constexpr Vector2& operator*=(T scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }
    
    constexpr Vector2& operator/=(T scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    // Comparison operators
    constexpr bool operator==(const Vector2& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    
    constexpr bool operator!=(const Vector2& rhs) const {
        return !(*this == rhs);
    }

    // Vector operations
    constexpr T dot(const Vector2& rhs) const {
        return x * rhs.x + y * rhs.y;
    }
    
    constexpr T cross(const Vector2& rhs) const {
        return x * rhs.y - y * rhs.x;
    }
    
    // Calculuate the magnitude of the vector
    constexpr T length() const {
        return std::sqrt(lengthSquared());
    }
    
    constexpr T lengthSquared() const {
        return x * x + y * y;
    }
    
    // Convert into a unit vector
    constexpr Vector2 normalized() const {
        T len = length();
        if (len > 0) {
            return *this / len;
        }
        return *this;
    }
    
    constexpr void normalize() {
        T len = length();
        if (len > 0) {
            *this /= len;
        }
    }

    // Utility functions
    static constexpr Vector2 zero() { return Vector2(0, 0); }
    static constexpr Vector2 one() { return Vector2(1, 1); }
    static constexpr Vector2 up() { return Vector2(0, -1); }
    static constexpr Vector2 down() { return Vector2(0, 1); }
    static constexpr Vector2 left() { return Vector2(-1, 0); }
    static constexpr Vector2 right() { return Vector2(1, 0); }
};

// Free functions for scalar multiplication
template<typename T>
constexpr Vector2<T> operator*(T scalar, const Vector2<T>& vec) {
    return vec * scalar;
}

// Utility functions
template<typename T>
constexpr T distance(const Vector2<T>& a, const Vector2<T>& b) {
    return (b - a).length();
}

template<typename T>
constexpr T distanceSquared(const Vector2<T>& a, const Vector2<T>& b) {
    return (b - a).lengthSquared();
}

template<typename T>
constexpr Vector2<T> lerp(const Vector2<T>& a, const Vector2<T>& b, T t) {
    return a + (b - a) * t;
}
