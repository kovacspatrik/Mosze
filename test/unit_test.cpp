#include "../Phone.hpp"
#include "../Notebook.hpp"
#include "../Computer.hpp"
#include "../Console.hpp"
#include "../Warehouse.hpp"
#include "../JSON.hpp"


#include <sstream>
#include <gtest/gtest.h>


TEST(parserTest, test_filename){
	std::string filename;
	std::map<std::string, std::string> testOutput; 
	std::map<std::string, std::string> expectedOutput;
	expectedOutput={
		{"name", "AMD creator daily"},
	    {"price", "1100000"},
	    {"manufacturer", "iBuyPower"},
        {"quantity", "3"},
        {"ramSize", "32"},
        {"storage", "2500"}};
	filename="../computer/Unit1.json";                       
	testOutput = JSON::Parse(filename);
	for (auto iter : expectedOutput){
		ASSERT_EQ(testOutput[iter.first],expectedOutput[iter.first]);
	}
}



int main(int argc, char** argv ){
	::testing::InitGoogleTest (&argc, argv);
	return RUN_ALL_TESTS();
}