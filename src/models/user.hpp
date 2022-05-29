#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User  
{
private:
	int id;
	std::string name;
	std::string mail;
	std::string sex;
	std::string birth_date;
	std::string adress;
	std::string password;
	int permissions;

public:
	User(std::string name,
		 std::string mail,
		 std::string sex,
		 std::string password,
		 std::string birth_date,
		 std::string adress,
		 int permissions,
		 int id);
	User();
	~User();
	int getUserPermissions();
	std::string getMail();
	int getId();
};

#endif // USER_H