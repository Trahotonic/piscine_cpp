/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:28:09 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/06/26 18:28:10 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("Shrubbery", 145, 137), _target("Default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
{
	*this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	(void)src;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::beExecuted(void) const
{
	DIR* dirp = opendir(".");
	struct dirent * dp;
	std::ofstream ofs(_target + "_shrubbery");
	ofs << ".";
	int n = 0;
	while ((dp = readdir(dirp)) != NULL) {
		if (n > 3)
			ofs << "\n|";
		if (n > 2)
		{
			ofs << "\n`--[" << dp->d_name << "]";
		}
		n++;
	}
	ofs << std::endl;
	closedir(dirp);

	ofs << "{\n\n               \\ _{\\{\\/}/}/}__\n"
			"             {/{/\\}{/{/\\}(\\}{/\\} _\n"
			"            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n"
			"         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
			"        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n"
			"       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
			"      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
			"      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n"
			"     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n"
			"      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n"
			"       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
			"      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n"
			"       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n"
			"         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n"
			"          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n"
			"            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n"
			"             {/{\\{\\{\\/}/}{\\{\\\\}/}\n"
			"              {){/ {\\/}{\\/} \\}\\}\n"
			"              (_)  \\.-'.-/\n"
			"          __...--- |'-.-'| --...__\n"
			"   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n"
			" -\"    ' .  . '    |.'-._| '  . .  '   jro\n"
			" .  '-  '    .--'  | '-.'|    .  '  . '\n"
			"          ' ..     |'-_.-|\n"
			"  .  '  .       _.-|-._ -|-._  .  '  .\n"
			"              .'   |'- .-|   '.\n"
			"  ..-'   ' .  '.   `-._.-´   .'  '  - .\n"
			"   .-' '        '-._______.-'     '  .\n";
}
