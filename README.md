# cpp-data-structures
Collection of C++ data structure implementations and unit tests. Primarily informational, since there are countless competing implementations, many of which were probably not written half a decade ago by an at-the-time freshman CS student.

Each structure has its own folder and own main.cpp file, which runs a test suite for the structure. To compile on *nix, you'll need a compiler like gcc or g++, and need to have CppUnit installed.

    sudo apt-get install g++
    sudo apt-get install libcppunit-1.13-0

To compile the binary, include the *-lcppunit* flag with g++. Not sure how to include CppUnit with other compilers.

    g++ -o whatever.out *.cpp -lcppunit
    ./whatever.out
