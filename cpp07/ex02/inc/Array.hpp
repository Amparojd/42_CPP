/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:56:04 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/28 19:15:00 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
    private:
        T*           _array;
        unsigned int _size;
    
    public:
    
        Array() : _array(NULL), _size(0) {}
        
        Array(unsigned int n) : _size(n) {
            if (n == 0)
            {
                _array = NULL;
            } 
            else
            {
                _array = new T[n];
            }
        }

         // Constructor de copia
    Array(const Array& other) : _array(NULL), _size(other._size) {
        if (_size > 0) {
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; ++i) {
                _array[i] = other._array[i];
            }
        }
    }

    // Operador de asignación
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _array;  // Liberar memoria existente
            _size = other._size;
            if (_size > 0) {
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; ++i) {
                    _array[i] = other._array[i];
                }
            } else {
                _array = NULL;
            }
        }
        return *this;
    }

    // Destructor
    ~Array() {
        delete[] _array;
    }

    // Operador de subíndice
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _array[index];
    }

    // Función para obtener el tamaño
    unsigned int size() const {
        return _size;
    }
};

#endif