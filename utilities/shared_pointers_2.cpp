// In this example we use a file pointer
// to create a temporary file that is
// deleted when there are no more references using the file pointer

#include <fstream> // for ofstream
#include <memory>  // for shared_ptr
#include <string>  // for strings
#include <cstdio>  // for remove

class FileDeleter
{
private:
    std::string filename; // we need a class and not a simple function to store the filename
public:
    FileDeleter(const std::string &fn) : filename(fn) {}
    void operator()(std::ofstream *fp)
    {                                  // this makes it a functor
        fp->close();                   // close file
        std::remove(filename.c_str()); // delete File
    }
};

int main()
{
    // create and open temporary file
    std::shared_ptr<std::ofstream> fp(new std::ofstream("tmpfile.txt"), // new file pointer
                                      FileDeleter("tmpfile.txt"));      // deleter
}