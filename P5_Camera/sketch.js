let capture;
let imgCounter = 1;

function setup() {
  createCanvas(640, 480);
  capture = createCapture(VIDEO);
  capture.size(640, 480);
  capture.hide();
}

function draw() {
  background(255);
  image(capture, 0, 0, width, height);
}

function keyPressed() {
  if (key === 'c' || key === 'C') {
    saveImage();
  }
}

function saveImage() {
  let filename = `image_${nf(imgCounter, 3)}.jpg`;
  saveCanvas(filename);
  imgCounter++;
}
