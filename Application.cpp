#include <iostream>
#include <vector>
#include "vec3.hpp"
#include "ppm.hpp"
#include "ray.hpp"

auto parse_args(int argc, char* argv[]) -> std::vector<std::string>;

color ray_color(const ray& r) {
	auto t = hit_sphere(point3(0, 0, -1), 0.5, r);
	if (t > 0.0) {
		vec3 N = unit_vector(r.at(t) - vec3(0, 0, -1));
		return 0.5 * color(N.x() + 1, N.y() + 1, N.z() + 1);
	}

	vec3 unit_direction = unit_vector(r.direction());
	t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

auto main(int argc, char* argv[]) -> int {
	try {
		auto args = parse_args(argc, argv);
		
		// Image
		const auto aspect_ratio = 16.0 / 9.0;
		const int width = 400;
		const int height = static_cast<int> (width / aspect_ratio);

		PPM p{ args[1], height, width };

		// Camera 
		auto viewport_height = 2.0;
		auto viewport_width = aspect_ratio * viewport_height;
		auto focal_length = 1.0;

		auto origin = point3{ 0,0,0 };
		auto horz = vec3{ viewport_width, 0, 0 };
		auto vert = vec3{ 0, viewport_height, 0 };
		auto lower_left_corner = origin - (horz / 2) - (vert / 2) - vec3{ 0,0,focal_length };

		// Render
		for (int j = p.Height() - 1; j >= 0; --j) {
			std::cerr << "\rScanlines remaining: " << j << std::flush;
			for (int i = 0; i < p.Width(); ++i) {
				auto u = double(i) / (p.Width() - 1);
				auto v = double(j) / (p.Height() - 1);
				ray r(origin, lower_left_corner + u * horz + v * vert - origin);
				color pixel_color = ray_color(r);
				p.WriteColor(pixel_color);
			}
		}
		std::cerr << "\nDone.\n";
	}
	catch (...) {
		return -1;
	}
	return 0;
}

auto parse_args(int argc, char* argv[])-> std::vector<std::string> {
	if (argc != 2) {
		std::cerr << "Put a filename after you call the program. Buffoon." << std::endl;
		throw "WHAT.";
	}
	std::vector<std::string> args(argv, argv + argc);
	return args;
}