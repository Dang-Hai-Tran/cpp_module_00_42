/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:23:21 by datran            #+#    #+#             */
/*   Updated: 2023/06/14 18:43:49 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
    std::cout << "Welcome to the AWESOME PHONE BOOK" << std::endl;
    PhoneBook phoneBook;
    while (true) {
        std::cout << "Select your command (ADD | SEARCH | EXIT): ";
        std::string command;
        std::getline(std::cin, command);
        if (command == "EXIT")
            break;
        else if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContact();
        } else
            std::cout << "Invalid command. Please enter correct command" << std::endl;
    }
    return (0);
}
