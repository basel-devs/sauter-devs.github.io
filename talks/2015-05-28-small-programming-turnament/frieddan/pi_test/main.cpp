#include<iostream>
#include<fstream>


int main(int number_of_args, char* args_as_array[]) {
  std::string pattern;
  std::string file;


  std::cout << "the Pi test" << std::endl;
  if(number_of_args != 3) {

    std::cout << "usage: call " << args_as_array[0]  << " file_to_read  pattern_to_search"  << std::endl << std::endl;

    pattern = "31415926535897932385";
    file = "big_pi_test_with_pi_test";
  }
  else {
    std::string file = args_as_array[1];
    std::string pattern = args_as_array[2];

    std::cout << "pattern: " << pattern << std::endl;
    std::cout << "file: " << file << std::endl;
  }

  std::ifstream ifs(file.c_str());
  if(!ifs.is_open()) {
    std::cerr << "ERROR: file " << file << "does not exists or cant be opened " << std::endl;
    return 1;
  }

  std::string data;
  std::string line;
  while(getline(ifs, line)){
    data.append(line);
  } 

  std::size_t idx{0};
  idx = data.find(pattern);

  std::cout << "position of Pattern " << pattern << " is: " << idx << std::endl;  
}
