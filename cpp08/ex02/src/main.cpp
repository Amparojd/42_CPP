/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:39:07 by ampjimen          #+#    #+#             */
/*   Updated: 2024/11/04 19:55:54 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/MutantStack.hpp"


// Función para imprimir el contenido de MutantStack
template <typename T>
void printMutantStack(const MutantStack<T>& mstack) {
    typename MutantStack<T>::const_iterator it = mstack.begin();
    typename MutantStack<T>::const_iterator ite = mstack.end();

    std::cout << "MutantStack elements: ";
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "===== MutantStack Tests =====" << std::endl;
    std::cout << std::endl;
    std::cout << "===== TEST 1: PUSH & POP =====" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    
    printMutantStack(mstack);
    std::cout << "Top element: " << mstack.top() << std::endl; // Should print 17
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl; // Should print 1
    printMutantStack(mstack);
    std::cout << "Added new elements" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << std::endl;
    std::cout << "===== TEST 2: PRINT ELEMENTS USING ITERATOR =====" << std::endl;
    printMutantStack(mstack);

    std::cout << std::endl;
    std::cout << "===== TEST 3: CHECK SIZE AND TOP =====" << std::endl;

    std::cout << "Current size: " << mstack.size() << std::endl;
    std::cout << "Top element: " << mstack.top() << std::endl;

    std::cout << std::endl;
    std::cout << "===== TEST 4: MODIFY ELEMENTS USING ITERATOR =====" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    while (it != mstack.end()) {
        *it += 1; // Increment each element by 1
        ++it;
    }
    std::cout << "After modification:" << std::endl;
    printMutantStack(mstack);

    std::cout << std::endl;
    std::cout << "===== TEST 5: CREATE A NORMAL STACK FROM MUTANTSTACK =====" << std::endl;
    std::stack<int> s(mstack);
    std::cout << "Normal stack size: " << s.size() << std::endl; // Should print size of the stack

    std::cout << std::endl;
    std::cout << "===== TEST 6: ADITONAL TESTS TO VALIDATE BEHAVIOR =====" << std::endl;
    mstack.pop(); // Remove the top element
    std::cout << "Size after pop: " << mstack.size() << std::endl; // Should print size - 1

    mstack.push(100); // Push new element
    std::cout << "New top after push: " << mstack.top() << std::endl; // Should print 100

    printMutantStack(mstack);

    return 0;
}



