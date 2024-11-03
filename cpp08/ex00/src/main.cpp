/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:22:13 by ampjimen          #+#    #+#             */
/*   Updated: 2024/11/03 19:30:29 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>


// Función para imprimir los elementos de cualquier contenedor
template <typename T>
void printContainer(const T& container) {
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Test 1: Prueba con std::vector<int>
    std::vector<int> myVector;
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    myVector.push_back(4);
    myVector.push_back(5);

    std::cout << std::endl;
    std::cout << "TEST 1 : find value with std::vector<int>" << std::endl;
    
    std::cout << "Values : ";
    printContainer(myVector);
    
    try {
        std::vector<int>::iterator it = easyfind(myVector, 3);
        std::cout << "Found value in vector: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(myVector, 10);
        std::cout << "Found value in vector: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    // Test 2: Prueba con std::list<int>
    std::list<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);
    myList.push_back(50);

    std::cout << std::endl;
    std::cout << "TEST 2 : find value with std::list<int>" << std::endl;
    std::cout << "Values : ";
    printContainer(myList);
    
    try {
        std::list<int>::iterator it = easyfind(myList, 20);
        std::cout << "Found value in list: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    try {
        std::list<int>::iterator it = easyfind(myList, 60);
        std::cout << "Found value in list: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    // Test 3: Prueba con std::deque<int>
    std::deque<int> myDeque;
    myDeque.push_back(100);
    myDeque.push_back(200);
    myDeque.push_back(300);
    myDeque.push_back(400);
    myDeque.push_back(500);

    std::cout << std::endl;
    std::cout << "TEST 3 : find value with std::deque<int>" << std::endl;
    std::cout << "Values : ";
    printContainer(myDeque);

    try {
        std::deque<int>::iterator it = easyfind(myDeque, 400);
        std::cout << "Found value in deque: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    try {
        std::deque<int>::iterator it = easyfind(myDeque, 700);
        std::cout << "Found value in deque: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}