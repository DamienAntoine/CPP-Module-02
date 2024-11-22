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
			std::cout << "Default constructor called" << std::endl;
		}

		Fixed(const int number)
		{
			std::cout << "Int constructor called" << std::endl;
			value = number << fractions;
		}

		Fixed(const float fnumber)
		{
			std::cout << "Float constructor called" << std::endl;
			value = roundf(fnumber * (1 << fractions));
		}

		Fixed(const Fixed &other)
		{
			std::cout << "Copy constructor called" << std::endl;
			*this = other;
		}

		~Fixed()
		{
			std::cout << "Destructor called" << std::endl;
		}

		Fixed &operator=(const Fixed &other)
		{
			std::cout << "Copy assignment operator called" << std::endl;
			if (this != &other)
				this->value = other.getRawBits();
			return *this;
		}

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
