#ifndef GRADEMANAGER_H
#define GRADEMANAGER_H

#include "../bd/gradeRepo.hpp"
#include "../models/grade.hpp"
#include <vector>

class GradeManager
{
private:
	GradeRepo* repository;

public:
	GradeManager(GradeRepo& repository);
	~GradeManager() = default;

	int addGrade(int value, std::string date, int user_id, int product_id);
	Grade getGrade(int id);
	void deleteGrade(int id);
	void updateGradeValue(int id, int value);
	std::vector<Grade> getGradesByProduct(int productId);
};

#endif // GRADEMANAGER_H