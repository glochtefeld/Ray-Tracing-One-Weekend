#ifndef VEC3_H
#define VEC3_H
#pragma once
#include <cmath>
#include <iostream>
using std::sqrt;

class vec3 {
private:
	double e[3];
public:
	vec3() : e{ 0,0,0 } {}
	vec3(double e0, double e1, double e2) : e{ e0,e1,e2 } {}

	double x() const;
	double y() const;
	double z() const;

	vec3 operator-() const;
	double operator[](int) const;
	vec3& operator+=(const vec3&);
	vec3& operator*=(const double);
	vec3& operator/=(const double);
	double length() const;
	double length_squared() const;
};

using point3 = vec3; // 3D point
using color = vec3; // RGB

// Utility Functions

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
	return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

inline vec3 operator+(const vec3& u, const vec3& v) {
	return vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}
inline vec3 operator-(const vec3& u, const vec3& v) {
	return vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}
inline vec3 operator*(const vec3& u, const vec3& v) {
	return vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}
inline vec3 operator*(double t, const vec3& v) {
	return vec3(t * v.x(), t * v.y(), t * v.z());
}

inline vec3 operator*(const vec3& v, double t) {
	return t * v;
}

inline vec3 operator/(vec3 v, double t) {
	return 1 / t * v;
}


inline double dot(const vec3& u, const vec3& v) {
	return u.x() * v.x()
		+ u.y() * v.y()
		+ u.z() * v.z();
}

inline vec3 cross(const vec3& u, const vec3& v) {
	return vec3(
		u.y() * v.z() - u.z() * v.y(),
		u.z() * v.x() - u.x() * v.z(),
		u.x() * v.y() - u.y() * v.x());
}

inline vec3 unit_vector(vec3 v) {
	return v / v.length();
}

#endif // VEC3_H
