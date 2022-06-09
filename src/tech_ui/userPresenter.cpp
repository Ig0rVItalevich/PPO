#include "userPresenter.hpp"

UserPresenter::UserPresenter(UserManager& manager)
{
	LOG(DEBUG) << "Создан UserPresenter";
	this->manager = &manager;
}

void UserPresenter::addApp(App* application)
{
	LOG(DEBUG) << "Вызвано addApp Presenter";
	this->application = application;
}

void UserPresenter::addUser()
{
	LOG(DEBUG) << "Вызвано addUser Presenter";
	std::string name = "", mail = "", sex = "", password = "", birth_date = "", address = "";
	int permissions = 0;

	this->application->printer("Введите имя: ");
	name = this->application->scanner();
	this->application->printer("Введите почту: ");
	mail = this->application->scanner();
	this->application->printer("Введите пол: ");
	sex = this->application->scanner();
	this->application->printer("Введите пароль: ");
	password = this->application->scanner();
	this->application->printer("Введите дату рождения(гггг-мм-дд): ");
	birth_date = this->application->scanner();
	this->application->printer("Введите адресс: ");
	address = this->application->scanner();

	if(manager->addUser(name, mail, sex, password, birth_date, address, permissions))
	{
		LOG(ERROR) << "Ошибка addUser Presenter";
		this->application->printer("Что-то пошло не так...");
	}
	else
	{
		this->application->printer("Операция прошла успешно.");
	}
}

void UserPresenter::deleteUser()
{
	LOG(DEBUG) << "Вызвано deleteUser Presenter";
	int id = 0;
	this->application->printer("Введите user_id: ");
	id = std::stoi(this->application->scanner());

	if(manager->getUser(id).getId() == 0)
	{
		LOG(WARNING) << "Пользователя с таким id не существует deleteUser Presenter";
		this->application->printer("Пользователя с таким id не существует.");
	}
	else
	{
		if(manager->deleteUser(id))
		{
			LOG(ERROR) << "Ошибка deleteUser Presenter";
			this->application->printer("Что-то пошло не так...");
		}
		else
		{
			this->application->printer("Операция прошла успешно.");
		}
	}
}

void UserPresenter::getUser()
{
	LOG(DEBUG) << "Вызвано getUser Presenter";
	int id = 0;
	this->application->printer("Введите user_id: ");
	id = std::stoi(this->application->scanner());

	User user = manager->getUser(id);
	if(user.getId() == 0)
	{
		LOG(WARNING) << "Пользователя с таким id не существует getUser Presenter";
		this->application->printer("Пользователя с таким id не существует.");
	}
	else
	{
		this->application->printer(user.toString());
	}
}