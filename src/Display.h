
#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <OpenGL/gl.h>

class Display {

    private:

        float display_bg_color [ 3 ];
        float grid_color [ 3 ];
        float axis_color [ 3 ];
        int max_display_size;
        int display_grid_unit;
        int axis_grid_unit;

        int window_width;
        int window_height;

        void drawText (
            
            const char * text,
            const GLint pos_x,
            const GLint pos_y,
            const int size
        
        );

    public:

        Display ( const int window_width, const int window_height );
        ~Display ();

        void setBackgroundColor ( const float r, const float g, const float b );
        void setMaxDisplaySize ( const int max_size );
        void setGridUnit ( const int unit );
        void setAxisUnit ( const int unit );
        void setAxisColor ( const float r, const float g, const float b );
        void setGridColor ( const float r, const float g, const float b );

        void showGrid ( const int unit = 50 );
        void showAxis ( const int unit = 100 );

};

Display::Display ( const int window_width, const int window_height ) {

    this -> window_height = window_height;
    this -> window_width = window_width;

    this -> grid_color [ 0 ] = 135 / 255.0;
    this -> grid_color [ 1 ] = 206 / 255.0;
    this -> grid_color [ 2 ] = 235 / 255.0;

    this -> axis_color [ 0 ] = 255 / 255.0;
    this -> axis_color [ 1 ] = 255 / 255.0;
    this -> axis_color [ 2 ] = 255 / 255.0;

};

Display::~Display () {

};

void Display::setBackgroundColor ( const float r, const float g, const float b ) {

    const float opacity = 1.0;

    this -> display_bg_color [ 0 ] = r;
    this -> display_bg_color [ 1 ] = g;
    this -> display_bg_color [ 2 ] = b;

    glClearColor ( this -> display_bg_color [ 0 ], this -> display_bg_color [ 1 ], this -> display_bg_color [ 2 ], opacity );

};

void Display::showAxis ( const int unit ) {

    int unit_distance = unit;
    float * color = this -> axis_color;

    glBegin ( GL_LINES );

        glColor3d ( color [ 0 ], color [ 1 ], color [ 2 ] );

        glVertex2f ( 0, this -> window_height );
        glVertex2f ( 0, - this -> window_height );

    glEnd ();

    glBegin ( GL_LINES );

        glColor3d ( color [ 0 ], color [ 1 ], color [ 2 ] );

        glVertex2f ( this -> window_width, 0 );
        glVertex2f ( - this -> window_width, 0 );

    glEnd ();

    while ( unit_distance < this -> window_width ) {

        const char * text = std::to_string ( unit_distance ).c_str ();
        const char * negate_text = std::to_string ( - unit_distance ).c_str ();

        this -> drawText ( text, unit_distance, 50, 3 );
        this -> drawText ( negate_text, -unit_distance, - 50, 4 );

        unit_distance += unit;

    }

    this -> drawText ( "X", this -> window_width - 38, - 50, 1 );

    unit_distance = unit;

    while ( unit_distance < this -> window_height ) {

        const char * text = std::to_string ( unit_distance ).c_str ();
        const char * negate_text = std::to_string ( - unit_distance ).c_str ();

        glColor3d ( color [ 0 ], color [ 1 ], color [ 2 ] );

        this -> drawText ( text, -100, unit_distance, 3 );
        this -> drawText ( negate_text, 50, - unit_distance, 4 );
            
        unit_distance += unit;

    }

    this -> drawText ( "Y", 50, this -> window_height - 38, 1 );

};

void Display::showGrid ( const int unit ) {

    int unit_distance = 0;
    float * color = this -> grid_color;

    while ( unit_distance < this -> window_width ) {

        glBegin ( GL_LINES );

            glColor3d ( color[ 0 ], color [ 1 ], color [ 2 ] );

            glVertex2f ( unit_distance, this -> window_height );
            glVertex2f ( unit_distance, - this -> window_height );

        glEnd ();

        glBegin ( GL_LINES );

            glColor3d ( color[ 0 ], color [ 1 ], color [ 2 ] );

            glVertex2f ( -unit_distance, this -> window_height );
            glVertex2f ( -unit_distance, - this -> window_height );

        glEnd ();

        unit_distance += unit;

    }

    unit_distance = 0;

    while ( unit_distance < this -> window_height ) {

        glBegin ( GL_LINES );

            glColor3d ( color [ 0 ], color [ 1 ], color [ 2 ] );

            glVertex2f ( this -> window_width, unit_distance );
            glVertex2f ( - this -> window_width, unit_distance );

        glEnd ();

        glBegin ( GL_LINES );

            glColor3d ( color [ 0 ], color [ 1 ], color [ 2 ] );

            glVertex2f ( this -> window_width, -unit_distance );
            glVertex2f ( - this -> window_width, -unit_distance );

        glEnd ();

        unit_distance += unit;

    }

};

void Display::drawText ( const char * text, const GLint pos_x, const GLint pos_y, const int size ) {

    glRasterPos2i ( pos_x, pos_y );

    for ( int index = 0; index < size; index ++ ) {

        glutBitmapCharacter ( GLUT_BITMAP_HELVETICA_12, text[ index ] );

    }

};

#endif