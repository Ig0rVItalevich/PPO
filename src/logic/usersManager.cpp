#include "usersManager.hpp"

UserManager::UserManager(UserRepo& repository)
{
	this->repository = &repository;
	LOG(DEBUG) << "Создан UserManager";
}

int UserManager::addUser(std::string name,
						 std::string mail,
						 std::string sex,
						 std::string password,
						 std::string birth_date,
						 std::string address,
						 int permissions)
{
	LOG(DEBUG) << "Вызов addUser BusinessLogic";
	return this->repository->addUser(name, mail, sex, password, birth_date, address, permissions);
}

int UserManager::getUserId(std::string mail)
{
	LOG(DEBUG) << "Вызов getUserId BusinessLogic";
	int id = this->repository->getUserId(mail);

	return id;
}

User UserManager::getUser(int id)
{
	LOG(DEBUG) << "Вызов getUser BusinessLogic";
	User user = this->repository->getUser(id);

	return user;
}

int UserManager::deleteUser(int id)
{
	LOG(DEBUG) << "Вызов deleteUser BusinessLogic";
	return this->repository->deleteUser(id);
}

bool UserManager::existUser(std::string mail)
{
	LOG(DEBUG) << "Вызов existUser BusinessLogic";
	bool check = this->repository->existUser(mail);

	return check;
}

void UserManager::updateUserName(int id, std::string name)
{
	LOG(DEBUG) << "Вызов updateUserName BusinessLogic";
	this->repository->updateUserName(id, name);
}

void UserManager::updateUserMail(int id, std::string mail)
{
	LOG(DEBUG) << "Вызов updateUserMail BusinessLogic";
	this->repository->updateUserMail(id, mail);
}

void UserManager::updateUserPassword(int id, std::string password)
{
	LOG(DEBUG) << "Вызов updateUserPassword BusinessLogic";
	this->repository->updateUserPassword(id, password);
}

void UserManager::updateUserAddress(int id, std::string address)
{
	LOG(DEBUG) << "Вызов updateUserAddress BusinessLogic";
	this->repository->updateUserAddress(id, address);
}