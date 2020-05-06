public class CompositeStringFilter implements StringFilter
{
        StringFilter[] filters;
        public CompositeStringFilter(StringFilter[] filters)
        {
                this.filters=new StringFilter[filters.length];
                for(int i=0; i<filters.length; i++)
                        this.filters[i]=filters[i];
        }
        public String filter(String s)
        {
                String string=new String(s);
                for(int i=0; i<filters.length; i++)
                        string=filters[i].filter(s);
                return string;
        }
}
