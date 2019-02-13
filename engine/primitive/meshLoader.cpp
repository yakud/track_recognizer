//
// Created by yakud on 2019-02-11.
//

/*for (int i = 0; i < Loader.LoadedMeshes.size(); i++)
{
   // Copy one of the loaded meshes to be our current mesh
   objl::Mesh curMesh = Loader.LoadedMeshes[i];

   // Print Mesh Name
   std::cout << "Mesh " << i << ": " << curMesh.MeshName << "\n";

   // Print Vertices
   std::cout << "Vertices:\n";

   // Go through each vertex and print its number,
   //  position, normal, and texture coordinate
   for (int j = 0; j < curMesh.Vertices.size(); j++) {
       std::cout << "V" << j << ": " <<
                 "P(" << curMesh.Vertices[j].Position.X << ", " << curMesh.Vertices[j].Position.Y << ", " << curMesh.Vertices[j].Position.Z << ") " <<
                 "N(" << curMesh.Vertices[j].Normal.X << ", " << curMesh.Vertices[j].Normal.Y << ", " << curMesh.Vertices[j].Normal.Z << ") " <<
                 "TC(" << curMesh.Vertices[j].TextureCoordinate.X << ", " << curMesh.Vertices[j].TextureCoordinate.Y << ")\n";
   }

   // Print Indices
   std::cout << "Indices:\n";

   // Go through every 3rd index and print the
   //	triangle that these indices represent
   for (int j = 0; j < curMesh.Indices.size(); j += 3) {
       std::cout << "T" << j / 3 << ": " << curMesh.Indices[j] << ", " << curMesh.Indices[j + 1] << ", " << curMesh.Indices[j + 2] << "\n";
   }

   // Print Material
   std::cout << "Material: " << curMesh.MeshMaterial.name << "\n";
   std::cout << "Ambient Color: " << curMesh.MeshMaterial.Ka.X << ", " << curMesh.MeshMaterial.Ka.Y << ", " << curMesh.MeshMaterial.Ka.Z << "\n";
   std::cout << "Diffuse Color: " << curMesh.MeshMaterial.Kd.X << ", " << curMesh.MeshMaterial.Kd.Y << ", " << curMesh.MeshMaterial.Kd.Z << "\n";
   std::cout << "Specular Color: " << curMesh.MeshMaterial.Ks.X << ", " << curMesh.MeshMaterial.Ks.Y << ", " << curMesh.MeshMaterial.Ks.Z << "\n";
   std::cout << "Specular Exponent: " << curMesh.MeshMaterial.Ns << "\n";
   std::cout << "Optical Density: " << curMesh.MeshMaterial.Ni << "\n";
   std::cout << "Dissolve: " << curMesh.MeshMaterial.d << "\n";
   std::cout << "Illumination: " << curMesh.MeshMaterial.illum << "\n";
   std::cout << "Ambient Texture Map: " << curMesh.MeshMaterial.map_Ka << "\n";
   std::cout << "Diffuse Texture Map: " << curMesh.MeshMaterial.map_Kd << "\n";
   std::cout << "Specular Texture Map: " << curMesh.MeshMaterial.map_Ks << "\n";
   std::cout << "Alpha Texture Map: " << curMesh.MeshMaterial.map_d << "\n";
   std::cout << "Bump Map: " << curMesh.MeshMaterial.map_bump << "\n";

   // Leave a space to separate from the next mesh
   std::cout << "\n";
}*/

#include "meshLoader.h"

using namespace engine::primitive;

std::tuple<Mesh *, engine::Error *> MeshLoader::LoadObj(std::string path) {
    // Initialize Loader
    objl::Loader Loader;

    // LoadObj .obj File
    bool loadout = Loader.LoadFile(std::move(path));

    auto err = new engine::Error(0, "");

    if (loadout) {
        for (auto curMesh : Loader.LoadedMeshes) {
            auto mesh = new Mesh();

            for (auto vert : curMesh.Vertices) {
                mesh->positions.emplace_back(vert.Position.X, vert.Position.Y, vert.Position.Z);
                mesh->normals.emplace_back(vert.Normal.X, vert.Normal.Y, vert.Normal.Z);
                mesh->uv.emplace_back(vert.TextureCoordinate.X, vert.TextureCoordinate.Y);

                // @TODO:
                mesh->colors.emplace_back(vert.Position.X + 0.1f, vert.Position.Y + 0.1f, vert.Position.Z + 0.1f, 1.0f);
            }

            for (int j = 0; j < curMesh.Indices.size(); j += 3) {
                mesh->indices.emplace_back(curMesh.Indices[j], curMesh.Indices[j + 1], curMesh.Indices[j + 2]);
            }

            return {mesh, err};
        }
    } else {
        err = new engine::Error(1, "Failed to LoadObj File. May have failed to find it or it was not an .obj file.");
    }

    return {nullptr, err};
}
