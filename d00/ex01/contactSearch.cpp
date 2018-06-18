#include "Contact.class.hpp"

void    doFirstName(Contact *it)
{
    unsigned long   m;
    size_t          ptr;

    if (it->getFirstName().length() > 10)
    {
        ptr = 0;
        while (ptr < 9)
            std::cout << it->getFirstName()[ptr++];
        std::cout << ".";
    }
    else
    {
        m = 0;
        while (m < 10 - it->getFirstName().length())
        {
            std::cout << " ";
            m++;
        }
        std::cout << it->getFirstName();
    }
    std::cout << "|";
}

void    doLastName(Contact *it)
{
    unsigned long   m;
    size_t          ptr;

    if (it->getLastName().length() > 10)
    {
        ptr = 0;
        while (ptr < 9)
            std::cout << it->getLastName()[ptr++];
        std::cout << ".";
    }
    else
    {
        m = 0;
        while (m < 10 - it->getLastName().length())
        {
            std::cout << " ";
            m++;
        }
        std::cout << it->getLastName();
    }
    std::cout << "|";
}

void    doNickName(Contact *it)
{
    unsigned long   m;
    size_t          ptr;

    if (it->getNickName().length() > 10)
    {
        ptr = 0;
        while (ptr < 9)
            std::cout << it->getNickName()[ptr++];
        std::cout << ".";
    }
    else
    {
        m = 0;
        while (m < 10 - it->getNickName().length())
        {
            std::cout << " ";
            m++;
        }
        std::cout << it->getNickName();
    }
}

int     indexInvalid(std::string string)
{
    size_t  n;

    n = 0;
    while (string[n] != '\0')
    {
        if (!isdigit(string[n]))
            return (1);
        n++;
    }
    if (std::stoi(string) > Contact::getObjCount() ||
            std::stoi(string) <= 0)
        return (1);
    return (0);
}

void    displayContacts(Contact **contact_list)
{
    int                             it;
    int                             n;
    std::string                     input;

    if (Contact::getObjCount() == 0)
    {
        std::cout << "\nThere are no contacts to show yet\n\n";
        return ;
    }
    std::cout << std::endl << "     index|first name| last name|  nickname" << std::endl;
    std::cout << "___________________________________________" << std::endl;
    it = 0;
    n = 1;
    while (it < Contact::getObjCount())
    {
        std::cout << "         " << n << "|";
        doFirstName(contact_list[it]);
        doLastName(contact_list[it]);
        doNickName(contact_list[it]);
        it++;
        n++;
        std::cout << std::endl << "___________________________________________" << std::endl;
    }
    std::cout << "\nPlease enter index of contact you`re searching for: ";
    std::cin >> input;
    while (indexInvalid(input))
    {
        input.clear();
        std::cout << "\nPlease enter valid and existing index: ";
        std::cin >> input;
    }
    it = 0;
    n = 1;
    while (n != std::stoi(input))
    {
        it++;
        n++;
    }
    std::cout << "\nFirst name:      " << contact_list[it]->getFirstName() << std::endl;
    std::cout << "Last name:       " << contact_list[it]->getLastName() << std::endl;
    std::cout << "Nickname:        " << contact_list[it]->getNickName() << std::endl;
    std::cout << "Login:           " << contact_list[it]->getLogin() << std::endl;
    std::cout << "Postal address:  " << contact_list[it]->getPostalAddress() << std::endl;
    std::cout << "Email address:   " << contact_list[it]->getEmailAddress() << std::endl;
    std::cout << "Phone number:    " << contact_list[it]->getPhoneNumber() << std::endl;
    std::cout << "Birthday date:   " << contact_list[it]->getBirthdayDate() << std::endl;
    std::cout << "Favourite meal:  " << contact_list[it]->getFavouriteMeal() << std::endl;
    std::cout << "Underwear color: " << contact_list[it]->getUnderwearColor() << std::endl;
    std::cout << "Darkest secret:  " << contact_list[it]->getDarkestSecret() << std::endl << std::endl;
}