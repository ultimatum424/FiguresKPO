#include "stdafx.h"
#include "Circle.h"


CCircle::CCircle(const SPoint& point, const double radius)
	:m_point(point),
	m_radius(radius)
{
}

double CCircle::GetArea() const
{
	return M_PI * pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

std::string CCircle::PrintInfo() const
{
	std::string outStroing = "CIRCLE: P=" + std::to_string(GetPerimeter());
	outStroing += "; S=" + std::to_string(GetArea());
	return outStroing;
}

