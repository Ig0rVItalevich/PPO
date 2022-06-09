#ifndef GRADEPRESENTER_H
#define GRADEPRESENTER_H

#include "../logging/easylogging++.h"
#include "../logic/gradeManager.hpp"
#include "../models/grade.hpp"
#include "app.hpp"

#include <vector>
#include <iostream>
#include <string>

class App;

class GradePresenter
{
private:
	GradeManager* manager;
	App* application;

public:
	GradePresenter(GradeManager& manager);
	~GradePresenter() = default;

	void addApp(App* application);

	void addGrade();
    void deleteGrade();
    void getGradesByProduct();
};

#endif // GRADEPRESENTER_H