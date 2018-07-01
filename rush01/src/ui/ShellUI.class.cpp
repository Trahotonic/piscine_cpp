//
// Created by Roman KYSLYY on 6/30/18.
//

#include "../../inc/ShellUI.class.hpp"

ShellUI::ShellUI() : _host(0), _cpu(0), _net(0), _ram(0)
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
	{
		n += 13;
		_host = 13;
	}
	if (cpuModule)
	{
		n += 13;
		_cpu = 13;
	}
	if (ramModule)
	{
		n += 7;
		_ram = 6;
	}
	if (netModule)
	{
		n += 5;
		_net = 5;
	}
	for (int i = 1; i < n + 1; i++)
	{
		mvwprintw(stdscr, i, 0, "|");
		mvwprintw(stdscr, i, 36, "|");
	}
//	mvwprintw(stdscr, n, 1, "___________________________________");
}

void ShellUI::displayHost(HostModule *hostModule)
{
	initscr();
	curs_set(0);
	nodelay(stdscr, true);
	keypad(stdscr, true);
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
	if (cpuModule)
	{
		int n = _host;
		attron(COLOR_PAIR(1));
		mvwprintw(stdscr, 1 + n, 1, "CPU:");
		mvwprintw(stdscr, 3 + n, 1, "Clock speed:");
		mvwprintw(stdscr, 5 + n, 1, "CPU user usage:");
		mvwprintw(stdscr, 7 + n, 1, "CPU wired usage:");
		mvwprintw(stdscr, 9 + n, 1, "CPU idle usage:");
		mvwprintw(stdscr, 11 + n, 1, "Amount of cores:");
		attroff(COLOR_PAIR(1));

		mvwprintw(stdscr, 2 + n, 1, cpuModule->getModel().c_str());
		mvwprintw(stdscr, 4 + n, 1, cpuModule->getClockSpeed().c_str());

		mvwprintw(stdscr, 6 + n, 1, "%.2f%%", cpuModule->getUserUsage());

		mvwprintw(stdscr, 8 + n, 1, "%.2f%%", cpuModule->getSystemUsage());

		mvwprintw(stdscr, 10 + n, 1, "%.2f%%", cpuModule->getIdleUsage());

		mvwprintw(stdscr, 12 + n, 1, "%d", cpuModule->getCores());
		mvwprintw(stdscr, 13 + n, 1, "___________________________________");
	}
}

void ShellUI::displayNet(NetModule *netModule)
{
	long 		tmpL;
	std::string	tmpS;

	if (netModule)
	{
		int n = _host + _cpu;
		attron(COLOR_PAIR(5));
		mvwprintw(stdscr, 1 + n, 1, "Packages sent:");
		mvwprintw(stdscr, 3 + n, 1, "Packages received:");
		attroff(COLOR_PAIR(5));

		tmpL = netModule->getCurRecPackages();
		tmpS = std::to_string(tmpL) + "/" + std::to_string(netModule->getMaxRecPackages() / 1000000) + "M";
		mvwprintw(stdscr, 2 + n, 1, tmpS.c_str());

		tmpL = netModule->getCurSentPackages();
		tmpS = std::to_string(tmpL) + "/" + std::to_string(netModule->getMaxSentPackages() / 1000000) + "M";
		mvwprintw(stdscr, 4 + n, 1, tmpS.c_str());
		mvwprintw(stdscr, 5 + n, 1, "___________________________________");
	}
}

void ShellUI::displayRam(RamModule *ramModule)
{
	long 		tmpL;
	std::string	tmpS;

	if (ramModule)
	{
		int n = _host + _cpu + _net;
		attron(COLOR_PAIR(3));
		mvwprintw(stdscr, 1 + n, 1, "Used memory:");
		mvwprintw(stdscr, 3 + n, 1, "Wired memory:");
		mvwprintw(stdscr, 5 + n, 1, "Unused memory:");
		attroff(COLOR_PAIR(3));
		tmpL = ramModule->getUsed() / 1000000;
		tmpS = std::to_string(tmpL) + "M";
		mvwprintw(stdscr, 2 + n, 1, "                    ");
		mvwprintw(stdscr, 2 + n, 1, tmpS.c_str());

		tmpL = ramModule->getWired() / 1000000;
		tmpS = std::to_string(tmpL) + "M";
		mvwprintw(stdscr, 4 + n, 1, "                    ");
		mvwprintw(stdscr, 4 + n, 1, tmpS.c_str());

		tmpL = ramModule->getUnused() / 1000000;
		tmpS = std::to_string(tmpL) + "M";
		mvwprintw(stdscr, 6 + n, 1, "                    ");
		mvwprintw(stdscr, 6 + n, 1, tmpS.c_str());
		mvwprintw(stdscr, 7 + n, 1, "___________________________________");
	}
}

void ShellUI::displayCat()
{
	int n = _host + _cpu + _net + _ram + 3;
	if (_cat % 3 == 0)
		mvwprintw(stdscr, 1 + n, 1, "  |\\_._/|               |\\_._/|\n"
									"   | o o |               | o o |\n"
									"   (  T  )               (  T  )\n"
									"  .^`-^-'^.              ^`-^-'^.\n"
									"  `.  ;  .'             `.  ;  .'\n"
									"  | | | | |             | | | | |\n"
									" ((_((|))_))           ((_((|))_))");
	else if (_cat % 3 == 1)
		mvwprintw(stdscr, 1 + n, 1, "  |,\\__/|               |\\__/,|\n"
									"   |  o o|               |o o  |\n"
									"   (   T )               ( T   )\n"
									"  .^`--^'^.             .^`^--'^.\n"
									"  `.  ;  .'             `.  ;  .'\n"
									"  | | | | |             | | | | |\n"
									" ((_((|))_))           ((_((|))_))");
	else
		mvwprintw(stdscr, 1 + n, 1, "  |\\__/,|               |,\\__/|\n"
									"   |o o  |               |  o o|\n"
									"   ( T   )               (   T )\n"
									"  .^`^--'^.             .^`^--'^.\n"
									"  `.  ;  .'             `.  ;  .'\n"
									"  | | | | |             | | | | | \n"
									" ((_((|))_))           ((_((|))_))");
	mvwprintw(stdscr, 1 + n + 7, 1, "-----------           -----------");
	_cat++;
}

int ShellUI::_cat = 0;
