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
    int relNS = 1;
    int relEW = 10;
    while (std::getline(inFile, x)) {
      int num = x[1]-'0';
      int i = 2;
      while(isdigit(x[i])){
        num = num*10+(x[i]-'0');
        i++;
      }
      if(x[0]=='N'){
        relNS = num+relNS;

      }
      if(x[0]=='S'){
        relNS = (relNS-num);
      }
      if(x[0]=='E'){
        relEW = num+relEW;
      }
      if(x[0]=='W'){
        relEW = relEW-num;
      }
      if(x[0]=='R'){
        switch(current){
          case 'E':
          if(num==90){
            current = 'S';
            int save = relNS;
            relNS = -relEW;
            relEW = save;
          }
          else if(num==180){
            current = 'W';
            relNS = -relNS;
            relEW = -relEW;
          }
          else if(num==270){
            current = 'N';
            int save = relNS;
            relNS = relEW;
            relEW = -save;
          }
          break;
          case 'W':
          if(num==90){
            current = 'N';
            int save = relNS;
            relNS = -relEW;
            relEW = save;
          }
          else if(num==180){
            current = 'E';
            relNS = -relNS;
            relEW = -relEW;
        }
          else if(num==270){
            current = 'S';
            int save = relNS;
            relNS = relEW;
            relEW = -save;
          }
          break;
          case 'N':
          if(num==90){
            current = 'E';
            int save = relNS;
            relNS = -relEW;
            relEW = save;
          }
          else if(num==180){
            current = 'S';
            relNS = -relNS;
            relEW = -relEW;
          }
          else if(num==270){
            current = 'W';
            int save = relNS;
            relNS = relEW;
            relEW = -save;
          }
          break;
          case 'S':
          if(num==90){
            current = 'W';
            int save = relNS;
            relNS = -relEW;
            relEW = save;
          }
          else if(num==180){
            current = 'N';
            relNS = -relNS;
            relEW = -relEW;
          }
          else if(num==270){
            current = 'E';
            int save = relNS;
            relNS = relEW;
            relEW = -save;
          }
          break;
        }
      }
      if(x[0]=='L'){
        switch(current){
          case 'E':
          if(num==90){
            current = 'N';
            int save = relNS;
            relNS = relEW;
            relEW = -save;
          }
          else if(num==180){
            current = 'W';
            relNS = -relNS;
            relEW = -relEW;
          }
          else if(num==270){
            current = 'S';
            int save = relNS;
            relNS = -relEW;
            relEW = save;
          }
          break;
          case 'W':
          if(num==90){
            current = 'S';
            int save = relNS;
            relNS = relEW;
            relEW = -save;
          }
          else if(num==180){
            relNS = -relNS;
            relEW = -relEW;
            current = 'E';}
          else if(num==270){
            current = 'N';
            int save = relNS;
            relNS = -relEW;
            relEW = save;}
          break;
          case 'N':
          if(num==90){
            int save = relNS;
            relNS = relEW;
            relEW = -save;
            current = 'W';}
          else if(num==180){
            relNS = -relNS;
            relEW = -relEW;
            current = 'S';}
          else if(num==270){
            current = 'E';
            int save = relNS;
            relNS = -relEW;
            relEW = save;}
          break;
          case 'S':
          if(num==90){
            int save = relNS;
            relNS = relEW;
            relEW = -save;
            current = 'E';}
          else if(num==180){
            relNS = -relNS;
            relEW = -relEW;
            current = 'N';}
          else if(num==270){
            current = 'W';
            int save = relNS;
            relNS = -relEW;
            relEW = save;}
          break;
        }
      }
      if(x[0]=='F'){
          curNS += num*relNS;
          curEW += num*relEW;
      }
      std::cout << "EW " << curEW << "  NS " << curNS << std::endl;
      std::cout << "Waypont" << "EW " << relEW << "  NS " << relNS << std::endl;
      //std::cout << "EW " << curEW << std::endl;
    }
    inFile.close();
    std::cout << "answers = " << abs(curNS)+abs(curEW) << std::endl;

    exit(1);   // call system to stop
    return 0;
}
