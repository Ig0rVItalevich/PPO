#include <gtest/gtest.h>

#include "../bd/productRepo.hpp"
#include "../logic/productManager.hpp"
#include "../models/product.hpp"

ProductRepo pr_repository = ProductRepo();
ProductManager pr_manager(pr_repository);

TEST(product, addProduct)
{
	// EXPECT_EQ(0, pr_manager.addProduct("qweqw", "asdasd", "dsfsdfsd", 2, 213, "fasdassdf", 4));
}

TEST(product, getProduct)
{
	// pr_manager.addProduct("sadasdfa", "asdasd", "dsfsdfsd", 2, 213, "sdfsdf", 4);
	EXPECT_EQ(1, pr_manager.getProduct(1).getId());
}

TEST(product, deleteProduct)
{
	// pr_manager.addProduct("bcvbcvb", "asdasd", "dsfsdfsd", 2, 213, "sdfsdf", 4)
	// EXPECT_EQ(2, pr_manager.getProduct(2).getId());
	// pr_manager.deleteProduct(2);
	// EXPECT_EQ(0, pr_manager.getProduct(2).getId());
}

TEST(product, updateProductTitle)
{
	pr_manager.updateProductTitle(1, "dfsdfsdf");
	EXPECT_EQ("dfsdfsdf", pr_manager.getProduct(1).getTitle());
}