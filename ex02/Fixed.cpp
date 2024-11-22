#include "Fixed.hpp"

int Fixed::getRawBits(void) const
{
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(value) / (1 << fractions));
}

int Fixed::toInt(void) const
{
	return (value >> fractions);
}

//assignment operator overload
Fixed& Fixed::operator=(const Fixed &other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

//math operators overload

Fixed Fixed::operator*(const Fixed &other)
{
    Fixed result;

    result.value = (value * other.value) >> fractions;
    return (result);
}

Fixed Fixed::operator--()
{
    value -= 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    value -= 1;
    return (temp);
}

Fixed Fixed::operator++()
{
    value += 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    value += 1;
    return (temp);
}

//comparison operators overload
bool Fixed::operator==(const Fixed &other) const
{
    return (value == other.value);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (value > other.value);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (value < other.value);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (value >= other.value);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (value <= other.value);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (value != other.value);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed &Fixed::min(Fixed &value, Fixed &other)
{
    if (value < other)
        return value;
    else
        return other;
}

const Fixed &Fixed::min(const Fixed &value, const Fixed &other)
{
    if (value < other)
        return value;
    else
        return other;
}

Fixed    &Fixed::max(Fixed &value, Fixed &other)
{
    if (value > other)
        return value;
    else
        return other;
}

const Fixed    &Fixed::max(const Fixed &value, const Fixed &other)
{
    if (value > other)
        return value;
    else
        return other;
}
