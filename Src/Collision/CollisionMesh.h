#ifndef CBN_COLLISIONMESH_H_INCLUDED
#define CBN_COLLISIONMESH_H_INCLUDED

#include <vector>
#include <Math/Vector.h>
#include <Math/Matrix.h>
#include "Collision.h"

class CollisionMesh {
    public:
        CollisionMesh(std::vector<PGE::Vector3f> verts,std::vector<int> inds);
        Collision checkCollision(PGE::Matrix4x4f matrix, PGE::Line3f line,float radius,int& outTriangleIndex) const;
        Collision checkCollision(PGE::Matrix4x4f matrix, PGE::Line3f line,float radius) const;
    private:
        std::vector<PGE::Vector3f> vertices;
        std::vector<int> indices;
};

#endif
