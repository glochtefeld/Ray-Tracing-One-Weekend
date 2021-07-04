#include "ppm.hpp"

PPM::PPM(const std::string& path, int h, int w) : name{ path }, height{ h }, width{ w } {
	file.open(name);
	file << "P3\n" << w << ' ' << h << "\n255\n";
};
PPM::~PPM() {
	file.close();
}
void PPM::WriteLine(const std::string& other) {
	file << other;
}
void PPM::WriteColor(color pixel) {
	file << static_cast<int>(255.999 * pixel.x()) << ' '
		<< static_cast<int>(255.999 * pixel.y()) << ' '
		<< static_cast<int>(255.999 * pixel.z()) << '\n';
}

auto PPM::Width() const -> int {
	return width;
}

auto PPM::Height() const -> int {
	return height;
}