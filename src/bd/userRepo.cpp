#include "userRepo.hpp"

int UserRepo::addUser(std::string name,
					  std::string mail,
					  std::string sex,
					  std::string password,
					  std::string birth_date,
					  std::string address,
					  int permissions)
{
	LOG(DEBUG) << "Вызов addUser Database";
	try
	{
		txn->exec(
			"INSERT INTO users (user_name, mail, birth_date, sex, address, permissions, user_password)\
              VALUES (" +
			txn->quote(name) + ", " + txn->quote(mail) + ", " + txn->quote(birth_date) + ", " +
			txn->quote(sex) + ", " + txn->quote(address) + ", " + txn->quote(permissions) + ", " +
			txn->quote(password) + ");");
	}
	catch(std::exception& e)
	{
		LOG(ERROR) << "Ошибка addUser Database" << e.what();
		return 1;
	}

	return 0;
}

int UserRepo::getUserId(std::string mail)
{
	LOG(DEBUG) << "Вызов getUserId Database";
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
	LOG(DEBUG) << "Вызов getUser Database";
	User user = User();
	pqxx::result res{txn->exec("SELECT user_name, mail, sex, birth_date, address, permissions FROM "
							   "users WHERE user_id = " +
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

int UserRepo::deleteUser(int id)
{
	LOG(DEBUG) << "Вызов deleteUser Database";
	try
	{
		txn->exec("DELETE FROM users WHERE user_id = " + txn->quote(id) + ";");
	}
	catch(std::exception& e)
	{
		LOG(ERROR) << "Ошибка deleteUser Database" << e.what();
	}

	return 0;
}

bool UserRepo::existUser(std::string mail)
{
	LOG(DEBUG) << "Вызов existUser Database";
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
	LOG(DEBUG) << "Вызов updateUserName Database";
	txn->exec("UPDATE users SET user_name  = " + txn->quote(name) +
			  "WHERE user_id = " + txn->quote(id) + ";");
}

void UserRepo::updateUserMail(int id, std::string mail)
{
	LOG(DEBUG) << "Вызов updateUserMail Database";
	txn->exec("UPDATE users SET mail  = " + txn->quote(mail) + "WHERE user_id = " + txn->quote(id) +
			  ";");
}

void UserRepo::updateUserPassword(int id, std::string password)
{
	LOG(DEBUG) << "Вызов updateUserPassword Database";
	txn->exec("UPDATE users SET user_password  = " + txn->quote(password) +
			  "WHERE user_id = " + txn->quote(id) + ";");
}

void UserRepo::updateUserAddress(int id, std::string address)
{
	LOG(DEBUG) << "Вызов updateUserAddress Database";
	txn->exec("UPDATE users SET address  = " + txn->quote(address) +
			  "WHERE user_id = " + txn->quote(id) + ";");
}