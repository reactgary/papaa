/**
 * Document: MaxCompiler Training (maxcompiler-training.pdf)
 * Chapter: 1      Exercise Solution: 1      Name: Brightness Solution
 * MaxFile name: BrightnessSolution
 * Summary:
 *   Adjusts the brightness of an image by adding a constant
 *   value to every pixel.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

#include "ppmIO.h"

int check()
{
	const char *verify_command =
		"cmp lena_brightness.ppm lena_brightness_expected.ppm";
	return(system(verify_command));
}

int main(void)
{
	printf("Loading image.\n");
	int32_t *inImage;
	int width = 0, height = 0;
	loadImage("lena.ppm", &inImage, &width, &height, 1);

	int dataSize = width * height * sizeof(int32_t);
	// Allocate a buffer for the output image
	int32_t *outImage = malloc(dataSize);

	printf("Running Kernel.\n");
	BrightnessSolution(width * height, 100, inImage, outImage);

	printf("Saving image.\n");
	writeImage("lena_brightness.ppm", outImage, width, height, 1);

	int status = check();
	if (status) {
		printf("Test failed.\n");
	} else {
		printf("Test passed OK!\n");
	}

	printf("Exiting\n");
	return status;
}
