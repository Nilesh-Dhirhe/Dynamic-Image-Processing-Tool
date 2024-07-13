#include <iostream>
#include "Image.h"

int main() {
    try {
        Image img("input.png");  // Replace with your input image filename
        int width = img.getWidth();
        int height = img.getHeight();

        // Example: Invert colors
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                unsigned char r, g, b, a;
                img.getPixel(x, y, r, g, b, a);
                img.setPixel(x, y, 255 - r, 255 - g, 255 - b, a);  // Invert colors
            }
        }

        img.save("output.png");  // Replace with desired output filename
        std::cout << "Image processed and saved successfully." << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
