#include <iostream>
#include <fstream>


int loc = 0;

bool exists(int num, int arr[2020], int cur){
  for(int i = cur-1; i > -1;i--){
    if(arr[i] == num){loc = i; return true;}
  }
  return false;
}

// cd /mnt/c/Users/laura/Documents/Advent/Addventofcode2020/
 //g++ -o 15 15.cc

int main() {
    int arr[2020];
    for(int i = 0; i < 2020;i++){
      arr[i] = -10;
    }
    arr[0] = 6;
    arr[1] = 4;
    arr[2] = 12;
    arr[3] = 1;
    arr[4] = 20;
    arr[5] = 0;
    arr[6] = 16;
    std::string x;
    int i = 0;
    for(int i = 7; i < 2020;i++){
      if(exists(arr[i-1],arr,i-1)){arr[i] = (i-1-loc);}
      else{ arr[i] = 0;}
    }
    std::cout << arr[2019] << std::endl;

    exit(1);   // call system to stop
    return 0;
}
