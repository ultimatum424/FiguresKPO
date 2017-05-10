#include "stdafx.h"
#include "BigInt.h"
#include <iostream>
#include <string>
#include <algorithm>
CBigInt::CBigInt()
{
	m_digits.resize(0, 1);
}

CBigInt::CBigInt(const int size)
{
	m_digits.resize(0, size);
}

bool CBigInt::IsPositive() const
{
	return  m_isPositive;
}

CBigInt& CBigInt::operator=(const CBigInt& num)
{
	this->m_isPositive = num.IsPositive();
	this->m_digits = num.m_digits;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, CBigInt& num)
{
	if (!num.IsPositive())
	{
		stream << "-";
	}
	std::reverse(num.m_digits.begin(), num.m_digits.end());
	for (int i : num.m_digits)
	{
		stream << i;
	}
	return stream;
}

std::istream & operator>>(std::istream & stream, CBigInt & num)
{
	std::string str;
	try
	{
		if (stream >> str)
		{
			int len = CBigInt::BASE;
			auto temp = std::to_string(len);
			len = std::count(temp.crbegin(), temp.crend(), '0');
			num.m_digits.clear();
			if (str[0] == '-')
			{
				num.SetSing(false);
				str.erase(str.begin());
			}
			for (size_t i = str.size() - 1; i >= 0; i -= len)
			{
				size_t start = i - len + 1;
				if (start < 0)
				{
					start = 0;
				}
				std::string digit = str.substr(start, i - start + 1);
				if (std::to_string(atoi(digit.c_str())) != digit)
				{
					throw std::logic_error("It is not number");
				}
				num.m_digits.push_back(atoi(digit.c_str()));			
			}
		}
	}
	catch (const std::exception& e)
	{
		stream.setstate(std::ios::failbit);
	}
	return stream;
}

bool operator==(const CBigInt& left, const CBigInt& right)
{
	if (left.m_digits.size() != right.m_digits.size())
	{
		return  false;
	}
	for (size_t i = 0; i < std::min(left.m_digits.size(), right.m_digits.size()); i++)
	{
		if (left.m_digits[i] != right.m_digits[i])
		{
			return  false;
		}
	}
	return true;
}

bool operator!=(const CBigInt& left, const CBigInt& right)
{
	return !(left == right);
}

bool operator>(const CBigInt& left, const CBigInt& right)
{
	if (left.m_digits.size() != right.m_digits.size())
	{
		return left.m_digits.size() > right.m_digits.size();
	}
	for (size_t i = left.m_digits.size() - 1; i >= 0; i--)
	{
		if (left.m_digits[i] != right.m_digits[i])
			return left.m_digits[i] > right.m_digits[i];
	}
	return false;
}

bool operator<(const CBigInt& left, const CBigInt& right)
{
	if ((left > right) || (left == right))
	{
		return  false;
	}
	return  true;
}

CBigInt CBigInt::operator+() const
{
	return *this;
}

CBigInt CBigInt::operator-() const
{
	CBigInt result = *this;
	result.SetSing(!result.m_isPositive);
	return result;
}

CBigInt const operator+(const CBigInt& first, const CBigInt& second)
{
	CBigInt result;
	CBigInt min;
	if (first > second)
	{
		result = first;
		min = second;

	}
	else
	{
		result = second;
		min = first;
	}

	unsigned int fCarry = 0;
	for (size_t i = 0; i < min.m_digits.size(); i++)
	{
		result.m_digits[i] = (result.m_digits[i] + min.m_digits[i] + fCarry);
		if (result.m_digits[i] >= CBigInt::BASE)
		{
			result.m_digits[i] -= CBigInt::BASE;
			fCarry = 1;
		}
		else
		{
			fCarry = 0;
		}
	}
	if (fCarry)
	{
		result.m_digits.push_back(fCarry);
	}
	return result;
}

CBigInt const operator-(const CBigInt& first, const CBigInt& second)
{
	if (!first.IsPositive())
	{
		return first + (-second);
	}
	else if (!second.IsPositive())
	{ 
		return -(-first + second);
	}
	else if (first < second)
	{
		return -(first - second);
	}
	unsigned int fCarry = 0;
	CBigInt result = first;
	for (size_t i = 0; i < second.m_digits.size() || fCarry != 0; i++)
	{
		result.m_digits[i] -= fCarry;
		if (i < second.m_digits.size())
		{
			result.m_digits[i] -= second.m_digits[i];
		}
		fCarry = (result.m_digits[i] < 0);
		if (fCarry)
		{
			result.m_digits[i] += CBigInt::BASE;
		}
	}

	while (result.m_digits.size() > 1 && result.m_digits.back() == 0)
	{
		result.m_digits.pop_back();
	}
	if (result.m_digits.size() == 1 && result.m_digits[0] == 0)
	{
		result.SetSing(true);
	}

	return result;
}


CBigInt::~CBigInt()
{
}

void CBigInt::SetSing(const bool isPositiveSing)
{
	m_isPositive = isPositiveSing;
}
