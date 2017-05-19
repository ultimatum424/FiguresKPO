#include "stdafx.h"
#include "Triangle.h"



CTriangle::CTriangle(const SPoint& point1, const SPoint& point2, const SPoint& point3)
	:m_point1(point1),
	m_point2(point2),
	m_point3(point3)
{
}

double CTriangle::GetArea() const
{
	double a = sqrt(pow((m_point1.x - m_point2.x), 2) + pow((m_point1.y - m_point2.y), 2));
	double b = sqrt(pow((m_point1.x - m_point3.x), 2) + pow((m_point1.y - m_point3.y), 2));
	double c = sqrt(pow((m_point2.x - m_point3.x), 2) + pow((m_point2.y - m_point3.y), 2));
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double CTriangle::GetPerimeter() const
{
	double a = sqrt(pow((m_point1.x - m_point2.x), 2) + pow((m_point1.y - m_point2.y), 2));
	double b = sqrt(pow((m_point1.x - m_point3.x), 2) + pow((m_point1.y - m_point3.y), 2));
	double c = sqrt(pow((m_point2.x - m_point3.x), 2) + pow((m_point2.y - m_point3.y), 2));
	return a + b + c;
}

std::string CTriangle::PrintInfo() const
{
	std::string outStroing = "TRIANGLE: P=" + std::to_string(GetPerimeter());
	outStroing += "; S=" + std::to_string(GetArea());
	return outStroing;
}
