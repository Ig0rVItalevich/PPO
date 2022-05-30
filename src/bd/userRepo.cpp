#include "userRepo.hpp"

int UserRepo::addUser(std::string name,
					   std::string mail,
					   std::string sex,
					   std::string password,
					   std::string birth_date,
					   std::string address,
					   int permissions)
{
	txn->exec(
		"INSERT INTO users (user_name, mail, birth_date, sex, address, permissions, user_password)\
              VALUES (" +
		txn->quote(name) + ", " + txn->quote(mail) + ", " + txn->quote(birth_date) + ", " +
		txn->quote(sex) + ", " + txn->quote(address) + ", " + txn->quote(permissions) + ", " +
		txn->quote(password) + ");");

	return 0;
}

int UserRepo::getUserId(std::string mail)
{
	int id = 0;
	pqxx::result res{txn->exec("SELECT user_id FROM users WHERE mail = " + txn->quote(mail) + ";")};

	for(auto row : res)
	{
		id = row[0].as<int>();
	}

	return id;
}

User UserRepo::getUser(int id)
{
	User user = User();
	pqxx::result res{txn->exec(
		"SELECT user_name, mail, sex, birth_date, address, permissions FROM users WHERE user_id = " +
		txn->quote(id) + ";")};

	for(auto row : res)
	{
		user = User(row[0].as<std::string>(),
					row[1].as<std::string>(),
					row[2].as<std::string>(),
					"",
					row[3].as<std::string>(),
					row[4].as<std::string>(),
					row[5].as<int>(),
					id);
	}

	return user;
}

void UserRepo::deleteUser(int id)
{
	txn->exec("DELETE FROM users WHERE user_id = " + txn->quote(id) + ";");
}

bool UserRepo::existUser(std::string mail)
{
	bool flag = false;

	pqxx::result res{
		txn->exec("SELECT EXISTS(SELECT 1 FROM users WHERE mail = " + txn->quote(mail) + ");")};

	for(auto row : res)
	{
		try
		{
			flag = row[0].as<bool>();
		}
		catch(...)
		{
			flag = false;
		}
	}

	return flag;
}

void UserRepo::updateUserName(int id, std::string name)
{
	txn->exec("UPDATE users SET user_name  = " + txn->quote(name) +
			  "WHERE user_id = " + txn->quote(id) + ";");
}

void UserRepo::updateUserMail(int id, std::string mail)
{
	txn->exec("UPDATE users SET mail  = " + txn->quote(mail) + "WHERE user_id = " + txn->quote(id) +
			  ";");
}

void UserRepo::updateUserPassword(int id, std::string password)
{
	txn->exec("UPDATE users SET user_password  = " + txn->quote(password) +
			  "WHERE user_id = " + txn->quote(id) + ";");
}

void UserRepo::updateUserAddress(int id, std::string address)
{
	txn->exec("UPDATE users SET address  = " + txn->quote(address) +
			  "WHERE user_id = " + txn->quote(id) + ";");
}