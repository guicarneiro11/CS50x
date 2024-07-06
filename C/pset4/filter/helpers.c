#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            BYTE average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int redTotal = 0, greenTotal = 0, blueTotal = 0;
            int count = 0;

            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int newRow = i + di;
                    int newCol = j + dj;

                    if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width) {
                        redTotal += image[newRow][newCol].rgbtRed;
                        greenTotal += image[newRow][newCol].rgbtGreen;
                        blueTotal += image[newRow][newCol].rgbtBlue;
                        count++;
                    }
                }
            }

            temp[i][j].rgbtRed = redTotal / count;
            temp[i][j].rgbtGreen = greenTotal / count;
            temp[i][j].rgbtBlue = blueTotal / count;
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = temp[i][j];
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Sobel kernels
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int Gy[3][3] = {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}
    };

    // Create a copy of the original image
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Apply Sobel operator to each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize Sobel sums for each color channel
            float sumRedX = 0, sumRedY = 0;
            float sumGreenX = 0, sumGreenY = 0;
            float sumBlueX = 0, sumBlueY = 0;

            // Iterate over the 3x3 grid surrounding the pixel
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    // Ensure the neighbor pixel is within bounds
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        // Apply Sobel kernels to each color channel
                        sumRedX += copy[ni][nj].rgbtRed * Gx[di + 1][dj + 1];
                        sumRedY += copy[ni][nj].rgbtRed * Gy[di + 1][dj + 1];
                        sumGreenX += copy[ni][nj].rgbtGreen * Gx[di + 1][dj + 1];
                        sumGreenY += copy[ni][nj].rgbtGreen * Gy[di + 1][dj + 1];
                        sumBlueX += copy[ni][nj].rgbtBlue * Gx[di + 1][dj + 1];
                        sumBlueY += copy[ni][nj].rgbtBlue * Gy[di + 1][dj + 1];
                    }
                }
            }

            // Calculate the final color values
            int red = round(sqrt(sumRedX * sumRedX + sumRedY * sumRedY));
            int green = round(sqrt(sumGreenX * sumGreenX + sumGreenY * sumGreenY));
            int blue = round(sqrt(sumBlueX * sumBlueX + sumBlueY * sumBlueY));

            // Limit the values to 255
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            // Update the image with the new values
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
}
