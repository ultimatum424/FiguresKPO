// FiguresKPO.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "BigInt.h"
#include <iostream>


int main()
{
	CBigInt a;
	CBigInt b;
	
	std::cin >> a;
	std::cin.clear();
	std::cin >> b;

	CBigInt c = a / b;
	std::cout << c << std::endl;
    return 0;
}

