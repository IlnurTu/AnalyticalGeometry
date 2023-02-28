#include "Plane.h"
#include "Matrix.h"

#ifndef GEO_ALGORITMS_H
#define GEO_ALGORITMS_H

void normalize(Plane &plane);

double getPointDeviation(Point m, const Plane &plane);

bool areOnDifferentSize(Point m, const Plane &plane);


double getDeterminantSquareMatrix(const SquareMatrix<3>& table);

Vector getVectorInNewBasis(const Vector& source, const Vector& l1,const Vector& l2,const Vector& l3);


#endif //GEO_ALGORITMS_H
