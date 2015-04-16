#ifndef HB_TIME_H
#define HB_TIME_H

namespace bienne
{
	/*!
	  \class Time
	  \ingroup core
	  \brief Class for representing intervals of time.

	  This class has microseconds precision.
	*/
	class Time
	{
	public:
		/*!
		  \brief Default constructor.
		*/
		Time();
		/*!
		  \brief Class destructor.
		*/
		~Time();
		/*!
		  \brief Get Time as seconds.
		  \return Number of seconds represented.
		*/
		double asSeconds() const;
		/*!
		  \brief Get Time as milliseconds.
		  \return Number of milliseconds represented.
		*/
		int asMilliseconds() const;
		/*!
		  \brief Get Time as microseconds.
		  \return Number of microseconds represented.
		*/
		long long asMicroseconds() const;

		/*!
		  \brief Construct Time from seconds.
		*/
		static Time seconds(double seconds);
		/*!
		  \brief Construct Time from milliseconds.
		*/
		static Time milliseconds(int milliseconds);
		/*!
		  \brief Construct Time from microseconds.
		*/
		static Time microseconds(long long microseconds);
		//! Game delta Time.
		static Time deltaTime;
		
	private:
		long long m_microseconds;
	};
}

bool operator ==(bienne::Time left, bienne::Time right);
bool operator !=(bienne::Time left, bienne::Time right);
bool operator <(bienne::Time left, bienne::Time right);
bool operator >(bienne::Time left, bienne::Time right);
bool operator <=(bienne::Time left, bienne::Time right);
bool operator >=(bienne::Time left, bienne::Time right);
bienne::Time operator -(bienne::Time right);
bienne::Time operator +(bienne::Time left, bienne::Time right);
bienne::Time& operator +=(bienne::Time &left, bienne::Time right);
bienne::Time operator -(bienne::Time left, bienne::Time right);
bienne::Time& operator -=(bienne::Time &left, bienne::Time right);
bienne::Time operator *(bienne::Time left, double right);
bienne::Time operator *(bienne::Time left, long long right);
bienne::Time operator *(double left, bienne::Time right);
bienne::Time operator *(long long left, bienne::Time right);
bienne::Time& operator *=(bienne::Time &left, double right);
bienne::Time& operator *=(bienne::Time &left, long long right);
bienne::Time operator /(bienne::Time left, double right);
bienne::Time operator /(bienne::Time left, long long right);
bienne::Time& operator /=(bienne::Time &left, double right);
bienne::Time& operator /=(bienne::Time &left, long long right);
double operator /(bienne::Time left, bienne::Time right);
bienne::Time operator %(bienne::Time left, bienne::Time right);
bienne::Time& operator %=(bienne::Time &left, bienne::Time right);
#endif