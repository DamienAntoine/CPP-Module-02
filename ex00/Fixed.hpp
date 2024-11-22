#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>

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
		Fixed(const Fixed &other) : value(other.value)
		{
			std::cout << "Copy constructor called" << std::endl;
			this->value = other.getRawBits();
		} //copy the object

		Fixed& operator=(const Fixed &other) //copy the object's content into another object of the same class
		{
			std::cout << "Copy assignment operator called" << std::endl;
			if (this != &other)
				this->value = other.getRawBits();
			return *this;
		}

		~Fixed()
		{
			std::cout << "Destructor called" << std::endl;
		}

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
