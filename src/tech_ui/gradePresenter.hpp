#ifndef GRADEPRESENTER_H
#define GRADEPRESENTER_H

#include "../logic/gradeManager.hpp"
#include "../models/grade.hpp"

#include <vector>
#include <iostream>
#include <string>

class GradePresenter
{
private:
	GradeManager* manager;

public:
	GradePresenter(GradeManager& manager);
	~GradePresenter() = default;

	void addGrade();
    void deleteGrade();
    void getGradesByProduct();
};

#endif // GRADEPRESENTER_H