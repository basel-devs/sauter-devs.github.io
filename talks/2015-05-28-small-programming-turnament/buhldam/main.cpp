#include <iostream>
#include <string>

#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>

int main(int argc, char** argv) {

  using namespace boost;

  interprocess::file_mapping fm(argv[1], interprocess::read_only);
  interprocess::mapped_region region (fm, interprocess::read_only, 0, 0);

  const char* begin = reinterpret_cast<const char*>(region.get_address());
  const char* beginpos = begin;
  const char* end = begin + region.get_size();

  std::string str(begin, end);
  auto pipos = str.find("31415926535897932385"); 
  std::cout << "String is gigantic : " << str.size() <<  ", pi is at " << pipos << std::endl;

  return 0;
}
