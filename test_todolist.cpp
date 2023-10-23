#include <gtest/gtest.h>
#include "TodoList.h"

TEST(TodoListTest, AddTask) {
    TodoList todoList;
    todoList.addTask("Task 1", "To-Do");
    todoList.addTask("Task 2", "In Progress");
    ASSERT_EQ(todoList.getTasks().size(), 2);
}

TEST(TodoListTest, ChangeTaskStatus) {
    TodoList todoList;
    todoList.addTask("Task 1", "To-Do");
    todoList.changeTaskStatus("Task 1", "In Progress");
    ASSERT_EQ(todoList.getTaskStatus("Task 1"), "In Progress");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TES
    TS();
}