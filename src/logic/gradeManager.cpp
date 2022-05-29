#include "gradeManager.hpp"

GradeManager::GradeManager(GradeRepo& repository)
{
	this->repository = repository;
}

~GradeManager::GradeManager() { }

void ReviewManager::addGrade(int value, std::string date, int user_id)
{
	this->repository->addGrade(value, date, user_id);
}

Grade GradeManager::getGrade(int id)
{
	Grade grade = this->repository->getGrade(id);

	return grade;
}

void GradeManager::deleteGrade(int id)
{
	this->repository->deleteGrade(id);
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