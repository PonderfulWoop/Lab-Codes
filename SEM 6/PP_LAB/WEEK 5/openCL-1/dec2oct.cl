__kernel void dec2oct(__global int *A, __global int *C)
{
	int idx = get_global_id(0);
	int dec = A[idx];
	int oct = 0, r, p = 1;
	
	while(dec != 0){
		r = dec % 8;
		oct = oct + p*r;
		dec = dec/8;
		p = p*10;
	}
	
	C[idx] = oct;
}