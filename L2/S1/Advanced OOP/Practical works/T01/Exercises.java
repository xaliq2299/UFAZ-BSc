import java.util.Scanner;

public class Exercises
{
        // Exercise 1
        public static int add(int a, int b)
        {
                return a+b;
        }
        public static int mult(int a, int b)
        {
                return a*b;
        }
        public static int max(int a, int b)
        {
                return a>b?a:b;
        }
        public static int min(int a, int b, int c)
        {
                return b<c?(a<b?a:b):(a<c?a:c);
        }
        public static int gcd(int a, int b)
        {
                if(a==0) return b;
                if(b==0) return a;
                while(true)
                {
                        if(a<b)
                        {
                                if(b%a==0)
                                        return a;
                                else
                                        b%=a;
                        }
			else
                        {
                                if(a%b==0)
                                        return b;
                                else
                                        a%=b;
                        }
                }
        }
        // Exercise 2
        public static int min(int[] array)
        {
                int iMinimum=0;
                for(int i=1; i<array.length; i++)
                        if(array[i]<array[iMinimum])
                                iMinimum=i;
                return array[iMinimum];
        }
        public static int find(int[] array, int value)
        {
                for(int i=0; i<array.length; i++)
                        if(array[i]==value)
                                return i;
                return -1;
        }
        public static int sumArray(int[] array)
        {
                int sum=0;
                for(int i=0; i<array.length; i++)
                        sum+=array[i];
                return sum;
        }
        public static void printArray(int[] array)
        {
                if(array.length>0)
                        System.out.print(array[0]);
                for(int i=1; i<array.length; i++)
                        System.out.print(" "+array[i]);
                System.out.println("");
        }
        public static int[] reverseArray(int[] array)
        {
                int[] reverse=new int[array.length];
                for(int i=0; i<array.length; i++)
                        reverse[i]=array[array.length-1-i];
                return reverse;
        }
        // Exercise 3
        public static int[] exercise3()
        {
		int[] answer;
                Scanner input=new Scanner(System.in);
                int a=input.nextInt(), b=input.nextInt();
                if(a%2==0 && b%2==0)
                {
			answer=new int[1];
			answer[0]=add(a, b);
		}
                else if(a%2==1 && b%2==1)
                {
			answer=new int[1];
			answer[0]=mult(a, b);
		}
                else
                {
			answer=new int[2];
			answer[0]=mult(a, a);
			answer[1]=mult(b, b);
		}
		return answer;
        }
        // Exercise 4
        public static void exercise4()
        {
                Scanner input=new Scanner(System.in);
                System.out.println("Give 2 integers successively :");
                int a=input.nextInt(), b=input.nextInt();
                System.out.println("Choose an operation :");
                System.out.println("1. +");
                System.out.println("2. -");
                System.out.println("3. *");
                System.out.println("4. /");
                System.out.println("5. %");
                System.out.print("Operation : ");
                int operation=input.nextInt();
                System.out.print("Output : ");
                switch(operation)
                {
                        case 1:
                        {
                                System.out.print(a+" + "+b+" = ");
                                System.out.println(a+b);
                                break;
                        }
                        case 2:
                        {
                                System.out.print(a+" - "+b+" = ");
                                System.out.println(a-b);
                                break;
                        }
                        case 3:
                        {
                                System.out.print(a+" * "+b+" = ");
                                System.out.println(a*b);
                                break;
                        }
                        case 4:
                        {
                                System.out.print(a+" / "+b+" = ");
                                System.out.println(a/b);
                                break;
                        }
                        case 5:
                        {
                                System.out.print(a+" % "+b+" = ");
                                System.out.println(a%b);
                                break;
                        }
                }
        }
        // Exercise 5
        public static float[][] takeFloat()
        {
                Scanner input=new Scanner(System.in);
                System.out.println("Rows and columns:");
                int m=input.nextInt(), n=input.nextInt();
                float[][] matrix=new float[m][n];
                for(int i=0; i<m; i++)
                        for(int j=0; j<n; j++)
                                matrix[i][j]=input.nextFloat();
                return matrix;
        }
        public static float[][] product(float[][] matA, float[][] matB)
        {
                if(matA.length==0 || matB.length==0)
                        return null;
                if(matA[0].length!=matB.length)
                        return null;
                float[][] matC=new float[matA.length][matB[0].length];
                for(int i=0; i<matC.length; i++)
                        for(int j=0; j<matC[0].length; j++)
                                for(int k=0; k<matA[0].length; k++)
                                        matC[i][j]+=(matA[i][k]*matB[k][j]);
                return matC;
        }
        public static void printMatrix(float[][] matrix)
        {
                if(matrix==null)
                        return;
                for(int i=0; i<matrix.length; i++)
                {
                        if(matrix[i].length>0)
                                System.out.print(matrix[i][0]);
                        for(int j=1; j<matrix[i].length; j++)
                                System.out.print(" "+matrix[i][j]);
                        System.out.println();
                }
        }
        // Exercise 6
        public static int[][] takeInt()
        {
                Scanner input=new Scanner(System.in);
                System.out.println("Rows and columns:");
                int m=input.nextInt(), n=input.nextInt();
                int[][] matrix=new int[m][n];
                for(int i=0; i<m; i++)
                        for(int j=0; j<n; j++)
                                matrix[i][j]=input.nextInt();
                return matrix;
        }
        public static Index findTwoDimensional(int[][] array, int value)
        {
                for(int i=0; i<array.length; i++)
                        for(int j=0; j<array[i].length; j++)
                                if(array[i][j]==value)
                                        return new Index(i, j);
                return new Index(-1, -1);
        }
}
