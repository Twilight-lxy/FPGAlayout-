#include <fstream>
#include <iostream>
#include <string>

#include "_readdata.h"
int main() {
  ReadDataSource readDataSource;
  std::cout << "read in:" << std::endl;
  for (const auto& row : readDataSource.data) {
    for (int number : row) {
      std::cout << number << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}