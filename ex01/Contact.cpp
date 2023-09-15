/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:07:49 by datran            #+#    #+#             */
/*   Updated: 2023/09/15 12:09:01 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){};
Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string daskestSecret) : firstName(firstName), lastName(lastName), nickName(nickName), phoneNumber(phoneNumber), daskestSecret(daskestSecret){};
std::string Contact::getFirstName(void) { return firstName; };
std::string Contact::getLastName(void) { return lastName; };
std::string Contact::getNickName(void) { return nickName; };
std::string Contact::getPhoneNumber(void) { return phoneNumber; };
std::string Contact::getDaskestSecret(void) { return daskestSecret; };
Contact::~Contact(){};
