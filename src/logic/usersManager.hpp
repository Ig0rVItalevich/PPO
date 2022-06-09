#ifndef USERSMANAGER_H
#define USERSMANAGER_H

#include "../bd/userRepo.hpp"
#include "../models/user.hpp"
#include "../logging/easylogging++.h"

class UserManager
{
private:
	UserRepo* repository;

public:
	UserManager(UserRepo& repository);
	~UserManager() = default;

	int addUser(std::string name,
				std::string mail,
				std::string sex,
				std::string password,
				std::string birth_date,
				std::string address,
				int permissions);
	int getUserId(std::string mail);
	User getUser(int id);
	int deleteUser(int id);
	bool existUser(std::string mail);
	void updateUserName(int id, std::string name);
	void updateUserMail(int id, std::string mail);
	void updateUserPassword(int id, std::string password);
	void updateUserAddress(int id, std::string address);
};

#endif // USERSMANAGER_H