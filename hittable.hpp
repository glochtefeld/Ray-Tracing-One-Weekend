#ifndef HITTABLE_H
#define HITTABLE_H
#pragma once
#include "rtweekend.hpp"
#include "hit_record.hpp"
#include "ray.hpp"

class material;

class hittable {
public:
	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};
#endif //HITTABLE_H