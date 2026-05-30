/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 10:47:22 by jodde             #+#    #+#             */
/*   Updated: 2026/05/29 22:26:53 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include "../includes/easyfind.tpp"

enum color
{
	RESET,
	RED,
	BROWN,
	GREEN,
	BLUE
};

void	display(std::string msg, color col)
{
	switch (col)
	{
		case (RED):
		{
			std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (BROWN):
		{
			std::cout << "\033[33m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (GREEN):
		{
			std::cout << "\033[32m" << msg << "\033[0m" << std::endl;
			break;
		}
		case (BLUE):
		{
			std::cout << "\033[34m" << msg << "\033[0m" << std::endl;
			break;
		}		
		default :
			std::cout << msg << std::endl;
	}
}

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
template <typename T>
void fillContainer(T& container)
{
    std::string data[] = {"alpha", "bravo", "charlie", "delta", "echo"};
    for (int i = 0; i < 5; i++)
        container.push_back(data[i]);
}

int main(void)
{
    display("///////EASYFIND TEST WITH CONTAINERS OF INTEGERS", BROWN);
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
    display("-- creation of an integer list --", BLUE);
    std::list<int> lst;
    fillContainer(lst, 5, 5, 5);
    std::cout << "list: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    try {
        std::list<int>::iterator it = easyfind(lst, 25);
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // ── 5. Test with deque of integers ───────────────────
    display("-- test with a deque of integers --", BLUE);
    display("-- creation of an integer deque --", BLUE);
    std::deque<int> arr(5);
    fillContainer(arr, 2, 2, 5);
    std::cout << "deque: ";
    for (std::deque<int>::iterator it = arr.begin(); it != arr.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    try {
        std::deque<int>::iterator it = easyfind(arr, 6);
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;    
    }
    display("///////EASYFIND TEST WITH CONTAINERS OF CHARACTERS", BROWN);
    // ── 1. Creation of a string vector ────────────────────────────────
    display("-- creation of a char vector --", BLUE);
    std::vector<char> charVec;
    fillContainer(charVec, 'a', 1, 5);
    std::cout << "vector: ";
    for (std::vector<char>::iterator it = charVec.begin(); it != charVec.end(); ++it)
        std::cout << *it << " ";
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
    // ── 4. Test with a linked list of characters ───────────────────────
    display("-- test with a linked list of characters --", BLUE);
    std::list<char> charList;
    fillContainer(charList, 'f', 1, 5);
    std::cout << "list: ";
    for (std::list<char>::iterator it = charList.begin(); it != charList.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    try {
        std::list<char>::iterator it = easyfind(charList, 'h');
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    // ── 5. Test with a deque of characters ───────────────────
    display("-- test with a deque of characters --", BLUE);
    std::deque<char> charDeque(5);
    fillContainer(charDeque, 'k', 1, 5);
    std::cout << "deque: ";
    for (std::deque<char>::iterator it = charDeque.begin(); it != charDeque.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    try {
        std::deque<char>::iterator it = easyfind(charDeque, 'm');
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    display("///////EASYFIND TEST WITH CONTAINERS OF STRINGS", BROWN);
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
    std::cout << "list: ";
    for (std::list<std::string>::iterator it =strList.begin(); it != strList.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    try {
        std::list<std::string>::iterator it = easyfind(strList, "charlie");
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    // ── 5. Test with a deque of strings ───────────────────
    display("-- test with a deque of strings --", BLUE);
    std::deque<std::string> strDeque;
    fillContainer(strDeque);
    std::cout << "deque: ";
    for (size_t i = 0; i < strDeque.size(); i++)
        std::cout << strDeque[i] << " ";
    std::cout << std::endl;
    try {
        std::deque<std::string>::iterator it = easyfind(strDeque, "papa");
        std::cout << "trouve: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
