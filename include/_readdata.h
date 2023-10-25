#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <map>
class ReadDataSource{
   public:
//    static ReadDataSource &getInstance(){
//      return instance;
//    }
   ReadDataSource() {
     // Task.reserve(1000);
     _read_die_network();
     _read_die_position();
     _readnet();
     _read_fpga();
   }
   //Die间的连接信息
   std::vector< std::vector<int> > data;
   int  DieNum{0};
   //FPGA  所包含的Die
   std::unordered_set<int>FpgaToDie[4];
   // Die 到fpga的映射 每一个Die属于哪个FPGA
   std::unordered_map<int,int>DieToFpga_Map;
   //Die 所包含的驱动以及负载节点
   std::unordered_set<int>DieToNode[20];
   //结点到Die的映射 每一个结点属于哪个Die
   std::unordered_map<int,int>NodeToDie_Map;
   //驱动节点的数量
   const int DriverNum=0;
   //求解的驱动到负载结点
   std::map<int,std::vector<int>>Task;
    // 读入design.net文件
    bool _readnet();
    //

    // 读入design.die.position文件
    bool _read_die_position();

    // 读入design.dir.network 文件
    bool _read_die_network();

    // 读入design.fpga.die文件
    bool _read_fpga();
    ~ReadDataSource()=default;
};

