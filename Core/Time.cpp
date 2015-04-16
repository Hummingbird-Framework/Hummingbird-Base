#include "Time.h"
using namespace bienne;

Time Time::deltaTime = Time::microseconds(0);

Time::Time():
m_microseconds(0)
{

}


Time::~Time()
{}


double Time::asSeconds() const
{
	return (double)m_microseconds/1e6;
}


int Time::asMilliseconds() const
{
	return m_microseconds/1000;
}


long long Time::asMicroseconds() const
{
	return m_microseconds;
}


Time Time::seconds(double seconds)
{
	Time t;
	t.m_microseconds = (long long)(seconds * 1e6);
	return t;
}


Time Time::milliseconds(int milliseconds)
{
	Time t;
	t.m_microseconds = milliseconds * 1000;
	return t;
}


Time Time::microseconds(long long microseconds)
{
	Time t;
	t.m_microseconds = microseconds;
	return t;
}


bool operator ==(bienne::Time left, bienne::Time right)
{
	return left.asMicroseconds() == right.asMicroseconds();
}


bool operator !=(bienne::Time left, bienne::Time right)
{
	return left.asMicroseconds() != right.asMicroseconds();
}


bool operator <(bienne::Time left, bienne::Time right)
{
	return left.asMicroseconds() < right.asMicroseconds();
}


bool operator >(bienne::Time left, bienne::Time right)
{
	return left.asMicroseconds() > right.asMicroseconds();
}


bool operator <=(bienne::Time left, bienne::Time right)
{
	return left.asMicroseconds() <= right.asMicroseconds();
}


bool operator >=(bienne::Time left, bienne::Time right)
{
	return left.asMicroseconds() >= right.asMicroseconds();
}


bienne::Time operator -(bienne::Time right)
{
	return Time::microseconds(-right.asMicroseconds());
}


bienne::Time operator +(bienne::Time left, bienne::Time right)
{
	return Time::microseconds(left.asMicroseconds() + right.asMicroseconds());
}


bienne::Time & operator +=(bienne::Time &left, bienne::Time right)
{
	left = left + right;
	return left;
}


bienne::Time operator -(bienne::Time left, bienne::Time right)
{
	return Time::microseconds(left.asMicroseconds() - right.asMicroseconds());
}


bienne::Time & operator -=(bienne::Time &left, bienne::Time right)
{
	left = left - right;
	return left;
}


bienne::Time operator *(bienne::Time left, double right)
{
	return Time::microseconds(left.asMicroseconds() * right);
}


bienne::Time operator *(bienne::Time left, long long right)
{
	return Time::microseconds(left.asMicroseconds() * right);
}


bienne::Time operator *(double left, bienne::Time right)
{
	return Time::microseconds(left * right.asMicroseconds());
}


bienne::Time operator *(long long left, bienne::Time right)
{
	return Time::microseconds(left * right.asMicroseconds());
}


bienne::Time & operator *=(bienne::Time &left, double right)
{
	left = left * right;
	return left;
}


bienne::Time & operator *=(bienne::Time &left, long long right)
{
	left = left * right;
	return left;
}


bienne::Time operator /(bienne::Time left, double right)
{
	return Time::microseconds(left.asMicroseconds() / right);
}


bienne::Time operator /(bienne::Time left, long long right)
{
	return Time::microseconds(left.asMicroseconds() / right);
}


bienne::Time & operator /=(bienne::Time &left, double right)
{
	left = left / right;
	return left;
}


bienne::Time & operator /=(bienne::Time &left, long long right)
{
	left = left / right;
	return left;
}


double operator /(bienne::Time left, bienne::Time right)
{
	return (double)left.asMicroseconds() / (double)right.asMicroseconds();
}


bienne::Time operator %(bienne::Time left, bienne::Time right)
{
	return Time::microseconds(left.asMicroseconds() % right.asMicroseconds());
}


bienne::Time & operator %=(bienne::Time &left, bienne::Time right)
{
	left = left % right;
	return left;
}
