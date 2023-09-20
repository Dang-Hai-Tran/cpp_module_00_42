/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:59:11 by datran            #+#    #+#             */
/*   Updated: 2023/09/20 15:06:52 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#define MAX_LONG_TEXT 10
#define SUCCESS 1
#define FAIL 0

class PhoneBook {
  private:
    Contact contactList[MAX_CONTACTS];
    int index;
    int count;

  public:
    PhoneBook();
    void addContact(void);
    void searchContact(void);
    ~PhoneBook();
};

#endif
