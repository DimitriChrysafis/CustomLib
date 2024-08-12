float angleX = 0;
float angleY = 0;
float angleZ = 0;
float zoom = 1;
float rotationSpeed = 0.02;

void setup() {
  size(800, 600, P3D);
}

void draw() {
  background(0);
  translate(width / 2, height / 2, -500);
  scale(zoom);

  rotateX(angleX);
  rotateY(angleY);
  rotateZ(angleZ);

  drawBoxWireframe(100);
  drawBoxSolid(100);
  
  pushMatrix();
  translate(200, 0, 0);
  drawConeWireframe(50, 100);
  drawConeSolid(50, 100);
  popMatrix();
  
  pushMatrix();
  translate(-200, 200, 0);
  drawPyramidWireframe(100, 150);
  drawPyramidSolid(100, 150);
  popMatrix();
  
  pushMatrix();
  translate(200, -200, 0);
  drawCylinderWireframe(50, 150);
  drawCylinderSolid(50, 150);
  popMatrix();
  
  pushMatrix();
  translate(0, 200, -200);
  drawDodecahedronWireframe(100);
  drawDodecahedronSolid(100);
  popMatrix();
  
  pushMatrix();
  translate(-200, -200, 200);
  drawIcosahedronWireframe(100);
  drawIcosahedronSolid(100);
  popMatrix();
  
  angleX += rotationSpeed;
  angleY += rotationSpeed;
  angleZ += rotationSpeed;
}

void drawBoxWireframe(float s) {
  float half = s / 2;
  PVector[] vertices = {
    new PVector(-half, -half, -half),
    new PVector(half, -half, -half),
    new PVector(half, half, -half),
    new PVector(-half, half, -half),
    new PVector(-half, -half, half),
    new PVector(half, -half, half),
    new PVector(half, half, half),
    new PVector(-half, half, half)
  };
  
  int[][] edges = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0},
    {4, 5}, {5, 6}, {6, 7}, {7, 4},
    {0, 4}, {1, 5}, {2, 6}, {3, 7}
  };

  stroke(0, 0, 255);
  for (int[] edge : edges) {
    PVector v1 = vertices[edge[0]];
    PVector v2 = vertices[edge[1]];
    line(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z);
  }
}

void drawBoxSolid(float s) {
  float half = s / 2;
  PVector[] vertices = {
    new PVector(-half, -half, -half),
    new PVector(half, -half, -half),
    new PVector(half, half, -half),
    new PVector(-half, half, -half),
    new PVector(-half, -half, half),
    new PVector(half, -half, half),
    new PVector(half, half, half),
    new PVector(-half, half, half)
  };
  
  int[][] faces = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {0, 1, 5, 4},
    {1, 2, 6, 5},
    {2, 3, 7, 6},
    {3, 0, 4, 7}
  };

  fill(0, 0, 255, 100);
  noStroke();
  beginShape(QUADS);
  for (int[] face : faces) {
    for (int vertex : face) {
      vertex(vertices[vertex].x, vertices[vertex].y, vertices[vertex].z);
    }
  }
  endShape();
}

void drawConeWireframe(float r, float h) {
  int numPoints = 36;
  float angleStep = TWO_PI / numPoints;
  
  stroke(255, 255, 0);
  for (int i = 0; i < numPoints; i++) {
    float angle0 = i * angleStep;
    float angle1 = (i + 1) * angleStep;

    PVector v0 = new PVector(r * cos(angle0), r * sin(angle0), 0);
    PVector v1 = new PVector(r * cos(angle1), r * sin(angle1), 0);
    
    line(v0.x, v0.y, v0.z, v1.x, v1.y, v1.z);
    line(v0.x, v0.y, v0.z, 0, 0, h);
    line(v1.x, v1.y, v1.z, 0, 0, h);
  }
}

void drawConeSolid(float r, float h) {
  int numPoints = 36;
  float angleStep = TWO_PI / numPoints;

  fill(255, 255, 0, 100);
  noStroke();
  beginShape(TRIANGLES);
  for (int i = 0; i < numPoints; i++) {
    float angle0 = i * angleStep;
    float angle1 = (i + 1) * angleStep;

    PVector v0 = new PVector(r * cos(angle0), r * sin(angle0), 0);
    PVector v1 = new PVector(r * cos(angle1), r * sin(angle1), 0);
    PVector top = new PVector(0, 0, h);

    vertex(v0.x, v0.y, v0.z);
    vertex(v1.x, v1.y, v1.z);
    vertex(top.x, top.y, top.z);
  }
  endShape();
}

