#include <fstream>
#include <iostream>
#include <string>

#include "_readdata.h"
int main() {
  ReadDataSource R;
  // std::cout << "read in:" << std::endl;
  // for (const auto& row : readDataSource.data) {
  //   for (int number : row) {
  //     std::cout << number << " ";
  //   }
  //   std::cout << std::endl;
  // }
  R.init();
  R.Layout();
  R.Printans_Path();
  R.Printans_Wire();

  return 0;
}