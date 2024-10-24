/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:58:18 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 11:58:20 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    //std::cout << "Default constructor called" << std::endl;
    this->_fixedPointValue = 0;
}

Fixed::Fixed( const Fixed &rhs ) {
    //std::cout << "Copy constructor called" << std::endl;
    // this->setRawBits(rhs.getRawBits());
    *this = rhs;
}

Fixed::Fixed( const int n ) : _fixedPointValue( n << _fractionalBits ) {
    //std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float n ) : _fixedPointValue( roundf( n * ( 1 << _fractionalBits ) ) ) {
    //std::cout << "Float constructor called" << std::endl;
	/*
	Example: n = 3.75
	
	*/
}

Fixed::~Fixed() {
    //std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void    Fixed::setRawBits( int const raw ) {
    this->_fixedPointValue = raw;
}

float   Fixed::toFloat( void ) const {
    return static_cast<float>( this->getRawBits() ) / ( 1 << _fractionalBits );
}

int     Fixed::toInt( void ) const {
    return this->_fixedPointValue >> _fractionalBits;
}

Fixed& Fixed::operator=( const Fixed &rhs ) {
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return o;
}

// Comparison operators
bool Fixed::operator>(const Fixed& rhs) const {
    return this->_fixedPointValue > rhs._fixedPointValue;
}

bool Fixed::operator<(const Fixed& rhs) const {
    return this->_fixedPointValue < rhs._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& rhs) const {
    return this->_fixedPointValue >= rhs._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& rhs) const {
    return this->_fixedPointValue <= rhs._fixedPointValue;
}

bool Fixed::operator==(const Fixed& rhs) const {
    return this->_fixedPointValue == rhs._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& rhs) const {
    return this->_fixedPointValue != rhs._fixedPointValue;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    return Fixed(this->toFloat() / rhs.toFloat());
}

// Pre and post increment/decreased

Fixed&   Fixed::operator++( void ) {
    ++this->_fixedPointValue;
    return *this;
}

Fixed   Fixed::operator++( int ) {
    Fixed tmp( *this );
    tmp._fixedPointValue = this->_fixedPointValue++;
    return tmp;
}

Fixed& Fixed::operator--( void ) {
    --this->_fixedPointValue;
    return *this;
}

Fixed Fixed::operator--( int ) {
    Fixed tmp( *this );
    tmp._fixedPointValue = this->_fixedPointValue--;
    return tmp;
}

//Min and Max

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}
