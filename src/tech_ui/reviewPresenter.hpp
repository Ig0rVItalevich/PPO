#ifndef REVIEWPRESENTER_H
#define REVIEWPRESENTER_H

#include "../logging/easylogging++.h"
#include "../logic/reviewManager.hpp"
#include "../models/review.hpp"
#include "app.hpp"

#include <vector>
#include <iostream>
#include <string>

class App;

class ReviewPresenter
{
private:
	ReviewManager* manager;
	App* application;

public:
	ReviewPresenter(ReviewManager& manager);
	~ReviewPresenter() = default;

	void addApp(App* application);

	void addReview();
    void deleteReview();
    void getReviewsByProduct();
};

#endif // REVIEWPRESENTER_H