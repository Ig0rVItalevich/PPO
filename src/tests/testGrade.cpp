#include <gtest/gtest.h>

#include "../bd/gradeRepo.hpp"
#include "../logic/gradeManager.hpp"
#include "../models/grade.hpp"

GradeRepo gr_repository = GradeRepo();
GradeManager gr_manager(gr_repository);

TEST(grade, addGrade)
{
	// EXPECT_EQ(0, gr_manager.addGrade(1, "2010-10-02", 17, 1));
}

TEST(grade, getGrade)
{
	// gr_manager.addGrade(1, "2012-10-02", 17, 1);
	EXPECT_EQ(1, gr_manager.getGrade(1).getId());
}

TEST(grade, deleteGrade)
{
	// gr_manager.addGrade(1, "2012-10-02", 17, 1)
	// EXPECT_EQ(2, gr_manager.getGrade(2).getId());
	// gr_manager.deleteGrade(2);
	// EXPECT_EQ(0, gr_manager.getGrade(2).getId());
}

TEST(grade, updateGradeValue)
{
	gr_manager.updateGradeValue(1, -1);
	EXPECT_EQ(-1, gr_manager.getGrade(1).getValue());
}