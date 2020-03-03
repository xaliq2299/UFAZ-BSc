var x=150, y=270;
function setup(){
        canvas = createCanvas(800,600);

}

function draw(){
    
    background(1,186,240); //1 186 240
    stroke(0,0,0);
    strokeWeight(1);
//    var x=5; let y=50; const l=50;
    ellipse(100,100,60,60);
    rect(70,130,60,100);
    rect(80,230,15,50);
    rect(105,230,15,50);
    rect(20,140,50,15);
    rect(20,140,50,15);
    rect(20+110,140,50,15)
    fill(100);
    ellipse(x,y,30,30);

 //   if(mouseIsPressed === true){
   //     textSize(36);
     //   text("hello"); }
   //if(mouseIsPressed === true)
            x++; y--;
//     if(x==50 && y == 300) 
  //              x--; y++;      
                   
    
/*        fill(237, 34, 93);
        noStroke();
        // conditionally display rectangle on mouse press
        if (mouseIsPressed === true) {
                fill(255);
                rect(x, y, size*0.75, size*0.15);
        }
}*/

}