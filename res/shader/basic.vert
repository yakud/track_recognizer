#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout (location = 1) in vec4 color;

uniform mat4 MVP = mat4(1);

out vec4 vertexColor;

void main()
{
    gl_Position = MVP * vec4(vertexPosition_modelspace, 1.0);
    vertexColor = color;
}