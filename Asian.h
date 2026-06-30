#pragma once

#include <vector>
#include <memory>

#include "payoff.h"

class AsianOption {
protected:
	std::unique_ptr<PayOff> payoff; // payoff function
public:

	explicit AsianOption(std::unique_ptr<PayOff> _payoff) noexcept;

	virtual ~AsianOption() = default;

	[[nodiscard]] virtual double pay_off_price(const std::vector<double>& spot_prices) const noexcept = 0;
};

class AsianOptionArithmetic : public AsianOption {
public:
	explicit AsianOptionArithmetic(std::unique_ptr<PayOff> _payoff) noexcept;
	~AsianOptionArithmetic() override = default;
	[[nodiscard]] double pay_off_price(const std::vector<double>& spot_prices) const noexcept override;
};

class AsianOptionGeometric : public AsianOption {
public:
	explicit AsianOptionGeometric(std::unique_ptr<PayOff> _payoff) noexcept;
	~AsianOptionGeometric() override = default;
	[[nodiscard]] double pay_off_price(const std::vector<double>& spot_prices) const noexcept override;
};

