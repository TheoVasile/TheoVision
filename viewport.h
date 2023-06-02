#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "scene.h"

class Viewport {
    public:
        Viewport(Scene *scene);
        void render();

        Scene *scene;
};