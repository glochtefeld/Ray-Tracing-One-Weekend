#ifndef CAMERA_H
#define CAMERA_H
#pragma once

#include "rtweekend.hpp"
#include "vec3.hpp"
#include "ray.hpp"

class camera
{
private:
	point3 origin;
	point3 lower_left_corner;
	vec3 horizontal;
	vec3 vertical;
public:
	camera();
	ray get_ray(double u, double v) const;
};

#endif // CAMERA_H
