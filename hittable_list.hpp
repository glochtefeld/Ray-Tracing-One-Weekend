#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H
#pragma once

#include <memory>
#include <vector>
#include "hittable.hpp"

class hittable_list : public hittable {
public:
	std::vector<std::shared_ptr<hittable>> objects;
public:
	hittable_list() = default;
	hittable_list(std::shared_ptr<hittable> object);
	void clear();
	void add(std::shared_ptr<hittable>);
	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;
};

#endif // HITTABLE_LIST_H