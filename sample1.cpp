#include <iostream>

#include "base_opts.hpp"

int main(int argc, char **argv)
{
  BaseOptions opt(argc, argv);
  opt.print_args();

  return 0;
}
