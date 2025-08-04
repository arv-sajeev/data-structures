#pragma once

#include <cstdlib>
#include <memory>
#include <optional>

class dynamic_array {
  private:
    std::unique_ptr<int[]> _data_array = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;

  public:
    dynamic_array(std::size_t capacity);
    int get(std::size_t i);
    void set(std::size_t i, int n);
    void push_back(int n);
    int pop_back(void);
    void resize();
    int get_size() const;
    int get_capacity() const;
};
