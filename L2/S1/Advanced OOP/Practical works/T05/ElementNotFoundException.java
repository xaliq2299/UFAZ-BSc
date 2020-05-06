public class ElementNotFoundException extends Exception
{
	private String object;
	public ElementNotFoundException(Object object)
	{
		this.object=object.toString();
	}
	public String getMessage()
	{
		return "Element "+object+" has not been found.";
	}
}
