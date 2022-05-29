#ifndef GRADEMANAGER_H
#define GRADEMANAGER_H

#include "../db/gradeRepo.hpp"
#include "../models/grade.hpp"
#include <vector>

class GradeManager
{
private:
	GradeRepo* repository;

public:
	GradeManager(GradeRepo& repository);
	~GradeManager();

	void addGrade(int value, std::string date, int user_id);
	Grade getGrade(int id);
	void deleteGrade(int id);
	void updateGradeValue(int id, int value);
	std::vector<Grade> getGradesByProduct(int productId);
};

#endif // GRADEMANAGER_H