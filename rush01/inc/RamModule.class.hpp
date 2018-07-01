/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:05:45 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 12:05:45 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_CLASS_HPP
# define RAMMODULE_CLASS_HPP

# include <iostream>
# include <fstream>
# include "../inc/IMonitorModule.hpp"

class RamModule : public virtual IMonitorModule {
public:
	RamModule();
	RamModule(const RamModule& ramModule);
	~RamModule();
	RamModule&	operator=(const RamModule& ramModule);

	long 	getUsed();
	long 	getWired();
	long 	getUnused();

	void	update();

private:
	long 	_used;
	long 	_wired;
	long 	_unused;
};

#endif
