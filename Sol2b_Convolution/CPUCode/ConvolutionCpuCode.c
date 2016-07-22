#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

float rand_interval(unsigned int min, unsigned int max)
{
    int r;
    const float range = 1 + max - min;
    const float buckets = RAND_MAX / range;
    const float limit = buckets * range;

    do
    {
        r = rand();
    } while (r >= limit);

    return min + (r / buckets);
}

void generateInputData(float *dataIn, int nx, int ny)
{
	for (int i = 0; i < nx * ny; i++) {
		dataIn[i] = rand_interval(0,255);
	}
	//dataIn[nx*ny/2+ny/2] = 9;
}

int check(int size, float *dataOut, float *expectedOut)
{
	int status =0;
	for (int i=0; i<size;i++) {
		if (dataOut[i]!=expectedOut[i]) {
			printf( "error at %i:\tdataOut = %5.2f\texpectedOut = %5.2f\n",i,dataOut[i],expectedOut[i]);
			status = 2;
		}
	}
	return status;
}

void print_2d_data(float *data, char* name, int nx, int ny)
{
	printf("\n%s\n", name);
	printf("Column y\n");
	for (int j=0; j<ny; j++) printf("%5i", j);
	printf("\n");
	for (int j=0; j<ny; j++) printf("-----");
	printf("\n");

 	for (int x = 0; x < nx; x++) {
		for (int y = 0; y < ny; y++) {
			printf("%5.3g", data[x * ny + y]);
		}
		printf(" | row x=[%i]", x);
		printf("\n");
	}
}

void TwoDAverageVariableCPU(int ny, int nx,  float w1, float w2, float w3, float w4, float w5,
		float w6, float w7, float w8, float w9, float *dataIn, float *dataOut)
{
	//3x3 Gaussian Convolution
	const float weight[3][3] = { {w1,w2,w3}, {w4,w5,w6}, {w7,w8,w9} };

	//croping margins
	const int nx_out = nx - 2;
	const int ny_out = ny - 2;

	//2D 3x3 Convolution
	for (int j = 0; j < ny_out; j++) {
		for (int i = 0; i < nx_out; i++) {
			for (int p = -1; p < 2; p++){
				for (int q = -1; q < 2; q++){
					dataOut[i*ny_out + j] += dataIn[(i+1 + p)*ny + (j + 1 + q)] * weight[p+1][q+1];

				}
			}
		}
	}

}

int main()
{
	const unsigned int NX = 16;
	const unsigned int NY = 8;
	unsigned int nxMax = 4096;

	if (NX > nxMax) {
		fprintf(stderr,"2D filter with maximum size nxMax=%d can not process data with nx=%d\n",nxMax,NX);exit(1);
	}

	float w1= 0.0625, w2 =0.125, w3 =0.0625, w4 = 0.125, w5 = 0.25, w6 = 0.125, w7 = 0.0625, w8 = 0.125, w9 = 0.0625;

	size_t sizeBytes = NX * NY * sizeof(float);
	size_t sizeBytesOut = (NX-2) * (NY-2) * sizeof(float);

	float *dataIn = malloc(sizeBytes);
	float *dataOut = malloc(sizeBytesOut);
	float *expectedOut = malloc(sizeBytesOut);

	generateInputData(dataIn, NX, NY);
	printf("Running DFE.\n");
	TwoDAverageVariableCPU(NY, NX, w1, w2, w3, w4, w5, w6, w7, w8, w9, dataIn, expectedOut);
	Convolution(NY, NX, NY, w1, w2, w3, w4, w5, w6, w7, w8, w9, dataIn, dataOut);

	// Display results, if we're running a small size
	if (NX < 20 && NY < 20) {
		print_2d_data(dataIn, "INPUT DATA", NX, NY);
		print_2d_data(expectedOut, "EXPECTED DATA", NX-2, NY-2);
		print_2d_data(dataOut, "OUTPUT DATA", NX-2, NY-2);
	} else
		printf("(Not displaying output data of size %dx%d)\n", NX, NY);

	int status = check((NX-2)*(NY-2), dataOut, expectedOut);

	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");

	return status;
}
