#include <iostream>
#include <fstream>


// cd /mnt/c/Users/laura/Documents/Advent/Addventofcode2020/
 //g++ -o 1point1 1point1.cc


int main() {
    std::ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
      std::cerr << "Unable to open file input.txt";
    }
    std::string x;
    int length = 1000;
    int arr[length];
    long count = 0;
    while (std::getline(inFile, x)) {
      arr[count] = stol(x);
      count++;
    }
    inFile.close();
    long sum = 0;
    int wrong = 50047984;
    for(int i = 0; i < 542; i++){
      for(int j = i; j < 542; j++){
          sum += arr[j];
          if(sum == wrong){
            long smallest = 1000000000000000;
            long largest = 0;
            for(int m=i; m<j+1;m++){
              if(arr[m] > largest){
                largest = arr[m];
              }
              if(arr[m] < smallest){
                smallest = arr[m];
              }
            }
            std::cout << largest << "+" << smallest << "=" << largest+smallest << std::endl;
            return 1;
          }
      }
      sum = 0;
    }
    exit(1);   // call system to stop
    return 0;
}
