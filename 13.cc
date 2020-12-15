#include <iostream>
#include <fstream>



// cd /mnt/c/Users/laura/Documents/Advent/Addventofcode2020/
 //g++ -o 1point1 1point1.cc

 int smallest;
 int busnum;

 void multiple(int save, int time){
   int i = 0;
   int combination = save*i;
   if(save==0){return;}
   while(combination<time){
     combination = save*i;
     i++;
   }
   if(combination < smallest){smallest = combination; busnum = save;}
   std::cout << save << " " << combination << std::endl;
 }

int main() {
    std::ifstream inFile;
    smallest = 10000000;
    inFile.open("input.txt");
    if (!inFile) {
      std::cerr << "Unable to open file input.txt";
    }
    std::string x;
    std::getline(inFile, x);
    int time = stoi(x);
    std::getline(inFile, x);
    inFile.close();
    char n = x[0];
    int i = 0;
    int save=0;
    while(n!='\n'){
      if(isdigit(n)){save = save*10+(n-'0');}
      else if(n==','){multiple(save, time);save = 0;}
      else if(n=='x'){i++;}
      else if(n=='.'){break;}
      i++;
      n=x[i];
      std::cout << save << std::endl;
    }
    multiple(save, time);
    std::cout << "smallest " << smallest << std::endl;
    std::cout << "busnum " << busnum << std::endl;
    std::cout << "wait " << smallest - time << std::endl;
    std::cout << "combi=" << busnum*(smallest - time) << std::endl;

    exit(1);   // call system to stop
    return 0;
}
