#ifndef HIT_RECORD_H
#define HIT_RECORD_H
#include "rtweekend.hpp"
#include "vec3.hpp"
#include "ray.hpp"

class material;

struct hit_record {
	point3 p;
	vec3 normal;
	shared_ptr<material> mat_ptr;
	double t;
	bool front_face;

	inline void set_face_normal(const ray& r, const vec3& outward_normal) {
		front_face = dot(r.direction(), outward_normal) < 0;
		normal = front_face ? outward_normal : -outward_normal;
	}
};
#endif // HIT_RECORD_H
