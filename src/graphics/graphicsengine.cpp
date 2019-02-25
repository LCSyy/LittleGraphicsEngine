#include "graphicsengine.hpp"
#include <cstring>
#include <iostream>

GraphicsEngine::GraphicsEngine()
{
    initializeOpenGLFunctions();
}

void GraphicsEngine::cleanupGL(Pipeline &pipe)
{
    glDeleteProgram(pipe.program);
    glDeleteVertexArrays(1,&pipe.vao);
}

void GraphicsEngine::update()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void GraphicsEngine::resize(int w, int h)
{
    glViewport(0,0,w,h);
}

void GraphicsEngine::clearColor(float r, float g, float b, float a)
{
    glClearColor(r,g,b,a);
}

void GraphicsEngine::createShaderProgram(Pipeline &pipeline,
                                         const GLchar *vsrc, const GLchar *fsrc,
                                         const GLchar *tctlsrc, const GLchar *tevalsrc,
                                         const GLchar *geosrc)
{
    pipeline.shaders[ShaderType::VERTEX] = createShader(GL_VERTEX_SHADER,&vsrc);
    if(isShaderOk(pipeline.shaders[ShaderType::VERTEX]) != GL_TRUE) {
        return;
    }

    pipeline.shaders[ShaderType::FRAGMENT] = createShader(GL_FRAGMENT_SHADER,&fsrc);
    if(isShaderOk(pipeline.shaders[ShaderType::FRAGMENT]) != GL_TRUE) {
        return;
    }

    if(tctlsrc) {
        pipeline.shaders[ShaderType::TESS_CONTROL] = createShader(GL_TESS_CONTROL_SHADER,&tctlsrc);
        if(isShaderOk(pipeline.shaders[ShaderType::TESS_CONTROL]) != GL_TRUE) {
            return;
        }
    }

    if(tevalsrc) {
        pipeline.shaders[ShaderType::TESS_EVALUATE] = createShader(GL_TESS_EVALUATION_SHADER,&tevalsrc);
        if(isShaderOk(pipeline.shaders[ShaderType::TESS_EVALUATE]) != GL_TRUE) {
            return;
        }
    }

    if(geosrc) {
        pipeline.shaders[ShaderType::GEOMETRY] = createShader(GL_FRAGMENT_SHADER,&geosrc);
        if(isShaderOk(pipeline.shaders[ShaderType::GEOMETRY]) != GL_TRUE) {
            return;
        }
    }

    pipeline.program = glCreateProgram();
    attachShaders(pipeline.program,pipeline.shaders);
    glLinkProgram(pipeline.program);
    if(isProgramOk(pipeline.program) != GL_TRUE) {
        return;
    }

    glDeleteShader(pipeline.shaders[ShaderType::VERTEX]);
    glDeleteShader(pipeline.shaders[ShaderType::FRAGMENT]);
}

GLuint GraphicsEngine::createShader(GLuint shader_type, const GLchar **src)
{
    GLuint id = glCreateShader(shader_type);
    glShaderSource(id,1,src,nullptr);
    glCompileShader(id);
    return id;
}

GLint GraphicsEngine::isShaderOk(GLuint shader_id)
{
    GLint success;
    char infoLog[512];
    glGetShaderiv(shader_id,GL_COMPILE_STATUS,&success);
    if(!success) {
        glGetShaderInfoLog(shader_id,512,nullptr,infoLog);
        std::cout << "SHADER:" << shader_id << ":" << infoLog << std::endl;
    }
    return success;
}

void GraphicsEngine::attachShaders(GLuint program_id, GLuint *shader_ids)
{
    for(GLsizei i = 0; i < 5; ++i) {
        if(shader_ids[i] > 0)
            glAttachShader(program_id,shader_ids[i]);
    }
}

void GraphicsEngine::detachShaders(GLuint program_id, GLuint *shader_ids)
{
    for(GLsizei i = 0; i < 5; ++i) {
        if(shader_ids[i] > 0)
            glDetachShader(program_id,shader_ids[i]);
    }
}

