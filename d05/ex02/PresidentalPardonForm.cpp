/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:27:48 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/06/26 18:27:49 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentalPardonForm.hpp"

PresidentalPardonForm::PresidentalPardonForm() : Form("President", 25, 5), _target("Default")
{
}

PresidentalPardonForm::PresidentalPardonForm(std::string target) : Form("President", 25, 5), _target(target)
{}

PresidentalPardonForm::PresidentalPardonForm(PresidentalPardonForm const &src)
{
	*this = src;
}

PresidentalPardonForm& PresidentalPardonForm::operator=(PresidentalPardonForm const &src)
{
	(void)src;
	return *this;
}

void PresidentalPardonForm::beExecuted() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}
