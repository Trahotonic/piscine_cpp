//
// Created by Roman KYSLYY on 6/30/18.
//

#include "../../inc/ShellUI.class.hpp"

ShellUI::ShellUI()
{
}

ShellUI::ShellUI(const ShellUI &shellUI)
{
	*this = shellUI;
}

ShellUI& ShellUI::operator=(const ShellUI &shellUI)
{
	(void)shellUI;
	return *this;
}

ShellUI::~ShellUI()
{}

void ShellUI::displayHost(HostModule *hostModule)
{
	if (hostModule)
	{
		mvwprintw(stdscr, 0, 0, hostModule->getHostName().c_str());
		mvwprintw(stdscr, 1, 0, hostModule->getUserName().c_str());
		mvwprintw(stdscr, 2, 0, hostModule->getOsName().c_str());
		mvwprintw(stdscr, 3, 0, hostModule->getOsVersion().c_str());
		mvwprintw(stdscr, 4, 0, hostModule->getOsBuild().c_str());
		mvwprintw(stdscr, 5, 0, hostModule->getTime().c_str());
	}
}

void ShellUI::displayCpu(CpuModule *cpuModule)
{
	float		tmpF;
	int 		tmpI;
	std::string	tmpS;

	if (cpuModule)
	{
		mvwprintw(stdscr, 7, 0, cpuModule->getModel().c_str());
		mvwprintw(stdscr, 8, 0, cpuModule->getClockSpeed().c_str());
		tmpF = cpuModule->getUserUsage();
		tmpS = std::to_string(tmpF);

		mvwprintw(stdscr, 9, 0, tmpS.c_str());

		tmpF = cpuModule->getSystemUsage();
		tmpS = std::to_string(tmpF);
		mvwprintw(stdscr, 10, 0, tmpS.c_str());

		tmpF = cpuModule->getIdleUsage();
		tmpS = std::to_string(tmpF);
		mvwprintw(stdscr, 11, 0, tmpS.c_str());

		tmpI = cpuModule->getCores();
		tmpS = std::to_string(tmpI);
		mvwprintw(stdscr, 12, 0, tmpS.c_str());
	}
}

void ShellUI::displayNet(NetModule *netModule)
{
	long 		tmpL;
	std::string	tmpS;

	if (netModule)
	{
		tmpL = netModule->getCurSentPackages();
		tmpS = std::to_string(tmpL) + "/" + std::to_string(netModule->getMaxSentPackages() / 1000000) + "M";
		mvwprintw(stdscr, 14, 0, tmpS.c_str());

		tmpL = netModule->getCurRecPackages();
		tmpS = std::to_string(tmpL) + "/" + std::to_string(netModule->getMaxRecPackages() / 1000000) + "M";
		mvwprintw(stdscr, 15, 0, tmpS.c_str());
	}
}

void ShellUI::displayRam(RamModule *ramModule)
{
	long 		tmpL;
	std::string	tmpS;

	if (ramModule)
	{
		tmpL = ramModule->getUsed() / 1000000;
		tmpS = std::to_string(tmpL) + "M";
		mvwprintw(stdscr, 17, 0, tmpS.c_str());

		tmpL = ramModule->getWired() / 1000000;
		tmpS = std::to_string(tmpL) + "M";
		mvwprintw(stdscr, 18, 0, tmpS.c_str());

		tmpL = ramModule->getUnused() / 1000000;
		tmpS = std::to_string(tmpL) + "M";
		mvwprintw(stdscr, 19, 0, tmpS.c_str());
	}
}
