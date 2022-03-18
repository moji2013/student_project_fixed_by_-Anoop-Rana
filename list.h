//
// Created by solo-l-ub on 3/18/22.
//

#ifndef STUDENT_PROJECT_FINAL_V2_LIST_H
#define STUDENT_PROJECT_FINAL_V2_LIST_H



#include <fstream>
#include <string>
namespace list {
    class list;
}
namespace friend_global_funcs {

    std::ofstream & operator << ( std::ofstream & , const list::list &) ; //const added here and keyword class removed from second parameter
    std::ifstream & operator >> ( std::ifstream & , list::list &) ;//keyword class removed from second parameter
}

namespace list {

    class list {

    private:

        std::string name;
        int price;
        short quantity;


    public:

        std::ofstream ofs;
        std::ifstream ifs;


        // file_mutators
        void set_created_file () noexcept(false) ;
        void set_readable_file ();

        // constructors
        list() noexcept ( noexcept ( set_created_file() ) )  ;

        list ( std::string  , int , short  ) noexcept(false) ;
        list ( class list &) noexcept ( noexcept ( set_created_file() ) ) ;

        // initialization to cover after construction of an obj
        void initialize ( std::string , int , short ) noexcept(false) ;

        // mutators
        void set_name ( std::string ) noexcept(false);
        void set_price ( int ) noexcept(false) ;
        void set_quantity ( short ) noexcept(false) ;


        // accessors

        std::string get_name ( ) const  noexcept;
        int get_price () const noexcept;
        int get_quantity () const noexcept;


        // Enqueries
        bool check_created_file () const noexcept;//const added here
        bool check_opened_file();

        // destructor
        ~list();



        // friend global functions
        // overloaded operators

        friend std::ofstream & friend_global_funcs :: operator << ( std::ofstream & , const list &) ;//const added here
        friend std::ifstream &  friend_global_funcs :: operator >> ( std::ifstream & , list &) ;


    };

}



#endif //STUDENT_PROJECT_FINAL_V2_LIST_H
