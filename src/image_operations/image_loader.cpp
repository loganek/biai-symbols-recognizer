#include "image_loader.h"

using namespace std;

ImageLoader::ImageLoader()
  :imgBuffer(NULL)
{
  file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
}

ImageLoader::~ImageLoader()
{
  ReleaseBuffer();
}

const Size& ImageLoader::GetSize()
{
  return size;
}

const bool* ImageLoader::GetImageBuffer()
{
  return imgBuffer;
}

const byte* ImageLoader::Load(const string& filename)
{
  this->filename = filename;

  ReleaseBuffer();
  OpenFile();

  if ( !CheckHeader() )
    throw exception();

  ReadImageSize();
  ReadImageData();
}

void ImageLoader::ReleaseBuffer()
{
  if ( imgBuffer != NULL )
    {
      delete imgBuffer;
      imgBuffer = NULL;
    }
}

void ImageLoader::OpenFile()
{
  try
    {
      file.open(filename, ios::in | ios::binary);
    }
  catch ( ifstream::failure e )
    {
      throw exception(e);
    }
}

bool ImageLoader::CheckHeader()
{
  short bfType;

  file.read((char*)&bfType, 2);

  return bfType == 0x4D42;
}

void ImageLoader::ReadImageSize()
{
  file.seekg(18);

  file.read((char*)&size.width, 4);
  file.read((char*)&size.height, 4);
}

void ImageLoader::ReadImageData()
{
  imgBuffer = new bool[size.width * size.height];
  
  int start = ReadOffset();

  file.seekg(start);

  byte rowBuffer[size.width * 3];
  std::streampos dummy = size.width % 4;

  for ( int i = size.height - 1; i >= 0; i-- )
    {
      file.read((char*)rowBuffer, size.width * 3);
      file.seekg(file.tellg() + dummy);

      InsertRowToBuffer(rowBuffer, size.height - i - 1);
    }
}

int ImageLoader::ReadOffset()
{
  int offset = 0;

  file.seekg(10);
  file.read((char*)&offset, 4);

  return offset;
}

void ImageLoader::InsertRowToBuffer(byte* rowBuffer, int rowIndex)
{
  for ( int i = 0; i < size.width; i++ )
    {
      imgBuffer[i + rowIndex * size.width] = NotWhitePixel(rowBuffer + i * 3);      
    }
}

bool ImageLoader::NotWhitePixel(byte* pixel)
{
  return *pixel != 255 || *(pixel + 1) != 255 || *(pixel + 2) != 255;
}
