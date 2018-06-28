/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequest.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:27:56 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/06/26 18:28:01 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequest.hpp"

RobotomyRequest::RobotomyRequest() : Form("Roboto", 72, 45), _target("Default")
{
}

RobotomyRequest::RobotomyRequest(std::string target) : Form("Roboto", 72, 45), _target(target)
{}

RobotomyRequest::RobotomyRequest(RobotomyRequest const &src)
{
	*this = src;
}

RobotomyRequest& RobotomyRequest::operator=(RobotomyRequest const &src)
{
	(void)src;
	return *this;
}

RobotomyRequest::~RobotomyRequest()
{}

void RobotomyRequest::beExecuted() const
{
	if (_count++ % 2 == 0)
	{
		std::cout << "* drill drill drill *\n" << _target << " has been robotomized successfully\n";
	}
	else
	{
		throw std::exception();
	}
}

int RobotomyRequest::_count = 0;
