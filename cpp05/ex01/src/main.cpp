/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:34:31 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/13 12:26:27 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"


int main() {
    try {
        std::cout <<  "=== Creando Bureaucrat Juan ===" << std::endl;
        Bureaucrat juan("Juan", 55);
        std::cout << juan << std::endl;

        std::cout <<  "\n=== Creando Formulario de Impuestos (grado requerido para firmar: 50, ejecutar: 30) ==="  << std::endl;
        Form taxForm("Formulario de Impuestos", 50, 30);
        std::cout << taxForm << std::endl;

        std::cout <<  "\n=== Juan intenta firmar el formulario ===" << std::endl;
        juan.signForm(taxForm);
        std::cout << taxForm << std::endl;

        std::cout << "\n=== Creando Bureaucrat Alice ===" << std::endl;
        Bureaucrat alice("Alice", 30);
        std::cout << alice << std::endl;
        
        std::cout << "\n=== Alice intenta firmar el formulario ===" << std::endl;
        alice.signForm(taxForm); // No debería poder firmar
        std::cout << taxForm << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Excepción atrapada: " << e.what() << std::endl;
    }

    return 0;
}

