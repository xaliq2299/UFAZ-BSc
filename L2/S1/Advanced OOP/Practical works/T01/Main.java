public class Main
{
        public static void main(String[] args)
        {
                int[] array=new int[args.length];
                for(int i=0; i<args.length; i++)
                        array[i]=Integer.parseInt(args[i]);
                System.out.println("min "+Exercises.min(array));
                System.out.println("find "+Exercises.find(array, 9));
                System.out.println("find "+Exercises.find(array, 13));
                System.out.println("sum "+Exercises.sumArray(array));
                Exercises.printArray(Exercises.reverseArray(array));
                System.out.println("Exercise 3:");
		int[] ex3=Exercises.exercise3();
                if(ex3.length==1)
			System.out.println(ex3[0]);
		else
			System.out.println(ex3[0]+" "+ex3[1]);
                Exercises.exercise4();
                Exercises.printMatrix(Exercises.product(Exercises.takeFloat(), Exercises.takeFloat()));
                int[][] arrayTwoDimensional=Exercises.takeInt();
                System.out.println("find "+Exercises.findTwoDimensional(arrayTwoDimensional, 9).toString());
                System.out.println("find "+Exercises.findTwoDimensional(arrayTwoDimensional, 13).toString());
        }

}
