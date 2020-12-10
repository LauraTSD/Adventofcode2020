
#include <iostream>
#include <fstream>

const int length = 104;

bool findnr(long arr[length],int nr){
  for(int i = 0; i < length; i++){
    if(arr[i]==nr){return true;}
  }
  return false;
}


bool reachend(long arr[length],int current, int highest, long long& permutations){
    //if(current == highest){permutations++; return true;}
    if(findnr(arr,current+1)){
      current = current+1;
      if(current == highest){permutations++;}
      else if(current>highest){return false;}
      else{reachend(arr, current, highest, permutations);}
    }
    if(findnr(arr,current+2)){
      current = current+2;
      if(current == highest){permutations++;}
      else if(current>highest){return false;}
      else{reachend(arr, current, highest, permutations);}
    }
    if(findnr(arr,current+3)){
      current = current+3;
      if(current == highest){permutations++; }
      else if(current>highest){return false;}
      else{reachend(arr, current, highest, permutations);}
    }
    if((permutations%1000)==0){std::cout << "perm" << permutations<<std::endl;}
    return false;
}

// cd /mnt/c/Users/laura/Documents/Advent/Addventofcode2020/
//g++ -o 1point1 1point1.cc

int main() {
  std::ifstream inFile;

  inFile.open("input.txt");
  if (!inFile) {
    std::cerr << "Unable to open file input.txt";
  }
  std::string x;
  long arr[length];
  long count = 0;
  while (std::getline(inFile, x)) {
    arr[count] = stol(x);
    count++;
  }
  inFile.close();

  int current = 0;
  long highest = 0;
  int pos = 0;
  for(int i = 0; i < length; i++){
    if(arr[i]>highest){highest = arr[i];}
  }
  long long permutations = 0;
  //permutations += reachend(arr, current, highest);
  reachend(arr, current, highest, permutations);
  std::cout << permutations << std::endl;
  exit(1);   // call system to stop
  return 0;
}
