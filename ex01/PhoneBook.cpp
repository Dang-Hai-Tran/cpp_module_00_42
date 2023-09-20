/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:59:04 by datran            #+#    #+#             */
/*   Updated: 2023/09/20 15:07:17 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

std::string truncateString(std::string str) {
    if (str.length() > MAX_LONG_TEXT) {
        return str.substr(0, 9) + ".";
    }
    return str;
};

bool isStringOnlyNumbers(std::string &str) {
    for (int i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i]))
            return (false);
    }
    return (true);
}

PhoneBook::PhoneBook() : index(0), count(0){};
void PhoneBook::addContact(void) {
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
    std::cout << "Enter first name: ";
    if (!std::getline(std::cin, firstName) || std::cin.eof()) {
        std::cerr << "Input error occurred." << std::endl;
        exit(1);
    }
    std::cout << "Enter last name: ";
    if (!std::getline(std::cin, lastName) || std::cin.eof()) {
        std::cerr << "Input error occurred." << std::endl;
        exit(1);
    }
    std::cout << "Enter nick name: ";
    if (!std::getline(std::cin, nickName) || std::cin.eof()) {
        std::cerr << "Input error occurred." << std::endl;
        exit(1);
    }
    std::cout << "Enter phone number: ";
    if (!std::getline(std::cin, phoneNumber) || std::cin.eof()) {
        std::cerr << "Input error occurred." << std::endl;
        exit(1);
    }
    std::cout << "Enter darkest secret: ";
    if (!std::getline(std::cin, darkestSecret) || std::cin.eof()) {
        std::cerr << "Input error occurred." << std::endl;
        exit(1);
    }
    if (firstName.empty() || lastName.empty() || nickName.empty() ||
        phoneNumber.empty() || darkestSecret.empty()) {
        std::cout << "Empty value found. Please enter correct value"
                  << std::endl;
        return;
    }
    Contact newContact(firstName, lastName, nickName, phoneNumber,
                       darkestSecret);
    if (index < MAX_CONTACTS) {
        contactList[index] = newContact;
        index++;
    } else if (index == MAX_CONTACTS) {
        index = 0;
        contactList[index] = newContact;
        index++;
    }
    if (count < MAX_CONTACTS)
        count++;
};

void PhoneBook::searchContact(void) {
    if (count == 0) {
        std::cout << "Phone Book is empty. Try to add contact before search"
                  << std::endl;
        return;
    }
    std::cout << std::setw(10) << "Index"
              << " | " << std::setw(10) << "First Name"
              << " | " << std::setw(10) << "Last Name"
              << " | " << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << std::setw(10) << i << " | " << std::setw(10)
                  << truncateString(contactList[i].getFirstName()) << " | "
                  << std::setw(10)
                  << truncateString(contactList[i].getLastName()) << " | "
                  << std::setw(10)
                  << truncateString(contactList[i].getNickName()) << std::endl;
    }
    std::cout << "Enter search index: ";
    std::string strIndexSearch;
    if (!std::getline(std::cin, strIndexSearch) || std::cin.eof()) {
        std::cerr << "Input error occurred." << std::endl;
        exit(1);
    }
    if (!isStringOnlyNumbers(strIndexSearch)) {
        std::cout << "Index is a number. Please enter valid index."
                  << std::endl;
        return;
    }
    int indexSearch = std::atoi(strIndexSearch.c_str());
    if (indexSearch < 0 || indexSearch > count - 1) {
        std::cout << "Invalid index value. Please enter valid index."
                  << std::endl;
        return;
    }
    Contact foundContact = contactList[indexSearch];
    std::cout << "All informations of this contact:" << std::endl;
    std::cout << "- first name: " << foundContact.getFirstName() << std::endl;
    std::cout << "- last name: " << foundContact.getLastName() << std::endl;
    std::cout << "- nick name: " << foundContact.getNickName() << std::endl;
    std::cout << "- phone number: " << foundContact.getPhoneNumber()
              << std::endl;
    std::cout << "- darkest secret: " << foundContact.getDarkestSecret()
              << std::endl;
}
PhoneBook::~PhoneBook(){};
