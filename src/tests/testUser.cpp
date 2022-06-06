#include <gtest/gtest.h>

#include "../bd/userRepo.hpp"
#include "../logic/usersManager.hpp"
#include "../models/user.hpp"

UserRepo us_repository = UserRepo();
UserManager us_manager(us_repository);

TEST(user, addUser)
{
	// us_manager.addUser("Кирилл", "fsdfsdfsd@mail.ru", "Мужчина", "qwerty123", "2000-02-01", "г. Москва", 0);
	EXPECT_EQ(1, us_manager.existUser("fsdfsdfsd@mail.ru"));
}

TEST(user, getUserId)
{
	EXPECT_EQ(17, us_manager.getUserId("qwerty@mail.ru"));
}

TEST(user, getUser)
{
	// us_manager.addUser("Азамат", "qwerty@mail.ru", "Мужчина", "qwerty123", "2000-02-01", "г. Москва", 0);
	EXPECT_EQ(17, us_manager.getUser(17).getId());
}

TEST(user, deleteUser)
{
	// us_manager.addUser("Динара", "zxczxc@mail.ru", "Женщина", "qwerty123", "2000-02-01", "г. Москва", 0);
	EXPECT_EQ(18, us_manager.getUser(18).getId());
	us_manager.deleteUser(18);
	EXPECT_EQ(0, us_manager.getUser(18).getId());
}

TEST(user, existUser)
{
	EXPECT_EQ(1, us_manager.existUser("qwerty@mail.ru"));
}

TEST(user, notExistUser)
{
	EXPECT_EQ(0, us_manager.existUser("notexistmail"));
}

TEST(user, updateUserName)
{
	us_manager.updateUserName(17, "Вася");
	EXPECT_EQ("Вася", us_manager.getUser(17).getName());
}