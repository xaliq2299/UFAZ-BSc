package decisionTree;

import util.Util;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

/**
 * Part II : group data into partitions (3 partitions w/ 50 instances each)
 * @author AJG
 *
 */

public class DecisionTree {
  private ArrayList<ArrayList<Float>> allData;
  private int sortingAttribute = 0;
  private double entropy = 0;
  
  private int totalVersicolor = 0;
  private int totalVirginica  = 0;
  private int totalSetosa     = 0;
  
  private ArrayList<Group> groups;
  
  public DecisionTree(String filename, String separator, int nbAttributes, int nbGroups){
    this.allData = new ArrayList<ArrayList<Float>>();
    this.groups  = new ArrayList<Group>(nbGroups);
    for (int i = 0; i < nbGroups; i++) this.groups.add(new Group());
    
    // Import data
    ArrayList<ArrayList<String>> data = Util.importCSV(filename, separator);
    for (ArrayList<String> entry : data) {
      ArrayList<Float> attributes = new ArrayList<Float>();
      int i;
      
      // Get first four attributes (SL SW PL PW)
      for (i = 0; i < nbAttributes-1; i++)
        attributes.add(Float.parseFloat(entry.get(i)));
      
      // Get label
      if (entry.get(i).equals("Iris-setosa")) {
        attributes.add(0.f); // setosa
        totalSetosa ++;
      }
      else if (entry.get(i).equals("Iris-versicolor")) {
        attributes.add(1.f); // versicolor
        totalVersicolor++;
      }
      else if (entry.get(i).equals("Iris-virginica")) {
        attributes.add(2.f); // virginica
        totalVirginica++;
      }
      else throw new RuntimeException("There was an error retrieving the label "+ entry.get(i));
      
      // Add instance
      this.allData.add(attributes);
    }
  }
  
  public void setSortingAttribute(int sortingAttributes) {
    this.sortingAttribute = sortingAttributes;
  }
  
  /* ==================== QUESTION 3.5a ====================
   * Compute the entropy for the whole data set
   */
  private void setEntropy(){
    double entropy = 0.0;
    /*
     * entropy = sum( (occSpecies/total)log2(occSpecies/total) )
     */
    this.entropy = -entropy;
  }
  
  /* ==================== QUESTION 3.2 ====================
   * Implement the comparator to sort the instances
   * Instances are sorted in ascending order, using the attribute we want to
   * compute the discriminative power of (set in the Test class)
   *    NB : the Comparator is used in the method "sortAllData" right below
   */
  private static Comparator<ArrayList<Float>> instanceComparator(int sortingAttribute){
    Comparator<ArrayList<Float>> comparator = new Comparator<ArrayList<Float>>(){
      @Override
      public int compare(ArrayList<Float> i1, ArrayList<Float> i2){
        return 0; /* TODO */
        /* You must compare the attribute "sortingAttribute" of instance i1 with
         * the attribute "sortingAttribute of instance i2
         * https://docs.oracle.com/javase/7/docs/api/java/lang/Float.html#compareTo(java.lang.Float)
         */
      }
    };
    return comparator;
  }
  
  public void sortAllData(){
    Collections.sort(this.allData, instanceComparator(this.sortingAttribute));
  }
  
  /* ==================== QUESTION 3.3 ====================
   * Partition the data into 3 groups (50 instances in each group)
   *    
   *    As you see, the method setGroups is already implemented !
   * 
   *  ===> you must write the method speciesOccurrence() in the class Group <===
   */ 
  public void setGroups(){
    int start = 0;
    int nbInstances = allData.size()/groups.size(); //50;
    for (Group g: groups){
      g.initGroup(this.allData.subList(start, start+nbInstances));
      g.speciesOccurrence();
      start += nbInstances;
    }
    this.setEntropy();
  }
  
  /* ==================== QUESTION 3.6 ====================
   * Compute the discriminative power of the current attribute (set in the Test class)
   */
  public double disc() {
    double disc = 0.0;
    for(Group g: groups){
      /*
       * disc = sum ((#g/#Iris)*H(g))
       */
    }
    disc = this.entropy - disc;
    return disc;
  }
  
  
  
  
  public double getEntropy(){ return this.entropy; }
  
  public void printAllData() {
    for (ArrayList<Float> instance: this.allData){
      System.out.println(instance);
    }
  }

  public void printGroups(){
    System.out.println("Data entropy: "+this.entropy + "  Disc=" + this.disc());
    for (Group g: this.groups)
      g.printGroup();
  }
}
