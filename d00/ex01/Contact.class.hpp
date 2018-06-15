//
// Created by Roman Kyslyy on 5/27/18.
//

#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

# include <list>
# include <iostream>
# include <cstring>

class   Contact
{
public:
    Contact(void);
    ~Contact(void);

    static int  getObjCount(void);
    void        setFirstName(std::string string);
    void        setLastName(std::string string);
    void        setNickName(std::string string);
    void        setLogin(std::string string);
    void        setPostalAddress(std::string string);
    void        setEmailAddress(std::string string);
    void        setPhoneNumber(std::string string);
    void        setBirthdayDate(std::string string);
    void        setFavouriteMeal(std::string string);
    void        setUnderwearColor(std::string string);
    void        setDarkestSecret(std::string string);
    std::string getFirstName(void);
    std::string getLastName(void);
    std::string getNickName(void);
    std::string getLogin(void);
    std::string getPostalAddress(void);
    std::string getEmailAddress(void);
    std::string getPhoneNumber(void);
    std::string getBirthdayDate(void);
    std::string getFavouriteMeal(void);
    std::string getUnderwearColor(void);
    std::string getDarkestSecret(void);
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string login;
    std::string postal_address;
    std::string email_address;
    std::string phone_number;
    std::string birthday_date;
    std::string favourite_meal;
    std::string underwear_color;
    std::string darkest_secret;
    static int  objCount;
};

void    addContact(Contact **contact_list);
void    displayContacts(Contact **contact_list);

#endif