//
// Created by solo-l-ub on 3/18/22.
//

#ifndef STUDENT_PROJECT_FINAL_V2_FILE_MISSING_H
#define STUDENT_PROJECT_FINAL_V2_FILE_MISSING_H



#include <exception>
namespace file_missing {

    class file_missing : public std::exception {

    private:
        const char * errors;

    public:
        file_missing ();
        file_missing ( const char * );

        const char * what() const noexcept override;



    };
}




#endif //STUDENT_PROJECT_FINAL_V2_FILE_MISSING_H
