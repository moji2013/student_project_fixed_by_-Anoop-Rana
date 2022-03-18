//
// Created by solo-l-ub on 3/18/22.
//

#ifndef STUDENT_PROJECT_FINAL_V2_EMPTY_H
#define STUDENT_PROJECT_FINAL_V2_EMPTY_H



#include <exception>

namespace empty {

    class empty : public std::exception {

    private:
        const char * errors ;

    public:
        empty();
        empty( const char * );


        const char * what() const noexcept override;



    };

}


#endif //STUDENT_PROJECT_FINAL_V2_EMPTY_H
