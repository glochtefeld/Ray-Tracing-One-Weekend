#include "vec3.hpp"

double vec3::x() const { return e[0]; }
double vec3::y() const { return e[1]; }
double vec3::z() const { return e[2]; }

vec3 vec3::operator-() const { return vec3(-e[0], -e[1], -e[2]); }
double vec3::operator[](int i) const { return e[i]; }
vec3& vec3::operator+=(const vec3& v) {
	e[0] += v.x();
	e[1] += v.y();
	e[2] += v.z();
	return *this;
}
vec3& vec3::operator*=(const double t) {
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}
vec3& vec3::operator/=(const double t) {
	return *this *= 1 / t;
}
double vec3::length() const {
	return sqrt(length_squared());
}
double vec3::length_squared() const {
	return e[0] * e[0]
		+ e[1] * e[1]
		+ e[2] * e[2];
}
bool vec3::near_zero() const {
	const auto s = 1e-8;
	return (fabs(e[0]) < s) && (fabs(e[1]) < s && (fabs(e[2]) < s));
}


auto random_in_unit_sphere()->vec3 {
	while (true) {
		auto p = rand_vec3(-1, 1);
		if (p.length_squared() >= 1) continue;
		return p;
	}
}

auto random_unit_vector()->vec3 {
	return unit_vector(random_in_unit_sphere());
}

auto random_in_hemisphere(const vec3& normal)->vec3 {
	vec3 in_unit_sphere = random_in_unit_sphere();
	if (dot(in_unit_sphere, normal) > 0.0)
		return in_unit_sphere;
	else
		return -in_unit_sphere;
}

vec3 reflect(const vec3& v, const vec3& n) {
	return v - 2 * dot(v, n) * n;
}