#include <iostream>

#include <array>
#include <string>
#include <list>
#include <vector>

void foo();


class ip_printer
{   
    public:

        
        template <typename T>
        using is_stritg = std::is_same<T,   std::string> ;
        
        template <typename T>
        using is_list= std::is_same<T,   std::list<typename T::value_type, typename T::allocator_type>> ;

        template <typename T>
        using is_vector = std::is_same<T,   std::vector<typename T::value_type, typename T::allocator_type>> ;
       
        //for integral 
        template <typename T1>
        friend typename std::enable_if_t<std::is_integral<T1>::value, void> loadInfo (T1& data, ip_printer& printer){
            auto raw_byte = reinterpret_cast<uint8_t*>(&data);
            std::array<uint8_t, sizeof(T1)> arr{*raw_byte};
                for(auto &i : arr)
                    std::cout << static_cast<int>(i) << ".";
              (void)(printer);
        }

        //for string 
        template <typename T1>
        friend typename std::enable_if_t<is_stritg<T1>::value, void> loadInfo (T1& data, ip_printer& printer){
            printer.m_data = data; 
            (void)(data);
            printer.print();}

        //for vector and list
        template <typename T1>
        friend typename std::enable_if_t<is_vector<T1>::value || is_list<T1>::value, void> loadInfo (T1& data, ip_printer& printer) { 
             printer.m_data = std::string{"is container"};
            (void)(data);
            printer.print();
        }

        ip_printer(): m_data{"empty"}{}
        
        void print() { std::cout << m_data << std::endl; }
    private: 
        std::string m_data;
};
