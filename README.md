# cpp-data-structures
Collection of C++ data structure implementations and unit tests. Primarily informational, since there are countless competing implementations, many of which were probably not written half a decade ago by an at-the-time freshman CS student.

Each structure has its own folder and own main.cpp file, which runs a test suite for the structure. To compile on *nix, you'll need a compiler like gcc or g++, and need to have CppUnit installed.

    sudo apt-get install g++
    sudo apt-get install libcppunit-1.13-0
    sudo apt-get install libcppunit-dev

To compile the binary, include the *-lcppunit* flag with g++. Not sure how to include CppUnit with other compilers.

    g++ -o whatever.out *.cpp -lcppunit
    ./whatever.out

I still need to finish sorting through the remaining structures, the folders up now include:

* [array](http://www.cplusplus.com/reference/array/array/) - Basically just a wrapper around an array. The less said, the better.
* [vector](http://www.cplusplus.com/reference/vector/vector/) - Vector implementation.
* [slist](http://www.cplusplus.com/reference/forward_list/forward_list/) - Singly-linked list implementation.
* [deque](http://www.cplusplus.com/reference/deque/deque/) - Double ended queue implementation.
* sorting-algorithms - Basic quicksort and mergesort implementations.
