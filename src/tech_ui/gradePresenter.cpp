#include "gradePresenter.hpp"

GradePresenter::GradePresenter(GradeManager& manager)
{
	this->manager = &manager;

	LOG(DEBUG) << "Создан GradePresenter";
}

void GradePresenter::addApp(App* application)
{
	LOG(DEBUG) << "Вызвано addApp Presenter";
	this->application = application;
}

void GradePresenter::addGrade()
{
	LOG(DEBUG) << "Вызвано addGrade Presenter";
	int value = 0, user_id = 0, product_id = 0;
	std::string date = "2022-06-06";

	this->application->printer("Введите значение оценки: ");
	value = std::stoi(this->application->scanner());
	this->application->printer("Введите user_id: ");
	user_id = std::stoi(this->application->scanner());
	this->application->printer("Введите product_id: ");
	product_id = std::stoi(this->application->scanner());

	if(manager->addGrade(value, date, user_id, product_id))
	{
		LOG(ERROR) << "Ошибка addGrade Presenter";
		this->application->printer("Что-то пошло не так...");
	}
	else
	{
		this->application->printer("Операция прошла успешно.");
	}
}

void GradePresenter::deleteGrade()
{
	LOG(DEBUG) << "Вызвано deleteGrade Presenter";
	int id = 0;
	this->application->printer("Введите grade_id: ");
	id = std::stoi(this->application->scanner());

	if(manager->getGrade(id).getId() == 0)
	{
		LOG(WARNING) << "Оценки с таким id не существует deleteGrade Presenter";
		this->application->printer("Оценки с таким id не существует.");
	}
	else
	{
		if(manager->deleteGrade(id))
		{
			LOG(ERROR) << "Ошибка deleteGrade Presenter";
			this->application->printer("Что-то пошло не так...");
		}
		else
		{
			this->application->printer("Операция прошла успешно.");
		}
	}
}

void GradePresenter::getGradesByProduct()
{
	LOG(DEBUG) << "Вызвано getGradesByProduct Presenter";
	int id = 0;
	this->application->printer("Введите product_id: ");
	id = std::stoi(this->application->scanner());

	std::vector<Grade> grades = manager->getGradesByProduct(id);
	if(!grades.size())
	{
		LOG(WARNING) << "Оценки отсутствуют getGradesByProduct Presenter";
		this->application->printer("Оценки отсутствуют.");
	}
	else
	{
		for(Grade grade : grades)
		{
			this->application->printer(grade.toString());
		}
	}
}