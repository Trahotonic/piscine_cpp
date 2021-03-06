/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 18:20:02 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/06/18 18:20:03 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int     i;
	size_t  n;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		n = 0;
		while (argv[i][n] != '\0')
		{
			if (argv[i][n] >= 'a' && argv[i][n] <= 'z')
				argv[i][n] -= 32;
			n += 1;
		}
		std::cout << argv[i];
		i += 1;
	}
	std::cout << std::endl;
	return (0);
}
