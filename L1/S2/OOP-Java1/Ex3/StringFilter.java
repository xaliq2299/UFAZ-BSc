public interface StringFilter{
	public String filter(String s);
}

class UpperCaseStringFilter implements StringFilter{
	public String filter(String s){
		return s.toUpperCase();
	}
}

class LowerCaseStringFilter implements StringFilter{
	public String filter(String s){
		return s.toLowerCase();
	}
}

class PrefixStringFilter implements StringFilter{
	int n;
	public PrefixStringFilter(int n){
		this.n = n;
	}
	
	public String filter(String s){
		s = s.substring(0, s.length()-n);
		return s;
	}
}

class SuffixStringFilter implements StringFilter{
	private int n;
	public SuffixStringFilter(int n){
		this.n = n;
	}

	public String filter(String s){
		s = s.substring(s.length()-n);
		return s;
	}
}

class CompositeStringFilter implements StringFilter{
	StringFilter[] filters = new StringFilter[4];
	CompositeStringFilter(StringFilter[] filters){
		this.filters[0] = filters[0];
		this.filters[1] = filters[1];
		this.filters[2] = filters[2];
		this.filters[3] = filters[3];
	}
	
	public String filter(String s){
		for(int i=0;i<filters.length;i++)
			System.out.println( filters[i].filter(s) );
		return s;
	}
}

class Main{
	public static String[] filter(String[] strings, StringFilter filter){
		for(int i=0;i<strings.length;i++)
				strings[i] = filter.filter(strings[i]);	
		return strings;
	}
	
	public static void main(String args[]){
		StringFilter filters[] = new StringFilter[4];
		filters[0] = new UpperCaseStringFilter();
		filters[1] = new LowerCaseStringFilter();
		filters[2] = new PrefixStringFilter(3);
		filters[3] = new SuffixStringFilter(3);
		String name = "Khaliq";
		
		CompositeStringFilter my = new CompositeStringFilter(filters);
		my.filter(name);
	}
}
