/**
 * Document: Dataflow Programming with Maxeler (pappa16.pdf)
 * Exercise 4      Name: Max-pooling layer
 * MaxFile name: Exercise4
 * Summary:
 *      CPU code for a kernel design of Max-pooling layer.
 */

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

void generateInputData(
	int size,
	uint32_t *inA)
{
	for (int i = 0; i < size; ++i)
		inA[i] = (uint32_t) 100 - i ;
}

void MaxpoolingCPU(
	int size,
	int width,
	uint32_t *in,
	uint32_t *outY)
{
	int k=0;
	for (int i=0; i < size/width; i++)
	{
		for (int j=0; j < width; j++)
		{
			// Pixels are streamed in column by column
			if ( i % 2 == 1 && j % 2 == 1 )
			{
				outY[k] = in[ i * width + j];
				outY[k] = fmax( outY[k], in[ i * width + (j-1)]);
				outY[k] = fmax( outY[k], in[ (i-1) * width + j]);
				outY[k] = fmax( outY[k], in[ (i-1) * width + (j-1)]);
				k++;
			}
		}
	}
}

int check(int size, uint32_t *outY, uint32_t *expected) {
	int status = 0;
	for (int i = 0; i < size; ++i) {
		if (outY[i] != expected[i]) {
			fprintf(stderr, "ERROR @ %d, expected %u, got %u\n",
				i, expected[i], outY[i]);
			status = 1;
		}
	}
	return status;
}

int main()
{
	const int size = 64;
	const int height = 8;
	int dataSize = size * sizeof(uint32_t);
	uint32_t *in = malloc(dataSize);
	uint32_t *outY = malloc(dataSize);
	uint32_t *expected = malloc(dataSize);

	generateInputData(size, in);

	printf("Running DFE.\n");
	Maxpooling(size, in, outY);

	MaxpoolingCPU(size, height, in, expected);

	int status = check(size/4, outY, expected);
	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}
