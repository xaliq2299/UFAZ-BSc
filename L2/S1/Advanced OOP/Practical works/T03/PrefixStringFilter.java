public class PrefixStringFilter implements StringFilter
{
        private int n;
        public PrefixStringFilter(int n)
        {
                this.n=n;
        }
        public String filter(String s)
        {
        	return s.substring(0, n);
        }
}
