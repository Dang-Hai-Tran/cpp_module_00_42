/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:08:10 by datran            #+#    #+#             */
/*   Updated: 2023/06/14 16:17:25 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

#define MAX_CONTACTS 8

class Contact {
public:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string daskestSecret;

public:
    Contact();
    Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string daskestSecret);
    std::string getFirstName(void);
    std::string getLastName(void);
    std::string getNickName(void);
    std::string getPhoneNumber(void);
    std::string getDaskestSecret(void);
    ~Contact();
};

#endif
