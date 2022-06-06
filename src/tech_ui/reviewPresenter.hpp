#ifndef REVIEWPRESENTER_H
#define REVIEWPRESENTER_H

#include "../logic/reviewManager.hpp"
#include "../models/review.hpp"

#include <vector>
#include <iostream>
#include <string>

class ReviewPresenter
{
private:
	ReviewManager* manager;

public:
	ReviewPresenter(ReviewManager& manager);
	~ReviewPresenter() = default;

	void addReview();
    void deleteReview();
    void getReviewsByProduct();
};

#endif // REVIEWPRESENTER_H