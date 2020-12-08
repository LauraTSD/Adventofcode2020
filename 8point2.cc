#include <iostream>
#include <fstream>

void makefalse(bool arr[637]){
  for(int i = 0; i < 638; i++){
    arr[i] = false;
  }
}

bool run(std::string arr[637],bool done[637]){
  int acc = 0;
  int getal = 0;
  size_t plus = 0;
  size_t min = 0;
  std::string cur = "";
  for(int j=1;j<637;j++){
    cur = arr[j];
    if(done[j]){
      std::cout << "j" << j<< " acc " << acc << std::endl; return false;}
    else{done[j] = true;}
    if(cur[0]=='a'){
      plus = cur.find('+');
      min = cur.find('-');
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
    else if(cur[0]=='j'){
      plus = cur.find('+');
      min = cur.find('-');
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
    else if(cur[0]=='n'){
      getal = 0;
    }
  }
  std::cout << "EINDE" << std::endl << std::endl;
  std::cout << "acc " << acc << std::endl;
  return true;
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
  std::string arr[637];
  bool done[637];
  int count = 1;
  while (std::getline(inFile, x)) {
    arr[count] = x;
    count++;
  }
  makefalse(done);
  inFile.close();
  //run(arr,done);
  std::string cur = "";
  for(int i = 1; i < 638; i++){
    inFile.open("input.txt");
    if (!inFile) {
      std::cerr << "Unable to open file input.txt";
    }
    int count = 1;
    while (std::getline(inFile, x)) {
      arr[count] = x;
      count++;
    }
    makefalse(done);
    inFile.close();
    std::cout << i << std::endl;
    cur = arr[i];
    if(cur[0]=='j'){arr[i][0] = 'n';arr[i][1] = 'o';}
    else if(cur[0]=='n'){arr[i][0] = 'j';arr[i][1] = 'm';}
    if(run(arr,done)){return 3;}
    makefalse(done);
    //if(cur[0]=='j'){arr[i][0] = 'n';arr[i][1] = 'o';}
    //else if(cur[0]=='n'){arr[i][0] = 'j';arr[i][1] = 'm';}
  }


  exit(1);   // call system to stop
  return 0;
}
