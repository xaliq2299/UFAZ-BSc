# Naval Battle Game

Naval Battle Game for Software Engineering Class, written in Java .

There are several versions (or modes) of the game to play:
-  local 1 player + computer   (console)
-  local 2 player on 1 screen  (console)
-  local 1 player + computer   (GUI)
-  local 2 player on 1 screen  (GUI)

## Getting Started

### Rules of a game
In our project you can play with computer or with another player in one screen. When you start playing the game you have to locate your ships. This is your main job. Afterwards your objective is to find out the hidden ships of enemy. All the players play in turns and the attempt is always to select some cell from enemy's board. Both of the players are provided with boards along with the two grids: the one which consists of your five ships and the other for collection of hit and miss markers.
The players play in turns and they take shots at each other. You can take a shot by pressing some cell on the 10 x 10 grid space of enemy. Like this game goes on until one of them sankes all the ships of the other. In that case that player becomes a winner.

### Installation and Execution
You can find all the project sources from the folder we provided. If you want to see and download it from github you can go to the github account of one of the authors below and see the repository under the name __NavalBattle__.
After downloading the folder of a project you can compile any version of a project you want through terminal via *javac* (Note that *javac* should be installed in your machine):
```
	javac *.java
```
Java executable .class files will be generated. Then you can run it using *java* command (Be sure that *java* is also installed into your machine):
```
	java BattleShip
```
in case of GUI version or
```
	java Main
```
in case of console versions.
If you have downloaded some version of project via release in github, again perform previous steps.
For sake of simplicity, it would be better to have some application like eclipse downloaded to your computer in order not to perform the previously shown steps.

## UML Diagrams

The following diagrams are presented for each version:

-  activity diagrams
-  usecase diagrams
-  sequence diagrams
-  state diagrams
-  class diagrams

## Versioning

For the versions available, see the [tags on this repository](https://github.com/Holmes-sh/NavalBattle/releases). 

## Doxygen

The very last version of our project (v3.0) is commented and documented according to doxygen. For this version one can find a file under the name **doxygenFile**. Be sure that *doxygen* is installed into your machine. After that you can type in terminal:
```
	doxygen doxygenFile
```
which will generate two new folders: _html_ and _latex_. These all hold useful information about project respectively the first in html format and the second in pdf format. For example, to show you we kept one of these files whose name is **index.html**. We recommend to find this file in html/ folder so that you can click on it and see what it outputs about our project.

## Authors
* **Xaliq Aghakarimov**  [xaliq2299](https://github.com/xaliq2299)
* **Irada Bunyatova**    [Holmes-sh](https://github.com/Holmes-sh)
