#include "binary_image.h"
#include <cstring>

BinaryImage::BinaryImage()
  : imageBuffer(NULL)
{
  
}

BinaryImage::~BinaryImage()
{
  ReleaseBuffer();
}

void BinaryImage::ReleaseBuffer()
{
  if ( imageBuffer != NULL )
    {
      delete imageBuffer;
      imageBuffer = NULL;
    }
}

const Size& BinaryImage::GetSize()
{
  return size;
}

void BinaryImage::LoadFromFile(const std::string& filename)
{
  ImageLoader loader;

  loader.Load(filename);
  size = loader.GetSize();

  imageBuffer = new bool[size.width * size.height];

  memcpy(imageBuffer, loader.GetImageBuffer(), size.width * size.height);
}

bool BinaryImage::GetPixel(int x, int y)
{
  if ( !CheckRange(x, y) )
    throw std::exception();

  return imageBuffer[x + y * size.width];
}

void BinaryImage::SetPixel(int x, int y, bool value)
{
  if ( !CheckRange(x, y) )
    throw std::exception();

  imageBuffer[x + y * size.height] = value;
}

bool BinaryImage::CheckRange(int x, int y)
{
  return x < size.width && y < size.height;
}
