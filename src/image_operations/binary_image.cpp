#include "image.h"

Image::Image()
{
  
}

void Image::LoadFromFile(const std::string& filename)
{
  ImageLoader loader;

  loader.Load(filename);
}

bool Image::GetPixel(int x, int y)
{

  return true;
}

void Image::SetPixel(int x, int y)
{
  
}
