/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:23:21 by datran            #+#    #+#             */
/*   Updated: 2023/09/17 12:13:54 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
    std::cout << "Welcome to the AWESOME PHONE BOOK" << std::endl;
    PhoneBook phoneBook;
    while (true) {
        std::cout << "Select your command (ADD | SEARCH | EXIT): ";
        std::string command;
        if (!std::getline(std::cin, command) || std::cin.eof()) {
            std::cerr << "Input error occurred." << std::endl;
            return (1);
        }
        if (command == "EXIT")
            break;
        else if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContact();
        } else
            std::cout << "Invalid command. Please enter correct command"
                      << std::endl;
    }
    return (0);
}
