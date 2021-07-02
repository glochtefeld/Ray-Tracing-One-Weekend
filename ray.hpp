#ifndef RAY_H
#define RAY_H
#pragma once
#include "vec3.hpp"
class ray
{
private:
	point3 orig;
	vec3 dir;
public:
	ray() {}
	ray(const point3&, const vec3&);
	point3 origin() const;
	vec3 direction() const;
	point3 at(double) const;
};
#endif // RAY_H