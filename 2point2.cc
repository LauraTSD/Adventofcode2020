#include <iostream>
#include <fstream>
#include <string>


// cd /mnt/c/Users/laura/Documents/Advent/Addventofcode2020/
 //g++ -o 1point1 1point1.cc

int main() {
    std::ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
    std::cerr << "Unable to open file input.txt";
    }
    std::string x;
    int least;
    int most;
    std::string letter;
    char letters;
    std::string passw;
    int totalright = 0;
    int totalwrong = 0;
    while (std::getline(inFile, x)) {
      int first = 0;
      int last = x.find('-');
      least = std::stoi(x.substr(first, last-first));
      int sp = x.find_first_of(' ');
      most = std::stoi(x.substr(last+1, sp-last));
      int dub = x.find(':');
      letter = x.substr(sp+1, dub-sp-1);
      letters = letter[0];
      int end = x.find('\n');
      passw = x.substr(dub+2, end-(dub+2));
      int count = 0;
      if((passw[least-1] == letters && passw[most-1] != letters) ||(passw[least-1] != letters
        && passw[most-1] == letters)){totalright++;}
      else{totalwrong++;}
    }
    std::cout << "right: " << totalright << " wrong: " << totalwrong << std::endl;
    inFile.close();

    exit(1);   // call system to stop
    return 0;
}
