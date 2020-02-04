#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>

#define MAX_SOURCE_SIZE (0x100000)

int main(void){
	int i;

	int LIST_SIZE;
	printf("Enter even no. of elems: \n");
	scanf("%d", &LIST_SIZE);
	int *A = (int*)malloc(sizeof(int)*LIST_SIZE);
	printf("Enter elems: \n");
	for(i = 0; i < LIST_SIZE; i++)
		scanf("%d", &A[i]);

	FILE *fp;

	char *source_str;
	size_t source_size;

	fp = fopen("chngadj.cl", "r");
	if(!fp){
		fprintf(stderr, "Failed to load kernel. \n");
		getchar();
		exit(1);
	}
	source_str = (char*)malloc(MAX_SOURCE_SIZE);
	source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);

	fclose(fp);

	cl_platform_id p_id = NULL;
	cl_device_id dev_id = NULL;
	cl_uint ret_num_dev;
	cl_uint ret_num_plat;

	cl_int ret = clGetPlatformIDs(1, &p_id, &ret_num_plat);
	ret = clGetDeviceIDs(p_id, CL_DEVICE_TYPE_GPU, 1, &dev_id, &ret_num_dev);

	//Create an OpenCL context
	cl_context context = clCreateContext(NULL, 1, &dev_id, NULL, NULL, &ret);

	//Create a Command Queue
	cl_command_queue cmdq = clCreateCommandQueue(context, dev_id, NULL, &ret);

	//Create memory buffers:
	cl_mem abuf = clCreateBuffer(context, CL_MEM_READ_ONLY, LIST_SIZE *sizeof(int), NULL, &ret);

	//Copy A to its buffer:
	ret = clEnqueueWriteBuffer(cmdq, abuf, CL_TRUE, 0, LIST_SIZE*sizeof(int), A, 0, NULL, NULL);


	//Create program from kernel source
	cl_program prog = clCreateProgramWithSource(context, 1, (const char**)&source_str, (const size_t*)&source_size, &ret);

	//Building the program
	ret = clBuildProgram(prog, 1, &dev_id, NULL, NULL, NULL);

	//Create the OpenCL kernel object
	cl_kernel kernel = clCreateKernel(prog, "chngadj", &ret);

	//Set the arguments:
	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&abuf);

	//Execute the OpenCL kernel on the array
	size_t global_item_size = LIST_SIZE/2;
	size_t local_item_size = 1;

	//Execute the kernel on the device
	cl_event event;
	ret = clEnqueueNDRangeKernel(cmdq, kernel, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL);

	ret = clFinish(cmdq);

	ret = clEnqueueReadBuffer(cmdq, abuf, CL_TRUE, 0, LIST_SIZE*sizeof(int), A, 0, NULL, NULL);

	for(i = 0; i < LIST_SIZE; i++)
		printf("%d\n", A[i]);

	//Clean Up

	ret = clFlush(cmdq);
	ret = clReleaseKernel(kernel);
	ret = clReleaseProgram(prog);
	ret = clReleaseMemObject(abuf);
	ret = clReleaseCommandQueue(cmdq);
	ret = clReleaseContext(context);

	free(A);
	getchar();
	return 0;
}
