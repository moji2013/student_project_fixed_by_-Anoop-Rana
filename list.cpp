//
// Created by solo-l-ub on 3/18/22.
//

#include "list.h"
#include"empty.h"
#include "file_missing.h"
namespace list{
// constructors
    list :: list () noexcept ( noexcept ( set_created_file() ) )  {
        // give 'em a valid obj
        // ,and a most common one
        name = "not_set" , price = 1 , quantity = 1;

        // not sure weather to call the
        set_created_file();
        // or simply call this
//    ofs.open("list.txt", ios::app);
    }

    list :: list ( std::string name , int price , short quantity ) noexcept(false) {

        set_name ( name );
        set_price ( price );
        set_quantity ( quantity );

        set_created_file();
    }

    list :: list ( class list &r ) noexcept ( noexcept ( set_created_file() ) )  {

        name = r.name;
        price = r.price;
        quantity = r.quantity;

        // how to copy file location then?

//    ofs = r.ofs;
        set_created_file();
    }
////


// initialization to cover after construction of an obj
    void list :: initialize ( std::string name , int price , short quantity ) {
        set_name ( name );
        set_price ( price );
        set_quantity ( quantity );
        set_created_file();
    }
////

// mutators
    void list :: set_name ( std::string name ) noexcept(false) {

        if ( name.empty() )
            throw new empty::empty ( "name can not be left out enter something \n");

        (*this).name = name;
    }

    void list :: set_price ( int price )  noexcept(false) {

        if ( !price )
            throw new empty :: empty ( "price can not be zero \n" );

        (*this).price = price;
    }

    void list :: set_quantity ( short quantity ) noexcept(false) {

        if ( !quantity )
            throw new empty :: empty ( "quantity can not be zero \n" );

        (*this).quantity = quantity;
    }

/////


// file mutators
    void list :: set_created_file () noexcept(false) {

        if ( !ofs.is_open() )
            ofs.open("student_list_file.txt", std::ios::app);

        if ( !ofs.is_open() )
            throw new file_missing :: file_missing ( "file couldn't be created or opened \n" );

    }

    void list :: set_readable_file () {

        if ( !ifs.is_open() )
            ifs.open ( "student_list_file.txt" );

        if ( !ifs.is_open() )
            throw new file_missing :: file_missing ( "file couldn't be opened by set_readable_file function \n" );

    }



////


// accessors
    std::string list :: get_name () const noexcept {
        return name;
    }
    int list :: get_price () const  noexcept {
        return price;

    }
    int list :: get_quantity () const  noexcept {
        return quantity;
    }

///

// enqueries
    bool list :: check_created_file () const noexcept{

        return ofs.is_open();
    }


    bool list :: check_opened_file (){

        return ifs.is_open();
    }


// destructive
    list :: ~list() {
        // release resources
        // close file
        // close connection
        // release heap memory

        ofs.close();
        ifs.close();

    }
}