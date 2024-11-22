#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>
#include <cmath>

// ************************************************************************** //
//                               Fixed   Class                                //
// ************************************************************************** //

class Fixed {

	private:
		int					value;
		static const int	fractions = 8;

	public:
		Fixed() : value(0)
		{
			//std::cout << "Default constructor called" << std::endl;
		}

		Fixed(const int number)
		{
			//std::cout << "Int constructor called" << std::endl;
			value = number << fractions;
		}

		Fixed(const float fnumber)
		{
			//std::cout << "Float constructor called" << std::endl;
			value = roundf(fnumber * (1 << fractions));
		}

		Fixed(const Fixed &other)
		{
			//std::cout << "Copy constructor called" << std::endl;
			*this = other;
		}

		~Fixed()
		{
			//std::cout << "Destructor called" << std::endl;
		}

		Fixed& operator=(const Fixed &other);
        Fixed operator*(const Fixed &other);
        Fixed operator++();
        Fixed operator++(int);
        Fixed operator--();
        Fixed operator--(int);
        bool operator==(const Fixed &value) const;
        bool operator>(const Fixed &value) const;
        bool operator<(const Fixed &value) const;
        bool operator>=(const Fixed &value) const;
        bool operator<=(const Fixed &value) const;
        bool operator!=(const Fixed &value) const;

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

        static Fixed    &min(Fixed &value, Fixed &other);
        const static Fixed    &min(const Fixed &value, const Fixed &other);
        static Fixed    &max(Fixed &value, Fixed &other);
        const static Fixed    &max(const Fixed &value, const Fixed &other);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
