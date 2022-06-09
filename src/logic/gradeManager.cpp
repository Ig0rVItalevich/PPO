#include "gradeManager.hpp"

GradeManager::GradeManager(GradeRepo& repository)
{
	this->repository = &repository;
	LOG(DEBUG) << "Создан GradeManager";
}

int GradeManager::addGrade(int value, std::string date, int user_id, int product_id)
{
	LOG(DEBUG) << "Вызов addGrade BusinessLogic";
	return this->repository->addGrade(value, date, user_id, product_id);
}

Grade GradeManager::getGrade(int id)
{
	LOG(DEBUG) << "Вызов getGrade BusinessLogic";
	Grade grade = this->repository->getGrade(id);

	return grade;
}

int GradeManager::deleteGrade(int id)
{
	LOG(DEBUG) << "Вызов deleteGrade BusinessLogic";
	return this->repository->deleteGrade(id);
}

void GradeManager::updateGradeValue(int id, int value)
{
	LOG(DEBUG) << "Вызов updateGradeValue BusinessLogic";
	this->repository->updateGradeValue(id, value);
}

std::vector<Grade> GradeManager::getGradesByProduct(int productId)
{
	LOG(DEBUG) << "Вызов getGradesByProduct BusinessLogic";
	std::vector<Grade> grades = this->repository->getGradesByProduct(productId);

	return grades;
}