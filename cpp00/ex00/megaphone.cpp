/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:17:38 by ampjimen          #+#    #+#             */
/*   Updated: 2024/08/20 18:09:57 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}	
	std::string msg;
	
	for (int i = 1; i < argc; i++)
		msg += argv[i];
	for (std::string::iterator it = msg.begin(); it != msg.end(); it++)
		*it = std::toupper(*it);
	std::cout << msg << std::endl;
	return (0);
}
