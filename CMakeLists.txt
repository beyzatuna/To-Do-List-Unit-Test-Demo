cmake_minimum_required(VERSION 3.10.0)
project(TodoList)

include(CTest)
enable_testing()
add_executable(TodoList todo_list.cpp)

# Google Test kütüphanesini bul
find_package(GTest REQUIRED)

# Google Test kütüphanesini kullanmak için include ve target_link_libraries komutlarını ekleyin
include_directories(${GTEST_INCLUDE_DIRS}) # Google Test başlık dosyalarının yolu
target_link_libraries(TodoList GTest::GTest) # Google Test kütüphane dosyasının adı











