#include <iostream>
#include <fstream>



// cd /mnt/c/Users/laura/Documents/Advent/Addventofcode2020/
 //g++ -o 1point1 1point1.cc
bool arr[26];
void makefalse(){
  for(int i = 0; i < 26; i++){
    arr[i] = false;
  }
}

int main() {
    std::ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
      std::cerr << "Unable to open file input.txt";
    }
    std::string x;
    int sum = 0;
    int newl = true;
    makefalse();
    while (std::getline(inFile, x)) {
      if(x !=""){
        if(newl){
          for(int j = 0; j<x.length();j++){
            int num = ((int) x[j])-97;
            arr[num] = true;
          }
        }else{
          for(int i = 0; i < 26; i++){
            char found = ((char) (i+97));
            if(x.find(found)==std::string::npos){arr[i] = false;}
          }
        }
        newl = false;
      }
      else{
        for(int i = 0; i<26; i++){
          if(arr[i]){sum++;}
        }
        makefalse();
        newl = true;
      }
    }
    std::cout << "sum" << sum << std::endl;
    inFile.close();

    exit(1);   // call system to stop
    return 0;
}
