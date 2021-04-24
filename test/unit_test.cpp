#include "../Phone.hpp"
#include "../Notebook.hpp"
#include "../Computer.hpp"
#include "../Console.hpp"
#include "../Warehouse.hpp"
#include "../JSON.hpp"


#include <sstream>
#include <gtest/gtest.h>


TEST(JsonparserTest, JSON_ifstream_work)
{
	std::string inputFilename = "../computers/AMDcreatordaily.json";
	std::map<std::string, std::string> exp_output;
	exp_output.insert(std::pair<std::string, std::string>("name", "AMD creator daily"));
	exp_output.insert(std::pair<std::string, std::string>("price", "1100000"));
	exp_output.insert(std::pair<std::string, std::string>("manufacturer", "iBuyPower"));
	exp_output.insert(std::pair<std::string, std::string>("quantity", "3"));
	exp_output.insert(std::pair<std::string, std::string>("ramSize", "32"));
	exp_output.insert(std::pair<std::string, std::string>("storage", "2500"));

    std::ifstream inputFile(inputFilename);

	std::map<std::string, std::string> test_output = JSON::Parse(inputFile);

    inputFile.close();

	ASSERT_EQ(exp_output, test_output);
}

TEST(JsonparserTest, JSON_Parse_good_fname)
{
	std::string inputFilename = "../computers/AMDcreatordaily.json";
	std::map<std::string, std::string> exp_output;
	exp_output.insert(std::pair<std::string, std::string>("name", "AMD creator daily"));
	exp_output.insert(std::pair<std::string, std::string>("price", "1100000"));
	exp_output.insert(std::pair<std::string, std::string>("manufacturer", "iBuyPower"));
	exp_output.insert(std::pair<std::string, std::string>("quantity", "3"));
	exp_output.insert(std::pair<std::string, std::string>("ramSize", "32"));
	exp_output.insert(std::pair<std::string, std::string>("storage", "2500"));
	
	std::map<std::string, std::string> test_output = JSON::Parse(inputFilename);
	
	ASSERT_EQ(exp_output, test_output);
}

TEST(JsonparserTest, JSON_Parse_bad_fname)
{
	std::string inputFilename = "../computers/AMDcreatordaily.json";
	
	ASSERT_THROW(JSON::Parse(inputFilename), std::runtime_error);
}


TEST(JsonparserTest, unit_test)
{
	
	std::map<std::string, std::string> maple = JSON::Parse("../computers/AMDcreatordaily.json");
	std::map<std::string, std::string> sally = JSON::Parse("../computers/Predator.json");
	ASSERT_FALSE(maple == sally);
}



int main(int argc, char** argv ){
	::testing::InitGoogleTest (&argc, argv);
	return RUN_ALL_TESTS();
}