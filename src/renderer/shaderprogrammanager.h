#ifndef SHADERPROGRAMMANAGER_H
#define SHADERPROGRAMMANAGER_H

#include "shared_library.h"
#include <string>

LENGINE_NAMESPACE_BEGIN

struct ShaderType {
    enum Shader {
        VERTEX,
        TESS_CONTROL,
        TESS_EVAL,
        GEOMETRY,
        FRAGMENT
    };
};

class ShaderProgramManager
{
public:
    ShaderProgramManager();

private:
    bool createShader(ShaderType::Shader iShader, const std::string &src);
};

LENGINE_NAMESPACE_END
#endif // SHADERPROGRAMMANAGER_H
