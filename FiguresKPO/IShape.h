#pragma once
class IShape
{
public:
	virtual ~IShape() = default;
	virtual double GetArea()const = 0;
	virtual double GetPerimeter()const = 0;
	virtual std::string PrintInfo() const = 0;
};

struct SPoint
{
	SPoint(double x, double y)
		:x(x), y(y)
	{
	}
	double x;
	double y;
};

