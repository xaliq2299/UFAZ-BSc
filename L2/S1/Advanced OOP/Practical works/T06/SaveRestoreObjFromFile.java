import java.io.*;
import java.lang.ClassNotFoundException;

public class SaveRestoreObjFromFile
{
	public static void saveToFile(String outputFile, Object object)
	{
		FileOutputStream fileOutputStream;
		try
		{
			fileOutputStream=new FileOutputStream(outputFile);
		}
		catch(IOException ioException)
		{
			System.out.println(ioException);
			return;
		}
		ObjectOutputStream objectOutputStream;
		try
		{
			objectOutputStream=new ObjectOutputStream(fileOutputStream);
		}
		catch(IOException ioException)
		{
			System.out.println(ioException);
			return;
		}
		try
		{
			objectOutputStream.writeObject(object);
		}
		catch(IOException ioException)
		{
			System.out.println(ioException);
			return;
		}
	}
	public static Object restoreFromFile(String inputFile)
	{
		FileInputStream fileInputStream;
		try
		{
			fileInputStream=new FileInputStream(inputFile);
		}
		catch(FileNotFoundException fileNotFoundException)
		{
			System.out.println(fileNotFoundException);
			return null;
		}
		ObjectInputStream objectInputStream;
		try
		{
			objectInputStream=new ObjectInputStream(fileInputStream);
		}
		catch(IOException ioException)
		{
			System.out.println(ioException);
			return null;
		}
		try
		{
			return objectInputStream.readObject();
		}
		catch(IOException ioException)
		{
			System.out.println(ioException);
			return null;
		}
		catch(ClassNotFoundException classNotFoundException)
		{
			System.out.println(classNotFoundException);
			return null;
		}
	}
	public static void main(String[] args)
	{
		CSVReader csvReader=new CSVReader("file.csv");
		csvReader.importData();
		for(int i=0; i<csvReader.getNumberOfEntries(); i++)
		{
			saveToFile("file.ser", csvReader.getEntry(i));
			System.out.println(restoreFromFile("file.ser").toString());
		}
	}
}