void drawPyramidWireframe(float s, float h) {
  float half = s / 2;
  PVector[] vertices = {
    new PVector(-half, -half, 0),
    new PVector(half, -half, 0),
    new PVector(half, half, 0),
    new PVector(-half, half, 0),
    new PVector(0, 0, h)
  };
  
  int[][] edges = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0},
    {0, 4}, {1, 4}, {2, 4}, {3, 4}
  };

  stroke(255, 165, 0);
  for (int[] edge : edges) {
    PVector v1 = vertices[edge[0]];
    PVector v2 = vertices[edge[1]];
    line(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z);
  }
}

void drawPyramidSolid(float s, float h) {
  float half = s / 2;
  PVector[] vertices = {
    new PVector(-half, -half, 0),
    new PVector(half, -half, 0),
    new PVector(half, half, 0),
    new PVector(-half, half, 0),
    new PVector(0, 0, h)
  };
  
  int[][] faces = {
    {0, 1, 4},
    {1, 2, 4},
    {2, 3, 4},
    {3, 0, 4},
    {0, 1, 2, 3}
  };

  fill(255, 165, 0, 100);
  noStroke();
  beginShape(TRIANGLES);
  for (int[] face : faces) {
    for (int vertex : face) {
      vertex(vertices[vertex].x, vertices[vertex].y, vertices[vertex].z);
    }
  }
  endShape();
}

void drawCylinderWireframe(float r, float h) {
  int numPoints = 36;
  float angleStep = TWO_PI / numPoints;

  stroke(255, 0, 255);
  for (int i = 0; i < numPoints; i++) {
    float angle0 = i * angleStep;
    float angle1 = (i + 1) * angleStep;

    PVector v0 = new PVector(r * cos(angle0), r * sin(angle0), 0);
    PVector v1 = new PVector(r * cos(angle1), r * sin(angle1), 0);
    PVector v2 = new PVector(r * cos(angle0), r * sin(angle0), h);
    PVector v3 = new PVector(r * cos(angle1), r * sin(angle1), h);

    line(v0.x, v0.y, v0.z, v1.x, v1.y, v1.z);
    line(v2.x, v2.y, v2.z, v3.x, v3.y, v3.z);
    line(v0.x, v0.y, v0.z, v2.x, v2.y, v2.z);
    line(v1.x, v1.y, v1.z, v3.x, v3.y, v3.z);
  }
}

void drawCylinderSolid(float r, float h) {
  int numPoints = 36;
  float angleStep = TWO_PI / numPoints;

  fill(255, 0, 255, 100);
  noStroke();
  beginShape(TRIANGLE_STRIP);
  for (int i = 0; i <= numPoints; i++) {
    float angle = i * angleStep;
    PVector v0 = new PVector(r * cos(angle), r * sin(angle), 0);
    PVector v1 = new PVector(r * cos(angle), r * sin(angle), h);

    vertex(v0.x, v0.y, v0.z);
    vertex(v1.x, v1.y, v1.z);
  }
  endShape();
  
  fill(255, 0, 255, 100);
  beginShape(TRIANGLE_FAN);
  PVector topCenter = new PVector(0, 0, h);
  for (int i = 0; i <= numPoints; i++) {
    float angle = i * angleStep;
    PVector v0 = new PVector(r * cos(angle), r * sin(angle), h);

    vertex(topCenter.x, topCenter.y, topCenter.z);
    vertex(v0.x, v0.y, v0.z);
  }
  endShape();
  
  beginShape(TRIANGLE_FAN);
  PVector bottomCenter = new PVector(0, 0, 0);
  for (int i = 0; i <= numPoints; i++) {
    float angle = i * angleStep;
    PVector v0 = new PVector(r * cos(angle), r * sin(angle), 0);

    vertex(bottomCenter.x, bottomCenter.y, bottomCenter.z);
    vertex(v0.x, v0.y, v0.z);
  }
  endShape();
}

