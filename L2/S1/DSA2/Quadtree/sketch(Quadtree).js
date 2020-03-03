/*
function setup(){
	canvas = createCanvas(400,400);

	let boundary = new Rectangle(200,200,200,200);
	background(0);
	boundary.show();
}
*/

/*
* SECOND Method that I am testing
*/
/*
var myCanvas;
var count = 0;

function setup(){
	myCanvas = createCanvas(400,400);
	//canvas.position(300,50);
	myCanvas.class("lemon");
	background(200);
}

function draw(){
	let boundary = new Rectangle(100,200,50,50);
	var size = 5+count ;
	boundary.show();

	fill(255,0,0,255);
	stroke(0);
	strokeWeight(1);
	ellipse(width/2, height/2, 50, 100);
  ellipse(width/4, height/2, 50, 50);

	ellipse(width*3/4, height*3/4, 25,25);
	count = count+5;

	//console.log(frameRate());
}
*/

/*
*  FRAME COUNTER TEST
*/

/*
function setup() {
        createCanvas(800, 300);
        textAlign(CENTER, CENTER);
				//frameRate(6);
}

function draw() {
        background(220);
        fill(237, 34, 93);
        textSize(36);
//        text("frameCount: " + frameCount, width/2, height/2);
}

/*
*   FRAME ANIMATION
*/

/*
function setup() {
        createCanvas(800, 300);
        rectMode(CENTER);
				//frameRate(3);
}
function draw() {
        background(1, 186, 240);
        // declaration of variables
        var x = width / 2;
        var y = height / 2;
        // increment the size with the current frameCount value
        var size = 200 + frameCount;
        // circle
        fill(237, 34, 93);
        noStroke();
        ellipse(x, y, size, size);
        // rectangle
        fill(255);
        rect(x, y, size*0.75, size*0.15);
}
*/


/*
*   CONDITION AND ANIMATION
*/
/*
var size;
function setup() {
        createCanvas(800, 300);
        rectMode(CENTER);
				size = 200;
}
function draw() {
background(1, 186, 240);
// declaration of variables
var x = width / 2;
var y = height / 2;
var size = 200;
if (frameCount < 30) {
				size = size + frameCount;
} else {
				size = size + 30;
}
// ellipse
fill(237, 34, 93);
noStroke();
ellipse(x, y, size, size);
// rectangle
fill(255);
rect(x, y, size*0.75, size*0.15);
}
*/

/*
*			MOUSE FUNCTIONS AND VARIABLES
*/
/*
function setup() {
        createCanvas(800, 300);
        rectMode(CENTER);
}
function draw() {
        background(1, 186, 240);
        // declaration of variables
        var x = width / 2;
				var y = height / 2;
        var size = 200; // control the size of the shapes
        // circle
        fill(237, 34, 93);
        noStroke();
        ellipse(x, y, size, size);
        // conditionally display rectangle on mouse press
        if (mouseIsPressed === true) {
                fill(255);
                rect(x, y, size*0.75, size*0.15);
        }
}
*/

/*
var toggle = true;
function setup() {
        createCanvas(800, 300);
        rectMode(CENTER);
}

function draw() {
        // change the toggle value based on mouse press.
        if (mouseIsPressed === true) {
                toggle = !toggle;
        }
        // display a different bg color based on the toggle value
        if (toggle === true) {
                background(1, 186, 240);
        } else {
                background(250, 150, 50);
        }
        // declaration of variables
        var x = width / 2;
        var y = height / 2;
        var size = 200;
        // circle
        fill(237, 34, 93);
        noStroke();
        ellipse(x, y, size, size);
        // rectangle
        fill(255);
        rect(x, y, size * 0.75, size * 0.15);
}

*/

/*
*			TO MAKE SOME DRAWING
*/
/*
function setup() {
        createCanvas(800, 300);
				background(1, 75, 100);//TO DRAW ON THE SCREEN
}
function draw() {
        //background(1, 75, 100);//EACH frame background
        // declaration of variables
				if (mouseIsPressed === true) {
        var x=mouseX; //var x = width / 2;
        var y=mouseY; //var y = height / 2;
			}
        var size = 25;
				// circle
        fill(237, 34, 93, 100);
        noStroke();
        ellipse(x, y, size, size);
}
*/

/*
*				RANDOM EXAMPLE
*/
/*
function setup() {
        createCanvas(800, 300);
        textAlign(CENTER, CENTER);
        fill(237, 34, 93);
        frameRate(1);
}
function draw() {
        var random_0 = random();
        var random_1 = random(10);
        var random_2 = random(100, 1000);
        var offset = 40;
        textSize(24);
        background(255);
        text(random_0, width/2, height/2-offset);
        text(random_1, width/2, height/2-0);
        text(random_2, width/2, height/2+offset);
}
*/

/*
*			Using noise function
*/
/*
function setup() {
        createCanvas(800, 300);
}
function draw() {
        background(1, 75, 100);
        // circle properties
        fill(237, 34, 93);
        noStroke();
        var diameter = 50;
        for (var i=0; i<width/diameter; i=i+1) {
                for (var j=0; j<height/diameter; j=j+1) {
                        ellipse(
                                diameter/2 + i * diameter,
                                diameter/2 + j * diameter,
																diameter * noise(frameCount/100),
																//uing then noise FUNCTION
																diameter * noise(frameCount/100)
															);
												}
									}
						}
*/
