#include "gradeManager.hpp"

GradeManager::GradeManager(GradeRepo& repository)
{
	this->repository = &repository;
}

int GradeManager::addGrade(int value, std::string date, int user_id, int product_id)
{
	return this->repository->addGrade(value, date, user_id, product_id);
}

Grade GradeManager::getGrade(int id)
{
	Grade grade = this->repository->getGrade(id);

	return grade;
}

int GradeManager::deleteGrade(int id)
{
	return this->repository->deleteGrade(id);
}

void GradeManager::updateGradeValue(int id, int value)
{
	this->repository->updateGradeValue(id, value);
}

std::vector<Grade> GradeManager::getGradesByProduct(int productId)
{
	std::vector<Grade> grades = this->repository->getGradesByProduct(productId);

	return grades;
}