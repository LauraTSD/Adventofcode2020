#include <iostream>
#include <fstream>



// cd /mnt/c/Users/laura/Documents/Advent/Addventofcode2020/
 //g++ -o 1point1 1point1.cc

 int smallest;
 int busnum;

 bool multiple(int getal, int tbf){
   long long i = 106723585912;
   int combination = getal*i;
   if(getal==0){return true;}
   while(combination<tbf){
     combination = getal*i;
     i++;
     if(combination==tbf){return true;}
   }
   if(combination==tbf){return true;}
   return false;
 }

 // bool equal(int arr[68],long long start){
 //   for(int i = 0; i < 68; i++){
 //     if((arr[i]*start+i)!=(arr[i+1]*start+i+1)){return false;}
 //   }
 //   std::cout << start << std::endl;
 //   return true;
 // }

int main() {
    std::ifstream inFile;
    smallest = 10000000;
    inFile.open("input.txt");
    if (!inFile) {
      std::cerr << "Unable to open file input.txt";
    }
    std::string x;
    std::getline(inFile, x);
    inFile.close();
    char n = x[0];
    int i = 0;
    int arrcount = 0;
    int save=0;
    int time = 0;
    int arr[68];
    while(n!='\n'){
      if(isdigit(n)){save = save*10+(n-'0');}
      else if(n==','){arr[arrcount]=save; arrcount++; save = 0;}
      else if(n=='x'){arr[arrcount]=0;arrcount++;i++;}
      else if(n=='.'){arr[arrcount]=save; arrcount++; save = 0; break;}
      i++;
      n=x[i];
    }
    // long long start =5882352941180;
    // // while(!(equal(arr,start))){start++;}
    //std::cout << arr[i] << "+" << i << std::endl;
    for(long long i = 5882352941180; i<1000000000000000000;i++){
      int tbf = arr[0]*i+1;
      int num = 1;
      int ortbf = tbf;
      while(multiple(arr[num],tbf)){
        num++; tbf++;
        if(arr[num]==19){std::cout << "einde voor" << ortbf << std::endl;return 1;}
      }
      //std::cout << "i: " << i << " num " << num << std::endl;
    }
    std::cout << std::endl;


    exit(1);   // call system to stop
    return 0;
}
