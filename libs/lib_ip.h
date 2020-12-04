#include <iostream>

#include <array>
#include <string>
#include <list>
#include <vector>

/*!
*   @brief Simple template predicate to check string-type 
*   @tparam T - template param to check
*/
template <typename T>
using is_string = std::is_same<T,   std::string> ;
        
/*!
*   @brief Simple template predicate to check list-type
*   @tparam T - template param to check 
*/
template <typename T>
using is_list= std::is_same<T,   std::list<typename T::value_type, typename T::allocator_type>> ;

/*!
*   @brief Simple template predicate to check vector-type 
*   @tparam T - template param to check
*/
template <typename T>
using is_vector = std::is_same<T,   std::vector<typename T::value_type, typename T::allocator_type>> ;
        
/*!
*   @brief SFINAE template for integral type
*   @tparam T - template param, if not integral then substitution failure
*   @param data - param, expected integral, integral representation of ip adress
*/
template <typename T1>
typename std::enable_if_t<std::is_integral<T1>::value, void> printInfo (T1& data){
    auto raw_byte = reinterpret_cast<uint8_t*>(&data);
    for(uint8_t i = sizeof(T1)-1; i > 0; std::cout << static_cast<int>(raw_byte[i--]) <<".");
    std::cout << static_cast<int>(raw_byte[0]) << std::endl;
}
     
/*!
*   @brief SFINAE template for string type
*   @tparam T1 - template param, if not string - substitution failure
*   @param data - param, expected stritg, stritg representation of ip adress
*/ 
template <typename T1>
typename std::enable_if_t<is_string<T1>::value, void> printInfo (T1& data){ std::cout << data << std::endl;}
     
/*!
*   @brief SFINAE template for container type
*   @tparam T1 - template param, if not container - substitution failure
*   @param data - param, expected vector or list, container representation of ip adress
*/ 
template <typename T1>
typename std::enable_if_t<is_vector<T1>::value || is_list<T1>::value, void> printInfo (T1& data) { 
for (auto it = data.begin(); it != data.end();)
{
    std::cout << static_cast<int>(*(it++));
    if (it != data.end()) 
    std::cout <<  ".";
}
std::cout << std::endl;
            
}