void drawDodecahedronWireframe(float s) {
  float t = (1.0 + sqrt(5.0)) / 2.0 * s / 2.0;
  PVector[] vertices = {
    new PVector(0, s, t), new PVector(0, s, -t), new PVector(0, -s, t), new PVector(0, -s, -t),
    new PVector(s, t, 0), new PVector(s, -t, 0), new PVector(-s, t, 0), new PVector(-s, -t, 0),
    new PVector(t, 0, s), new PVector(-t, 0, s), new PVector(t, 0, -s), new PVector(-t, 0, -s)
  };
  
  int[][] edges = {
    {0, 4}, {4, 1}, {1, 5}, {5, 0},
    {2, 6}, {6, 3}, {3, 7}, {7, 2},
    {0, 2}, {4, 6}, {1, 3}, {5, 7},
    {8, 0}, {0, 10}, {10, 9}, {9, 8},
    {11, 2}, {2, 10}, {10, 11}, {11, 9},
    {8, 11}, {11, 9}, {9, 10}, {10, 8}
  };

  stroke(255, 105, 180);
  for (int[] edge : edges) {
    PVector v1 = vertices[edge[0]];
    PVector v2 = vertices[edge[1]];
    line(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z);
  }
}

void drawDodecahedronSolid(float s) {
  float t = (1.0 + sqrt(5.0)) / 2.0 * s / 2.0;
  PVector[] vertices = {
    new PVector(0, s, t), new PVector(0, s, -t), new PVector(0, -s, t), new PVector(0, -s, -t),
    new PVector(s, t, 0), new PVector(s, -t, 0), new PVector(-s, t, 0), new PVector(-s, -t, 0),
    new PVector(t, 0, s), new PVector(-t, 0, s), new PVector(t, 0, -s), new PVector(-t, 0, -s)
  };
  
  int[][] faces = {
    {0, 4, 1, 5}, {2, 6, 3, 7}, {8, 0, 10, 9},
    {11, 2, 10, 9}, {8, 11, 9, 10}
  };

  fill(255, 105, 180, 100);
  noStroke();
  beginShape(TRIANGLES);
  for (int[] face : faces) {
    for (int vertex : face) {
      vertex(vertices[vertex].x, vertices[vertex].y, vertices[vertex].z);
    }
  }
  endShape();
}

void drawIcosahedronWireframe(float s) {
  float t = s * 0.5;
  PVector[] vertices = {
    new PVector(0, t, s), new PVector(0, -t, s), new PVector(0, -t, -s),
    new PVector(0, t, -s), new PVector(t, 0, s), new PVector(-t, 0, s),
    new PVector(-t, 0, -s), new PVector(t, 0, -s), new PVector(s, -s, 0),
    new PVector(s, s, 0), new PVector(-s, -s, 0), new PVector(-s, s, 0)
  };
  
  int[][] edges = {
    {0, 4}, {4, 1}, {1, 5}, {5, 0},
    {2, 6}, {6, 3}, {3, 7}, {7, 2},
    {8, 0}, {0, 10}, {10, 9}, {9, 8},
    {11, 2}, {2, 10}, {10, 11}, {11, 9},
    {8, 11}, {11, 9}, {9, 10}, {10, 8}
  };

  stroke(255, 20, 147);
  for (int[] edge : edges) {
    PVector v1 = vertices[edge[0]];
    PVector v2 = vertices[edge[1]];
    line(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z);
  }
}

void drawIcosahedronSolid(float s) {
  float t = s * 0.5;
  PVector[] vertices = {
    new PVector(0, t, s), new PVector(0, -t, s), new PVector(0, -t, -s),
    new PVector(0, t, -s), new PVector(t, 0, s), new PVector(-t, 0, s),
    new PVector(-t, 0, -s), new PVector(t, 0, -s), new PVector(s, -s, 0),
    new PVector(s, s, 0), new PVector(-s, -s, 0), new PVector(-s, s, 0)
  };

  int[][] faces = {
    {0, 4, 1, 5}, {2, 6, 3, 7}, {8, 0, 10, 9},
    {11, 2, 10, 9}, {8, 11, 9, 10}
  };

  fill(255, 20, 147, 100);
  noStroke();
  beginShape(TRIANGLES);
  for (int[] face : faces) {
    for (int vertex : face) {
      vertex(vertices[vertex].x, vertices[vertex].y, vertices[vertex].z);
    }
  }
  endShape();
}

void mouseDragged() {
  float dx = (mouseX - pmouseX) * 0.01;
  float dy = (mouseY - pmouseY) * 0.01;
  angleX += dy;
  angleY += dx;
}

void mouseWheel(MouseEvent event) {
  float e = event.getCount();
  zoom += e * 0.1;
  zoom = constrain(zoom, 0.1, 5);
}
