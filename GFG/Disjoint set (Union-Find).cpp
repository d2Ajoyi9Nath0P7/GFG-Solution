
/*Complete the functions below*/
int find(int A[],int X)
{
    if(A[X] == X)
    {
        return X;
    }
    return A[X] = find(A,A[X]);
}
void unionSet(int A[],int X,int Z)
{
	int par_a = find(A,X);
	int par_b = find(A,Z);
	
	A[par_a] = par_b;
}