// FiguresKPO.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "IShape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include <functional>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <sstream>

namespace
{
	


	void OutputResult(const std::vector<std::shared_ptr<IShape>>& figures)
	{
		for (auto shape : figures)
		{
			std::cout << "Area: " << shape->GetArea() << std::endl << "Perimeter: " << shape->GetPerimeter() << std::endl;
		}
	}

	void ParseLine(const std::string& line, std::vector<std::shared_ptr<IShape>>& figures)
	{
		std::stringstream stream(line);
		std::vector<std::string> splittedString
		{
			std::istream_iterator<std::string>(stream),{}
		};
		std::string figureType = splittedString[0];

		if (splittedString[0] == "TRIANGLE")
		{
			SPoint point1 = SPoint(std::stod(splittedString[1]), std::stod(splittedString[2]));
			SPoint point2 = SPoint(std::stod(splittedString[3]), std::stod(splittedString[4]));
			SPoint point3 = SPoint(std::stod(splittedString[5]), std::stod(splittedString[6]));
			figures.push_back(std::make_shared<CTriangle>(CTriangle(point1, point2, point3)));
		}
		else if (splittedString[0] == "RECTANGLE")
		{
			SPoint point1 = SPoint(std::stod(splittedString[1]), std::stod(splittedString[2]));
			SPoint point2 = SPoint(std::stod(splittedString[3]), std::stod(splittedString[4]));
			figures.push_back(std::make_shared<CRectangle>(CRectangle(point1, point2)));
		}
		else if (splittedString[0] == "CIRCLE")
		{
			SPoint point1 = SPoint(std::stod(splittedString[1]), std::stod(splittedString[2]));
			double radius = std::stod(splittedString[3]);
			figures.push_back(std::make_shared<CCircle>(CCircle(point1, radius)));
		}
	}

	void Pasre(std::string m_fileName)
	{
		std::ifstream inFile(m_fileName);
		std::vector<std::shared_ptr<IShape>> figures;
		for (std::string line; std::getline(inFile, line);)
		{
			ParseLine(line, figures);
		}
		OutputResult(figures);
	}
	
}

int main()
{
	Pasre("../input.txt");
	return 0;
}