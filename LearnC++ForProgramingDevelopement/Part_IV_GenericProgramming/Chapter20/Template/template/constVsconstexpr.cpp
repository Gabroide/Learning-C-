const double constValue = sin(0.5);
constexpr double constexprValue = sin(0.5);

void ConstFunction(double value)
{
	const double constValue = value;
	constexpr double constexprValue = value;
}