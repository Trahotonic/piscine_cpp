#include "Contact.class.hpp"

void    addContact(Contact *contact_list[8])
{
    std::string buffer;

    if (Contact::getObjCount() == 8)
    {
        std::cout << "\nContact list is full\n\n";
        return ;
    }
    Contact *adder = new Contact;
    std::cout << "\nAdding new contact" << std::endl << std::endl;
    std::cout << "Enter first name: ";
    std::cin >> buffer;
    adder->setFirstName(buffer);
    buffer.clear();

    std::cout << "Enter last name: ";
    std::cin >> buffer;
    adder->setLastName(buffer);
    buffer.clear();

    std::cout << "Enter nickname: ";
    std::cin >> buffer;
    adder->setNickName(buffer);
    buffer.clear();

    std::cout << "Enter login: ";
    std::cin >> buffer;
    adder->setLogin(buffer);
    buffer.clear();

    std::cout << "Enter postal address: ";
    std::cin >> buffer;
    adder->setPostalAddress(buffer);
    buffer.clear();

    std::cout << "Enter email address: ";
    std::cin >> buffer;
    adder->setEmailAddress(buffer);
    buffer.clear();

    std::cout << "Enter phone number: ";
    std::cin.ignore();
    std::getline(std::cin, buffer);
    adder->setPhoneNumber(buffer);
    buffer.clear();

    std::cout << "Enter birthday date: ";
    std::cin >> buffer;
    adder->setBirthdayDate(buffer);
    buffer.clear();

    std::cout << "Enter favourite meal: ";
    std::cin >> buffer;
    adder->setFavouriteMeal(buffer);
    buffer.clear();

    std::cout << "Enter underwear color: ";
    std::cin >> buffer;
    adder->setUnderwearColor(buffer);
    buffer.clear();

    std::cout << "Enter darkest secret: ";
    std::cin >> buffer;
    adder->setDarkestSecret(buffer);
    buffer.clear();
    contact_list[Contact::getObjCount() - 1] = adder;
    std::cout << std::endl << "Contact added" << std::endl << std::endl;
}