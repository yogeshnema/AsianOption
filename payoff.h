#pragma once

#include <algorithm>
#include <memory>

class PayOff {

public:
	PayOff() = default;
	virtual ~PayOff() = default;
	[[nodiscard]] virtual double operator()(const double& S) const noexcept = 0;
};

class PayOffCall : public PayOff {
private:
	double E;

public:
		explicit PayOffCall(double E) noexcept;
		~PayOffCall() override = default;

		[[nodiscard]] double operator()(const double& S) const noexcept override;
};

class PayOffPut : public PayOff {

private:
	double E;

public:
	explicit PayOffPut(double E) noexcept;
	~PayOffPut() override = default;

	[[nodiscard]] double operator()(const double& S) const noexcept override;
};

