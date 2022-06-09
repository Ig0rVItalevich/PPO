#ifndef USERPRESENTER_H
#define USERPRESENTER_H

#include "../logging/easylogging++.h"
#include "../logic/usersManager.hpp"
#include "../models/user.hpp"
#include "app.hpp"

#include <iostream>
#include <string>

class App;

class UserPresenter
{
private:
	UserManager* manager;
	App* application;

public:
	UserPresenter(UserManager& manager);
	~UserPresenter() = default;

	void addApp(App* application);
	
	void addUser();
    void deleteUser();
    void getUser();
};

#endif // USERPRESENTER_H