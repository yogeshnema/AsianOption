#include <numeric>
#include <cmath>

#include "Asian.h"

AsianOption::AsianOption(std::unique_ptr<PayOff> _payoff) noexcept : pay_off(std::move(_payoff)) {}

AsianOptionArithmetic::AsianOptionArithmetic(std::unique_ptr<PayOff> _payoff) noexcept : AsianOption(std::move(_payoff)) {}

double AsianOptionArithmetic::pay_off_price(const std::vector<double>& spot_prices) const noexcept {
	std::size_t num_times = spot_prices.size();
	double sum = std::accumulate(spot_prices.begin(), spot_prices.end(), 0.0) ;
	double arit_mean = sum / static_cast<double>(num_times);
	return (*pay_off)(arit_mean);
}
