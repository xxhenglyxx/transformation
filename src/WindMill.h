
#ifndef WINDMILL_H
#define WINDMILL_H

#include "Shape.h"

class WindMill : public Shape {

    private:

        GLenum draw_type;
        float cube_color [ 3 ];
        float triangle_color [ 9 ];
        float size;
        
        float cube_points [ 4 ] [ 2 ];
        float triangle_points [ 3 ] [ 2 ];

        void _drawTriangle ();
        void _drawCube ();

    public:

        WindMill ( const float size );
        ~WindMill ();

        void setColor ( const float r, const float g, const float b, const int object ); // 0 for cube, 1 for triangle
        void setSize ( const float size );
        void setDrawType ( const GLenum draw_type );

        void getSize ();
        void draw ();

};

WindMill::~WindMill () {};

WindMill::WindMill ( const float size ) {

    this -> size = size;
    const float cube_length = this -> size / 2.0;
    const float triangle_length = this -> size;

    this -> draw_type = GL_TRIANGLES;

    this -> cube_color [ 0 ] = 1.0;
    this -> cube_color [ 1 ] = 1.0;
    this -> cube_color [ 2 ] = 1.0;

    this -> triangle_color [ 0 ] = .0;
    this -> triangle_color [ 1 ] = .0;
    this -> triangle_color [ 2 ] = .0;

    this -> cube_points [ 0 ][ 0 ] = cube_length;
    this -> cube_points [ 0 ][ 1 ] = cube_length;
    this -> cube_points [ 1 ][ 0 ] = cube_length;
    this -> cube_points [ 1 ][ 1 ] = -cube_length;
    this -> cube_points [ 2 ][ 0 ] = -cube_length;
    this -> cube_points [ 2 ][ 1 ] = cube_length;
    this -> cube_points [ 3 ][ 0 ] = -cube_length;
    this -> cube_points [ 3 ][ 1 ] = -cube_length;

    this -> triangle_points [ 0 ][ 0 ] = .0;
    this -> triangle_points [ 0 ][ 1 ] = .0;
    this -> triangle_points [ 1 ][ 0 ] = triangle_length;
    this -> triangle_points [ 1 ][ 1 ] = cube_length;
    this -> triangle_points [ 2 ][ 0 ] = cube_length;
    this -> triangle_points [ 2 ][ 1 ] = cube_length;

    this -> size = 100;

};

void WindMill::_drawCube () {

    glBegin ( this -> draw_type );

        glColor3d ( this -> cube_color [ 0 ], this -> cube_color [ 1 ], this -> cube_color [ 2 ] );

        glVertex2f ( this -> cube_points [ 0 ][ 0 ], this -> cube_points [ 0 ][ 1 ] );
        glVertex2f ( this -> cube_points [ 1 ][ 0 ], this -> cube_points [ 1 ][ 1 ] );
        glVertex2f ( this -> cube_points [ 2 ][ 0 ], this -> cube_points [ 2 ][ 1 ] );
        glVertex2f ( this -> cube_points [ 3 ][ 0 ], this -> cube_points [ 3 ][ 1 ] );

    glEnd ();

};

void WindMill::_drawTriangle () {

    glBegin ( this -> draw_type );

        glColor3d ( this -> triangle_color [ 0 ], this -> triangle_color [ 1 ], this -> triangle_color [ 2 ] );

        glVertex2f ( this -> triangle_points [ 0 ][ 0 ], this -> triangle_points [ 0 ][ 1 ] );
        glVertex2f ( this -> triangle_points [ 1 ][ 0 ], this -> triangle_points [ 1 ][ 1 ] );
        glVertex2f ( this -> triangle_points [ 2 ][ 0 ], this -> triangle_points [ 2 ][ 1 ] );

    glEnd ();

}

void WindMill::draw () {

    this -> _drawCube ();

    this -> _drawTriangle ();

}

#endif