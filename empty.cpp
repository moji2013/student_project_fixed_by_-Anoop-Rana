//
// Created by solo-l-ub on 3/18/22.
//

#include "empty.h"

namespace empty{
    empty :: empty () {

        errors = "name can't be empty !\n";
    }

    empty :: empty ( const char * errors ) {

        (*this).errors = errors;

    }


    const char * empty :: what () const noexcept {

        return errors;
    }
}