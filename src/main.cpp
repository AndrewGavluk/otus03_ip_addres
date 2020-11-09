#include "../libs/lib_ip.h" 
int main(){
foo();

	std::string testString ("mySitename.com");
	ip_printer t_string;
	ip_printer1(testString, t_string);

	std::vector<int> testVector{1,2,3,4};
	ip_printer t_vector;
	ip_printer1(testVector, t_vector);

	std::list<int> testList{1,2,3,4};
	ip_printer t_list;
	ip_printer1(testList, t_list);

return 0;
}
