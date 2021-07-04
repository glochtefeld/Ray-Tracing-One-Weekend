#ifndef MATERIAL_H
#define MATERIAL_H
#pragma once

#include "vec3.hpp"
#include "ray.hpp"
#include "hit_record.hpp"
struct hit_record;

class material
{
public:
	virtual bool scatter(
		const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
	) const = 0;
};

class lambertian : public material {
public:
	color albedo;
public:
	lambertian(const color& a) : albedo(a) {}
	virtual bool scatter(
		const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
	) const override;
};

class metal : public material {
public:
	color albedo;
public:
	metal(const color& a) : albedo(a) {}
	virtual bool scatter(
		const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
	) const override;
};
#endif // MATERIAL_H