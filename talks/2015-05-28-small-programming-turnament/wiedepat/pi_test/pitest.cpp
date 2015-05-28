#include <iostream>
#include <fstream>
#include <boost/math/constants/constants.hpp>
#include <boost/algorithm/searching/knuth_morris_pratt.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;

int main(int argc,char ** argv)
{

    //input file
    std::ifstream piDumpFile("big_pi_test_with_pi_test");
    if(piDumpFile.fail())
    {
        std::cout << "Sorry, no file to process." << std::endl;
        return 0;
    }
    
    //piDumpFile >> piDump;
    //

    piDumpFile.seekg(0, piDumpFile.end);
    std::streampos lengthToRead = piDumpFile.tellg();
    piDumpFile.seekg(0, piDumpFile.beg);


    std::string piDump(lengthToRead, '\0');
    
    piDumpFile.read(const_cast<char*>(piDump.data()), lengthToRead);



    std::cout << "piDump.size() " << piDump.size() << std::endl;

    //get PI constant
    boost::multiprecision::cpp_dec_float_50 piPrecise =
            boost::math::constants::pi<boost::multiprecision::cpp_dec_float_50>();
    //round it
    piPrecise = round(piPrecise * 10e18);
    //get pattern
    std::string piStrRound20 = piPrecise.str();
    std::cout << "Searching for rounded PI:" << piStrRound20 << std::endl;

    //perform KMP algorithm
    std::string::iterator piIterator = boost::algorithm::knuth_morris_pratt_search(
            piDump.begin(),piDump.end(), piStrRound20.begin(), piStrRound20.end());

    if(piIterator == piDump.end())
    {
        std::cout << "Could not find PI !" << std::endl;
    }else
    {
        std::cout << "Found PI at position n=" << std::distance(piDump.begin(),piIterator)+1 << std::endl;
    }

	return 0;
}
