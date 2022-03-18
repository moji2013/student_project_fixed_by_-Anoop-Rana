#ifndef MSG_ENTER_NAME
#define MSG_ENTER_NAME "please_enter_item_name \n"
#endif

#ifndef MSG_ENTER_PRICE
#define MSG_ENTER_PRICE "please_enter_price\n"
#endif

// preprocessor directives macros

#ifndef MSG
#define MSG(X) #X;
#endif

// global identifiers
// global constant identifiers

// constants

#include <iostream>

// using namespaces


// classes
#include "file_missing.h"
#include "empty.h"
#include "list.h"
using friend_global_funcs::operator<<;
using friend_global_funcs::operator>>;

int main() {



    // obj creation
    list :: list obj;
/////////////////////////////////////////


    // writing obj to file
    std::cout << MSG_ENTER_NAME;
    std::string temp_name;
    std::cin >> temp_name;

    std::cout << MSG_ENTER_PRICE;
    int temp_price;
    std::cin >> temp_price;


    std::cout << MSG(please_enter_quantity);
    std::cout << std::endl;
    short temp_quantity;
    std::cin >> temp_quantity;


    try {

        obj.set_name ( temp_name );
        obj.set_price ( temp_price );
        obj.set_quantity ( temp_quantity );

        obj.set_created_file();

        obj.ofs << obj;

        // protected code

        std::cout << "successfully written to file \n";

    }
    catch (  class empty :: empty *e) {
        std::cout << (*e).what();

    }
    catch ( class file_missing :: file_missing *e) {
        std::cout << (*e).what();
    }
    catch ( std::exception e ) {
        std::cout << e.what();
    }
    catch ( ... ) {

        std::cout << "couldn't write contact administrator \n";
    }


    // finally so will execute otherwise

    std::cout << "end of try catch write \n";

///////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////



    // reading into an obj

    try {

        obj.ifs >> obj;


        // protected code
        std::cout << "successfully read into obj\n";


        std::cout << obj.get_name() << "\t";
        std::cout << obj.get_quantity() << "\t";
        std::cout << obj.get_price() << std::endl;

    }
    catch ( file_missing :: file_missing *e ) {

        std::cout << (*e).what();
    }
    catch ( std::exception e ) {
        std::cout << e.what();
    }

    catch (...) {
        std::cout << "couldn't read contact admin \n";

    }

    // finally
    std::cout << "end of try catch read \n";


    //////////////////////////////////////////////////

    return 0;
}
