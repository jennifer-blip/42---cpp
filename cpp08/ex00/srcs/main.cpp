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

template <typename T>
void fillContainer(T& container, int start, int step, int count)
{
    for (int i = 0; i < count; i++)
        container.push_back(start + i * step);
}

// Overload for containers holding characters
template <typename T>
void fillContainer(T& container, char start, int step, int count)
{
    for (int i = 0; i < count; i++)
        container.push_back(static_cast<char>(start + i * step));
}

// Overload for containers holding std::string
template <typename Container>
void fillContainer(Container& container)
{
    std::string data[] = {"alpha", "bravo", "charlie", "delta", "echo"};
    for (int i = 0; i < 5; i++)
        container.push_back(data[i]);
}

int main(void)
{
    display("///////EASYFIND TEST WITH DIFFERENT CONTAINERS OF INTEGERS", BROWN);
    // ── 1. Creation of an integer vector ────────────────────────────────
    display("-- creation of an integer vector --", BLUE);
    std::vector<int> vec;
    fillContainer(vec, 0, 10, 5);
    std::cout << "vector: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    // ── 2. Recherche d'une valeur existante ───────────────────────────────
    display("-- find an existing value --", BLUE);
    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // ── 3. Recherche d'une valeur inexistante ─────────────────────────────
    display("-- find a non-existing value --", BLUE);
    try {
        std::vector<int>::iterator it = easyfind(vec, 100);
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // ── 4. Test avec une liste chaînée (std::list) ───────────────────────
    display("-- test with a linked list --", BLUE);
    std::list<int> lst;
    fillContainer(lst, 5, 5, 5);
    try {
        std::list<int>::iterator it = easyfind(lst, 25);
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // ── 5. Test with deque of integers ───────────────────
    display("-- test with a deque of integers --", BLUE);
    std::deque<int> arr(5);
    fillContainer(arr, 2, 2, 5);
    try {
        std::deque<int>::iterator it = easyfind(arr, 6);
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;    
    }
    display("///////EASYFIND TEST WITH DIFFERENT CONTAINERS OF CHARACTERS", BROWN);
    // ── 1. Creation of a string vector ────────────────────────────────
    display("-- creation of a char vector --", BLUE);
    std::vector<char> charVec;
    fillContainer(charVec, 'a', 1, 5);
    std::cout << "vector: ";
    for (size_t i = 0; i < charVec.size(); i++)
        std::cout << charVec[i] << " ";
    std::cout << std::endl;
    // ── 2. Find an existing value ───────────────────────────────
    display("-- find an existing value --", BLUE);
    try {
        std::vector<char>::iterator it = easyfind(charVec, 'c');
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    } 
    // ── 3. Find a non-existing value ───────────────────────────────
    display("-- find a non-existing value --", BLUE);
    try {
        std::vector<char>::iterator it = easyfind(charVec, 'z');
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    // ── 4. Test with a linked list of strings ───────────────────────
    display("-- test with a linked list of characters --", BLUE);
    std::list<char> charList;
    fillContainer(charList, 'f', 1, 5);
    try {
        std::list<char>::iterator it = easyfind(charList, 'h');
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    // ── 5. Test with a deque of strings ───────────────────
    display("-- test with a deque of characters --", BLUE);
    std::deque<char> charDeque(5);
    fillContainer(charDeque, 'k', 1, 5);
    try {
        std::deque<char>::iterator it = easyfind(charDeque, 'm');
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    display("///////EASYFIND TEST WITH DIFFERENT CONTAINERS OF STRINGS", BROWN);
     // ── 1. Creation of a string vector ────────────────────────────────
    display("-- creation of a string vector --", BLUE);
    std::vector<std::string> strVec;
    fillContainer(strVec);
    std::cout << "vector: ";
    for (size_t i = 0; i < strVec.size(); i++)
        std::cout << strVec[i] << " ";
    std::cout << std::endl;
    // ── 2. Find an existing value ───────────────────────────────
    display("-- find an existing value --", BLUE);
    try {
        std::vector<std::string>::iterator it = easyfind(strVec, "echo");
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    } 
    // ── 3. Find a non-existing value ───────────────────────────────
    display("-- find a non-existing value --", BLUE);
    try {
        std::vector<std::string>::iterator it = easyfind(strVec, "zulu");
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    // ── 4. Test with a linked list of strings ───────────────────────
    display("-- test with a linked list of strings --", BLUE);
    std::list<std::string> strList;
    fillContainer(strList);
    try {
        std::list<std::string>::iterator it = easyfind(strList, "charlie");
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    // ── 5. Test with a deque of strings ───────────────────
    display("-- test with a deque of strings --", BLUE);
    std::deque<std::string> strDeque(5);
    fillContainer(strDeque);
    try {
        std::deque<std::string>::iterator it = easyfind(strDeque, "papa");
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
