#include <gtest/gtest.h>
#include <string>
#include "dynamic_array.hpp"

TEST(dynamic_array_tests, constructor) {
  constexpr std::size_t SIZE = 200;
  auto a = dynamic_array(SIZE);
  EXPECT_EQ(0, a.get_size());
  EXPECT_EQ(SIZE, a.get_capacity());
}

TEST(dynamic_array_tests, make_entries) {
  constexpr std::size_t SIZE = 1;
  auto a = dynamic_array(SIZE);
  EXPECT_EQ(0, a.get_size());
  EXPECT_EQ(SIZE, a.get_capacity());

  constexpr std::size_t ENTRIES = 1;
  for (int i = 0; i < ENTRIES; i++) {
    a.push_back(i);
    EXPECT_EQ(i+1, a.get_size());
    EXPECT_LE(i, a.get_capacity());
  }
}

TEST(dynamic_array_tests, get_entries) {
  constexpr std::size_t SIZE = 1;
  auto a = dynamic_array(SIZE);

  EXPECT_EQ(0, a.get_size());
  EXPECT_EQ(SIZE, a.get_capacity());

  int entries[] = {0, 1, 2, 3, 4, 5};

  for (int i = 0; i < sizeof(entries)/sizeof(int); i++) {
    a.push_back(entries[i]);
    EXPECT_EQ(i+1, a.get_size());
    EXPECT_LE(i, a.get_capacity());
  }

  for (int i = 0; i < sizeof(entries)/sizeof(int); i++) {
    EXPECT_EQ(a.get(i), entries[i]) << "at index " << std::to_string(i);
  }
}

TEST(dynamic_array_tests, get_entries_random) {
  constexpr std::size_t SIZE = 1;
  auto a = dynamic_array(SIZE);

  EXPECT_EQ(0, a.get_size());
  EXPECT_EQ(SIZE, a.get_capacity());

  int entries[] = {0, 1, 5, 234243, 234211, 23, 2323, 34, 23342, 32323, 456, 7251, 2342};

  for (int i = 0; i < sizeof(entries)/sizeof(int); i++) {
    a.push_back(entries[i]);
    EXPECT_EQ(i+1, a.get_size());
    EXPECT_LE(i, a.get_capacity());
  }

  for (int i = 0; i < sizeof(entries)/sizeof(int); i++) {
    EXPECT_EQ(a.get(i), entries[i]) << "at index " << std::to_string(i);
  }
}

TEST(dynamic_array_tests, set_entries) {
  constexpr std::size_t SIZE = 1;
  auto a = dynamic_array(SIZE);

  EXPECT_EQ(0, a.get_size());
  EXPECT_EQ(SIZE, a.get_capacity());

  int entries[] = {0, 1, 2, 3, 4, 5};

  for (int i = 0; i < sizeof(entries)/sizeof(int); i++) {
    a.push_back(entries[i]);
    EXPECT_EQ(i+1, a.get_size());
    EXPECT_LE(i, a.get_capacity());
  }

  for (int i = 0; i < sizeof(entries)/sizeof(int); i++) {
    EXPECT_EQ(a.get(i), entries[i]) << "at index " << std::to_string(i);
  }

  for (int i = 0; i < sizeof(entries)/sizeof(int); i++) {
    a.set(i, 2 * entries[i]);
  }

  for (int i = 0; i < sizeof(entries)/sizeof(int); i++) {
    EXPECT_EQ(a.get(i), 2 * entries[i]) << "at index " << std::to_string(i);
  }
}

TEST(dynamic_array_tests, set_entries_random) {
  constexpr std::size_t SIZE = 1;
  auto a = dynamic_array(SIZE);

  EXPECT_EQ(0, a.get_size());
  EXPECT_EQ(SIZE, a.get_capacity());

  int entries[] = {0, 1, 5, 234243, 234211, 23, 2323, 34, 23342, 32323, 456, 7251, 2342};

  for (int i = 0; i < sizeof(entries)/sizeof(int); i++) {
    a.push_back(entries[i]);
    EXPECT_EQ(i+1, a.get_size());
    EXPECT_LE(i, a.get_capacity());
  }

  for (int i = 0; i < sizeof(entries)/sizeof(int); i++) {
    EXPECT_EQ(a.get(i), entries[i]) << "at index " << std::to_string(i);
  }

  for (int i = 0; i < sizeof(entries)/sizeof(int); i++) {
    a.set(i, 2 * entries[i]);
  }

  for (int i = 0; i < sizeof(entries)/sizeof(int); i++) {
    EXPECT_EQ(a.get(i), 2 * entries[i]) << "at index " << std::to_string(i);
  }
}

TEST(dynamic_array_tests, pop_entries_random) {
  constexpr std::size_t SIZE = 1;
  auto a = dynamic_array(SIZE);

  int entries[] = {0, 1, 2, 3, 4, 5};

  for (int i = 0; i < sizeof(entries)/sizeof(int); i++) {
    a.push_back(entries[i]);
    EXPECT_EQ(i+1, a.get_size());
    EXPECT_LE(i, a.get_capacity());
  }

  for (int i = 0; i < sizeof(entries)/sizeof(int); i++) {
    EXPECT_EQ(a.get(i), entries[i]) << "at index " << std::to_string(i);
  }

  for (int i = (sizeof(entries)/sizeof(int) - 1); i >= 0; i--) {
    auto popped = a.pop_back();
    EXPECT_EQ(popped, entries[i]);
  }
}

TEST(dynamic_array_tests, out_of_bounds_get) {
  constexpr std::size_t SIZE = 1;
  auto a = dynamic_array(SIZE);

  EXPECT_ANY_THROW(a.get(SIZE+1));
}

TEST(dynamic_array_tests, out_of_bounds_set) {
  constexpr std::size_t SIZE = 1;
  auto a = dynamic_array(SIZE);

  EXPECT_ANY_THROW(a.set(SIZE+1, 1));
}

