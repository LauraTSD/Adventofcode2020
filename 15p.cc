#include <iostream>
#include <fstream>


long long loc = 0;

bool exists(long long num, long long arr[30000000], long long cur){
  for(long long i = cur-1; i > -1;i--){
    if(num>i){return false;}
    if(arr[i] == num){loc = i; return true;}
  }
  return false;
}

// cd /mnt/c/Users/laura/Documents/Advent/Addventofcode2020/
 //g++ -o 15 15.cc

int main() {
    long long* arr = new long long[30000000];
    for(long long i = 0; i < 30000000;i++){
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
    long long i = 0;
    for(long long i = 7; i < 30000000;i++){
      if(i%100000==0){std::cout << i << std::endl;}
      if(exists(arr[i-1],arr,i-1)){arr[i] = (i-1-loc);}
      else{ arr[i] = 0;}
    }
    std::cout << arr[29999999] << std::endl;
    delete[] arr;

    exit(1);   // call system to stop
    return 0;
}
