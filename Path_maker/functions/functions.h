#include <iostream>
#include <vector>

#ifndef FUNCT
#define FUNCT

class Path_Image
{
  private:
  std::vector <std::string> seeds;
  std::string name = "Generated/Path_00.png";
  int size_x, size_y;
  char answer;
  int how_many_images = 10;



  public:
    void seed_to_class();
    void generate_images();
};

void generating_seed(int how_many_seeds);
void reading_seed();
void menu();
void console();
void ifwindow();
void test();


#endif
