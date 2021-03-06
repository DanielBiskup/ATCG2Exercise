//
// Created by alex on 17.11.20.
//

#ifndef BCG_GRAPHICS_BCG_MATERIAL_H
#define BCG_GRAPHICS_BCG_MATERIAL_H

#include <vector>
#include "bcg_attribute.h"
#include "bcg_opengl.h"

namespace bcg{

struct material{
    std::vector<attribute> attributes;
    std::vector<ogl_texture> textures;

    ogl_vertex_array vao;
    size_t num_elements;

    virtual void upload(const glsl_program &program){
        for(auto &texture : textures){
            texture.activate();
        }
    }
};

}

#endif //BCG_GRAPHICS_BCG_MATERIAL_H
