import * as THREE from './deps/three.module.min.js';

// Definiciones de los elementos básicos
// Escena
const scene = new THREE.Scene();
scene.background = new THREE.Color( 0x19203C);
// Relación de aspecto para el tamaño de la cámara
const aspect = window.innerWidth / window.innerHeight;
// Renderizador
const renderer = new THREE.WebGLRenderer();
renderer.setSize( window.innerWidth, window.innerHeight );
// Cámara
const camera = new THREE.PerspectiveCamera( 45, aspect, 1, 1000); 
scene.add(camera)

// Se une el renderer al cuerpo de la página
document.body.appendChild( renderer.domElement );

// Creación de los objetos básicos para el triángulo
const geometry = new THREE.BufferGeometry();

// Definición de un arreglo de flotantes para los puntos
const vertices = new Float32Array ([
    -0.5,0,0,
    0.5,0,0,
    0,Math.sqrt(0.5),0
]);

// Se añade el atributo al objeto geometry
geometry.setAttribute('position', new THREE.BufferAttribute(vertices, 3));


// Array de colores con los colores G,B,R
var colors = new Uint8Array([
    0,255,0,
    0,0,255,
    255,0,0
]);

// Se añade el atributo de colores al geometry
geometry.setAttribute('color', new THREE.BufferAttribute(colors,3, true));


// Se especifica que el material será un MeshBasicMaterial y tiene el siguiente objeto
// con sus propiedades
var material = new THREE.MeshBasicMaterial({
    color: 0xffffff, vertexColors: colors
})

// Se crea el Mesh 
var triangulo = new THREE.Mesh(geometry, material);

// Se añade el triángulo a la escena
scene.add(triangulo);

// Ajustes en la posición de la cámara de forma vertical y de altura
camera.position.z = 2
camera.position.y = 0.25

// Renderiza la escena
renderer.render(scene,camera);