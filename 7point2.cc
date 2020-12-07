#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstddef>


std::vector<char> find_range {'1','2','3','4','5','6','7','8','9'};


int main() {
    std::ifstream inFile;
    inFile.open("input.txt");
    std::string arr[100000];
    int arcount = 0;
    if (!inFile) {
      std::cerr << "Unable to open file input.txt";
    }
    std::string x;
    while (std::getline(inFile, x)) {
      if(x.find("shiny gold bags contain")!=std::string::npos){
        auto result = std::find_first_of(x.begin(), x.end(), find_range.begin(), find_range.end());
        int location = std::distance(x.begin(), result);
        while(result != x.end()){
          int komma = x.find_first_of(",", location);
          std::string bag;
          if(komma == std::string::npos){bag = x.substr(location+2,(x.length()-(location+3)));}
          else{bag = x.substr(location+2,(komma)-(location+2));}
          char st =  x[location];
          std::string s(1, st);
          int num =  std::stoi(s);
          for(int j = 0; j < num; j++){
            arr[arcount] = bag;
            arcount++;
          }
          result = std::find_first_of(result+1, x.end(), find_range.begin(), find_range.end());
          location = std::distance(x.begin(), result);
        }
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
        std::string word  = arr[i];
        if(word[word.length()-1]!='s'){arr[i] = arr[i]+"s";}
        std::string finds = arr[i] + " contain";
        if(x.find(finds)!=std::string::npos){
          auto result = std::find_first_of(x.begin(), x.end(), find_range.begin(), find_range.end());
          int location = std::distance(x.begin(), result);
          while(result != x.end()){
            int komma = x.find_first_of(",", location);
            std::string bag;
            if(komma == std::string::npos){bag = x.substr(location+2,(x.length()-(location+2))-1);}
            else{bag = x.substr(location+2,(komma)-(location+2));}
            char st =  x[location];
            std::string s(1, st);
            int num =  std::stoi(s);
            for(int j = 0; j < num; j++){
              arr[arcount] = bag;
              arcount++;
            }
            result = std::find_first_of(result+1, x.end(), find_range.begin(), find_range.end());
            location = std::distance(x.begin(), result);
          }
        }
      }
      inFile.close();

    }
    std::cout << arcount << std::endl;

    exit(1);   // call system to stop
    return 0;
}
