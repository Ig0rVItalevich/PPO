#ifndef USERREPO_H
#define USERREPO_H

#include "../logging/easylogging++.h"
#include "../models/user.hpp"
#include <iostream>
#include <string>

#include <pqxx/pqxx>

class InterfaceUserRepo
{
public:
	InterfaceUserRepo(){};
	~InterfaceUserRepo() = default;

	void addUser(std::string name,
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

class UserRepo : public InterfaceUserRepo
{
private:
	std::shared_ptr<pqxx::connection> connection;
	std::shared_ptr<pqxx::nontransaction> txn;

public:
	explicit UserRepo(std::string bd_str)
		: connection(new pqxx::connection(bd_str))
		, txn(new pqxx::nontransaction(*connection)){};
	~UserRepo() = default;

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

#endif // USERREPO_H