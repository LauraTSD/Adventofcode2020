#include <iostream>
#include <fstream>

const int width = 91;
const int height = 97;

bool nooccupied(int i, int j, char arr[height][width]){
  for(int k = i-1; k<i+2;k++){
    for(int l = j-1; l<j+2;l++){
      if(arr[k][l]=='#'&&k>=0&&k<height&&l>=0&&l<width){
        return false;
      }
    }
  }
  return true;
}
bool fouroccupied(int i, int j, char arr[height][width]){
  int count = 0;
  for(int k = i-1; k<i+2;k++){
    for(int l = j-1; l<j+2;l++){
      if(k>-1&&k<height&&l>-1&&l<width){
        if(arr[k][l]=='#'){
          count++;
        }
        if(k==i&&j==l){count--;}
      }
    }
  }
  if(count >= 4) return true;
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
    char arr[height][width];
    int line = 0;
    while (std::getline(inFile, x)) {
      for(int i = 0; i < x.length(); i++){
        arr[line][i] = x[i];
      }
      line++;
    }

    inFile.close();
    bool movement = true;
    while(movement){
      movement = false;
      char copys[height][width];
      for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
          copys[i][j] = arr[i][j];
        }
      }
      for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
          if(arr[i][j]=='L'){
            if(nooccupied(i,j,copys)){
              arr[i][j]='#';
              movement = true;
            }
          }
          else if(arr[i][j]=='#'){
            if(fouroccupied(i,j,copys)){
              arr[i][j]='L';
              movement = true;
            }
          }
        }
      }
      for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
          std::cout << arr[i][j];
        }
        std::cout << std::endl;
      }
      std::cout << std::endl << std::endl;
    } //while
    int count = 0;
    for(int i = 0; i < height; i++){
      for(int j = 0; j < width; j++){
        if(arr[i][j]=='#'){
          count++;
        }
      }
    }
    std::cout << count << std::endl;
    exit(1);   // call system to stop
    return 0;
}
