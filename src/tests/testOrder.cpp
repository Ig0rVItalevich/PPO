#include <gtest/gtest.h>

#include "../bd/orderRepo.hpp"
#include "../logic/orderManager.hpp"
#include "../models/order.hpp"
#include "../models/product.hpp"

#include <vector>

OrderRepo or_repository = OrderRepo();
OrderManager or_manager(or_repository);

TEST(order, addOrder)
{
  std::vector<Product> products = {};
	// EXPECT_EQ(0, or_manager.addOrder("dfsdfsdf", "asdasda", "2014-10-02", 17, products));
}

TEST(order, getOrder) {
  std::vector<Product> products = {};
  or_manager.addOrder("dfsdfsdf", "asdasdfaa", "2013-10-02", 17, products);
  EXPECT_EQ(1, or_manager.getOrder(1).getId());
}

TEST(order, deleteOrder) {
  std::vector<Product> products = {};
  // or_manager.addOrder("dfsasdfsdf", "asdasdffa", "2011-10-02", 17, products);
  // EXPECT_EQ(2, or_manager.getOrder(2).getId());
  // or_manager.deleteGrade(2);
  // EXPECT_EQ(0, or_manager.getOrder(2).getId());
}

TEST(order, updateOrderStatus) {
  or_manager.updateOrderStatus(1, "cvxvxc");
  EXPECT_EQ("cvxvxc", or_manager.getOrder(1).getStatus());
}