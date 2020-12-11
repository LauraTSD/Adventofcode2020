#include <iostream>
#include <fstream>

const int width = 91;
const int height = 97;
// const int width = 10;
// const int height = 10;

bool nooccupied(int i, int j, char arr[height][width]){
  for(int k = i-1; k > -1; k--){
    if(arr[k][j]=='#'){return false;}
    else if(arr[k][j]=='L'){k=-1;}
  }
  for(int k = i+1; k < height; k++){
    if(arr[k][j]=='#'){return false;}
    else if(arr[k][j]=='L'){k=height;}
  }
  for(int l = j-1; l > -1; l--){
    if(arr[i][l]=='#'){return false;}
    else if(arr[i][l]=='L'){l=-1;}
  }
  for(int l = j+1; l < width; l++){
    if(arr[i][l]=='#'){return false;}
    else if(arr[i][l]=='L'){l=width;}
  }
  int n = j-1;
  for(int m = i-1; m > -1; m--){
      if(n<0){m=-1;}
      else if(n>-1&&arr[m][n]=='#'){return false;}
      else if(arr[m][n]=='L'){m=-1;}
      n--;
  }
  int o = i+1;
  for(int p = j+1; p < width; p++){
      if(o>=height){p=width;}
      else if(o<height&&arr[o][p]=='#'){return false;}
      else if(arr[o][p]=='L'){p=width;}
      o++;
  }
  n = j-1;
  for(int m = i+1; m < height; m++){
      if(n<0){m=height;}
      else if(n>-1&&arr[m][n]=='#'){return false;}
      else if(arr[m][n]=='L'){m=height;}
      n--;
  }
  o = i-1;
  for(int p = j+1; p < width; p++){
      if(o<0){p=width;}
      if(o>-1&&arr[o][p]=='#'){return false;}
      else if(arr[o][p]=='L'){p=width;}
      o--;
  }
  return true;
}

bool fouroccupied(int i, int j, char arr[height][width]){
  int count = 0;
  for(int k = i-1; k > -1; k--){
    if(arr[k][j]=='#'){count++; k=-1;}
    else if(arr[k][j]=='L'){k=-1;}
  }
  for(int k = i+1; k < height; k++){
    if(arr[k][j]=='#'){count++; k=height;}
    else if(arr[k][j]=='L'){k=height;}
  }
  for(int l = j-1; l > -1; l--){
    if(arr[i][l]=='#'){count++; l=-1;}
    else if(arr[i][l]=='L'){l=-1;}
  }
  for(int l = j+1; l < width; l++){
    if(arr[i][l]=='#'){count++; l=width;}
    else if(arr[i][l]=='L'){l=width;}
  }
  int n = j-1;
  for(int m = i-1; m > -1; m--){
    if(n<0){m=-1;}
      else if(n>-1&&arr[m][n]=='#'){count++; m=-1;}
      else if(arr[m][n]=='L'){m=-1;}
      n--;
  }
  int o = i+1;
  for(int p = j+1; p < width; p++){
    if(o>=height){p=width;}
      else if(o<height&&arr[o][p]=='#'){count++; p=width;}
      else if(arr[o][p]=='L'){ p=width;}
      o++;
  }
  n = j-1;
  for(int m = i+1; m < height; m++){
    if(n<0){m=height;}
    else if(n>-1&&arr[m][n]=='#'){count++;m=height;}
      else if(arr[m][n]=='L'){m=height;}
      n--;
  }
  o = i-1;
  for(int p = j+1; p < width; p++){
    if(o<0){p=width;}
    else   if(o>-1&&arr[o][p]=='#'){count++; p=width;}
      else if(arr[o][p]=='L'){ p=width;}
      o--;
  }
  if(count >= 5) return true;
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
    char copys[height][width];
    bool movement = true;
    while(movement){
      movement = false;
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
      // for(int i = 0; i < height; i++){
      //   for(int j = 0; j < width; j++){
      //     std::cout << arr[i][j];
      //   }
      //   std::cout << std::endl;
      // }
      // std::cout << std::endl << std::endl;
    } //while
    long count = 0;
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
