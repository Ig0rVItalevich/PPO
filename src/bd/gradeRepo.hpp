#ifndef GRADEREPO_H
#define GRADEREPO_H

#include "../models/grade.hpp"
#include <iostream>
#include <string>

class InterfaceGradeRepo
{
public:
	InterfaceGradeRepo();
	~InterfaceGradeRepo() = default;

	void addGrade(int value, std::string date, int user_id, int product_id);
	Grade getGrade(int id);
	void deleteGrade(int id);
	void updateGradeValue(int id, int value);
	std::vector<Grade> getGradesByProduct(int productId);
};

class GradeRepo : public InterfaceGradeRepo
{
private:
	std::shared_ptr<pqxx::connection> connection;
	std::shared_ptr<pqxx::work> txn;

public:
	explicit GradeRepo()
		: connection(new pqxx::connection("postgresql://postgres:qwerty123@localhost/ppo"))
		, txn(new pqxx::work(*connection)){};
	~GradeRepo() = default;

	void addGrade(int value, std::string date, int user_id, int product_id);
	Grade getGrade(int id);
	void deleteGrade(int id);
	void updateGradeValue(int id, int value);
	std::vector<Grade> getGradesByProduct(int productId);
};

#endif // GRADEREPO_H