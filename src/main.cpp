#include "../libs/lib_ip.h" 

int main(){

	char testChar{-1};
	loadInfo(testChar);

	short testshort{0};
	loadInfo(testshort);

	int testInt{2130706433};
	loadInfo(testInt);

	long testLong{8875824491850138409};
	loadInfo(testLong);

	std::string testString ("mySitename.com");	
	loadInfo(testString);

	std::vector<int> testVector{1,2,3,4};
	loadInfo(testVector);

	std::list<int> testList{1,2,3,4};
	loadInfo(testList); 

return 0;
}
