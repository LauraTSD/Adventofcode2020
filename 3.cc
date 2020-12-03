#include <iostream>
#include <fstream>



// cd /mnt/c/Users/laura/Documents/Advent/Addventofcode2020/
 //g++ -o 1point1 1point1.cc

int main() {
    int ar[323][3000];
    int add;
    std::ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
      std::cerr << "Unable to open file input.txt";
    }
    std::string x;
    int i = 0;
    while (std::getline(inFile, x)) {
      //for(int i =0; i<323; i++){
      int read = 0;
      for(int j = 0; j<3000; j++){
        if(x[read] == '#' || x[read] == '.'){
          if(x[read] == '#'){ add = 1;}
          else{add = 0;}
          ar[i][j] = add;
          read++;
        }
        else{read = 0; j--;}
      }
      i++;
    }
    inFile.close();
    int xc = 0;
    int counter = 0;
    // for(int j = 0; j<62; j++){
    //   std::cout << ar[0][j];
    // }

    for(int i = 0; i < 323; i++){
      if(ar[i][xc]){counter++;}
      xc+=1;
    }
    std::cout << "Right 1, down 1: " << counter << std::endl;
    counter = 0;
    xc = 0;
    for(int i = 0; i < 323; i++){
      if(ar[i][xc]){counter++;}
      xc+=3;
    }
    std::cout << "Right 3, down 1: " << counter << std::endl;
    counter = 0;
    xc = 0;
    for(int i = 0; i < 323; i++){
      if(ar[i][xc]){counter++;}
      xc+=5;
    }
    std::cout << "Right 5, down 1: " << counter << std::endl;
    counter = 0;
    xc = 0;
    for(int i = 0; i < 323; i++){
      if(ar[i][xc]){counter++;}
      xc+=7;
    }
    std::cout << "Right 7, down 1: " << counter << std::endl;
    counter = 0;
    xc = 0;
    for(int i = 0; i < 323; i+=2){
      if(ar[i][xc]){counter++;}
      xc+=1;
    }
    std::cout << "Right 1, down 2: " << counter << std::endl;
    exit(1);   // call system to stop
    return 0;
}
