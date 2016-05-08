#ifndef BTN_H
#define BTN_H

template<typename generic>
struct BTN
{
  BTN* p;
  BTN* l;
  BTN* r;
  generic* d;
  unsigned int depth;
};

#endif
