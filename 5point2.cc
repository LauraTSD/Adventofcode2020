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
    int lowest = 1000*8+7;
    bool arr[868];
    for(int i = 0; i<868; i++){
      arr[i] = false;
    }
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
      //if(low*8+lowrow > highest){highest = low*8+lowrow;}
      //if(low*8+lowrow < lowest){lowest = low*8+lowrow;}
      arr[low*8+lowrow-70] = true;
    }
    for(int j = 0; j<868; j++){
      if(!arr[j]){std::cout << j + 70 << std::endl;}
    }
    inFile.close();
    //std::cout << "high" << highest << std::endl;
    //std::cout << "lowest" << lowest << std::endl;
    exit(1);   // call system to stop
    return 0;
}
