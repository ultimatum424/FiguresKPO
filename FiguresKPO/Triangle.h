#pragma once
#include "IShape.h"

class CTriangle : public IShape
{
public:
	CTriangle(const SPoint & point1, const SPoint & point2, const SPoint & point3);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string PrintInfo() const override;
private:
	SPoint m_point1;
	SPoint m_point2;
	SPoint m_point3;

};

