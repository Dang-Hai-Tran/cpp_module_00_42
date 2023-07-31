/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:59:04 by datran            #+#    #+#             */
/*   Updated: 2023/06/14 18:54:32 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

std::string truncateString(std::string &str) {
    if (str.length() > MAX_LONG_TEXT) {
        return str.substr(0, 9) + ".";
    }
    return str;
};

PhoneBook::PhoneBook() : index(0), count(0){};
void PhoneBook::addContact(void) {
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter nick name: ";
    std::getline(std::cin, nickName);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);
    if (firstName.empty() || lastName.empty() || nickName.empty() || phoneNumber.empty() || darkestSecret.empty()) {
        std::cout << "Empty value found. Please enter correct value" << std::endl;
        return;
    }
    Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
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
        std::cout << "Phone Book is empty. Try to add contact before search" << std::endl;
        return;
    }
    std::cout << std::setw(10) << "Index"
              << " | "
              << std::setw(10) << "First Name"
              << " | "
              << std::setw(10) << "Last Name"
              << " | "
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << std::setw(10) << i << " | "
                  << std::setw(10) << truncateString(contactList[i].firstName) << " | "
                  << std::setw(10) << truncateString(contactList[i].lastName) << " | "
                  << std::setw(10) << truncateString(contactList[i].nickName) << std::endl;
    }
    std::cout << "Enter search index: ";
    std::string strIndexSearch;
    std::getline(std::cin, strIndexSearch);
    int indexSearch = std::atoi(strIndexSearch.c_str());
    if (indexSearch < 0 || indexSearch > count - 1) {
        std::cout << "Invalid index number. Please enter correct index" << std::endl;
        return;
    }
    Contact foundContact = contactList[indexSearch];
    std::cout << "All informations of this contact:" << std::endl;
    std::cout << "- first name: " << foundContact.firstName << std::endl;
    std::cout << "- last name: " << foundContact.lastName << std::endl;
    std::cout << "- nick name: " << foundContact.nickName << std::endl;
    std::cout << "- phone number: " << foundContact.phoneNumber << std::endl;
    std::cout << "- darkest secret: " << foundContact.daskestSecret << std::endl;
}
PhoneBook::~PhoneBook(){};
