#include "../include/_readdata.h"

bool ReadDataSource::_readnet() {
  std::ifstream inputFile("/home/hxm/桌面/test1/source/design.net");
  if (inputFile.is_open()) {
    std::string line;
    while (std::getline(inputFile, line)) {
      std::string tmp;
      int i;
      int DriverId;
      int num;
      for (i = 0; i < line.size(); i++) {
        if (line[i] == ' ' && line[i - tmp.size() - 1] == 'p') {
          num = std::stoi(tmp.c_str());
          num = num * (-1) - 1;
          break;
        } else if (line[i] == ' ') {
          num = std::stoi(tmp.c_str());
          break;
        }
        if ('0' <= line[i] && line[i] <= '9') {
          tmp += line[i];
        }
      }

      if (line[i + 1] == 's')
        DriverId = num;
      else {
        Task[DriverId].push_back(num);
        //DriverId-->num
        int id=NodeToDie_Map[DriverId]*DieNum+NodeToDie_Map[num];
        DieToDie[id].from=DriverId;
        DieToDie[id].to=num;
        DieToDie[id].val++;
      }
      // Debug
      // std::cout << line << std::endl;
    }
    inputFile.close();
    return true;
  } else {
    std::cerr << "Failed to open the file::design.net" << std::endl;
    return false;
  }
}
bool ReadDataSource::_read_die_position() {
  std::ifstream inputFile("/home/hxm/桌面/test1/source/design.die.position");
  if (inputFile.is_open()) {
    std::string line;
    int Dieidx = -1;
    while (std::getline(inputFile, line)) {
      if (line.back() == ':') continue;
      ++Dieidx;
      std::string tmp;
      for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ' && line[i - tmp.size() - 1] == 'p') {
          tmp = "-" + tmp;
          int cnt = std::stoi(tmp.c_str());
          cnt--;
          NodeToDie_Map[cnt] = Dieidx;
          DieToNode[Dieidx].insert(cnt);
          tmp.clear();
          continue;
        } else if (line[i] == ' ') {
          int cnt = std::stoi(tmp.c_str());
          NodeToDie_Map[cnt] = Dieidx;
          DieToNode[Dieidx].insert(cnt);
          tmp.clear();
          continue;
        }
        if ('0' <= line[i] && line[i] <= '9' && line[i + 1] != ':') {
          tmp = tmp + line[i];
        }
      }
      // int cnt = std::stoi(tmp.c_str());
      // NodeToDie_Map[cnt] = Dieidx;
      // DieToNode[Dieidx].insert(cnt);
      // Debug
      // std::cout << line << std::endl;
    }
    inputFile.close();
    return true;
  } else {
    std::cerr << "Failed to open the file::design.die.position." << std::endl;
    return false;
  }
}

bool ReadDataSource::_read_fpga() {
  std::ifstream inputFile("/home/hxm/桌面/test1/source/design.fpga.die");
  if (inputFile.is_open()) {
    std::string line;
    // 读入的FPGA的ID
    int Fpgaidx = -1;
    while (std::getline(inputFile, line)) {
      ++Fpgaidx;
      std::string tmp;
      for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
          int cnt = std::stoi(tmp.c_str());
          DieToFpga_Map[cnt] = Fpgaidx;
          FpgaToDie[Fpgaidx].insert(cnt);
          tmp.clear();
          continue;
        }
        if ('0' <= line[i] && line[i] <= '9' && line[i + 1] != ':') {
          tmp = tmp + line[i];
        }
      }
      int cnt = std::stoi(tmp.c_str());
      DieToFpga_Map[cnt] = Fpgaidx;
      FpgaToDie[Fpgaidx].insert(cnt);
      //  DieToFpga_Map
      // Debug
      // std::cout << line << std::endl;
    }
    inputFile.close();
    return true;
  } else {
    std::cerr << "Failed to open the file::design.fpga.die." << std::endl;
    return false;
  }
}

bool ReadDataSource::_read_die_network() {
  std::ifstream inputFile("/home/hxm/桌面/test1/source/design.die.network");
  if (!inputFile.is_open()) {
    std::cerr << "not open" << std::endl;
    return false;
  }

  // 逐行读取文件
  std::string line;
  while (std::getline(inputFile, line)) {
    std::istringstream iss(line);
    int number;
    std::vector<int> row;
    while (iss >> number) {
      row.push_back(number);
    }
    data.push_back(row);
  }
  DieNum = data[0].size();
  inputFile.close();
  return true;
}

void ReadDataSource::init(){
    
   // std::sort();
 //将Die的任务进行数量进行排序
 std::sort(DieToDie.begin(),DieToDie.end());
 while(!DieToDie.front().val){
   DieToDie.erase(DieToDie.begin());
 }


}
// 分层图
// 魔改 网络流
// 慢启动防止拥塞
// 暴搜？
// 考虑FPGA的数量如何去优化
//   
void ReadDataSource:: Layout(){
    

}
void ReadDataSource::Printans_Path(){

}

void ReadDataSource:: Printans_Wire(){
   
}
