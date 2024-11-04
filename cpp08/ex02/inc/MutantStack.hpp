/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:38:44 by ampjimen          #+#    #+#             */
/*   Updated: 2024/11/04 19:39:46 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <exception>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
private:
    // Usar el contenedor de stack
    using std::stack<T>::c;

public:

        MutantStack() : std::stack<T>() {}
        MutantStack(MutantStack const &src) : std::stack<T>(src) {}
        ~MutantStack() {}
        MutantStack &operator=(MutantStack const &rhs)
        {
            if (this != &rhs)
                std::stack<T>::operator=(rhs);
            return *this;
        }
        
    // Tipo de iterador
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;


    // Funciones miembro
    void push(const T &value) {
        std::stack<T>::push(value);
    }

    void pop() {
        std::stack<T>::pop();
    }

    T &top() {
        return std::stack<T>::top();
    }

    const T &top() const {
        return std::stack<T>::top();
    }

    size_t size() const {
        return std::stack<T>::size();
    }

    bool empty() const {
        return std::stack<T>::empty();
    }

        // Funciones para iteradores
    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }

    // Añadido para soporte de iteradores constantes
    const_iterator begin() const {
        return std::stack<T>::c.begin();
    }

    const_iterator end() const {
        return std::stack<T>::c.end();
    }

};

#endif
