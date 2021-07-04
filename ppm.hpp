#ifndef PPM_H
#define PPM_H
#pragma once
#include <fstream>
#include <string>
#include "rtweekend.hpp"
#include "vec3.hpp"

class PPM {
private:
	const std::string name;
	const int height;
	const int width;
	std::ofstream file;
public:
	PPM(const std::string&, int, int);
	~PPM();
	void WriteLine(const std::string& other);
	void WriteColor(color pixel, int samples);
	auto Height() const -> int;
	auto Width() const -> int;
};
#endif // PPM_H