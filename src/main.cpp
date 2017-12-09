
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

#include <iostream>

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#include "WindMill.h"
#include "Display.h"

WindMill windMill ( 500 );
Display display ( WINDOW_WIDTH, WINDOW_HEIGHT );

void render () {

    glClear ( GL_COLOR_BUFFER_BIT );

    display.showGrid ();
    display.showAxis ();

    windMill.draw ();

    glFlush ();

}

int main ( int args_len, char * args_context [] ) {

    glutInit ( &args_len, args_context );

    glutInitDisplayMode ( GLUT_SINGLE );
    glutInitWindowSize ( WINDOW_WIDTH, WINDOW_HEIGHT );
    glutInitWindowPosition ( 100, 100 );
    glutCreateWindow ( "Transformation" );

    glLoadIdentity ();
    gluOrtho2D ( -WINDOW_WIDTH, WINDOW_WIDTH, -WINDOW_HEIGHT, WINDOW_HEIGHT );
    glFlush ();

    display.setBackgroundColor ( .3, .5, .6 );

    glutDisplayFunc ( render );

    glutMainLoop ();

    return 0;

};