GLint GraphicsEngine::isProgramOk(GLuint program_id)
{
    GLint success;
    char infoLog[512];
    glGetProgramiv(program_id,GL_LINK_STATUS,&success);
    if(!success) {
        glGetProgramInfoLog(program_id,512,nullptr,infoLog);
        std::cout << "PROGRAM:" << infoLog << std::endl;
    }
    return success;
}

void GraphicsEngine::createVertexArray(Pipeline &pipeline)
{
    glGenVertexArrays(1,&pipeline.vao);
    glBindVertexArray(pipeline.vao);

    glGenBuffers(1,&pipeline.vbo);
    glBindBuffer(GL_ARRAY_BUFFER,pipeline.vbo);
    glBufferData(GL_ARRAY_BUFFER,pipeline.vertex_buffer_capacity,nullptr,GL_STATIC_DRAW);

    glGenBuffers(1,&pipeline.ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,pipeline.ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, pipeline.element_buffer_capacity, nullptr, GL_STATIC_DRAW);

    glVertexAttribPointer(0,pipeline.vertex_position_component_size,GL_FLOAT,GL_FALSE,static_cast<GLsizei>(sizeof(float))*pipeline.vertex_position_component_size,nullptr);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
}

void GraphicsEngine::drawBegin(const Pipeline &pipe)
{
    glUseProgram(pipe.program);
    glBindVertexArray(pipe.vao);
}

void GraphicsEngine::setUniformValue(const Pipeline &pipe, UniformType::EUniformType type, const std::string &uni_name, float *data)
{
    int loc = glGetUniformLocation(pipe.program,uni_name.c_str());

    if(UniformType::Float == type) {
        glUniform1f(loc,*data);
    } else if(UniformType::Float4x4 == type) {
        glUniformMatrix4fv(loc,1,GL_FALSE,data);
    }
}

void GraphicsEngine::drawEnd(const Pipeline &pipe)
{
    glPolygonMode(GL_FRONT_AND_BACK,pipe.polygon_mode);

    if(pipe.element_buffer_size > 0){
        glEnable(GL_PRIMITIVE_RESTART);
        glPrimitiveRestartIndex(0xffff);
        glDrawElements(pipe.draw_mode,pipe.element_buffer_size / static_cast<int>(sizeof(unsigned int)),GL_UNSIGNED_INT,nullptr);
    } else {
        glDrawArrays(pipe.draw_mode,0,pipe.vertex_buffer_size / (pipe.vertex_position_component_size * static_cast<int>(sizeof(float))));
    }

    glBindVertexArray(0);
    glUseProgram(0);
}

void GraphicsEngine::uploadData(Pipeline &pipe, int data_size, const float *data, int indice_size, const uint *indices)
{
    if(data_size > 0 && pipe.vertex_buffer_size + data_size <= pipe.vertex_buffer_capacity) {
        glBindBuffer(GL_ARRAY_BUFFER,pipe.vbo);
        GLvoid *ptr = glMapBufferRange(GL_ARRAY_BUFFER,static_cast<GLintptr>(pipe.vertex_buffer_size),static_cast<GLsizeiptr>(data_size),GL_MAP_WRITE_BIT);
        std::memcpy(ptr,data,static_cast<size_t>(data_size));
        glUnmapBuffer(GL_ARRAY_BUFFER);
        glBindBuffer(GL_ARRAY_BUFFER,0);
        pipe.vertex_buffer_size += data_size;
    }

    if(indice_size > 0 && pipe.element_buffer_size + indice_size <= pipe.element_buffer_capacity) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,pipe.ebo);
        GLvoid *ptr = glMapBufferRange(GL_ELEMENT_ARRAY_BUFFER,static_cast<GLintptr>(pipe.element_buffer_size),static_cast<GLsizeiptr>(indice_size),GL_MAP_WRITE_BIT);
        std::memcpy(ptr,indices,static_cast<size_t>(indice_size));
        glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
        pipe.element_buffer_size += indice_size;
    }
}
