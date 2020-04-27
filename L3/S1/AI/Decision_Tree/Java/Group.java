package decisionTree;

import util.Util;
import java.util.ArrayList;
import java.util.List;

public class Group {
  private ArrayList<ArrayList<Float>> instances;
  
  // For the occurrences of each species in the group
  private int versicolor;
  private int virginica;
  private int setosa;
  private double entropy;
  
  public Group(){
    this.instances  = new ArrayList<ArrayList<Float>>();
    this.versicolor = 0;
    this.virginica  = 0;
    this.setosa     = 0;
    this.entropy = 0.f;
  }
  
  public int getGroupSize(){
    return instances.size();
  }
  
  public void initGroup(List<ArrayList<Float>> list){
    this.instances = new ArrayList<ArrayList<Float>>(list);
  }
  
  /* ==================== QUESTION 3.4 ====================
   * Compute the occurences of each species in the group
   */
  public void speciesOccurrence(){
    /*
     * for each instance i in the group do
     *    if      attribute 4 of i is 1 then setosa ++
     *    else if attribute 4 of i is 2 then versicolor++
     *    else if attribute 4 of i is 3 the virginica++
     * end
     */
    this.setEntropy(); // when the partition is built, we can directly set the entropy of the partition
  }
  
  /* ==================== QUESTION 3.5b ====================
   * Compute the entropy of the group using the number of instances
   * of each species in the group
   */
  private void setEntropy(){
    int groupSize = this.instances.size();
    double entropy = 0.f;
    /*
     * entropy = proba_occu_versicolor * log2(proba_occu_versicolor) +
     *           proba_occu_virginica  * log2(proba_occu_virginica) +
     *           proba_occu_setosa     * log2(proba_occu_setosa)
     */
    this.entropy = -entropy;
  }
  
  public double getEntropy(){
    return this.entropy;
  }
  
  public void printGroup(){
    System.out.println("["+this.instances.size()+ "]  Setosa: "+ this.setosa + 
        "   Versicolor: " + this.versicolor + "   Virginica: " + this.virginica +
        "   Entropy=" + this.entropy);
  }
}
