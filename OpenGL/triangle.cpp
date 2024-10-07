#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

// Definicion del Vertex Shader en código GLSL

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos; \n"
    "layout (location = 1) in vec3 aColor; \n"
    "out vec3 ourColor; \n"
    "void main() \n"
    "{\n"
    " gl_Position = vec4(aPos,1.0);\n"
    " ourColor = aColor; \n"
    "}\n\0";

// Definicion del Fragment Shader en código GLSL

const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 ourColor; \n"
    "void main() \n"
    "{\n"
    " FragColor = vec4(ourColor,1.0f);\n"
    "}\n\0";

// Funcion para manejo de IO del teclado 

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window,true);
    }
}


int main() {

    // Funciones de inicialización

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Window Object para contener toda la data y se requiere para todo lo de GLFW
    GLFWwindow* window = glfwCreateWindow(800, 600, "Lab3", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent( window );

    if (!gladLoadGL(glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //shaders

    // Vertex Shader
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
    glCompileShader(vertexShader);

    int success; 
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    
    // Verificacion de compilacion exitosa del vertex shader
    
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Fragment Shader
    
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    // Verificacion de compilacion exitosa del fragment shader
    
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    };

    // Se unen los shaders en un solo programa

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram,vertexShader);
    glAttachShader(shaderProgram,fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    };

    // No se necesitan, se pueden borrar
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Se crean los vértices del triángulo
    // La sintaxis es ver.x, ver.y, ver.z, r, g, b
    // Buildeo del vertice y de los buffer
    float vertices[] = {
        // x y z r g b
        0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom right
       -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // bottom left
        0.0f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f  // top
    };

    // Creación del vertex array object y del vertex buffer object
    // Estsos se encargaran de leer el arreglo de vertices 
    // para convertirlos y pasarlos a los shaders
    unsigned int VBO;
    unsigned int VAO;
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 6*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    


    glUseProgram(shaderProgram);

    while(!glfwWindowShouldClose(window)){
        processInput(window);
        
        // Creación del fondo
        
        glClearColor(0.09f,0.12f,0.23f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Creacion del vertex buffer object    
        glBindVertexArray(VAO);
        
        // Se dibuja el triángulo
        glDrawArrays(GL_TRIANGLES,0,3);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }

    // Se eliminan los objetos
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    glDeleteProgram(shaderProgram);

    // Terminación del programa
    glfwTerminate();
    return 0;
}
