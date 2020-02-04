__kernel void chngadj(__global int *A)
{
	int idx = get_global_id(0);
	int temp = A[2*idx];
	A[2*idx] = A[2*idx+1];
	A[2*idx+1] = temp;
}