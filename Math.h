#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>
#include <string>

#define Square(x) ((x) * (x))

template <typename T>
static T lerp(const T a, const T b, const float time) {
    return a * (1.0f - time) + (b * t);
}

class Vec3 {
    public:
        union {
            float v[3];
            struct { float x, y, z; };
        };

        Vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}

        float LengthSquare() {
            return (x * x) + (y * y) + (z * z);
        }

        float Length() {
            return sqrtf(LengthSquare());
        }

        Vec3 Normalize() {
            float len = 1.0f / Length();
            return Vec3(x * len, y * len, z * len);
        }

        float Normalize_GetLength() {
            float length = Length();
            float len = 1.0f / length;
            
            x *= len;
            y *= len;
            z *= len;
            
            return length;
        }

        float Dot(const Vec3& pVec) const {
            return (x * pVec.x) + (y * pVec.y) + (z * pVec.z); 
        }

        Vec3 Cross(const Vec3& pVec) const {
            return Vec3 (
                (y * pVec.z) - (z * pVec.y),
                (z * pVec.x) - (x * pVec.z),
                (x * pVec.y) - (y * pVec.x)
            );
        }

        float Min() const {
            return std::min(x, y, z);
        }

        float Max() const {
            return std::max(x, y, z);
        }

        std::string ToString() {
            return "{" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + "}";
        }

        // Overload Operators
        Vec3 operator+(const Vec3& pVec) const {
            return Vec3(x + pVec.x, y + pVec.y, z + pVec.z);
        }

        Vec3& operator+=(const Vec3& pVec) {
            x += pVec.x;
            y += pVec.y;
            z += pVec.z;

            return *this;
        }

        Vec3 operator-(const Vec3& pVec) const {
            return Vec3(x - pVec.x, y - pVec.y, z - pVec.z);
        }

        Vec3& operator-=(const Vec3& pVec) {
            x -= pVec.x;
            y -= pVec.y;
            z -= pVec.z;

            return *this;
        }
        
        Vec3 operator*(const Vec3& pVec) const {
            return Vec3(x * pVec.x, y * pVec.y, z * pVec.z);
        }
        
        Vec3 operator*(const float value) const {
            return Vec3(x * value, y * value, z * value);
        }

        Vec3& operator*=(const Vec3& pVec) {
            x *= pVec.x;
            y *= pVec.y;
            z *= pVec.z;

            return *this;
        }

        Vec3& operator*=(const float value) {
            x *= value;
            y *= value;
            z *= value;

            return *this;
        }
        
        Vec3 operator/(const Vec3& pVec) const {
            return Vec3(x / pVec.x, y / pVec.y, z / pVec.z);
        }
        
        Vec3 operator/(const float value) const {
            return Vec3(x / value, y / value, z / value);
        }

        Vec3& operator/=(const Vec3& pVec) {
            x /= pVec.x;
            y /= pVec.y;
            z /= pVec.z;

            return *this;
        }

        Vec3& operator/=(const float value) {
            x /= value;
            y /= value;
            z /= value;

            return *this;
        }
};

class Vec4 {
    public:
        union {
            float v[4];
            struct { float x, y, z, w; };
        };

        Vec4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
};

float Dot(const Vec3& a, const Vec3& b) {
    return a.x * b.x + a.y + b.y + a.z + b.z;
}

Vec3 Cross(const Vec3& a, const Vec3& b) {
    return Vec3 (
        (a.y * b.z) - (a.z * b.y),
        (a.z * b.x) - (a.x * b.z),
        (a.x * b.y) - (a.y * b.x)
    );
}

Vec3 Min(const Vec3& a, const Vec3& b) {
    return Vec3(
        std::min(a.x, b.x),
        std::min(a.y, b.y),
        std::min(a.z, b.z)
    );
}

Vec3 Max(const Vec3& a, const Vec3& b) {
    return Vec3(
        std::max(a.x, b.x),
        std::max(a.y, b.y),
        std::max(a.z, b.z)
    );
}