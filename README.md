# OpenGL

for 3D Vision

## 01-02 개발 환경

<details>
<summary>Click</summary>


### CMAKE의 작동 방식
- Meta-project description
    - 각 플랫폼 / 선호하는 빌드 방식에 맞는 프로젝트 파일을 생성
    - windows의 경우 visual studio project
    - Linux의 경우 Makefile
    - macOS의 경우 XCode / Makefile
    - Android의 경우 Ninja build
    - 기타 등등 ..

```cmake
// connfigure
cmake -Bbuild . -DCMAKE_BUILD_TYPE=[Debug|Release]

cmake --build build --config Debug

// 귀찮다 -> VSCODE + CMAKE 커맨드 사용

// F7 -> Build
// Ctrl + F5 -> Debug 
```

</details>


## 02-01 Cmake dependency

<details>
<summary>Click</summary>

### CMAKE를 이용한 외부라이브러리 사용하기


```cmake
// CMakeLists.txt에 다음을 추가 (1)
# ExternalProject 관련 명령어 셋 추가
include(ExternalProject)       

# Dependecy 관련 변수 설정
set(DEP_INSTALL_DIR ${PROJECT_BINARY_DIR}/install)
set(DEP_INCLUDE_DIR ${DEP_INSTALL_DIR}/include)
set(DEP_LIB_DIR ${DEP_INSTALL_DIR}/lib)
```


```cmake
// CMakeLists.txt에 다음을 추가 (2)
# spdlog: fast logger library
ExternalProject_Add(
    dep-spdlog
    GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
    GIT_TAG "v1.x"
    GIT_SHALLOW 1
    UPDATE_COMMAND ""
    PATCH_COMMAND ""
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
    TEST_COMMAND ""
)
# Dependency 리스트 및 라이브러리 파일 리스트 추가
set(DEP_LIST ${DEP_LIST} dep-spdlog)
set(DEP_LIBS ${DEP_LIBS} spdlog$<$<CONFIG:Debug>:d>)
```


```cmake
// CMakeLists.txt에 다음을 추가 (3)
# 우리 프로젝트에 include / lib 관련 옵션 추가
target_include_directories(${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${DEP_LIBS})

# Dependency들이 먼저 build 될 수 있게 관계 설정
add_dependencies(${PROJECT_NAME} ${DEP_LIST})
```

</details>

## 02-02 CMake dependecy - GLFW

<details>
<summary>Click</summary>


### GLFW DEPENDENCY 추가하기(1)
- OpenGL은 3D그래픽을 위한 API일 뿐
- 화면에 그림을 그리기 위해서는 다음과 같은 작업이 추가적으로 필요함
    - 윈도우 생성하기
    - 윈도우에 OpenGL을 위한 surface 생성하고 연결하기
    - 키보드 / 마우스 입력 연결하기

- GLFW
    - Open-source, cross-platform library for
        - creating windows, contexts, and surfaces
        - receving input and events


```
# glfw
ExternalProject_Add(
    dep_glfw
    GIT_REPOSITORY "https://github.com/glfw/glfw.git"
    GIT_TAG "3.3.2"
    GIT_SHALLOW 1
    UPDATE_COMMAND "" PATCH_COMMAND "" TEST_COMMAND ""
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
        -DGLFW_BUILD_EXAMPLES=OFF
        -DGLFW_BUILD_TESTS=OFF
        -DGLFW_BUILD_DOCS=OFF
    )
set(DEP_LIST ${DEP_LIST} dep_glfw)
set(DEP_LIBS ${DEP_LIBS} glfw3)
```

### GLFW로 윈도우를 생성하기

```
set(WINDOW_NAME "Hello, OpenGL!")
set(WINDOW_WIDTH 640)
set(WINDOW_HEIGHT 480)
```

```
target_compile_definitions(${PROJECT_NAME} PUBLIC
  WINDOW_NAME="${WINDOW_NAME}"
  WINDOW_WIDTH=${WINDOW_WIDTH}
  WINDOW_HEIGHT=${WINDOW_HEIGHT}
  )
```


```C++
#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>

int main(int argc, const char** argv) {
    // 시작을 알리는 로그
    SPDLOG_INFO("Start program");  // 로그 찍기

    // glfw 라이브러리 초기화, 실패하면 에러 출력후 종료
    SPDLOG_INFO("Initialize glfw");
    if (!glfwInit()) {
        const char* description = nullptr;
        glfwGetError(&description);
        SPDLOG_ERROR("failed to initialize glfw: {}", description);
        return -1;
    }

    // glfw 윈도우 생성, 실패하면 에러 출력후 종료
    SPDLOG_INFO("Create glfw window");
    auto window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME,
      nullptr, nullptr);
    if (!window) {
        SPDLOG_ERROR("failed to create glfw window");
        glfwTerminate();
        return -1;
    }

    // glfw 루프 실행, 윈도우 close 버튼을 누르면 정상 종료
    SPDLOG_INFO("Start main loop");
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
```

