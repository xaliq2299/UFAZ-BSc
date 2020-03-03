public class array2dim {

	public static void main(String[] args){
		int[][] matrix1 = { {1,2,3},{4,5,6} };
		int[][] matrix2 = { {1,2,3},{4,5,6},{7,8,9} };
		int ind = searchValue(matrix1, 2);
		System.out.println(ind);
		System.out.println(equal(matrix1, matrix2));
	}

	
	public static int searchValue(int[][] array, int n){
		for(int row=0;row<array.length;row++){
			for(int j=0;j<array[row].length;j++){
				if (array[row][j] == n)
					return row+j;
			}		
		}
		return -1;
	}
	
	public static boolean equal(int array1[][], int array2[][]){
		if (array1.length == array2.length && array1[array1.length-1].length == array2[array2.length-1].length){
			for(int row=0;row<array1.length;row++){
				for(int j=0;j<array1[row].length;j++){
					if(array1[row][j] != array2[row][j])
						return false;
				}
			}
			return true;
		}
		else
			return false;
	}
}
