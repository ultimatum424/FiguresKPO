#pragma once
#include <vector>

class CBigInt
{
public:
	static const unsigned int BASE = 10;
	CBigInt();
	CBigInt(const int num);
	bool IsPositive() const;
	void SetSing(const bool isPositiveSing);
	

	
	CBigInt& CBigInt::operator=(const CBigInt& num);
	CBigInt CBigInt::operator+() const;
	CBigInt CBigInt::operator-() const;
	void ShiftDigit();

	std::vector<int> m_digits;
	~CBigInt();
private:
	
	bool m_isPositive = true;


};


std::ostream& operator<<(std::ostream& stream, CBigInt & num);
std::istream & operator>>(std::istream & stream, CBigInt & num);

bool operator==(const CBigInt& left, const CBigInt& right);
bool operator!=(const CBigInt& left, const CBigInt& right);
bool operator>(const CBigInt& left, const CBigInt& right);
bool operator<(const CBigInt& left, const CBigInt& right);

CBigInt const operator+ (const CBigInt& first, const CBigInt& second);
CBigInt const operator- (const CBigInt& first, const CBigInt& second);
CBigInt const operator* (const CBigInt& first, const CBigInt& second);
CBigInt const operator/ (const CBigInt& first, const CBigInt& second);





