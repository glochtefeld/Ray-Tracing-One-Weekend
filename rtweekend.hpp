#ifndef RTWEEKEND_H
#define RTWEEKEND_H
#pragma once

#include <cmath>
#include <random>
#include <limits>
#include <memory>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
	return degrees * pi / 180.0;
}

inline double random_double(double min=0, double max=1) { // [min,max)
	static std::uniform_real_distribution<double> distribution(min, max);
	static std::mt19937 generator;
	return distribution(generator);
}

inline double clamp(double x, double min, double max) {
	return x < min ? min : x > max ? max : x;
}
#endif // !RTWEEKEND_H

