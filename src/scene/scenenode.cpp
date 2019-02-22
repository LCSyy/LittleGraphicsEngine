#include "scenenode.hpp"

unsigned SceneNode::__id = 0;

SceneNode::SceneNode(SceneNode *parent)
    : _parent(parent)
{
    ++__id;
    _id = __id;
}

SceneNode::~SceneNode()
{
    --_id;

    for(SceneNode *child: _children) {
        delete child;
        child = nullptr;
    }
}
