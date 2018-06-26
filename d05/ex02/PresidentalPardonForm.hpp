/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:27:51 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/06/26 18:27:52 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTALPARDONFORM_HPP
#define PRESIDENTALPARDONFORM_HPP

# include "Form.hpp"

class PresidentalPardonForm : public Form
{
private:
	std::string _target;
public:
	PresidentalPardonForm(void);
	PresidentalPardonForm(std::string target);
	PresidentalPardonForm(PresidentalPardonForm const & src);

	PresidentalPardonForm	&operator=(PresidentalPardonForm const & src);

	~PresidentalPardonForm(void);

	void	beExecuted(void) const;
};

#endif
