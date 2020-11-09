#include <iostream>

#include <array>
#include <string>
#include <list>
#include <vector>

        template <typename T>
        using is_stritg = std::is_same<T,   std::string> ;
        
        template <typename T>
        using is_list= std::is_same<T,   std::list<typename T::value_type, typename T::allocator_type>> ;

        template <typename T>
        using is_vector = std::is_same<T,   std::vector<typename T::value_type, typename T::allocator_type>> ;
        //for integral 
        template <typename T1>
        typename std::enable_if_t<std::is_integral<T1>::value, void> loadInfo (T1& data){
            auto raw_byte = reinterpret_cast<uint8_t*>(&data);
            for(uint8_t i = sizeof(T1)-1; i > 0; std::cout << static_cast<int>(raw_byte[i--]) <<".");
            std::cout << static_cast<int>(raw_byte[0]) << std::endl;
        }

        //for string 
        template <typename T1>
        typename std::enable_if_t<is_stritg<T1>::value, void> loadInfo (T1& data){ std::cout << data << std::endl;}

        //for vector and list
        template <typename T1>
        typename std::enable_if_t<is_vector<T1>::value || is_list<T1>::value, void> loadInfo (T1& data) { 
            for (auto it = data.begin(); it != data.end();)
            {
                 std::cout << static_cast<int>(*(it++));
                 if (it != data.end()) 
                    std::cout <<  ".";
            }
            std::cout << std::endl;
        }