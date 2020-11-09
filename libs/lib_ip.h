#include <iostream>

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
       
        //for string 
        template <typename T1>
        friend typename std::enable_if_t<is_stritg<T1>::value, void> ip_printer1 (T1& data, ip_printer& printer){
            printer.m_data = std::string{"is string"}; 
            (void)(data);}


        //for vector 
        template <typename T1>
        friend typename std::enable_if_t<is_vector<T1>::value, void> ip_printer1 (T1& data, ip_printer& printer) { 
             printer.m_data = std::string{"is vector"};
            (void)(data);
        }

        //for list 
        template <typename T1>
        friend typename std::enable_if_t<is_list<T1>::value, void> ip_printer1 (T1& data, ip_printer& printer) { 
             printer.m_data = std::string{"is vector"};
            (void)(data);
        }

        ip_printer(): m_data{"empty"}{}
        
        void print() { std::cout << m_data << std::endl; }
    private: 
        std::string m_data;
};
