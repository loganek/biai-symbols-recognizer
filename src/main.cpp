#include "image_operations/image_loader.h"
#include <iostream>


int main()
{
  try
    {
      ImageLoader img;
      img.Load("image_operations/testimage.bmp");
      const bool* buff = img.GetImageBuffer();

      for ( int i =0; i < img.GetSize().height; i++ )
	{
	  for ( int j = 0; j < img.GetSize().width; j++ )
	    std::cout << buff[i * img.GetSize().width + j];

	  std::cout << std::endl;
	}
    }
  catch ( std::exception ex )
    {
      std::cout << "Wyjatek: "  << ex.what() << std::endl;
    }
}
