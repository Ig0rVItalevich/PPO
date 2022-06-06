#include "gradeRepo.hpp"

int GradeRepo::addGrade(int value, std::string date, int user_id, int product_id)
{
	try
	{
		txn->exec("INSERT INTO grades (value, grade_date, user_id) \
              VALUES (" +
				  txn->quote(value) + ", " + txn->quote(date) + ", " + txn->quote(user_id) + ");");

		int id = 0;
		pqxx::result res{txn->exec("SELECT max(grade_id) FROM grades;")};
		for(auto row : res)
		{
			id = row[0].as<int>();
		}

		txn->exec("INSERT INTO products_grades (product_id, grade_id) \
              VALUES (" +
				  txn->quote(product_id) + ", " + txn->quote(id) + ");");
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}

Grade GradeRepo::getGrade(int id)
{
	Grade grade = Grade();
	pqxx::result res{txn->exec(
		"SELECT value, grade_date, user_id FROM grades WHERE grade_id = " + txn->quote(id) + ";")};

	for(auto row : res)
	{
		grade = Grade(id, row[0].as<int>(), row[1].as<std::string>(), row[2].as<int>());
	}

	return grade;
}

int GradeRepo::deleteGrade(int id)
{
	try
	{
		txn->exec("DELETE FROM grades WHERE grade_id = " + txn->quote(id) + ";");
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}

void GradeRepo::updateGradeValue(int id, int value)
{
	txn->exec("UPDATE grades SET value  = " + txn->quote(value) +
			  "WHERE grade_id = " + txn->quote(id) + ";");
}

std::vector<Grade> GradeRepo::getGradesByProduct(int productId)
{
	std::vector<Grade> grades;
	pqxx::result res{
		txn->exec("SELECT grade_id, value, grade_date, user_id FROM grades JOIN products_grades "
				  "USING(grade_id) WHERE product_id = " +
				  txn->quote(productId) + ";")};

	for(auto row : res)
	{
		Grade grade =
			Grade(row[0].as<int>(), row[1].as<int>(), row[2].as<std::string>(), row[3].as<int>());
		grades.push_back(grade);
	}

	return grades;
}