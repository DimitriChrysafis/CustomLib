float angleTorus = 0;
float angleSphere = 0;
float angleBox = 0;
float angleCone = 0;
float anglePyramid = 0;
float angleCylinder = 0;
float angleDodecahedron = 0;
float angleIcosahedron = 0;

void setup() {
  size(1200, 800, P3D);
  noFill();
}

void draw() {
  background(0);
  
  translate(width / 2, height / 2, -800);

  directionalLight(255, 255, 255, -1, -1, -1);
  ambientLight(100, 100, 100);

  // Torus
  pushMatrix();
  rotateX(angleTorus);
  rotateY(angleTorus * 0.5);
  stroke(255, 0, 0);
  strokeWeight(1);
  torusWireframe(150, 50);
  popMatrix();

  // Sphere
  pushMatrix();
  rotateX(angleSphere * 0.5);
  rotateY(angleSphere);
  translate(400, 0, 0);
  stroke(0, 255, 0);
  strokeWeight(1);
  sphereWireframe(100);
  popMatrix();

  // Box
  pushMatrix();
  rotateX(angleBox);
  rotateY(angleBox * 0.5);
  translate(-400, 0, 0);
  stroke(0, 0, 255);
  strokeWeight(1);
  boxWireframe(100);
  popMatrix();

  // Cone
  pushMatrix();
  rotateX(angleCone);
  rotateY(angleCone * 0.5);
  translate(0, 400, 0);
  stroke(255, 255, 0);
  strokeWeight(1);
  coneWireframe(80, 150);
  popMatrix();

  // Pyramid
  pushMatrix();
  rotateX(anglePyramid);
  rotateY(anglePyramid * 0.5);
  translate(0, -400, 0);
  stroke(255, 0, 255);
  strokeWeight(1);
  pyramidWireframe(80, 100);
  popMatrix();

  // Cylinder
  pushMatrix();
  rotateX(angleCylinder);
  rotateY(angleCylinder * 0.5);
  translate(600, 0, 0);
  stroke(0, 255, 255);
  strokeWeight(1);
  cylinderWireframe(50, 150);
  popMatrix();

  // Dodecahedron
  pushMatrix();
  rotateX(angleDodecahedron);
  rotateY(angleDodecahedron * 0.5);
  translate(-600, 0, 0);
  stroke(255, 165, 0);
  strokeWeight(1);
  dodecahedronWireframe(100);
  popMatrix();

  // Icosahedron
  pushMatrix();
  rotateX(angleIcosahedron);
  rotateY(angleIcosahedron * 0.5);
  translate(0, 0, 600);
  stroke(128, 0, 128);
  strokeWeight(1);
  icosahedronWireframe(100);
  popMatrix();

  angleTorus += 0.01;
  angleSphere += 0.015;
  angleBox += 0.02;
  angleCone += 0.025;
  anglePyramid += 0.03;
  angleCylinder += 0.035;
  angleDodecahedron += 0.04;
  angleIcosahedron += 0.045;
}

void torusWireframe(float r, float t) {
  int numTheta = 36;
  int numPhi = 36;
  float thetaSpacing = TWO_PI / numTheta;
  float phiSpacing = TWO_PI / numPhi;

  for (int i = 0; i < numTheta; i++) {
    float theta0 = i * thetaSpacing;
    float theta1 = (i + 1) * thetaSpacing;

    for (int j = 0; j < numPhi; j++) {
      float phi0 = j * phiSpacing;
      float phi1 = (j + 1) * phiSpacing;

      PVector v00 = torusVertex(r, t, theta0, phi0);
      PVector v01 = torusVertex(r, t, theta0, phi1);
      PVector v10 = torusVertex(r, t, theta1, phi0);
      PVector v11 = torusVertex(r, t, theta1, phi1);

      line(v00.x, v00.y, v00.z, v01.x, v01.y, v01.z);
      line(v01.x, v01.y, v01.z, v11.x, v11.y, v11.z);
      line(v11.x, v11.y, v11.z, v10.x, v10.y, v10.z);
      line(v10.x, v10.y, v10.z, v00.x, v00.y, v00.z);
    }
  }
}

void sphereWireframe(float r) {
  int numLat = 18;
  int numLon = 36;
  
  for (int i = 0; i < numLat; i++) {
    float lat0 = PI * (-0.5 + (float) (i) / numLat);
    float lat1 = PI * (-0.5 + (float) (i + 1) / numLat);

    for (int j = 0; j < numLon; j++) {
      float lon0 = TWO_PI * (float) (j) / numLon;
      float lon1 = TWO_PI * (float) (j + 1) / numLon;

      PVector v00 = sphereVertex(r, lat0, lon0);
      PVector v01 = sphereVertex(r, lat0, lon1);
      PVector v10 = sphereVertex(r, lat1, lon0);
      PVector v11 = sphereVertex(r, lat1, lon1);

      line(v00.x, v00.y, v00.z, v01.x, v01.y, v01.z);
      line(v01.x, v01.y, v01.z, v11.x, v11.y, v11.z);
      line(v11.x, v11.y, v11.z, v10.x, v10.y, v10.z);
      line(v10.x, v10.y, v10.z, v00.x, v00.y, v00.z);
    }
  }
}

void boxWireframe(float s) {
  float half = s / 2;
  beginShape(LINES);
  vertex(-half, -half, -half);
  vertex(half, -half, -half);
  
  vertex(half, -half, -half);
  vertex(half, half, -half);
  
  vertex(half, half, -half);
  vertex(-half, half, -half);
  
  vertex(-half, half, -half);
  vertex(-half, -half, -half);
  
  vertex(-half, -half, half);
  vertex(half, -half, half);
  
  vertex(half, -half, half);
  vertex(half, half, half);
  
  vertex(half, half, half);
  vertex(-half, half, half);
  
  vertex(-half, half, half);
  vertex(-half, -half, half);
  
  vertex(-half, -half, -half);
  vertex(-half, -half, half);
  
  vertex(half, -half, -half);
  vertex(half, -half, half);
  
  vertex(half, half, -half);
  vertex(half, half, half);
  
  vertex(-half, half, -half);
  vertex(-half, half, half);
  endShape();
}

