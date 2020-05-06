public class Exercise1
{
	public static String[] filter(String[] strings, StringFilter filter)
	{
		String[] newStrings=new String[strings.length];
		for(int i=0; i<strings.length; i++)
			newStrings[i]=filter.filter(strings[i]);
		return newStrings;
	}
	public static void main(String[] args)
	{
		StringFilter composite1[]={new LowerCaseStringFilter(), new UpperCaseStringFilter(), new PrefixStringFilter(5), new SuffixStringFilter(3)};
		StringFilter composite2[]={new UpperCaseStringFilter(), new LowerCaseStringFilter(), new SuffixStringFilter(5), new PrefixStringFilter(3)};
		String[] newStrings1=filter(args, new CompositeStringFilter(composite1));
		String[] newStrings2=filter(args, new CompositeStringFilter(composite2));
		for(int i=0; i<args.length; i++)
			System.out.println(newStrings1[i]+" "+newStrings2[i]);
	}
}
