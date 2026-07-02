#include "payoff.h"
#include <algorithm>

PayOffCall::PayOffCall(double _E) noexcept : E(_E) {};


double PayOffCall::operator()(const double& S) const noexcept{
	return std::max(S - E, 0.0);
}

PayOffPut::PayOffPut(double _E) noexcept : E(_E) {};


double PayOffPut::operator()(const double& S) const noexcept {
	return std::max(E - S, 0.0);
}