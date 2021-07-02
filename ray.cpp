#include "ray.hpp"
ray::ray(const point3& origin, const vec3& direction) : orig{ origin }, dir{ direction } {}
point3 ray::origin() const { return orig; }
vec3 vec3::direction() const { return dir; }
point3 vec3::at(double t) const {
	return orig + t * dir;
}