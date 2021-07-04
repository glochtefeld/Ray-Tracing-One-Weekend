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
void PPM::WriteColor(color pixel, int samples_per_pixel) {
	auto r = pixel.x();
	auto g = pixel.y();
	auto b = pixel.z();

	auto scale = 1.0 / samples_per_pixel;
	r *= sqrt(scale);
	g *= sqrt(scale);
	b *= sqrt(scale);

	file << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
		<< static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
		<< static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}

auto PPM::Width() const -> int {
	return width;
}

auto PPM::Height() const -> int {
	return height;
}