#include "../libs/lib_ip.h" 

int main(){

	ip_printer test;

	char testChar{-1};
	loadInfo(testChar, test); // SFINAE 

	short testshort{0};
	loadInfo(testshort, test); // SFINAE 

	int testInt{2130706433};
	loadInfo(testInt, test); // SFINAE 

	long testLong{8875824491850138409};
	loadInfo(testLong, test); // SFINAE 

	std::string testString ("mySitename.com");	
	loadInfo(testString, test); // SFINAE 

	std::vector<int> testVector{1,2,3,4};
	loadInfo(testVector, test);  // SFINAE 

	std::list<int> testList{1,2,3,4};
	loadInfo(testList, test);  // SFINAE 

return 0;
}
