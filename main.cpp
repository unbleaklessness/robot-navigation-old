#include <GL/glu.h>
#include <GL/freeglut.h>
#include <vector>
#include <utility>
#include <cstdio>
#include <ctime>

#include "shape.h"
#include "text.h"
#include "world.h"

#define WIN_WIDTH 400
#define WIN_HEIGHT 400

clock_t current_time = clock();
clock_t last_time = current_time;
float dt = 0;

vector1 robot, walls, square, rectangle, circle, obstacles, room;

void init_shapes() {
    robot = shape::make_rectangle(200, 200, 23, 71);
    shape::rotate(robot, 0.45);
//    room = world::make_room_2(WIN_WIDTH, WIN_HEIGHT);
    walls = world::room_2::make_walls();
    square = world::room_2::make_square();
    rectangle = world::room_2::make_rectangle();
    circle = world::room_2::make_circle();

    room.insert(room.end(), walls.begin(), walls.end());
    room.insert(room.end(), square.begin(), square.end());
    room.insert(room.end(), rectangle.begin(), rectangle.end());
    room.insert(room.end(), circle.begin(), circle.end());

    obstacles = shape::minkowski_sum(robot, room);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(2.5);

    glColor3f(0.5, 0.55, 1);
    shape::draw(obstacles);

    glColor3f(0, 0.3, 1);
    shape::draw(room);

    glColor3f(1, 0, 0);
    shape::draw(robot);

    char message[50];
    sprintf(message, "dt: %f", dt);
    glColor3f(1.0, 0, 1.0);
    text::print(50, 50, message);

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, WIN_WIDTH, 0.0, WIN_HEIGHT, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

    glutPostRedisplay();
}

void idle() {
    current_time = clock();
    dt = static_cast<float>(current_time - last_time) / CLOCKS_PER_SEC;
    last_time = current_time;
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    init_shapes();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutCreateWindow("Robot Navigation");
    
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}