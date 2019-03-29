#ifndef SCENENODE_HPP_
#define SCENENODE_HPP_

#include <vector>
#include <string>

class SceneNode
{
    friend class SceneManager;

public:
    explicit SceneNode(SceneNode *parent);
    ~SceneNode();

    inline unsigned int id() const;
    inline const std::string &name() const;

    inline void setName(const std::string &name);

protected:
    inline void addChild(SceneNode *child);

private:
    static unsigned int __id;

    unsigned int _id{0};
    std::string _nodeName;

    SceneNode *_parent{nullptr};
    std::vector<SceneNode*> _children;
};

///////////////////////////////

inline unsigned SceneNode::id() const
{
    return _id;
}

inline const std::string &SceneNode::name() const
{
    return _nodeName;
}

inline void SceneNode::setName(const std::string &name)
{
    _nodeName = name;
}

inline void SceneNode::addChild(SceneNode *child)
{
    if(child)
        _children.push_back(child);
}


#endif
