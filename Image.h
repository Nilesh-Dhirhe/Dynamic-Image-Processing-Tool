#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>

class Image {
private:
    unsigned int width;
    unsigned int height;
    std::vector<unsigned char> data;  // Image data in RGBA format (assuming 8-bit per channel)

public:
    Image(int w, int h);
    Image(const std::string& filename);

    int getWidth() const;
    int getHeight() const;
    void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    void getPixel(int x, int y, unsigned char& r, unsigned char& g, unsigned char& b, unsigned char& a);
    void save(const std::string& filename);

    // Add more methods for image processing (e.g., filters, resizing, etc.)
};

#endif // IMAGE_H
