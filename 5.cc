#include <iostream>
#include <fstream>
#include <math.h>



// cd /mnt/c/Users/laura/Documents/Advent/Addventofcode2020/
 //g++ -o 1point1 1point1.cc

int main() {
    std::ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
      std::cerr << "Unable to open file input.txt";
    }
    std::string x;
    int highest = 0*8+0;
    while (std::getline(inFile, x)) {
      int low = 0;
      int high = 127;
      int lowrow = 0;
      int highrow = 7;
      for(int i=0; i< 7;i++){
        if(x[i] == 'B'){low = floor((high-low)/2)+low+1;}
        else if(x[i] =='F'){high = floor((high-low)/2)+low;}
      }
      for(int i=7; i<10;i++){
        if(x[i] == 'R'){lowrow = floor((highrow-lowrow)/2)+lowrow+1;}
        if(x[i] == 'L'){highrow = floor((highrow-lowrow)/2)+lowrow;}
      }
      if(low*8+lowrow > highest){highest = low*8+lowrow;}
    }
    inFile.close();
    std::cout << highest << std::endl;
    exit(1);   // call system to stop
    return 0;
}
