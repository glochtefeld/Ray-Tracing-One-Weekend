#ifndef SPHERE_H
#define SPHERE_H
#pragma once
#include "hittable.hpp"
#include "vec3.hpp"

class sphere : public hittable
{
public:
	point3 center;
	double radius;
public:
	sphere() = default;
	sphere(point3 cen, double r) : center{ cen }, radius{ r } {};
	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;
};
#endif // SPHERE_H