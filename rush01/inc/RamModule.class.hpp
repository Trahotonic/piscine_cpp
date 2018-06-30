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

class RamModule {
public:
	RamModule();
	RamModule(const RamModule& ramModule);
	~RamModule();
	RamModule&	operator=(const RamModule& ramModule);
private:
	long _used;
	long _wired;
};

#endif
