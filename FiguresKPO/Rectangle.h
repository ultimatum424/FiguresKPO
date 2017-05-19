#pragma once
#include "IShape.h"

class CRectangle :
	public IShape
{
public:
	CRectangle(const SPoint & point1, const SPoint & point2);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string PrintInfo() const override;
private:
	SPoint m_point1;
	SPoint m_point2;
};