void coneWireframe(float r, float h) {
  int num = 36;
  float angleStep = TWO_PI / num;
  
  for (int i = 0; i < num; i++) {
    float angle0 = i * angleStep;
    float angle1 = (i + 1) * angleStep;
    
    float x0 = r * cos(angle0);
    float y0 = r * sin(angle0);
    float x1 = r * cos(angle1);
    float y1 = r * sin(angle1);

    line(x0, y0, 0, x1, y1, 0);
    line(0, 0, 0, x0, y0, h);
    line(0, 0, 0, x1, y1, h);
  }
}

void pyramidWireframe(float s, float h) {
  float half = s / 2;
  
  beginShape(LINES);
  vertex(-half, -half, -half);
  vertex(half, -half, -half);
  
  vertex(half, -half, -half);
  vertex(half, half, -half);
  
  vertex(half, half, -half);
  vertex(-half, half, -half);
  
  vertex(-half, half, -half);
  vertex(-half, -half, -half);
  
  vertex(-half, -half, -half);
  vertex(0, 0, h);
  
  vertex(half, -half, -half);
  vertex(0, 0, h);
  
  vertex(half, half, -half);
  vertex(0, 0, h);
  
  vertex(-half, half, -half);
  vertex(0, 0, h);
  
  endShape();
}

void cylinderWireframe(float r, float h) {
  int num = 36;
  float angleStep = TWO_PI / num;
  
  for (int i = 0; i < num; i++) {
    float angle0 = i * angleStep;
    float angle1 = (i + 1) * angleStep;
    
    float x0 = r * cos(angle0);
    float y0 = r * sin(angle0);
    float x1 = r * cos(angle1);
    float y1 = r * sin(angle1);

    line(x0, y0, -h / 2, x1, y1, -h / 2);
    line(x0, y0, h / 2, x1, y1, h / 2);
    line(x0, y0, -h / 2, x0, y0, h / 2);
    line(x1, y1, -h / 2, x1, y1, h / 2);
  }
}

void dodecahedronWireframe(float s) {
  float t = (1.0 + sqrt(5.0)) / 2.0 * s / 2.0;
  float[][] vertices = {
    {0, s, t},
    {0, s, -t},
    {0, -s, t},
    {0, -s, -t},
    {s, t, 0},
    {s, -t, 0},
    {-s, t, 0},
    {-s, -t, 0},
    {t, 0, s},
    {t, 0, -s},
    {-t, 0, s},
    {-t, 0, -s}
  };
  int[][] edges = {
    {0, 4}, {4, 8}, {8, 0}, {0, 5}, {5, 9},
    {9, 0}, {1, 6}, {6, 10}, {10, 1}, {1, 7},
    {7, 11}, {11, 1}, {2, 4}, {4, 10}, {10, 2},
    {2, 6}, {6, 8}, {8, 2}, {3, 5}, {5, 9},
    {9, 3}, {3, 7}, {7, 11}, {11, 3}, {2, 7},
    {7, 4}, {4, 2}
  };

  stroke(255, 165, 0);
  strokeWeight(1);
  beginShape(LINES);
  for (int i = 0; i < edges.length; i++) {
    int[] edge = edges[i];
    float[] v1 = vertices[edge[0]];
    float[] v2 = vertices[edge[1]];
    line(v1[0], v1[1], v1[2], v2[0], v2[1], v2[2]);
  }
  endShape();
}

void icosahedronWireframe(float s) {
  float t = (1.0 + sqrt(5.0)) / 2.0 * s / 2.0;
  float[][] vertices = {
    {0, s, t}, {0, s, -t}, {0, -s, t}, {0, -s, -t},
    {s, t, 0}, {s, -t, 0}, {-s, t, 0}, {-s, -t, 0},
    {t, 0, s}, {t, 0, -s}, {-t, 0, s}, {-t, 0, -s}
  };
  int[][] edges = {
    {0, 4}, {4, 8}, {8, 0}, {0, 5}, {5, 9},
    {9, 0}, {1, 6}, {6, 10}, {10, 1}, {1, 7},
    {7, 11}, {11, 1}, {2, 4}, {4, 10}, {10, 2},
    {2, 6}, {6, 8}, {8, 2}, {3, 5}, {5, 9},
    {9, 3}, {3, 7}, {7, 11}, {11, 3}, {2, 7},
    {7, 4}, {4, 2}
  };

  stroke(128, 0, 128);
  strokeWeight(1);
  beginShape(LINES);
  for (int i = 0; i < edges.length; i++) {
    int[] edge = edges[i];
    float[] v1 = vertices[edge[0]];
    float[] v2 = vertices[edge[1]];
    line(v1[0], v1[1], v1[2], v2[0], v2[1], v2[2]);
  }
  endShape();
}

PVector torusVertex(float r, float t, float theta, float phi) {
  float x = (r + t * cos(theta)) * cos(phi);
  float y = (r + t * cos(theta)) * sin(phi);
  float z = t * sin(theta);
  return new PVector(x, y, z);
}

PVector sphereVertex(float r, float lat, float lon) {
  float x = r * cos(lat) * cos(lon);
  float y = r * cos(lat) * sin(lon);
  float z = r * sin(lat);
  return new PVector(x, y, z);
}
