#include <gtest/gtest.h>

#include "../bd/reviewRepo.hpp"
#include "../logic/reviewManager.hpp"
#include "../models/review.hpp"

ReviewRepo re_repository = ReviewRepo();
ReviewManager re_manager(re_repository);

TEST(review, addReview)
{
	EXPECT_EQ(0, re_manager.addReview("sdfsdfsdf", "2010-10-02", 17, 1));
}

TEST(review, getReview)
{
	re_manager.addReview("sdfsdfsdf", "2010-10-02", 17, 1);
	EXPECT_EQ(1, re_manager.getReview(1).getId());
}

TEST(review, deleteReview)
{
	// re_manager.addReview("sdfsdfsdf", "2010-10-02", 17, 1)
	// EXPECT_EQ(2, re_manager.getReview(2).getId());
	// re_manager.deleteReview(2);
	// EXPECT_EQ(0, re_manager.getReview(2).getId());
}

TEST(review, updateReviewContent)
{
	re_manager.updateReviewContent(1, "hfhdfhd");
	EXPECT_EQ("hfhdfhd", re_manager.getReview(1).getContent());
}