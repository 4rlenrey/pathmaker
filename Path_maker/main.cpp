#include <iostream>
#include "functions/functions.h"
#include <thread>

using namespace std;


int main(int argc, char const *argv[])
{
  thread windowt(ifwindow);
  windowt.join();

  thread tconsole(console);
  tconsole.join();

    return 0;
}
