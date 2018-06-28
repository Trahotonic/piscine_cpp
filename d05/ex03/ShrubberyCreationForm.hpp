/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:28:12 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/06/26 18:28:12 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP


#include <sys/types.h>
#include <dirent.h>
#include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	std::string const _target;
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string);
	ShrubberyCreationForm(ShrubberyCreationForm const & src);

	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const & src);

	~ShrubberyCreationForm(void);

	void	beExecuted(void) const;
};

#endif
