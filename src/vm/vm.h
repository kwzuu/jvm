
#include "../types.h"
#include "../constants.h"
#include "../class/Class.h"
#include <vector>
using std::vector;

class VM {
    public:
        VM();
        ~VM();
        void loadClass(Class class_);
        Class getClass(char* classpath);
        MethodInfo getMethod(char* classpath, char* methodname);
        void displayAllCpInfo(char* classpath);
    private:
        vector<Class> classes;

};