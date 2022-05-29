#include "user.hpp"

User::User(std::string name,
		   std::string mail,
		   std::string sex,
		   std::string password,
		   std::string birth_date,
		   std::string adress,
		   int permissions,
		   int id = 0)
{
	this->id = id;
	this->name = name;
    this->mail = mail;
    this->sex = sex;
    this->birth_date = birth_date;
    this->adress = adress;
	this->password = password;
	this->permissions = permissions;
}

User::User()
{
	this->id = 0;
	this->name = "";
    this->mail = "";
    this->sex = "";
    this->birth_date = "";
    this->adress = "";
	this->password = "";
	this->permissions = 0;
}

User::~User() { }

int User::getUserPermissions()
{
	return this->permissions;
}

int User::getId()
{
	return this->id;
}

std::string User::getMail()
{
	return this->mail;
}