/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 10:47:22 by jodde             #+#    #+#             */
/*   Updated: 2026/05/25 14:47:38 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include "../includes/display.hpp"
#include "../includes/easyfind.tpp"

int main(void)
{
    // ── 1. Création d'un vector d'entiers ────────────────────────────────
    display("-- creation d'un vector d'entiers --", BLUE);
    std::vector<int> vec(5);
    for (int i = 0; i < 50; i += 10)
        vec.push_back(i);
    std::cout << "vector: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    // ── 2. Recherche d'une valeur existante ───────────────────────────────
    display("-- recherche d'une valeur existante --", BLUE);
    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // ── 3. Recherche d'une valeur inexistante ─────────────────────────────
    display("-- recherche d'une valeur inexistante --", BLUE);
    try {
        std::vector<int>::iterator it = easyfind(vec, 100);
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

     // ── 4. Test avec une liste chaînée (std::list) ───────────────────────
     display("-- test avec une liste chaînée --", BLUE);
     std::list<int> lst;
     for (int i = 5; i < 50; i += 10)
         lst.push_back(i);
     try {
         std::list<int>::iterator it = easyfind(lst, 25);
         std::cout << "trouve: " << *it << std::endl;
     } catch (const std::exception& e) {
         std::cout << e.what() << std::endl;
     }

     // ── 5. Test avec un tableau statique (std::array) ───────────────────
     display("-- test avec un tableau statique --", BLUE);
     std::deque<int> arr(5);
     for (size_t i = 0; i < 5; i++)
         arr[i] = static_cast<int>(i + 1) * 2;
     try {
         std::deque<int>::iterator it = easyfind(arr, 6);
         std::cout << "trouve: " << *it << std::endl;
     } catch (const std::exception& e) {
         std::cout << e.what() << std::endl;    
}
}
