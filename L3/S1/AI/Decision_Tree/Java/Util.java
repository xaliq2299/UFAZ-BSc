package decisionTree;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.ByteArrayInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.Reader;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Arrays;

public class Util {
  
  public static double log2(double x){
    if (x < 0.000001) return 0;
    return Math.log(x)/Math.log(2);
  }
  
  /**
   * It's better to use dedicated libraries such as OpenCSV.
   * In the meantime, just make sure there's no other lines than data lines
   * (no header, no blank lines and so on)
   */
  public static ArrayList<ArrayList<String>> importCSV(String filename, String separator) {
    ArrayList<ArrayList<String>> data = new ArrayList<ArrayList<String>>();
    String line = "";
    try {
      BufferedReader br = new BufferedReader(new FileReader(filename));
      while ((line = br.readLine()) != null){
        if (line.isEmpty()) continue; // skip line if line is empty
        ArrayList<String> dataAsString = new ArrayList<String>(Arrays.asList(line.split(separator)));
        data.add(dataAsString);
      }
      br.close();
    }catch(IOException e) {e.printStackTrace();}
    return data;
  }
  
  public static void exportDataToCSV(String filename, String data) {
    try {
      Writer out = new BufferedWriter(new FileWriter(filename));
      out.write(data);
      out.close();
    } catch (IOException e) { e.printStackTrace(); }
  }
  
  
  
  static public String importTextFromFile(String filename){
    String text = "";
    try {
      Reader r = new FileReader(filename);
      BufferedReader br = new BufferedReader(r);
      int b;
      while((b = br.read()) != -1){ // read a single byte
        text += (char) b;
      }
      br.close();
      r.close();
      return text;
    } catch (IOException e) {
      e.printStackTrace();
    }
    return null;
  }
  
  static public ArrayList<ArrayList<String>> readAndImportCSV(String filename){
    ArrayList<ArrayList<String>> entries = new ArrayList<ArrayList<String>>();
    try {
      Reader r = new FileReader(filename);
      BufferedReader br = new BufferedReader(r);
      String line;
      while((line = br.readLine()) != null){
        System.out.println(line);
        ArrayList<String> values = 
            new ArrayList<String>(Arrays.asList(line.split(",")));
       entries.add(values);
      }
      br.close();
      r.close();
      return entries;
    } catch (IOException e) {
      e.printStackTrace();
    }
    return null;
  }
  
  static void exportTextToFile(String filename, String text) {
    try {
      InputStream in   = new BufferedInputStream(new ByteArrayInputStream(text.getBytes()));
      OutputStream out = new BufferedOutputStream(new FileOutputStream(filename));
      int b;
      while((b = in.read()) != -1){
        out.write(b);
      }
      in.close();
      out.close();
    } catch (IOException e) { e.printStackTrace(); }
  }
 
}
