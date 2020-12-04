#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <sstream>


// cd /mnt/c/Users/laura/Documents/Advent/Addventofcode2020/
 //g++ -o 1point1 1point1.cc
bool byr;
bool iyr;
bool eyr;
bool hgt;
bool ecl;
bool pid;
bool hcl;
//bool cid

void allfalse(){
byr =false;;
iyr=false;
eyr=false;
hgt=false;
hcl=false;
ecl=false;
pid=false;
//cid=false;
}

int main() {
    std::ifstream inFile;
    std::string arr[10];
    inFile.open("input.txt");
    if (!inFile) {
      std::cerr << "Unable to open file input.txt";
    }
    std::string x;
    int countright = 0;
    int countwrong = 0;
    allfalse();
    while (std::getline(inFile, x)) {
      if(x.length()!=1){
        std::string what = x.substr(x.find("byr:")+4,4);
        if(x.find("byr:")!= std::string::npos&&std::stoi(what)<2003&&std::stoi(what)>1919){byr = true;}

        what = x.substr(x.find("iyr:")+4,4);
        if(x.find("iyr:")!= std::string::npos&&std::stoi(what)<2021&&std::stoi(what)>2009){iyr = true;}

        what = x.substr(x.find("eyr:")+4,4);
        if(x.find("eyr:")!= std::string::npos&&std::stoi(what)<2031&&std::stoi(what)>2019){eyr = true;}

        bool cm = (x.find("cm")!= std::string::npos);
        bool in = (x.find("in")!= std::string::npos);
        if(cm){what = x.substr(x.find("hgt:")+4,3);}
        if(in){what = x.substr(x.find("hgt:")+4,2);}
        if(x.find("hgt:")!= std::string::npos&&((cm&&std::stoi(what)<194&&std::stoi(what)>149)||(in&&std::stoi(what)<77&&std::stoi(what)>58))){hgt = true;}

        what = x.substr(x.find("ecl:")+4,3);
        if(x.find("ecl:")!= std::string::npos&&(what=="amb"||what=="blu"||what=="brn"||what=="gry"||what=="grn"||what=="hzl"||what=="oth")){ecl = true;}

        int end = x.find_first_of(" ",x.find("pid:"));
        if(end == std::string::npos){end = x.find_first_of("\n",x.find("pid:"));}
        what = x.substr(x.find("pid:")+4,9);
        if(x.find("pid:")!= std::string::npos&&!isdigit(x[x.find("pid:")+14])&&isdigit(what[8])){pid = true;}

        what = x.substr(x.find("hcl:")+5,7);
        if(x.find("hcl:")!= std::string::npos&&(x[x.find("hcl:")+4]=='#')){hcl = true;}
      }
      else if(x.length()==1){
        if(byr&&iyr&&eyr&&hgt&&ecl&&pid&&hcl){countright++;}
        else{countwrong++;}
        allfalse();
      }

    }
    inFile.close();
    std::cout << "right:" << countright << std::endl;
    std::cout << "wrong:" << countwrong << std::endl;
    exit(1);   // call system to stop
    return 0;
}
