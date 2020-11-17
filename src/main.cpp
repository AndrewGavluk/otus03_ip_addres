#include "../libs/lib_ip.h" 

int main(){

	char testChar{-1};
	printInfo(testChar);

	short testshort{0};
	printInfo(testshort);

	int testInt{2130706433};
	printInfo(testInt);

	long testLong{8875824491850138409};
	printInfo(testLong);

	std::string testString ("mySitename.com");	
	printInfo(testString);

	std::vector<int> testVector{1,2,3,4};
	printInfo(testVector);

	std::list<int> testList{1,2,3,4};
	printInfo(testList); 

return 0;
}
