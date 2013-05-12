#include "image_perimeter.h"

ImagePerimeter::ImagePerimeter(const BinaryImage& image)
{
  this->image = image;
  perimeter = 0;
}

int ImagePerimeter::GetPerimeter()
{
  return perimeter;
}

void ImagePerimeter::RunAlgorithm()
{
  perimeter = 0;

  for ( int i = 0; i < image.GetSize().height; i++ )
    for ( int j = 0; j < image.GetSize().width; j++)
      if ( IsPixelInPerimeter(j, i) )
	perimeter++;
}

bool ImagePerimeter::IsPixelInPerimeter(int x, int y)
{
  bool value = image.GetPixel(x, y);

  if ( value == false )
    return false;

  if ( x == 0 || y == 0)
    return true;

  if ( x == image.GetSize().width - 1 || y == image.GetSize().height - 1 )
    return true;

  if ( image.GetPixel(x - 1, y - 1) == false ||
       image.GetPixel(x - 1, y) == false ||
       image.GetPixel(x - 1, y + 1) == false ||
       image.GetPixel(x, y - 1) == false ||
       image.GetPixel(x, y) == false ||
       image.GetPixel(x, y + 1) == false ||
       image.GetPixel(x + 1, y - 1) == false ||
       image.GetPixel(x + 1, y) == false ||
       image.GetPixel(x + 1, y + 1) == false)
    return true;

  return false;
}
