package decisionTree;

/*
 * Classe de test pour la classification avec arbre de décision
 * 
 * ATTENTION ! Comme vous le verrez ce test rudimentaire ne porte que sur 1 passe
 *             de l'algorithme et affiche simplement les attributs et leur pouvoir discriminant
 *             (charge à vous de faire le reste :-)
 */

public class Test {

  public static void main(String[] args) {
    
    DecisionTree dt = null;
    
    for (int i = 0; i < 4 /*nb of attributes*/; i++){
      System.out.println("Attributes: 0/SL 1/SW 2/PL 3/PW\n***Attribute #"+i);
      dt = new DecisionTree("iris_text.data",
          ",", /* separator */
          5 /* nb of columns in the data set */,
          3 /* nb of groups (short, average, long) */);
      dt.setSortingAttribute(i); // i is the attribute we want to determine the discriminative power of
      dt.sortAllData();
      dt.setGroups();
      dt.printGroups();
    }
  }

}

/* Example of expected output with this test :
 * (the output is quite verbose)
 * 
Attributes: 0/SL 1/SW 2/PL 3/PW
***Attribute #0
Data entropy: 1.5849625049610565  Disc=0.6825026066620299
[50]  Setosa: 44   Versicolor: 5   Virginica: 1   Entropy=0.6073635628072781
[50]  Setosa: 6   Versicolor: 32   Virginica: 12   Entropy=1.2732696933020597
[50]  Setosa: 0   Versicolor: 13   Virginica: 37   Entropy=0.826746358101542
Attributes: 0/SL 1/SW 2/PL 3/PW
***Attribute #1
Data entropy: 1.5849625049610565  Disc=0.2502134599619441
[50]  Setosa: 2   Versicolor: 29   Virginica: 19   Entropy=1.1720147658149722
[50]  Setosa: 16   Versicolor: 16   Virginica: 18   Entropy=1.582683186824695
[50]  Setosa: 32   Versicolor: 5   Virginica: 13   Entropy=1.2495490630218091
Attributes: 0/SL 1/SW 2/PL 3/PW
***Attribute #2
Data entropy: 1.5849625049610565  Disc=1.3666658858735081
[50]  Setosa: 50   Versicolor: 0   Virginica: 0   Entropy=-0.0
[50]  Setosa: 0   Versicolor: 47   Virginica: 3   Entropy=0.32744491887270344
[50]  Setosa: 0   Versicolor: 3   Virginica: 47   Entropy=0.32744491887270344
Attributes: 0/SL 1/SW 2/PL 3/PW
***Attribute #3
Data entropy: 1.5849625049610565  Disc=1.3666658858735081
[50]  Setosa: 50   Versicolor: 0   Virginica: 0   Entropy=-0.0
[50]  Setosa: 0   Versicolor: 47   Virginica: 3   Entropy=0.32744491887270344
[50]  Setosa: 0   Versicolor: 3   Virginica: 47   Entropy=0.32744491887270344

*/