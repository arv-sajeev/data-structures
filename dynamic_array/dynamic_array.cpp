#include "dynamic_array.hpp"
#include <stdexcept>
#include <exception>
#include <string>
#include <algorithm>

dynamic_array::dynamic_array(std::size_t capacity) {
  _capacity = capacity;
  _data_array = std::make_unique<int[]>(capacity);
}

int dynamic_array::get(std::size_t i) {
  if (i >= _size) {
    throw std::out_of_range("index i :: " 
        + std::to_string(i)  
        + " out of range");
  }
  return _data_array[i];
}

void dynamic_array::set(std::size_t i, int n) {
  if (i >= _size) {
    throw std::out_of_range("index i :: " 
        + std::to_string(i)  
        + " out of range");
  }
  _data_array[i] = n;
}

void dynamic_array::resize() {
  constexpr std::size_t RESIZE_FACTOR = 2;
  auto new_capacity = _capacity * RESIZE_FACTOR;
  auto resized_buffer = std::make_unique<int[]>(new_capacity);

  std::copy(_data_array.get(), _data_array.get() + _size, 
      resized_buffer.get());

  _data_array = std::move(resized_buffer);
  _capacity = new_capacity;
}

void dynamic_array::push_back(int n) {
  if (_size >= _capacity) {
    dynamic_array::resize();
  }
  _data_array[_size] = n;
  _size++;
}

int dynamic_array::pop_back() {
  if (_size == 0) {
    throw std::out_of_range("trying pop on an empty array");
  }
  --_size;
  return _data_array[_size];
}

int dynamic_array::get_size() const {
  return _size;
}

int dynamic_array::get_capacity() const {
  return _capacity;
}
