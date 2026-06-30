#pragma once

#include <algorithm>
#include <memory>

class PayOff {
protected:
	double strike; // strike price

public:
	PayOff() = default;
	virtual ~PayOff() = default;

	[[nodiscard]] virtual double computeFixed(double mean) const noexcept = 0;
	[[nodiscard]] virtual double computeFloat(double mean, double spot) const noexcept = 0;
};

class PayOffCall : public PayOff {
	public:
		explicit PayOffCall(double E) noexcept;
		~PayOffCall() override = default;

		[[nodiscard]] double computeFixed(double mean) const noexcept override;
		[[nodiscard]] double computeFloat(double mean, double spot) const noexcept override;
};
