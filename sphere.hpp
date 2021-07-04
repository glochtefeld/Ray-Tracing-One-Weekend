#ifndef SPHERE_H
#define SPHERE_H
#pragma once
#include "rtweekend.hpp"
#include "hittable.hpp"
#include "hit_record.hpp"
#include "vec3.hpp"

class sphere : public hittable
{
public:
	point3 center;
	double radius;
	shared_ptr<material> mat_ptr;
public:
	sphere() = default;
	sphere(point3 cen, double r, shared_ptr<material> m) : center(cen), radius(r), mat_ptr(m) {};
	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;
};
#endif // SPHERE_H