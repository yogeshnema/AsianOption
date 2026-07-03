// AsianOption.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <print>
#include <vector>
#include <memory>
#include <cmath>

#include "Asian.h"
#include "payoff.h"
#include "path_generation.h"

int main()
{
	const unsigned num_sims = 100000;
	const unsigned num_intervals = 250;

	const double S = 30;
	const double K = 29;
	const double r = 0.04;
	const double v = 0.3;
	const double T = 1.0;

	std::vector<double> spot_prices(num_intervals , S);

	auto payoffCall = std::make_unique<PayOffCall>(K);
	AsianOptionArithmetic asianOption(std::move(payoffCall));

	double payoff_sum = 0.0;
	for(unsigned i=0; i<num_sims; ++i) {
		calc_path_spot_prices(spot_prices, r, v, T);
		payoff_sum += asianOption.pay_off_price(spot_prices);
	}

	double discounted_payoff_avg = std::exp(-r * T) * (payoff_sum / static_cast<double>(num_sims));
}
