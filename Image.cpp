#include "Image.h"
#include "lodepng.h"  // Library for PNG image loading and saving
#include <stdexcept>  // Include for std::runtime_error

Image::Image(const std::string& filename) {
    unsigned int error = lodepng::decode(data, width, height, filename);
    if (error) {
        throw std::runtime_error("Error loading image: " + std::string(lodepng_error_text(error)));
    }
}

int Image::getWidth() const {
    return width;
}

int Image::getHeight() const {
    return height;
}

void Image::setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    int index = 4 * (y * width + x);
    data[index + 0] = r;
    data[index + 1] = g;
    data[index + 2] = b;
    data[index + 3] = a;
}

void Image::getPixel(int x, int y, unsigned char& r, unsigned char& g, unsigned char& b, unsigned char& a) {
    int index = 4 * (y * width + x);
    r = data[index + 0];
    g = data[index + 1];
    b = data[index + 2];
    a = data[index + 3];
}

void Image::save(const std::string& filename) {
    unsigned int error = lodepng::encode(filename, data, width, height);
    if (error) {
        throw std::runtime_error("Error saving image: " + std::string(lodepng_error_text(error)));
    }
}

// Implement additional image processing methods here
