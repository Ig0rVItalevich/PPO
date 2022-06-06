#ifndef USERPRESENTER_H
#define USERPRESENTER_H

#include "../logic/usersManager.hpp"
#include "../models/user.hpp"

#include <iostream>
#include <string>

class UserPresenter
{
private:
	UserManager* manager;

public:
	UserPresenter(UserManager& manager);
	~UserPresenter() = default;

	void addUser();
    void deleteUser();
    void getUser();
};

#endif // USERPRESENTER_H