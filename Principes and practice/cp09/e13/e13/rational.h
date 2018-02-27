#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <iostream>

using std::endl;
using std::cout;

int nwd(int a, int b);
int nww(int a, int b);

class Rational
{
private:
	int numerator;
	int denominator;
public:
	class Invalid
	{};
	Rational(int a = 0, int b = 1);
	double get_d() const;
	void show() const;
	Rational operator+(const Rational& r);
};

Rational::Rational(int a, int b) : numerator(a), denominator(b)
{
	if (b == 0)
		throw Invalid();
}

double Rational::get_d() const
{
	return static_cast<double>(numerator) / static_cast<double>(denominator);
}

Rational Rational::operator+(const Rational& r)
{
	int den = nww(denominator, r.denominator);
	int a = numerator * den / denominator;
	int b = r.numerator * den /r.denominator;

	return Rational(a + b, den);
}

void Rational::show() const
{
	cout << numerator << endl;
	cout << denominator << endl;
}

int nwd(int a, int b)
{
	int n;
	if (b == 0)
		n = a;
	else
		n = nwd(b, a%b);
	return n;
}

int nww(int a, int b)
{
	return a*b / nwd(a, b);
}

#endif // !RATIONAL_H_
