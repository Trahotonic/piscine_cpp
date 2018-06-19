/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 18:34:04 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/06/18 18:34:06 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void    Contact::setFirstName(std::string string)
{
    this->first_name = string;
}

void    Contact::setLastName(std::string string)
{
    this->last_name = string;
}

void    Contact::setNickName(std::string string)
{
    this->nickname = string;
}

void    Contact::setLogin(std::string string)
{
    this->login = string;
}

void    Contact::setPostalAddress(std::string string)
{
    this->postal_address = string;
}

void    Contact::setEmailAddress(std::string string)
{
    this->email_address = string;
}

void    Contact::setPhoneNumber(std::string string)
{
    this->phone_number = string;
}

void    Contact::setBirthdayDate(std::string string)
{
    this->birthday_date = string;
}

void    Contact::setFavouriteMeal(std::string string)
{
    this->favourite_meal = string;
}

void    Contact::setUnderwearColor(std::string string)
{
    this->underwear_color = string;
}

void    Contact::setDarkestSecret(std::string string)
{
    this->darkest_secret = string;
}

std::string Contact::getFirstName(void)
{
    return (this->first_name);
}

std::string Contact::getLastName(void)
{
    return (this->last_name);
}

std::string Contact::getNickName(void)
{
    return (this->nickname);
}

std::string Contact::getLogin(void)
{
    return (this->login);
}

std::string Contact::getPostalAddress(void)
{
    return (this->postal_address);
}

std::string Contact::getEmailAddress(void)
{
    return (this->email_address);
}

std::string Contact::getPhoneNumber(void)
{
    return (this->phone_number);
}

std::string Contact::getBirthdayDate(void)
{
    return (this->birthday_date);
}

std::string Contact::getFavouriteMeal(void)
{
    return (this->favourite_meal);
}

std::string Contact::getUnderwearColor(void)
{
    return (this->underwear_color);
}

std::string Contact::getDarkestSecret(void)
{
    return (this->darkest_secret);
}
