#ifndef GRAPHICSENGINE_HPP
#define GRAPHICSENGINE_HPP

#include<QOpenGLFunctions_4_3_Core>

struct ShaderType {
    enum EShaderType {
        VERTEX        = 0,
        TESS_CONTROL  = 1,
        TESS_EVALUATE = 2,
        GEOMETRY      = 3,
        FRAGMENT      = 4
    };
};

struct UniformType {
    enum EUniformType {
        Float,
        Float4x4
    };
};

struct Pipeline {
    GLuint shaders[5]={0};
    GLuint program{0};
    GLuint vao{0};
    GLuint vbo{0};
    GLuint ebo{0};
    GLint vertex_buffer_capacity{1024};
    GLint element_buffer_capacity{1024};
    GLint vertex_buffer_size{0};
    GLint element_buffer_size{0};

    GLenum draw_mode{GL_LINE_STRIP};
    GLenum polygon_mode{GL_LINE};

    GLint vertex_position_component_size;

};

class GraphicsEngine: protected QOpenGLFunctions_4_3_Core
{
public:
    GraphicsEngine();

public: // Qt interface
    void initializeGL();
    void cleanupGL(Pipeline &pipe);
    void update();
    void resize(int w, int h);
    void clearColor(float r, float g, float b, float a=1.0f);


    // ** shader **
    GLuint createShader(GLuint shader_type, const GLchar **src);
    GLint isShaderOk(GLuint shader_id); // **
    // void deleteShader(GLuint shader_id); => glDeleteShader()
    // void isShader(GLuint id); => glIsShader()

    // ** program **
    void attachShaders(GLuint program_id, GLuint *shader_ids);
    void detachShaders(GLuint program_id, GLuint *shader_ids);
    GLint isProgramOk(GLuint program_id); // **
    // GLuint createProgram(); => glCreateProgram()
    // void linkProgram(GLuint program_id); => glLinkProgram()
    // void deleteProgram(GLuint program_id); => glDeleteProgram()
    // void isProgram(GLuint id); => glIsProgram()

    void createShaderProgram(Pipeline &pipeline,
                       const GLchar *vsrc,
                       const GLchar *fsrc,
                       const GLchar *tctlsrc = nullptr,
                       const GLchar *tevalsrc = nullptr,
                       const GLchar *geosrc = nullptr);

    // ** vertex array object **
    void createVertexArray(Pipeline &pipeline);

    void drawBegin(const Pipeline &pipe);
    void setUniformValue(const Pipeline &pipe, UniformType::EUniformType type, const std::string &uni_name, float *data);
    void drawEnd(const Pipeline &pipe);
    void uploadData(Pipeline &pipe, int data_size, const float *data, int indice_size, const uint *indices);

private:

};

#endif // GRAPHICSENGINE_HPP
