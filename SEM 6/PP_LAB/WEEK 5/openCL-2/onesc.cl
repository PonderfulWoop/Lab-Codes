__kernel void onesc(__global int *A, __global int *C)
{
	int idx = get_global_id(0);
	
	int dec = A[idx];
	int one_c = 0;
	int num[20];
	int r;
	int i = 0;
	
	while(dec != 0){
		r = dec % 10;
		if(r == 0)
			num[i++] = 1;
		else
			num[i++] = 0;
		
		dec = dec/10;
	}
	
	while(i>=1){
		one_c = one_c*10 + num[i-1];
		i = i - 1;
	}	
	
	C[idx] = one_c;
}