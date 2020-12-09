#include <iostream>
#include <fstream>

int length = 1000;
int preamble = 25;

// cd /mnt/c/Users/laura/Documents/Advent/Addventofcode2020/
 //g++ -o 1point1 1point1.cc
bool check(int *arr, int i){
  for(int j = i-preamble; j < i; j++){
    for(int k = i-preamble; k < i; k++){
      if(k!=j&&((arr[k]+arr[j])==arr[i])){
        return true;
      }
    }
  }
  return false;
}


int main() {
    std::ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
      std::cerr << "Unable to open file input.txt";
    }
    std::string x;
    int arr[length];
    long count = 0;
    while (std::getline(inFile, x)) {
      arr[count] = stol(x);
      count++;
    }
    inFile.close();
    for(int i = preamble; i < length; i++){
        if(!check(arr,i)){
          std::cout << arr[i] << " is false" << std::endl;
          return 1;
        }
    }
    exit(1);   // call system to stop
    return 0;
}
