#pragma once
#include <glm/glm.hpp>
#include "shaders/shader.h"
#include <vector>
#include <string>


struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture{
    unsigned int id;
    string type;
    string path;
};

class Mesh {
    public:
        //mesh data
        vector<Vertex> vertices;
        vector<unsigned int> indices;
        vector<Texture>  textures;

        Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
        void Draw(Shader &shader);

    private:
        //render data
        unsigned int VAO, VBO, EBO;
        void setupMesh();
};