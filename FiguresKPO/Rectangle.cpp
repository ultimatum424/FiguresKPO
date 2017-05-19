#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(const SPoint& point1, const SPoint& point2)
	:m_point1(point1),
	m_point2(point2)
{
}

double CRectangle::GetPerimeter() const
{
	double a = abs(m_point1.x - m_point2.x);
	double b = abs(m_point1.y - m_point2.y);
	return 2 * (a + b);	
}

double CRectangle::GetArea() const
{
	double a = abs(m_point1.x - m_point2.x);
	double b = abs(m_point1.y - m_point2.y);
	return a * b;
}

std::string CRectangle::PrintInfo() const
{
	std::string outStroing = "RECTANGLE: P=" + std::to_string(GetPerimeter());
	outStroing += "; S=" + std::to_string(GetArea());
	return outStroing;
}


