// FiguresKPO.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "BigInt.h"
#include <iostream>
#include <fstream>
#include <string>

namespace
{

	void WowrkWithFile(const std::string& filename)
	{
		std::ifstream fin(filename);
		std::ofstream fout("../output.txt");
		std::string firstStr;
		std::string operand;
		std::string secondStr;
		while (!fin.eof())
		{
			fin >> firstStr;
			fin >> operand;
			fin >> secondStr;
			CBigInt first(firstStr);
			CBigInt second(secondStr);
			if (operand == "+")
			{
				CBigInt result = first + second;
				fout << firstStr << operand << secondStr << "=" << result << "\n";
			}

			else if (operand == "-")
			{
				CBigInt result = first - second;
				fout << firstStr << operand << secondStr << "=" << result << "\n";
			}

			else if (operand == "*")
			{
				CBigInt result = first * second;
				fout << firstStr << operand << secondStr << "=" << result << "\n";
			}

			else if (operand == "/")
			{
				try
				{
					CBigInt result = first / second;
					fout << firstStr << operand << secondStr << "=" << result << "\n";
				}
				catch (...)
				{
					fout << "Divison by Zero \n";
				}
				
			}
			else
			{
				fout << "unknow operand \n";
			}
		}
	}
}

int main()
{
	//CBigInt a;
//	CBigInt b;
	//ReadFormFile(a, b);
	//CBigInt c = a / b;
	//std::cout << c << std::endl;
	//WriteToFile(c);
	WowrkWithFile("../input.txt");
    return 0;
}

