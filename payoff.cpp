#include "payoff.h"

PayOffCall::PayOffCall(double E) noexcept {
	strike = E;
}

double PayOffCall::computeFixed(double mean) const noexcept {
	return std::max(mean - strike, 0.0);
}

double PayOffCall::computeFloat(double mean, double spot) const noexcept {
	return std::max(spot - strike, 0.0);
}
