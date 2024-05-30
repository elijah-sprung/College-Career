#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

__host__ void vector_add(float* vector_a, float* vector_b, float* vector_c, int length);

__global__ void vecAddKernel(float* A, float* B, float* C, int length);

void load_vector(float** vector, int* length, char *file_name);
void output_vector(float** vector, int length, char *file_name);

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		fprintf(stderr, "Invalid number of arguments. \n");
		exit(1);
	}

	float * vector_a = NULL, * vector_b = NULL, * vector_c = NULL;
	int length;

	load_vector(&vector_a, &length, argv[1]);
	load_vector(&vector_b, &length, argv[2]);

	vector_c = (float*)malloc(length * sizeof(float));

	vector_add(vector_a, vector_b, vector_c, length);

	output_vector(&vector_c, length, argv[3]);

	return 0;
}

__host__ void vector_add(float* vector_a, float* vector_b, float* vector_c, int length)
{
	float *A_d, *B_d, * C_d;
	int size = length * sizeof(float);

	cudaMalloc((void**)&A_d, size);
	cudaMalloc((void**)&B_d, size);
	cudaMalloc((void**)&C_d, size);

	cudaMemcpy(A_d, vector_a, size, cudaMemcpyHostToDevice);
	cudaMemcpy(B_d, vector_b, size, cudaMemcpyHostToDevice);

	vecAddKernel<<<ceil(length / 256.0), 256 >>>(A_d, B_d, C_d, length);

	cudaMemcpy(vector_c, C_d, size, cudaMemcpyDeviceToHost);

	cudaFree(A_d);
	cudaFree(B_d);
	cudaFree(C_d);
}

__global__ void vecAddKernel(float* A, float* B, float* C, int length)
{
	int i = threadIdx.x + blockDim.x * blockIdx.x;
	if (i < length)
	{
		C[i] = A[i] + B[i];
	}
}

void load_vector(float** vector, int* length, char *file_name)
{
	FILE* input_file;
	float holder;

	if ((input_file = fopen(file_name, "r")) == NULL)
	{
		printf("Error: File could not be opened. \n");
		exit(2);
	}

	fscanf(input_file, "%f", &holder);
	// printf("%f", holder);

	*length = holder;

	*vector = (float*)malloc(*length * sizeof(float));

	for (int i = 0; i < *length; i++)
	{
		fscanf(input_file, "%f", &holder);
		(*vector)[i] = holder;
	}

	fclose(input_file);
}

void output_vector(float** vector, int length, char *file_name)
{
	FILE* output_file;

	if ((output_file = fopen(file_name, "w")) == NULL)
	{
		printf("Error: File could not be opened. \n");
		exit(2);
	}

	for (int i = 0; i < length; i++)
	{
		fprintf(output_file, "%f ", (*vector)[i]);
	}

	fclose(output_file);
}
