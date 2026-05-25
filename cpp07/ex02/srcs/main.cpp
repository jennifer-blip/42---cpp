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
#include "../includes/display.hpp"
#include "../includes/Array.tpp"

int main(void)
{
    // ── 1. Constructeur par défaut ─────────────────────────────────────────
    display("-- constructeur par defaut --", BLUE);
    Array<int> empty;
    std::cout << "size: " << empty.size() << std::endl;

    // ── 2. Constructeur avec taille, valeurs initialisées à zéro ──────────
    display("-- constructeur avec n=5 --", BLUE);
    Array<int> arr(5);
    std::cout << "size: " << arr.size() << std::endl;
    std::cout << "valeurs initiales: " << arr << std::endl;

    // ── 3. Accès et modification via operator[] ────────────────────────────
    display("-- acces et modification --", BLUE);
    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = static_cast<int>(i) * 10;
    std::cout << "apres modification: " << arr << std::endl;

    // ── 4. Constructeur par copie (deep copy) ─────────────────────────────
    display("-- copie profonde --", BLUE);
    Array<int> copy(arr);
    arr[0] = 999;
    std::cout << "original modifie: " << arr << std::endl;
    std::cout << "copie inchangee:  " << copy << std::endl;

    // ── 5. Opérateur d'affectation (deep copy) ────────────────────────────
    display("-- affectation profonde --", BLUE);
    Array<int> assigned(3);
    assigned = copy;
    copy[0] = 888;
    std::cout << "copy modifiee:    " << copy << std::endl;
    std::cout << "assigned inchangee: " << assigned << std::endl;

    // ── 6. Exception out_of_range ─────────────────────────────────────────
    display("-- exception hors bornes --", BLUE);
    try {
        std::cout << arr[999] << std::endl;
    }
    catch (std::out_of_range& e) {
        std::cerr << "exception attrapee: " << e.what() << std::endl;
    }

    // ── 7. Accès sur tableau vide ──────────────────────────────────────────
    display("-- exception sur tableau vide --", BLUE);
    try {
        std::cout << empty[0] << std::endl;
    }
    catch (std::out_of_range& e) {
        std::cerr << "exception attrapee: " << e.what() << std::endl;
    }

    // ── 8. Type string ────────────────────────────────────────────────────
    display("-- type string --", BLUE);
    Array<std::string> words(3);
    words[0] = "Hello";
    words[1] = "world";
    words[2] = "!";
    std::cout << words << std::endl;

    return 0;
}
