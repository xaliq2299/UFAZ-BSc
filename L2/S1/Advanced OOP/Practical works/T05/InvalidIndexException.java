public class InvalidIndexException extends Exception
{
	private int index;
	public InvalidIndexException(int index)
	{
		this.index=index;
	}
	public String getMessage()
	{
		return "Index: "+index+" is invalid.";
	}
}
