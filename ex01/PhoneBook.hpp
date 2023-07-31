/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:59:11 by datran            #+#    #+#             */
/*   Updated: 2023/06/14 18:21:14 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#define MAX_LONG_TEXT 10
#define SUCCESS 1
#define FAIL 0

class PhoneBook {
public:
    Contact contactList[MAX_CONTACTS];
    int index;
    int count;

public:
    PhoneBook();
    void addContact(void);
    void searchContact(void);
    ~PhoneBook();
};

std::string truncateString(std::string &str);

#endif
