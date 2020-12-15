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
    char current = 'E';
    int curNS = 0;
    int curEW = 0;
    while (std::getline(inFile, x)) {
      int num = x[1]-'0';
      int i = 2;
      while(isdigit(x[i])){
        num = num*10+(x[i]-'0');
        i++;
      }
      if(x[0]=='N'){
        curNS += num;
      }
      if(x[0]=='S'){
        curNS -= num;
      }
      if(x[0]=='E'){
        curEW += num;
      }
      if(x[0]=='W'){
        curEW -= num;
      }
      if(x[0]=='R'){
        switch(current){
          case 'E':
          if(num==90){current = 'S';}
          else if(num==180){current = 'W';}
          else if(num==270){current = 'N';}
          break;
          case 'W':
          if(num==90){current = 'N';}
          else if(num==180){current = 'E';}
          else if(num==270){current = 'S';}
          break;
          case 'N':
          if(num==90){current = 'E';}
          else if(num==180){current = 'S';}
          else if(num==270){current = 'W';}
          break;
          case 'S':
          if(num==90){current = 'W';}
          else if(num==180){current = 'N';}
          else if(num==270){current = 'E';}
          break;
        }
      }
      if(x[0]=='L'){
        switch(current){
          case 'E':
          if(num==90){current = 'N';}
          else if(num==180){current = 'W';}
          else if(num==270){current = 'S';}
          break;
          case 'W':
          if(num==90){current = 'S';}
          else if(num==180){current = 'E';}
          else if(num==270){current = 'N';}
          break;
          case 'N':
          if(num==90){current = 'W';}
          else if(num==180){current = 'S';}
          else if(num==270){current = 'E';}
          break;
          case 'S':
          if(num==90){current = 'E';}
          else if(num==180){current = 'N';}
          else if(num==270){current = 'W';}
          break;
        }
      }
      if(x[0]=='F'){
        switch(current){
          case 'E':
          curEW += num;
          break;
          case 'W':
          curEW  -= num;
          break;
          case 'N':
          curNS += num;
          break;
          case 'S':
          curNS -= num;
          break;
        }
      }
      std::cout << "NS " << curNS << std::endl;
      std::cout << "EW " << curEW << std::endl;
    }
    inFile.close();
    std::cout << "answers = " << abs(curNS)+abs(curEW) << std::endl;

    exit(1);   // call system to stop
    return 0;
}
