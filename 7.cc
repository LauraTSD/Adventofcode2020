#include <iostream>
#include <fstream>



// cd /mnt/c/Users/laura/Documents/Advent/Addventofcode2020/
 //g++ -o 1point1 1point1.cc

void makeEmpty(std::string arr[1000]){
  for(int i = 0; i < 1000; i++){
    arr[i] = "";
  }
}


int main() {
    std::ifstream inFile;
    inFile.open("input.txt");
    std::string arr[1000];
    makeEmpty(arr);
    int count  = 0;
    int arcount = 0;
    if (!inFile) {
      std::cerr << "Unable to open file input.txt";
    }
    std::string x;
    while (std::getline(inFile, x)) {
      int cont = x.find("contain");
      if(x.find("shiny gold bags",cont)!=std::string::npos){
        arr[arcount] = x.substr(0,cont-2);
        arcount++;
      }
    }
    inFile.close();
    for(int i = 0; i<arcount ;i++){
      inFile.open("input.txt");
      if (!inFile) {
        std::cerr << "Unable to open file input.txt";
      }
      std::string x;
      while (std::getline(inFile, x)) {
        int cont = x.find("contain");
        if(x.find(arr[i],cont)!=std::string::npos){
          arr[arcount] = x.substr(0,cont-2);
          arcount++;
        }
      }
      inFile.close();
    }

    for (int i=0; i<arcount; i++)
    {
        int j;
        for (j=0; j<i; j++)
           if (arr[i] == arr[j])
               break;
         if (i == j)
          count++;
    }
    std::cout << count << std::endl;

    exit(1);   // call system to stop
    return 0;
}
