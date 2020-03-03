public class integers{

	public static void main(String args[]){
		System.out.println(add(7,2));
	}
	
	public static int add(int a, int b){
		return a+b;
	}
  
	public static int mult(int a, int b){
 	 	return a*b;
	}
  
	public static int max(int a, int b){
 	 	return a>b ? a : b;
	}
  
	public static int min(int a, int b, int c){
  		if(a>b){
  			if(b<c)	return b;
  			else	return c;
  		}
  		if(a<b){
  			if(c>a)	return a;
  			else	return c;
  		}
  		return -1;
  	}	
  
	public static int gcd(int a, int b){
  		int ans = 0;
  		if(a>b){
  			for(int i=a;i>=1;i--){
  				if(a%i == 0 && b%i == 0){
  					ans = i;
  					break;
  				}
  			}
  		}
  		else if(b>a){
			for(int i=b;i>=1;i--){
  				if(a%i == 0 && b%i == 0){
  					ans = i;
  					break;
  				}
  			}
  		
  		}
  		else
			ans = a;
  
  		return ans;
	}
}
