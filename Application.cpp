#include <iostream>
#include <string>
#include <sstream>
#include "vec3.hpp"

class PPM {
public:
	std::string source{};
	int height{};
	int width{};
public:
	PPM(int h, int w) : height{ h }, width{ w } {
		source.append("P3\n" + std::to_string(w) + ' ' + std::to_string(h) + "\n255\n");
	};
	PPM(const PPM& other) : source{ other.source } {};
	void WriteLine(const std::string& other) {
		source.append(other);
	}
	void WriteColor(color pixel) {
		std::stringstream ss;
		ss << static_cast<int>(255.999 * pixel.x()) << ' '
			<< static_cast<int>(255.999 * pixel.y()) << ' '
			<< static_cast<int>(255.999 * pixel.z()) << '\n';
		source.append(ss.str());
	}
};

int main() {
	PPM p{ 256, 256 };
	for (int j = p.height - 1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << std::flush;
		for (int i = 0; i < p.width; ++i) {
			auto r = double(i) / (p.width - 1);
			auto g = double(j) / (p.height - 1);
			auto b = 0.25;

			color pixel_color{ double(i) / (p.width - 1),double(j) / (p.height - 1),0.25 };
			p.WriteColor(pixel_color);
		}
	}
	std::cout << p.source;
	std::cerr << "\nDone.\n";

}