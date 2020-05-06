import java.util.ArrayList;
import java.io.*;

public class CSVReader
{
	private String fileName;
	private ArrayList<ArrayList<String>> entries;
	public CSVReader(String filename)
	{
		this.fileName=new String(filename);
		entries=new ArrayList<ArrayList<String>>();
	}
	// We will split entries around commas and store them as arrays of Strings.
	public void importData()
	{
		FileReader fileReader;
		try
		{
			fileReader=new FileReader(fileName);
		}
		catch(FileNotFoundException fileNotFoundException)
		{
			System.out.println(fileNotFoundException);
			return;
		}
		BufferedReader bufferedReader=new BufferedReader(fileReader);
		String currentString;
		String[] splitString;
		ArrayList<String> currentList;
		try
		{
			while((currentString=bufferedReader.readLine())!=null)
			{
					currentList=new ArrayList<String>();
					splitString=currentString.split(",");
					for(String currentSubString : splitString)
						currentList.add(currentSubString);
					entries.add(currentList);
			}
		}
		catch(IOException ioException)
		{
			System.out.println(ioException);
		}
		try
		{
			bufferedReader.close();
		}
		catch(IOException ioException)
                {
                        System.out.println(ioException);
                }
		try
		{
			fileReader.close();
		}
		catch(IOException ioException)
                {
                        System.out.println(ioException);
                }
	}
	public int getNumberOfEntries()
	{
		return entries.size();
	}
	public ArrayList<String> getEntry(int i)
	{
		ArrayList<String> entry=new ArrayList<String>();
		entry.addAll(0, entries.get(i));
		for(String currentString : entry)
			currentString=new String(currentString);
		return entry;
	}
}
