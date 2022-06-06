#include "userPresenter.hpp"

UserPresenter::UserPresenter(UserManager& manager)
{
	this->manager = &manager;
}

void UserPresenter::addUser()
{
	std::string name = "", mail = "", sex = "", password = "", birth_date = "", address = "";
	int permissions = 0;

	std::cout << "Введите имя: ";
	std::cin >> name;
	std::cout << "Введите почту: ";
	std::cin >> mail;
	std::cout << "Введите пол: ";
	std::cin >> sex;
	std::cout << "Введите пароль: ";
	std::cin >> password;
	std::cout << "Введите дату рождения(гггг-мм-дд): ";
	std::cin >> birth_date;
	std::cout << "Введите адресс: ";
	std::cin >> address;

	if(manager->addUser(name, mail, sex, password, birth_date, address, permissions))
	{
		std::cout << "Что-то пошло не так..." << std::endl;
	}
	else
	{
		std::cout << "Операция прошла успешно." << std::endl;
	}
}

void UserPresenter::deleteUser()
{
	int id = 0;
	std::cout << "Введите user_id: ";
	std::cin >> id;

	if(manager->getUser(id).getId() == 0)
	{
		std::cout << "Пользователя с таким id не существует." << std::endl;
	}
	else
	{
		if(manager->deleteUser(id))
		{
			std::cout << "Что-то пошло не так..." << std::endl;
		}
		else
		{
			std::cout << "Операция прошла успешно." << std::endl;
		}
	}
}

void UserPresenter::getUser()
{
	int id = 0;
	std::cout << "Введите user_id: ";
	std::cin >> id;

	User user = manager->getUser(id);
	if(user.getId() == 0)
	{
		std::cout << "Пользователя с таким id не существует." << std::endl;
	}
	else
	{
		std::cout << user.toString() << std::endl;
	}
}