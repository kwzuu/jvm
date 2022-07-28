
#include "../types.h"
#include "../constants.h"
#include "../class/Class.h"
#include <vector>
using std::vector;

class VM {
    public:
        VM(int argc, char **argv);
        ~VM();
        //! Class
        void loadClass(Class class_);
        Class getClass(char* classpath);
        //! Method
        MethodInfo getMethod(char* classpath, char* methodname);
        void openMethodTree
        //! Constant Pool
        void displayAllCpInfo(char* classpath);
    private:
        bool verifyValidBytecodeVersion(u4 version);
        // Maps classpath to Class
        ClassMap classmap;
        // Maps classpath.methodname to MethodInfo
        MethodMap methodmap;

};