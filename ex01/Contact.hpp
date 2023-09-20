/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:08:10 by datran            #+#    #+#             */
/*   Updated: 2023/09/20 14:23:16 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

#define MAX_CONTACTS 8

class Contact {
  private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

  public:
    Contact();
    Contact(std::string &firstName, std::string &lastName,
            std::string &nickName, std::string &phoneNumber,
            std::string &darkestSecret);
    std::string &getFirstName(void);
    std::string &getLastName(void);
    std::string &getNickName(void);
    std::string &getPhoneNumber(void);
    std::string &getDarkestSecret(void);
    ~Contact();
};

#endif
