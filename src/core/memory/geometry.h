#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

/*
 float
 Attribute(x,y,z) Attribute(r,g,b) Attribute(s,t)
 Vertex(pos,color,tex)

 Geometry(Vertex,...)
 Node
*/

template<typename T, unsigned int n>
struct Attribute
{
    T d[n];
};

using Position2D = Attribute<float,2>;
using Position3D = Attribute<float,3>;
using Color = Attribute<float,4>;
using TexCoord = Attribute<float,2>;

struct Vertex
{
    Vertex() { }
    ~Vertex() { cout << "that's ok!" << endl; }

    friend ostream &operator<<(ostream &os, const Vertex &vert) {
        cout << "position: " << vert.pos.d[0] << "," << vert.pos.d[1] << "," << vert.pos.d[2] << endl;
        cout << "color: " << vert.color.d[0] << "," << vert.color.d[1] << "," << vert.color.d[2] << "," << vert.color.d[3] << endl;
        cout << "text coord: " << vert.tex.d[0] << "," << vert.tex.d[1]  << endl;
    }

    Position3D pos;
    Color color;
    TexCoord tex;
};

struct Geometry
{
    Vertex *vert{nullptr};
    size_t vertCount{0};
};

class VertexPool
{
    using VertexCount = size_t;
    using VertexAlloc = allocator<Vertex>;
    using VertexAllocTraits = allocator_traits<VertexAlloc>;
public:
    VertexPool() {
        _startPtr = VertexAllocTraits::allocate(_alloc,_totalCount);
        _curPtr = _endPtr = _startPtr;
    }

    void pushVertices(const float *data, VertexCount n) {
        if(_endPtr - _curPtr <= n) {
            new(_curPtr) Vertex[n]; // placement new
            memcpy(_curPtr,data,sizeof(Vertex)*n);
            _curPtr += n;
        }
    }

    const Vertex *objAt(VertexCount index) {
        auto _objPtr = _startPtr + index;
        if(_objPtr < _curPtr) {
            return _objPtr;
        }
        return nullptr;
    }

    ~VertexPool() {
        VertexAllocTraits::deallocate(_alloc,_startPtr,_totalCount);
    }

private:
    VertexAlloc  _alloc;
    VertexCount  _totalCount{1024}; 
    Vertex      *_startPtr{nullptr};
    Vertex      *_curPtr{nullptr};
    Vertex      *_endPtr{nullptr};
};

#endif