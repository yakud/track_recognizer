//
// Created by yakud on 2019-02-11.
//

#include "mesh_loader.h"

using namespace engine::primitive;

std::tuple<Mesh *, std::optional<engine::Error>> MeshLoader::LoadObj(std::string path) {
    // Initialize Loader
    objl::Loader Loader;

    // LoadObj .obj File
    bool loadout = Loader.LoadFile(std::move(path));

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

            return {mesh, std::nullopt};
        }
    }

    auto err = engine::Error(1, "Failed to LoadObj File. May have failed to find it or it was not an .obj file.");

    return {nullptr, err};
}
