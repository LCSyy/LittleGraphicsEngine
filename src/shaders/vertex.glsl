#version 430 core
layout(location=0) in vec3 ioPos;

void main()
{
    gl_Position = vec4(ioPos,1.0f);
}
