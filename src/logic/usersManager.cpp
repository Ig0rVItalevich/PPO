#include "usersManager.hpp"

UserManager::UserManager(UserRepo &repository)
{
	this->repository = &repository;
}

int UserManager::addUser(std::string name,
						  std::string mail,
						  std::string sex,
						  std::string password,
						  std::string birth_date,
						  std::string address,
						  int permissions)
{
	return this->repository->addUser(name, mail, sex, password, birth_date, address, permissions);
}

int UserManager::getUserId(std::string mail)
{
	int id = this->repository->getUserId(mail);

	return id;
}

User UserManager::getUser(int id)
{
	User user = this->repository->getUser(id);

	return user;
}

void UserManager::deleteUser(int id)
{
	this->repository->deleteUser(id);
}

bool UserManager::existUser(std::string mail)
{
	bool check = this->repository->existUser(mail);

	return check;
}

void UserManager::updateUserName(int id, std::string name)
{
	this->repository->updateUserName(id, name);
}

void UserManager::updateUserMail(int id, std::string mail)
{
	this->repository->updateUserMail(id, mail);
}

void UserManager::updateUserPassword(int id, std::string password)
{
	this->repository->updateUserPassword(id, password);
}

void UserManager::updateUserAddress(int id, std::string address)
{
	this->repository->updateUserAddress(id, address);
}