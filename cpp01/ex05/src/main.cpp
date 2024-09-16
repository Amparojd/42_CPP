/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:25:08 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/16 18:43:27 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	std::string input;
  Harl        harl;

  do
  {
      std::cout << "Enter a level: DEBUG, INFO, WARNING or ERROR. To exit, EXIT" << std::endl;
      std::cin >> input;
	if (std::cin.eof())
        break;
      harl.complain(input);
  } while (input.compare("EXIT"));
	return 0;
}


/*El ejercicio consiste en crear 
una clase llamada Harl que simule
 el comportamiento de un personaje 
 que se queja en diferentes niveles 
 de severidad: "DEBUG", "INFO", "WARNING" y 
 "ERROR". Cada nivel tiene un mensaje específico.
  El objetivo principal es implementar un método 
  complain que seleccione y ejecute el mensaje 
  apropiado en función del nivel dado como 
  parámetro, utilizando punteros a funciones 
  miembro en lugar de múltiples if/else if/else. 
  Esto promueve una forma más eficiente y elegante de manejar 
la lógica condicional*/