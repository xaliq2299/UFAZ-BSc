public class array{

	public static void main(String[] args){
		int[] list = {1,2,3,4,5,8,9,10,11};
		//...
	}

	public static int min(int[] array){
		int small = array[0];
		for(int i=0;i<array.length;i++){
			if(array[i] < small)
				small = array[i];
		}
		return small;
	}

	public static int find(int[] array, int value){
		for(int i=0;i<array.length;i++){
			if(array[i] == value)
				return i;
		}
		return -1;
	}

	public static int sumArray(int[] array){
		int sum=0;
		for(int i=0;i<array.length;i++)
			sum+=array[i];
		return sum;
	}

	public static void printArray(int array[])
	{
		for(int i=0;i<array.length;i++)
			System.out.printf("%4d", array[i]);
		System.out.println();
	}

	public static int[] reverseArray(int array[]){
		int j=array.length-1;
		int[] new_array = new int[array.length];
		for(int i=0; i<array.length; i++){
	 		new_array[j] = array[i];
	 		j--;
	 	}
	 	return new_array;
	}
}
