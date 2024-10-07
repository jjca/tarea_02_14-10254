# Jorge Correia - 14-10254 - OpenGL

Para realizar esta pregunta se siguió la guía y configuración del libro *Learn OpenGL* - https://learnopengl.com/

# Ambiente de desarrollo y ejecución

Se desarrolló bajo Windows 10.

# Dependencias
- MinGW
- GCC en Windows
- GLFW
- GLAD
- Se requiere que la tarjeta de video posea los drivers más actualizados para poder trabajar con las últimas versiones de OpenGL

Para GLFW se descargaron los binarios y están incluidos en el repositorio. 

# Compilación y ejecución bajo Windows
Se requiere compilar el aplicativo usando el siguiente comando desde el terminal de Windows (Símbolo del Sistema):

```g++ -O2 -g -std=c++17 -I./include "-L./lib" triangle.cpp src/gl.c -lglfw3dll -lopengl32 -o triangle.exe```

Una vez compilado, ejecutar el archivo `triangle.exe`.