#include "image_operations/binary_image.h"
#include <iostream>


int main()
{
  try
    {
      BinaryImage img;
      img.LoadFromFile("image_operations/testimage.bmp");
      
      for ( int i =0; i < img.GetSize().height; i++ )
	{
	  for ( int j = 0; j < img.GetSize().width; j++ )
	    std::cout << img.GetPixel(j, i);

	  std::cout << std::endl;
	}
    }
  catch ( std::exception ex )
    {
      std::cout << "Wyjatek: "  << ex.what() << std::endl;
    }
}
