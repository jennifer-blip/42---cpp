/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:47:22 by jodde             #+#    #+#             */
/*   Updated: 2026/05/18 14:47:38 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/data.hpp"
#include "../includes/display.hpp"

int main()
{
    Data data;
    data.s1 = "Hello";
    data.n = 42;
    data.s2 = "World";
    Data* ptr = &data;

    display("Original data: s1 = " + data.s1 + ", n = " + std::to_string(data.n) + ", s2 = " + data.s2, BLUE);
    display("// Serialize the data", BROWN);
    std::cout << "Original data address: " << ptr << std::endl;
    uintptr_t raw = Serializer::serialize(ptr);
    display("Serialized data address: " + std::to_string(raw), GREEN);
    display("Serialized data : s1 = " + data.s1 + ", n = " + std::to_string(data.n) + ", s2 = " + data.s2, GREEN);

    display("// Deserialize the data", BROWN);
    Data* deserializedData = Serializer::deserialize(raw);
     std::cout << "Deserialized data address: " << deserializedData << std::endl;
    display("Deserialized data: s1 = " + deserializedData->s1 + ", n = " + std::to_string(deserializedData->n) + ", s2 = " + deserializedData->s2, GREEN);

    return 0;
}
