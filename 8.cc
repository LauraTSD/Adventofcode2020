#include <iostream>
#include <fstream>

void makefalse(bool arr[637]){
  for(int i = 0; i < 638; i++){
    arr[i] = false;
  }
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
  int acc = 0;
  int getal = 0;
  std::string arr[637];
  bool done[637];
  int count = 1;
  while (std::getline(inFile, x)) {
    arr[count] = x;
    count++;
  }
  makefalse(done);
  inFile.close();
  for(int j=1;j<638;j++){
    std::string cur = arr[j];
    if(done[j]){std::cout << "acc " << acc << std::endl; return 1;}
    else{done[j] = true;}
    if(cur[0]=='a'){
      size_t plus = cur.find('+');
      size_t min = cur.find('-');
      if(plus!=std::string::npos){
        getal = (int)cur[plus+1]-48;
        for(int i = plus+2; i < cur.length();i++){
          getal = getal*10+((int)cur[i]-48);
        }
        acc += getal;
      }
      else if(min!=std::string::npos){
        getal = (int)cur[min+1]-48;
        for(int i = min+2; i < cur.length();i++){
          getal = getal*10+((int)cur[i]-48);
        }
        acc -= getal;
      }
      getal = 0;
    }
    if(cur[0]=='j'){
      size_t plus = cur.find('+');
      size_t min = cur.find('-');
      if(plus!=std::string::npos){
        getal = (int)cur[plus+1]-48;
        for(int i = plus+2; i < cur.length();i++){
          getal = getal*10+((int)cur[i]-48);
        }
        j += getal-1;
      }
      else if(min!=std::string::npos){
        getal = (int)cur[min+1]-48;
        for(int i = min+2; i < cur.length();i++){
          getal = getal*10+((int)cur[i]-48);
        }
        j -= (getal+1);
      }
      getal = 0;
    }
    if(cur[0]=='n'){
      //do nothing
    }
  }

  exit(1);   // call system to stop
  return 0;
}
