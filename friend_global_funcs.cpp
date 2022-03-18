//
// Created by solo-l-ub on 3/18/22.
//




#include "list.h"
#include "file_missing.h"
#include "empty.h"
namespace friend_global_funcs {

    std::ofstream & operator<< (std::ofstream &ofs, const list::list &l)  { //const added here

        if (!l.check_created_file())
            throw new file_missing::file_missing(
                    "can not write info to file something wrong with acquiring file in constructor of obj \n");


        ofs << l.name << "\t" << l.price << "\t" << l.quantity << "\n"; //changed l.name() to l.name

        return ofs;

    }


    std::ifstream & operator>>(std::ifstream &ifs, list :: list &l) {

        l.set_readable_file();

        if (!l.check_opened_file())
            throw new file_missing::file_missing(
                    "can't retrieve data cuz file is not associated with obj currently I'm in operated >> overloaded fuc \n");


        ifs >> l.name >> l.price >> l.quantity;

        return ifs;
    }

}
