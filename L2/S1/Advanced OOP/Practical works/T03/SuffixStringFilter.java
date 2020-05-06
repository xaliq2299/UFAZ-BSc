public class SuffixStringFilter implements StringFilter
{
        private int n;
        public SuffixStringFilter(int n)
        {
                this.n=n;
        }
        public String filter(String s)
        {
                return s.substring(s.length()-n, s.length());
        }
}
