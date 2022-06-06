#include "gradePresenter.hpp"

GradePresenter::GradePresenter(GradeManager& manager)
{
	this->manager = &manager;
}

void GradePresenter::addGrade()
{
	int value = 0, user_id = 0, product_id = 0;
	std::string date = "2022-06-06";

	std::cout << "Введите значение оценки: ";
	std::cin >> value;
	std::cout << "Введите user_id: ";
	std::cin >> user_id;
	std::cout << "Введите product_id: ";
	std::cin >> product_id;

	if(manager->addGrade(value, date, user_id, product_id))
	{
		std::cout << "Что-то пошло не так..." << std::endl;
	}
	else
	{
		std::cout << "Операция прошла успешно." << std::endl;
	}
}

void GradePresenter::deleteGrade()
{
	int id = 0;
	std::cout << "Введите grade_id: ";
	std::cin >> id;

	if(manager->getGrade(id).getId() == 0)
	{
		std::cout << "Оценки с таким id не существует." << std::endl;
	}
	else
	{
		if(manager->deleteGrade(id))
		{
			std::cout << "Что-то пошло не так..." << std::endl;
		}
		else
		{
			std::cout << "Операция прошла успешно." << std::endl;
		}
	}
}

void GradePresenter::getGradesByProduct()
{
	int id = 0;
	std::cout << "Введите product_id: ";
	std::cin >> id;

	std::vector<Grade> grades = manager->getGradesByProduct(id);
	if(!grades.size())
	{
		std::cout << "Оценки отсутствуют." << std::endl;
	}
	else
	{
		for(Grade grade : grades)
		{
			std::cout << grade.toString() << std::endl;
		}
	}
}