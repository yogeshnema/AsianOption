#pragma once

#include <vector>
#include <cmath>
#include <random>


inline double gaussian_box_muller() noexcept {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_real_distribution<> dist(0.0, 1.0);

	double x = 0.0, y = 0.0, euclid_sq = 0.0;

	do {
		x = dist(gen) * 2 - 1;
		y = dist(gen) * 2 - 1;
		euclid_sq = x * x + y * y;
	} while (euclid_sq >= 1.0 || euclid_sq == 0.0);

	return x * std::sqrt(-2 * std::log(euclid_sq) / euclid_sq);
}

inline void calc_path_spot_prices(std::vector<double>& spot_prices,
	double r,
	double sigma,
	double T
) noexcept {

	if (spot_prices.size() < 2) return;

	double dt = T / static_cast<double>(spot_prices.size()-1);
	
	double drift = std::exp(dt * (r - 0.5 * sigma * sigma));
	double vol = std::sqrt(sigma * sigma* dt);

	for (std::size_t i = 1; i < spot_prices.size(); ++i) {
		double gauss_BM = gaussian_box_muller();
		spot_prices[i] = spot_prices[i - 1] * drift*std::exp(vol*gauss_BM);
	}
}