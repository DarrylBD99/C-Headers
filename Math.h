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

class Matrix {
    private:
        Matrix Identity() {
            Matrix value;

            for (int i = 0; i < 4; i++) {
                value.a[i][i] = 1;
            }
            
            return value;
        }

        Matrix mul(const Matrix& matrix) const {
            Matrix ret;
            ret .m[0] = m[0] * matrix .m[0] + m[1] * matrix .m[4] + m[2] * matrix .m[8] + m[3] * matrix .m[12];
            ret.m[1] = m[0] * matrix .m[1] + m[1] * matrix .m[5] + m[2] * matrix .m[9] + m[3] * matrix .m[13];
            ret.m[2] = m[0] * matrix .m[2] + m[1] * matrix .m[6] + m[2] * matrix .m[10] + m[3] * matrix .m[14];
            ret.m[3] = m[0] * matrix .m[3] + m[1] * matrix .m[7] + m[2] * matrix .m[11] + m[3] * matrix .m[15];
            ret.m[4] = m[4] * matrix .m[0] + m[5] * matrix .m[4] + m[6] * matrix .m[8] + m[7] * matrix .m[12];
            ret.m[5] = m[4] * matrix .m[1] + m[5] * matrix .m[5] + m[6] * matrix .m[9] + m[7] * matrix .m[13];
            ret.m[6] = m[4] * matrix .m[2] + m[5] * matrix .m[6] + m[6] * matrix .m[10] + m[7] * matrix .m[14];
            ret.m[7] = m[4] * matrix .m[3] + m[5] * matrix .m[7] + m[6] * matrix .m[11] + m[7] * matrix .m[15];
            ret.m[8] = m[8] * matrix .m[0] + m[9] * matrix .m[4] + m[10] * matrix .m[8] + m[11] * matrix .m[12];
            ret.m[9] = m[8] * matrix .m[1] + m[9] * matrix .m[5] + m[10] * matrix .m[9] + m[11] * matrix .m[13];
            ret.m[10] = m[8] * matrix .m[2] + m[9] * matrix .m[6] + m[10] * matrix .m[10] + m[11] * matrix .m[14];
            ret.m[11] = m[8] * matrix .m[3] + m[9] * matrix .m[7] + m[10] * matrix .m[11] + m[11] * matrix .m[15];
            ret.m[12] = m[12] * matrix .m[0] + m[13] * matrix .m[4] + m[14] * matrix .m[8] + m[15] * matrix .m[12];
            ret.m[13] = m[12] * matrix .m[1] + m[13] * matrix .m[5] + m[14] * matrix .m[9] + m[15] * matrix .m[13];
            ret.m[14] = m[12] * matrix .m[2] + m[13] * matrix .m[6] + m[14] * matrix .m[10] + m[15] * matrix .m[14];
            ret.m[15] = m[12] * matrix .m[3] + m[13] * matrix .m[7] + m[14] * matrix .m[11] + m[15] * matrix .m[15];
            return ret;
        }
    
    public:
        union {
            float a[4][4];
            float m[16];
        };

        Matrix() {
            *this = Identity();
        }

        Matrix(float values[16]) {
            for (int i = 0; i < 16; i++) {
                m[i] = values[i];
            }
        }

        // Martix Transform
        Vec4 Transform(const Vec4& vector) {
            return Vec4(
                a[0][0] * vector.x + a[0][1] * vector.y + a[0][2] * vector.z + a[0][3] * vector.w,
                a[1][0] * vector.x + a[1][1] * vector.y + a[1][2] * vector.z + a[1][3] * vector.w,
                a[2][0] * vector.x + a[2][1] * vector.y + a[2][2] * vector.z + a[2][3] * vector.w,
                a[3][0] * vector.x + a[3][1] * vector.y + a[3][2] * vector.z + a[3][3] * vector.w
            );
        }

        static Matrix Translate(float x, float y, float z) {
            Matrix translate;
            
            translate.a[0][3] = x;
            translate.a[1][3] = y;
            translate.a[2][3] = z;

            return translate;
        }

        static Matrix RotateX(float angle) {
            Matrix rotateX;
            
            rotateX.a[1][1] = std::cosf(angle);
            rotateX.a[1][2] = -std::sinf(angle);
            rotateX.a[2][1] = std::cosf(angle);
            rotateX.a[2][2] = std::cosf(angle);

            return rotateX;
        }

        static Matrix RotateY(float angle) {
            Matrix rotateY;
            
            rotateY.a[0][0] = std::cosf(angle);
            rotateY.a[0][2] = std::sinf(angle);
            rotateY.a[2][0] = -std::cosf(angle);
            rotateY.a[2][2] = std::cosf(angle);

            return rotateY;
        }

        static Matrix RotateZ(float angle) {
            Matrix rotateZ;
            
            rotateZ.a[0][0] = std::cosf(angle);
            rotateZ.a[0][1] = -std::sinf(angle);
            rotateZ.a[1][0] = std::cosf(angle);
            rotateZ.a[1][1] = std::cosf(angle);

            return rotateZ;
        }

        static Matrix Scale(float value) {
            Matrix scale;
            
            scale.a[0][0] = value;
            scale.a[1][1] = value;
            scale.a[2][2] = value;
            
            return scale;
        }

        // Martix Operators
        void Transpose() {
            a[0][1] = a[1][0];
            a[0][2] = a[2][0];
            a[0][3] = a[3][0];
            a[1][0] = a[0][1];
            a[1][1] = a[1][1];
            a[1][2] = a[2][1];
            a[1][3] = a[3][1];
            a[2][0] = a[0][2];
            a[2][1] = a[1][2];
            a[2][2] = a[2][2];
            a[2][3] = a[3][2];
            a[3][0] = a[0][3];
            a[3][1] = a[1][3];
            a[3][2] = a[2][3];
        }
        
        Vec4 Mul(const Vec4& vector) {
            return Vec4(
                vector.x * a[0][0] + vector.y * a[0][1] + vector.z * a[0][2] + vector.w * a[0][3],
                vector.x * a[1][0] + vector.y * a[1][1] + vector.z * a[1][2] + vector.w * a[1][3],
                vector.x * a[2][0] + vector.y * a[2][1] + vector.z * a[2][2] + vector.w * a[2][3],
                vector.x * a[3][0] + vector.y * a[3][1] + vector.z * a[3][2] + vector.w * a[3][3]
            );
        }

        Vec3 MulPoint(const Vec3& vector) {
            return Vec3(
                vector.x * a[0][0] + vector.y * a[0][1] + vector.z * a[0][2] + a[0][3],
                vector.x * a[1][0] + vector.y * a[1][1] + vector.z * a[1][2] + a[1][3],
                vector.x * a[2][0] + vector.y * a[2][1] + vector.z * a[2][2] + a[2][3]
            );
        }

        Vec3 MulVec(const Vec3& vector) {
            return Vec3(
                vector.x * a[0][0] + vector.y * a[0][1] + vector.z * a[0][2],
                vector.x * a[1][0] + vector.y * a[1][1] + vector.z * a[1][2],
                vector.x * a[2][0] + vector.y * a[2][1] + vector.z * a[2][2]
            );
        }

        // Operator Overload
        float& operator[](int index) {
            return m[index];
        }

        Matrix& operator*(const Matrix& matrix) const {
            return mul(matrix);
        }

        Matrix& operator*=(const Matrix& matrix) {
            *this = mul(matrix);
            return *this;
        }
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