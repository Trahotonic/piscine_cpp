/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contactForm.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 18:34:16 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/06/18 18:34:17 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

void    addContact(Contact *contact_list[8])
{
    std::string buffer;

    if (Contact::getObjCount() == 8)
    {
        std::cout << "\nContact list is full\n\n";
        return ;
    }
    Contact *adder = new Contact;
    std::cout << "\nAdding new contact" << std::endl << std::endl;
    std::cout << "Enter first name: ";
	std::getline(std::cin, buffer);
    adder->setFirstName(buffer);
    buffer.clear();

    std::cout << "Enter last name: ";
	std::getline(std::cin, buffer);
    adder->setLastName(buffer);
    buffer.clear();

    std::cout << "Enter nickname: ";
	std::getline(std::cin, buffer);
    adder->setNickName(buffer);
    buffer.clear();

    std::cout << "Enter login: ";
	std::getline(std::cin, buffer);
    adder->setLogin(buffer);
    buffer.clear();

    std::cout << "Enter postal address: ";
	std::getline(std::cin, buffer);
    adder->setPostalAddress(buffer);
    buffer.clear();

    std::cout << "Enter email address: ";
	std::getline(std::cin, buffer);
    adder->setEmailAddress(buffer);
    buffer.clear();

    std::cout << "Enter phone number: ";
    std::getline(std::cin, buffer);
    adder->setPhoneNumber(buffer);
    buffer.clear();

    std::cout << "Enter birthday date: ";
	std::getline(std::cin, buffer);
    adder->setBirthdayDate(buffer);
    buffer.clear();

    std::cout << "Enter favourite meal: ";
	std::getline(std::cin, buffer);
    adder->setFavouriteMeal(buffer);
    buffer.clear();

    std::cout << "Enter underwear color: ";
	std::getline(std::cin, buffer);
    adder->setUnderwearColor(buffer);
    buffer.clear();

    std::cout << "Enter darkest secret: ";
	std::getline(std::cin, buffer);
    adder->setDarkestSecret(buffer);
    buffer.clear();
    contact_list[Contact::getObjCount() - 1] = adder;
    std::cout << std::endl << "Contact added" << std::endl << std::endl;
}
