/*
  File: btn.h
  Author: Matthew White CS153 B
  Contains the binary tree node struct
*/
#ifndef BTN_H
#define BTN_H

template<typename generic>
struct BTN
{
    BTN* p;
    BTN* l;
    BTN* r;
    generic* data;
};

#endif
