public class matrixMultiply{
	
	public static void main(String args[]){
		float[][] matA={ {5,9}, {2,3}, {0, 8} };
		float[][] matB={ {1,3}, {7,5} };
		
		System.out.println("Matrix A=");
		printMatrix(matA);
		System.out.println("Matrix B=");
		printMatrix(matB);
		float[][] matC=product(matA, matB);		
		
		if(matC == null) System.out.println("These matrices can't be multiplied\n");	
		else {
			System.out.println("A*B=");
			printMatrix(matC);
		}
	}

	public static void printMatrix(float[][] array){
		for(int row=0;row<array.length;row++){
			for(int j=0;j<array[row].length;j++)
				System.out.printf("%7.0f", array[row][j]);
			System.out.println();
		}
	}
	
	public static float[][] product(float[][] matA, float[][] matB){
		int a, b, c;
		float[][] matC= new float[matA.length][matB[0].length];
		if( matA[0].length != matB.length) return null;
		else{
			for(a=0;a<matA.length;a++)
			{
				for(b=0;b<matB[0].length;b++)
				{
					int sum=0;
					for(c=0;c<matB.length;c++)
						sum+=( matA[a][c]*matB[c][b] );
					matC[a][b]=sum;	
				}	
			}
		} 		
		return matC;
	}
}
