//Jeff Chastine
#include <Windows.h>
#include <GL\glew.h>
#include <GL/glut.h>
#include <math.h> 

void init()

{
    // Set display window color to as glClearColor(R,G,B,Alpha)
    glClearColor(1.0, 1.0, 1.0, 0.0);
    // Set projection parameters.
    glMatrixMode(GL_PROJECTION);
    // Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max Height)
    gluOrtho2D(0.0, 800, 0.0, 600);
}

void home()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear display window
    // Set line segment color as glColor3f(R,G,B)

    //side Wall
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(200, 100);
    glVertex2i(200, 350);
    glVertex2i(100, 350);
    glVertex2i(100, 400);
    glVertex2i(700, 400);
    glVertex2i(700, 350);
    glVertex2i(600, 350);
    glVertex2i(600, 100);
    glEnd();

    //Left window 
    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_POLYGON);
    glVertex2i(230, 320);
    glVertex2i(350, 320);
    glVertex2i(350, 230);
    glVertex2i(230, 230);
    glEnd();

    // lines on left window
    glColor3f(0.1, 0.7, 0.5);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(290, 320);
    glVertex2i(290, 230);
    glVertex2i(230, 273);
    glVertex2i(350, 273);
    glEnd();

    //right window
    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_POLYGON);
    glVertex2i(430, 320);
    glVertex2i(550, 320);
    glVertex2i(550, 230);
    glVertex2i(430, 230);
    glEnd();

    // lines on right window 
    glColor3f(0.1, 0.7, 0.5);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(490, 320);
    glVertex2i(490, 230);
    glVertex2i(430, 273);
    glVertex2i(550, 273);
    glEnd();

    // Front Door
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(350, 200);
    glVertex2i(425, 200);
    glVertex2i(425, 100);
    glVertex2i(350, 100);
    glEnd();


    // Front Door Lock/knob
    glColor3f(0.2, 0.5, 0.9);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2i(400, 150);
    glEnd();

    //semi-circle roof
    //fix variable naming
    glColor3f(0.2, 0.5, 0.1);
    int centerx = 400;//x axis center
    int centery = 400;//y axis center
    int roofr = 100;//radius
    int roofd = 200;//diameter
    float PI = 3.141592653589793238f;
    float semicircleangle = PI * 1.0f;
    int steps = 100;
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < steps; i++) {
        float theta = semicircleangle * float(i) / float(steps);//get the current angle 
        float x = roofr * cosf(theta);//calculate the x component 
        float y = roofr * sinf(theta);//calculate the y component 
        glVertex2f(x + centerx, y + centery);//output vertex 
    }
    glEnd();

    //first circle moon

    int moonr = 50;
    int mooncenterx = 700;
    int mooncentery = 500;
    int moonsteps = 100;
    float circleangle = PI * 2.0f;
    glColor3f(0.5, 0.35, 0.05);
    glBegin(GL_TRIANGLE_FAN);
    for (int a = 0; a <= moonsteps; a++) {
        float angle = circleangle * float(a) / float(moonsteps);//get the current angle 
        float moonx = moonr * cosf(angle);//calculate the x component 
        float moony = moonr * sinf(angle);//calculate the y component 
        glVertex2f(moonx + mooncenterx, moony + mooncentery);//output vertex 
    }
    glEnd();

    //second circle moon
    int moon2r = 50;
    int mooncenter2x = 725;
    int mooncenter2y = 525;
    int moonsteps2 = 100;
    float circleangle2 = PI * 2.0f;

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLE_FAN);
    for (int b = 0; b <= moonsteps; b++) {
        float angle2 = circleangle * float(b) / float(moonsteps2);//get the current angle 
        float moon2x = moonr * cosf(angle2);//calculate the x component 
        float moon2y = moonr * sinf(angle2);//calculate the y component 
        glVertex2f(moon2x + mooncenter2x, moon2y + mooncenter2y);//output vertex 
    }
    glEnd();



    // Process all OpenGL routine s as quickly as possible
    glFlush();
}

int main(int argc, char** argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);

    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Set top - left display window position.
    glutInitWindowPosition(100, 100);

    // Set display window width and height
    glutInitWindowSize(900, 700);

    // Create display window with the given title
    glutCreateWindow("2D House Assignment");

    // Execute initialization procedure
    init();

    // Send graphics to display window
    glutDisplayFunc(home);

    // Display everything and wait.
    glutMainLoop();

}