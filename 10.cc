
#include <iostream>
#include <fstream>

const int length = 104;

bool hasnumbers(long arr[length]){
  for(int i = 0; i < length; i++){
    if(arr[i]!=0){return true;}
  }
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
    long lowest = 100000000;
    int pos = 0;
    for(int i = 0; i < length; i++){
      if(arr[i]<lowest){lowest = arr[i]; pos = i;}
    }
    arr[pos] = 0;
    int current = lowest;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    bool found = false;
    while(hasnumbers(arr)){
      found = false;
      for(int i = 0; i < length; i++){
        if(arr[i]==current+1){
          current = arr[i];
          pos = i;
          arr[i]=0;
          count1++;
          found = true;
          break;
        }
      }
      if(!found){
        for(int i = 0; i < length; i++){
          if(arr[i]==current+2){
            current = arr[i];
            pos = i;
            arr[i]=0;
            count2++;
            found = true;
            break;
          }
        }
      }
      if(!found){
        for(int i = 0; i < length; i++){
          if(arr[i]==current+3){
            current = arr[i];
            pos = i;
            arr[i]=0;
            count3++;
            found = true;
            break;
          }
        }
      }
    }
    std::cout << count1+1 << " " << count2 << " " << count3+1 << " " << std::endl;
    exit(1);   // call system to stop
    return 0;
}
