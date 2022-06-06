cmake_minimum_required(VERSION 3.16)

project(ppo)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -g3")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wpedantic -g3")

enable_testing()
include_directories(./bd ./logic ./models ./tech_ui)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(unit.out tests/tests.cpp 
                                        tests/testUser.cpp models/user.cpp logic/usersManager.cpp bd/userRepo.cpp
                                        tests/testGrade.cpp models/grade.cpp logic/gradeManager.cpp bd/gradeRepo.cpp
                                        tests/testReview.cpp models/review.cpp logic/reviewManager.cpp bd/reviewRepo.cpp
                                        tests/testOrder.cpp models/order.cpp logic/orderManager.cpp bd/orderRepo.cpp
                                        tests/testProduct.cpp models/product.cpp logic/productManager.cpp bd/productRepo.cpp)
target_link_libraries(unit.out ${GTEST_LIBRARIES} -lpqxx -lpq -pthread)

add_executable(main.out tech_ui/main.cpp tech_ui/app.cpp
                                        tech_ui/userPresenter.cpp models/user.cpp logic/usersManager.cpp bd/userRepo.cpp
                                        tech_ui/gradePresenter.cpp models/grade.cpp logic/gradeManager.cpp bd/gradeRepo.cpp
                                        tech_ui/reviewPresenter.cpp models/review.cpp logic/reviewManager.cpp bd/reviewRepo.cpp
                                        tech_ui/orderPresenter.cpp models/order.cpp logic/orderManager.cpp bd/orderRepo.cpp
                                        tech_ui/productPresenter.cpp models/product.cpp logic/productManager.cpp bd/productRepo.cpp)
target_link_libraries(main.out -lpqxx -lpq -pthread)