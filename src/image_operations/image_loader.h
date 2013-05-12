#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include <string>
#include <fstream>

struct Size
{
  int width;
  int height;
};

typedef unsigned char byte;

class ImageLoader
{
 private:
  std::fstream file;
  std::string filename;
  Size size;
  bool* imgBuffer;

  void ReleaseBuffer();
  void OpenFile();
  bool CheckHeader();
  void ReadImageSize();
  void ReadImageData();
  int ReadOffset();
  static bool NotWhitePixel(byte* pixel);
  void InsertRowToBuffer(byte* rowBuffer, int rowIndex);
 public:
  ImageLoader();
  ~ImageLoader();
  const byte* Load(const std::string& filename);
  const Size& GetSize();
  const bool* GetImageBuffer();
};

#endif
