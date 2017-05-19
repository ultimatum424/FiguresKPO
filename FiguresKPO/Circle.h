#pragma once
#include "IShape.h"

class CCircle :
	public IShape
{
public:
	CCircle(const SPoint & point, const double radius);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string PrintInfo() const override;
private:
	SPoint m_point;
	double m_radius;
};

