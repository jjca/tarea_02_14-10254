# Jorge Correia - 14-10254 - Three.js

Se inicializaron los parámetros básicos y fundamentales para mostrar en Three.js, los cuales son:

- Escena
- Renderizador: es el encargado de renderizar la escena de acuerdo a la cámara definida. El renderizador utilizado fue WebGL.
- Cámara

# Ambiente de desarrollo y ejecución

Se desarrolló bajo Windows 10.

Para la ejecución se requiere un servidor web básico, por ejemplo, `npx serve` o el módulo `http.server` de Python. El servidor web usado no requiere ninguna otra dependencia.

Si se ejecuta con `http.server` de Python:

```
pip install -m http.server
py -m http.server # Ejecutar este comando en el directorio donde esté el index.html
```

Posteriormente, abrir el navegador y acceder a la URL `localhost:8000`

Si se quiere usar otro servidor web, puede consultarse la [documentación de Three.js](https://threejs.org/docs/index.html#manual/en/introduction/Installation)

Las dependencias vienen incluidas en el directorio `deps` donde se encuentra minificada la librería `three.js`.

Se siguió como referencia el video de Huse360 - https://www.youtube.com/watch?v=ueYdSVOmnmg