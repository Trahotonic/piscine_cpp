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

void ShellUI::displayField(HostModule *hostModule, CpuModule *cpuModule,
						   RamModule *ramModule, NetModule *netModule)
{
	mvwprintw(stdscr, 0, 1, "___________________________________");
	int n = 0;
	if (hostModule)
		n += 12;
	if (cpuModule)
		n += 12;
	if (ramModule)
		n += 7;
	if (netModule)
		n += 8;
	for (int i = 1; i < n + 1; i++)
	{
		mvwprintw(stdscr, i, 0, "|");
		mvwprintw(stdscr, i, 36, "|");
	}
	mvwprintw(stdscr, n, 1, "___________________________________");
}

void ShellUI::displayHost(HostModule *hostModule)
{
	use_default_colors();
	start_color();
	init_pair(1, COLOR_RED, -1);
	init_pair(2, COLOR_BLUE, -1);
	init_pair(3, COLOR_CYAN, -1);
	init_pair(4, COLOR_YELLOW, -1);
	init_pair(5, COLOR_GREEN, -1);
	if (hostModule)
	{
		attron(COLOR_PAIR(4));
		mvwprintw(stdscr, 1, 1, "HOST:");
		mvwprintw(stdscr, 3, 1, "USER:");
		mvwprintw(stdscr, 5, 1, "Operation System:");
		mvwprintw(stdscr, 7, 1, "OS version:");
		mvwprintw(stdscr, 9, 1, "OS build:");
		mvwprintw(stdscr, 11, 1, "Time:");
		attroff(COLOR_PAIR(4));
		mvwprintw(stdscr, 2, 1, hostModule->getHostName().c_str());
		mvwprintw(stdscr, 4, 1, hostModule->getUserName().c_str());
		mvwprintw(stdscr, 6, 1, hostModule->getOsName().c_str());
		mvwprintw(stdscr, 8, 1, hostModule->getOsVersion().c_str());
		mvwprintw(stdscr, 10, 1, hostModule->getOsBuild().c_str());
		mvwprintw(stdscr, 12, 1, hostModule->getTime().c_str());
		mvwprintw(stdscr, 13, 1, "___________________________________");
	}
}

void ShellUI::displayCpu(CpuModule *cpuModule)
{
	float		tmpF;
	int 		tmpI;
	std::string	tmpS;

	if (cpuModule)
	{
		attron(COLOR_PAIR(2));
		mvwprintw(stdscr, 14, 1, "CPU:");
		mvwprintw(stdscr, 16, 1, "Clock speed:");
		mvwprintw(stdscr, 19, 1, "CPU user usage:");
		mvwprintw(stdscr, 21, 1, "CPU wired usage:");
		mvwprintw(stdscr, 23, 1, "CPU idle usage:");
		mvwprintw(stdscr, 25, 1, "Amount of cores:");
		attroff(COLOR_PAIR(2));

		mvwprintw(stdscr, 15, 1, cpuModule->getModel().c_str());
		mvwprintw(stdscr, 17, 1, cpuModule->getClockSpeed().c_str());

		tmpF = cpuModule->getUserUsage();
		tmpS = std::to_string(tmpF);
		mvwprintw(stdscr, 20, 1, tmpS.c_str());

		tmpF = cpuModule->getSystemUsage();
		tmpS = std::to_string(tmpF);
		mvwprintw(stdscr, 22, 1, tmpS.c_str());

		tmpF = cpuModule->getIdleUsage();
		tmpS = std::to_string(tmpF);
		mvwprintw(stdscr, 24, 1, tmpS.c_str());

		tmpI = cpuModule->getCores();
		tmpS = std::to_string(tmpI);
		mvwprintw(stdscr, 26, 1, tmpS.c_str());
		mvwprintw(stdscr, 27, 1, "___________________________________");
		mvwprintw(stdscr, 20, 6, "%   ");
		mvwprintw(stdscr, 22, 6, "%   ");
		mvwprintw(stdscr, 24, 6, "%   ");
	}
}

void ShellUI::displayNet(NetModule *netModule)
{
	long 		tmpL;
	std::string	tmpS;

	if (netModule)
	{
		attron(COLOR_PAIR(5));
		mvwprintw(stdscr, 28, 1, "Packages received:");
		mvwprintw(stdscr, 30, 1, "Packages sent:");
		attroff(COLOR_PAIR(5));

		tmpL = netModule->getCurRecPackages();
		tmpS = std::to_string(tmpL) + "/" + std::to_string(netModule->getMaxRecPackages() / 1000000) + "M";
		mvwprintw(stdscr, 29, 1, tmpS.c_str());

		tmpL = netModule->getCurSentPackages();
		tmpS = std::to_string(tmpL) + "/" + std::to_string(netModule->getMaxSentPackages() / 1000000) + "M";
		mvwprintw(stdscr, 31, 1, tmpS.c_str());
		mvwprintw(stdscr, 32, 1, "___________________________________");
	}
}

void ShellUI::displayRam(RamModule *ramModule)
{
	long 		tmpL;
	std::string	tmpS;

	if (ramModule)
	{
		attron(COLOR_PAIR(3));
		mvwprintw(stdscr, 33, 1, "Used memory:");
		mvwprintw(stdscr, 35, 1, "Wired memory:");
		mvwprintw(stdscr, 37, 1, "Unused memory:");
		attroff(COLOR_PAIR(3));
		tmpL = ramModule->getUsed() / 1000000;
		tmpS = std::to_string(tmpL) + "M";
		mvwprintw(stdscr, 34, 1, tmpS.c_str());

		tmpL = ramModule->getWired() / 1000000;
		tmpS = std::to_string(tmpL) + "M";
		mvwprintw(stdscr, 36, 1, tmpS.c_str());

		tmpL = ramModule->getUnused() / 1000000;
		tmpS = std::to_string(tmpL) + "M";
		mvwprintw(stdscr, 38, 1, tmpS.c_str());
	}
}
