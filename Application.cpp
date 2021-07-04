#include <iostream>
#include <vector>
#include <thread>
#include "rtweekend.hpp"
#include "ppm.hpp"
#include "hittable_list.hpp"
#include "sphere.hpp"
#include "camera.hpp"
#include "vec3.hpp"
#include "material.hpp"


auto parse_args(int argc, char* argv[]) -> std::vector<std::string>;

color ray_color(const ray& r, const hittable& world, int depth) {
	hit_record rec;
	if (depth <= 0)
		return color(0, 0, 0);

	if (world.hit(r, 0.001, infinity, rec)) {
		ray scattered;
		color attenuation;
		if (rec.mat_ptr->scatter(r, rec, attenuation, scattered))
			return attenuation * ray_color(scattered, world, depth - 1);
		return color(0, 0, 0);
	}
	vec3 unit_direction = unit_vector(r.direction());
	auto t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

auto main(int argc, char* argv[]) -> int {
	try {
		auto args = parse_args(argc, argv);
		
		// multithreading
		const int cores = 12;


		// Image
		const auto aspect_ratio = 16.0 / 9.0;
		const int width = 400;
		const int height = static_cast<int> (width / aspect_ratio);
		const int samples_per_pixel = 100;
		const int max_depth = 50;

		PPM p{ args[1], height, width };

		// World
		hittable_list world;

		auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
		auto material_center = make_shared<lambertian>(color(0.7, 0.3, 0.3));
		auto material_left = make_shared<metal>(color(0.8, 0.8, 0.8));
		auto material_right = make_shared<metal>(color(0.8, 0.6, 0.2));

		world.add(make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0, material_ground));
		world.add(make_shared<sphere>(point3(0.0, 0.0, -1.0), 0.5, material_center));
		world.add(make_shared<sphere>(point3(-1.0, 0.0, -1.0), 0.5, material_left));
		world.add(make_shared<sphere>(point3(1.0, 0.0, -1.0), 0.5, material_right));

		// Camera 
		camera cam;

		// Render
		for (int j = p.Height() - 1; j >= 0; --j) {
			std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
			for (int i = 0; i < p.Width(); ++i) {
				color pixel_color(0, 0, 0);
				
				for (int s = 0; s < samples_per_pixel; ++s) {
					auto u = (i + random_double()) / (p.Width() - 1);
					auto v = (j + random_double()) / (p.Height() - 1);
					ray r = cam.get_ray(u, v);
					pixel_color += ray_color(r, world, max_depth);
				}
				p.WriteColor(pixel_color,samples_per_pixel);
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