</details>

## 02-03: 첫 OpenGL 윈도우

<details>
<summary>Click</summary>

### GLAD DEPENDENCY 추가하기

- GLAD
    - GL/GLES Loader-Generator
        - OpenGL은 spec과 구현체(diver, dll)가 따로 존재
        - OpenGL 함수를 사용하기 전에 해당함수들의 구현체가 어디 있는지 로딩하는 과정이 필요

```
# glad
ExternalProject_Add(
    dep_glad
    GIT_REPOSITORY "https://github.com/Dav1dde/glad"
    GIT_TAG "v0.1.34"
    GIT_SHALLOW 1
    UPDATE_COMMAND ""
    PATCH_COMMAND ""
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
        -DGLAD_INSTALL=ON
    TEST_COMMAND ""
    )
set(DEP_LIST ${DEP_LIST} dep_glad)
set(DEP_LIBS ${DEP_LIBS} glad)
```

```C++
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
```


```C++
#include <glad/glad.h>

glfwMakeContextCurrent(window);


// glad를 활용한 OpenGL 함수 로딩
if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    SPDLOG_ERROR("failed to initialize glad");
    glfwTerminate();
    return -1;
}
auto glVersion = glGetString(GL_VERSION);
SPDLOG_INFO("OpenGL context version: {}", glVersion); // 오류
```


### GLFW CALLBACKS

- GLFW로 생성된 윈도우에 특정 이벤트가 발생했을 때 실행되는 콜백함수 지정
    - 윈도우의 크기가 변경
    - 윈도우에 마우스 입력
    - 윈도우에 키보드 입력
    - 기타 등등..
- glfwXXXXCallback()의 함수 프로토타입을 가지고 있음

- 윈도우의 프레임버퍼 크기가 변경되었을 때 호출하기 위한 콜백 정의
- glViewport():OpenGL이 그림을 그릴 영역 지정

```C++
void OnFramebufferSizeChange(GLFWwindow* window, int width, int height) {
    SPDLOG_INFO("framebuffer size changed: ({} x {})", width, height);
    glViewport(0, 0, width, height);
}
```


```C++
void OnKeyEvent(GLFWwindow* window,
    int key, int scancode, int action, int mods) {
    SPDLOG_INFO("key: {}, scancode: {}, action: {}, mods: {}{}{}",
        key, scancode,
        action == GLFW_PRESS ? "Pressed" :
        action == GLFW_RELEASE ? "Released" :
        action == GLFW_REPEAT ? "Repeat" : "Unknown",
        mods & GLFW_MOD_CONTROL ? "C" : "-",
        mods & GLFW_MOD_SHIFT ? "S" : "-",
        mods & GLFW_MOD_ALT ? "A" : "-");
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
```

```C++
OnFramebufferSizeChange(window, WINDOW_WIDTH, WINDOW_HEIGHT);
```

### 렌더링 코드

```C++
void Render() {
    glClearColor(0.1f, 0.2f, 0.3f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
```


### FRAMEBUFFER SWAP(Double Buffering)

- 화면에 그림을 그리는 과정
    - 프레임버퍼 2개를 준비(front/back)
    - back buffer에 그림 그리기
    - front와 back을 바꿔치기
    - 위의 과정 반복
- 그림이 그려지는 과정이 노출되지 않도록 해줌


### 사용한 함수
- glViewport()
- glClearColor(R,G,B,X);
- glClear()


</details>

## 03-01: 그래픽스 파이프라인


### Graphics Pipeline

- Application : 그리고 싶은 정점의 위치 / 색상 등을 입력 (make tri)
- Geometry Processing : 정점 단위의 처리. 정점의 위치 결정 (projection)
- Rasterization : 정점 단위로 구성된 삼각형을 픽셀 단위로 변경 (projection to pixel)
- Pixel Processing : 픽셀 단위의 처리. 픽셀 색상의 결정 (pixel to screen)

- Application : 애플리케이션 프로그램 영역. OpenGL 함수 호출
- Geometry, Rasterization, Pixel : GPU 영역


### Application


### Geometry Processing