#include "userRepo.hpp"

void UserRepo::addUser(std::string name,
					   std::string mail,
					   std::string sex,
					   std::string password,
					   std::string birth_date,
					   std::string adress,
					   int permissions)
{
	txn->exec(
		"INSERT INTO users (user_name, mail, birth_date, sex, adress, permissions, user_password)\
              VALUES (" +
		txn->quote(name) + ", " + txn->quote(mail) + ", " + txn->quote(birth_date) + ", " +
		txn->quote(sex) + ", " + txn->quote(adress) + ", " + txn->quote(permissions) + ", " +
		txn->quote(password) + ");");

	txn->commit();
}

int UserRepo::getUserId(std::string mail)
{
	int id = 0;
	pqxx::result res{txn->exec("SELECT id FROM users WHERE mail = " + txn->quote(mail) + ";")};

	for(auto row : res)
	{
		id = atoi(row[0].c_str());
	}

	return id;
}

User UserRepo::getUser(int id)
{
	User user = User();
	pqxx::result res{txn->exec(
		"SELECT user_name, mail, sex, birth_date, adress, permissions FROM users WHERE user_id = " +
		txn->quote(id) + ";")};

	for(auto row : res)
	{
		user = User(row[0].as<std::string>(),
					row[1].as<std::string>(),
					row[2].as<std::string>(),
					"",
					row[3].as<std::string>(),
					row[4].as<std::string>(),
					atoi(row[5].c_str()));
	}

	return user;
}

void UserRepo::deleteUser(int id)
{
	txn->exec("DELETE FROM users WHERE user_id = " + txn->quote(id) + ";");

	txn->commit();
}

bool UserRepo::existUser(std::string mail)
{
	bool flag = false;

	pqxx::result res{txn->exec("SELECT (SELECT user_id FROM users WHERE mail = " + txn->quote(mail) + ") = 1;")};

	for(auto row : res)
	{
		try
		{
			flag = row[0].as<bool>();
		}
		catch (...)
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

	txn->commit();
}

void UserRepo::updateUserMail(int id, std::string mail)
{
	txn->exec("UPDATE users SET mail  = " + txn->quote(mail) + "WHERE user_id = " + txn->quote(id) +
			  ";");

	txn->commit();
}

void UserRepo::updateUserPassword(int id, std::string password)
{
	txn->exec("UPDATE users SET user_password  = " + txn->quote(password) +
			  "WHERE user_id = " + txn->quote(id) + ";");

	txn->commit();
}

void UserRepo::updateUserAddress(int id, std::string address)
{
	txn->exec("UPDATE users SET address  = " + txn->quote(adress) +
			  "WHERE user_id = " + txn->quote(id) + ";");

	txn->commit();
}