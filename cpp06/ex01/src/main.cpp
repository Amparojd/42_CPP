/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:56:33 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/28 17:34:02 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data* data = new Data;
    data->value = 42;

    // Serializar
    uintptr_t rawData = Serializer::serialize(data);

    // Deserializar
    Data* retData = Serializer::deserialize(rawData);

    // Imprimir resultados
    std::cout << "Data address: " << data << std::endl;
    std::cout << "Data value: " << data->value << std::endl;
    std::cout << "Raw address: " << rawData << std::endl;
    std::cout << "Data deserialized address: " << retData << std::endl;
    std::cout << "Data deserialized value: " << retData->value << std::endl;

    // Liberar memoria
    delete data;
    return 0;
}