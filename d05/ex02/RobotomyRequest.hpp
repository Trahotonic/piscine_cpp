/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequest.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:28:05 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/06/26 18:28:06 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUEST_HPP
#define ROBOTOMYREQUEST_HPP

#include "Form.hpp"

class RobotomyRequest : public Form
{
private:
	std::string _target;
	static int	_count;
public:
	RobotomyRequest(void);
	RobotomyRequest(std::string target);
	RobotomyRequest(RobotomyRequest const & src);

	RobotomyRequest	&operator=(RobotomyRequest const & src);

	~RobotomyRequest(void);

	void	beExecuted(void) const;
};

#endif
