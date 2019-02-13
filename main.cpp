#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
//#include <SOIL.h>

// Include all GLM core / GLSL features
#include <glm/glm.hpp> // vec2, vec3, mat4, radians

// Include all GLM extensions
#include <glm/ext.hpp> // perspective, translate, rotate

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stdio.h>
#include <chrono>

#include <primitive/mesh_loader.h>
#include <shader/shader.h>
#include <shader/basic_shader.h>
#include <primitive/model.h>
#include <primitive/camera.h>

using namespace engine;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main()
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", nullptr, nullptr); // Windowed
    if (!window) {
        glfwTerminate();
        return -1;

    }
    glfwMakeContextCurrent(window);

    // GLEW init
    glewExperimental = GL_TRUE;
    glewInit();

    /* Create basic shader */
    auto shaderLoader = new shader::Loader();
    auto compiler = new shader::Compiler();
    auto basicShader = new shader::Shader(shaderLoader, compiler);

    if (auto err = InitBasicShader(basicShader); err) {
        printf("%s", err->Message.c_str());
        glfwTerminate();
    }

    /* Load mesh */
    auto meshLoader = new primitive::MeshLoader();
    auto [mesh, err] = meshLoader->LoadObj("res/model/monk.obj");
    if (err) {
        printf("%s", err->Message.c_str());
        glfwTerminate();
    };


    /* Create model */
    auto modelMonk = new primitive::Model(mesh, basicShader);
//    auto camera = new primitive::Camera();

//    camera->GetEntity()->translate = glm::translate(camera->GetEntity()->translate, glm::vec3(5,0,0));
//    camera->LookAt(modelMonk->GetEntity()->GetTranslation());
//    camera->GetEntity()->UpdateMatrix();
//
//    modelMonk->UpdateMVP(camera);

    /* Triangle */
//    auto triangle = new primitive::Triangle();
//    triangle->Init();
//    glm::mat4 trans;
//    trans = glm::rotate(trans, 90.0f, glm::vec3(0.0, 0.0, 1.0));
//    trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
//
//    GLint transformLoc = glGetUniformLocation(basicShader->Program(), "transform");
//    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

//    glBindFragDataLocation(basicShader->Program(), 0, "color");
//    GLint posAttrib = glGetAttribLocation(basicShader->Program(), "position");
//    glEnableVertexAttribArray(posAttrib);
//    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE,
//                          5*sizeof(float), 0);
//
//    GLint colAttrib = glGetAttribLocation(basicShader->Program(), "color");
//    glEnableVertexAttribArray(colAttrib);
//    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE,
//                          5*sizeof(float), (void*)(2*sizeof(float)));
//
//    GLint uniColor = glGetUniformLocation(basicShader->Program(), "triangleColor");
//    auto t_start = std::chrono::high_resolution_clock::now();
//    GLuint location = glGetUniformLocation(basicShader->Program(), "transform");

//    GLuint MatrixID = glGetUniformLocation(basicShader->Program(), "MVP");

    // Проекционная матрица : 45&deg; поле обзора, 4:3 соотношение сторон, диапазон : 0.1 юнит <-> 100 юнитов
//    glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
//    glm::mat4 Projection = glm::ortho(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);

    // Или, для ортокамеры
//    glm::mat4 View       = glm::lookAt(
//            glm::vec3(5,0,0), // Камера находится в мировых координатах (4,3,3)
//            glm::vec3(0,0,0), // И направлена в начало координат
//            glm::vec3(0,1,0)  // "Голова" находится сверху
//    );

    // Матрица модели : единичная матрица (Модель находится в начале координат)
//    glm::mat4 Model = glm::mat4(1.0f);  // Индивидуально для каждой модели
//    Model = glm::scale(Model, glm::vec3(1.0f, 1.0f, 1.0f));
//    Model = glm::rotate(Model, 1.0f, glm::vec3(1.0f, 0.0f, 0.0f));

    // Итоговая матрица ModelViewProjection, которая является результатом перемножения наших трех матриц
//    glm::mat4 MVP = Projection * View * Model; // Помните, что умножение матрицы производиться в обратном порядке

    // Включить тест глубины
    glEnable(GL_DEPTH_TEST);

    // Фрагмент будет выводиться только в том, случае, если он находится ближе к камере, чем предыдущий
    glDepthFunc(GL_LESS);

    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        modelMonk->Draw();

//        glm::mat4 m = glm::mat4(1);
//        m = glm::scale(m, glm::vec3(0.3f, 0.3f, 0.3f));
//        m = glm::translate(m, glm::vec3(sin((GLfloat)glfwGetTime() * 5) / 2, cos((GLfloat)glfwGetTime() * 5) / 2, 0.0f));
//        m = glm::rotate(m, (GLfloat)glfwGetTime() * 0.5f, glm::vec3(1.0f, 1.0f, 1.0f));

//        RotationMatrix = glm::rotate(RotationMatrix,(GLfloat)glfwGetTime() * 2.0f, glm::vec3(0.5f, 1.0f, 0.3f));

//        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
//        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(m));

//        basicShader->Use();
//        triangle->Draw();

//        auto t_now = std::chrono::high_resolution_clock::now();
//        float time = std::chrono::duration_cast<std::chrono::duration<float>>(t_now - t_start).count();
//
//        glUniform3f(
//                uniColor,
//                (sin(time * 4.0f) + 1.0f) / 2.0f,
//                (cos(time * 3.0f) + 1.0f) / 3.0f,
//                (cos(time * 2.0f) + 1.0f) / 3.0f
//        );

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteProgram(basicShader->Program());

//    glDeleteBuffers(1, &vbo);
//
//    glDeleteVertexArrays(1, &vao);

    glfwTerminate();
    return 0;


    /////////////////////////////////////////////////////////////////////////////////

//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    /* Create a windowed mode window and its OpenGL context */
//    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//    if (!window)
//    {
//        glfwTerminate();
//        return -1;
//    }
//
//    glfwSetKeyCallback(window, key_callback);
//
//    /* Make the window's context current */
//    glfwMakeContextCurrent(window);
//
//    /* Loop until the user closes the window */
//    while (!glfwWindowShouldClose(window))
//    {
//        /* Render here */
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        /* Swap front and back buffers */
//        glfwSwapBuffers(window);
//
//        /* Poll for and process events */
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
//    return 0;
}