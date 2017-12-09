
#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <Matrix/Matrix.h>
#include <Vector/Vector.h>

template < class T >
class Transformation {

    private:

        T x, y, z, angle;
        Matrix < T > matrices;
        Vector < T > vectors;

    public:

        // accessors
        void currentMatrix ();

        // mutators
        void rotate ( const T angle, const T x, const T y, const T z );
        void translate ( const T dx, const T dy, const T dz );
        void scale ( const T dx, const T dy, const T dz );

        void createRotationMatrix ();
        void createTranslationMatrix ();
        void createScaleMatrix ();

};

#endif