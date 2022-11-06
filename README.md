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

<details>
<summary>Click</summary>

### Graphics Pipeline

- Application : 그리고 싶은 정점의 위치 / 색상 등을 입력 (make tri)
- Geometry Processing : 정점 단위의 처리. 정점의 위치 결정 (projection)
- Rasterization : 정점 단위로 구성된 삼각형을 픽셀 단위로 변경 (projection to pixel)
- Pixel Processing : 픽셀 단위의 처리. 픽셀 색상의 결정 (pixel to screen)


        Application : 애플리케이션 프로그램 영역. OpenGL 함수 호출
        Geometry, Rasterization, Pixel : GPU 영역

### Programmable Shader
- Shader : 각 파이프라인 단계마다 GPU상에서 실행 되는 작은 프로그램
- GLSL(GL Shading Language)라는 C기반 프로그래밍 언어로 작성

 VERTAX DATA[] -> VERTEX SHADER -> SHAPE ASSEMBLE -> GEOMETRY SHADER -> RSTERIZATION -> FRAGMENT SHADER -> TEST AND BLENDING

### OPENGL SHADER

- OpenGL은 그림을 그려내기 위해 두 개의 SHADER가 반드시 필요
    - Vertex Shader
    - Fragment Shader
- Shader 코드는 OpenGL 코드 내에서 빌드 / 로딩됨
- 미리 빌드한 뒤 로딩하는 방법 : SPIR-V 이용
    - 이번 수업에서는 다루지 않을 예정

### SHADER CODE LOADING
- 임의의 shader 파일을 읽는다
- shader 오브젝트를 만들고 shader 읽어들인 shader 코드를 세팅한다
- shader를 컴파일한다
- shader 컴파일 결과가 실패했다면 에러를 레포팅한다


### TEXT FILE LOADING
- optional<>
    - C++17부터 사용 가능한 표준 라이브러리
    - 어떤 값이 있거나 없는 경우를 포인터 없이 표현 가능

```C++
#include "common.h"
#include <fstream>
#include <sstream>

std::optional<std::string> LoadTextFile(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        SPDLOG_ERROR("failed to open file: {}", filename);
        return {};
    }
    std::stringstream text;
    text << fin.rdbuf();
    return text.str();
}
```
### SHADER CLASS DESIGN

- Shader 클래스 설계
    - OpenGL shader object를 가지고 있다
    - 인스턴스가 생성될 때 로딩할 파일명을 받자
    - 입력된 파일명으로부터 인스턴스 생성이 실패하면 메모리할당 해제
    - C++11 smart pointer 활용

</details>

## 03-02: 스마트 포인터와 클래스 디자인

<details>
<summary>Click</summary>

### Smart Pointer

- Smart Pointer
    - C++11 부터 사용 가능한 좀 더 안전한 포인터
    - 메모리 할당을 받을 때 소유권에 대한 정보가 있다
    - 명시적인 delete 구문이 필요없다
    - std::unique_ptr<>: 해당 메모리 블록을 단독으로 소유
    - std::shared_ptr<>: 해당 메모리 블록의 소유권을 공유
    - std::weak_ptr<>: 해당 메모리 소유권은 없지만 접근은 가능


- 일반 포인터를 이용하는 경우: 메모리를 두번 해제하면 문제 발생
```C++
{
  int* a = new int;
  int* b = a;

  // ...

  delete a;
  delete b; // 두 번 메모리를 해제하여 문제 발생
}
```

- unique_ptr<>를 사용하는 경우: 소유권을 가진 인스턴스가 스코프 밖으로 벗어났을때 메모리 자동 해제
```C++
{
  std::unique_ptr<int> a = std::make_unique();
  int* b = a.get();

  // ...
}

```

- unique_ptr<>를 사용하는 경우: 소유권을 가진 인스턴스가 일반적인 방법으로 다른 쪽에 소유권을 이전하려는 경우 에러 발생
```C++
{
  // 컴파일 에러 > 런타임 에러 -> 실수 막아줌
  std::unique_ptr<int> a = std::make_unique();
  std::unique_ptr<int> b = a; // error 발생

  // ...
}
```

- unique_ptr<>를 사용하는 경우: std::move() 함수를 사용해서 명시적으로 소유권 이전 가능. 대신 이전에 소유권을 가진 인스턴스는 nullptr를 갖게됨
```C++
{
  std::unique_ptr<int> a = std::make_unique();
  std::unique_ptr<int> b = std::move(a); // 이후 a는 null pointer

  // a는 nullptr가 되어 더이상 사용 불가능
}
```

### Shader 클래스 설계

- src/common.h에 다음 매크로를 추가
    - std::unique_ptr 대신 클래스이름UPtr 사용
```C++
#define CLASS_PTR(klassName) \
class klassName; \
using klassName ## UPtr = std::unique_ptr<klassName>; \
using klassName ## Ptr = std::shared_ptr<klassName>; \
using klassName ## WPtr = std::weak_ptr<klassName>;
```

- src/shader.h 생성
```C++
#ifndef __SHADER_H__
#define __SHADER_H__

#include "common.h"

CLASS_PTR(Shader);
class Shader {
public:
    static ShaderUPtr CreateFromFile(const std::string& filename,GLenum shaderType);
    
    ~Shader();
    uint32_t Get() const { return m_shader; }    
private:
    Shader() {}
    bool LoadFile(const std::string& filename, GLenum shaderType);
    uint32_t m_shader { 0 };
};

#endif // __SHADER_H__
```

- 이렇게 설계된 이유
    - 생성자가 private인 이유: CreateFromFile() 함수 외에 다른 방식의 Shader 인스턴스 생성을 막기 위해서
    - Get()은 있는데 Set()는 없는 이유: shader 오브젝트의 생성 관리는 Shader 내부에서만 관리
    - LoadFile()이 bool을 리턴하는 이유: 생성에 실패할 경우 false를 리턴하기 위해서

### Shader 클래스 구현

- src/shader.cpp
- CreateFromFile() 구현
```C++
#include "shader.h"

ShaderUPtr Shader::CreateFromFile(const std::string& filename, GLenum shaderType) {
    auto shader = ShaderUPtr(new Shader());
    if (!shader->LoadFile(filename, shaderType))
        return nullptr;
    return std::move(shader);
}
```


- 소멸자 ~Shader 구현
    - m_shader는 처음에 0으로 초기화
    - m_shader에 0이 아닌 다른 값이 들어가 있다면 glDeleteShader()를 호출하여 shader object 제거

```C++
Shader::~Shader() {
  if (m_shader) {
    glDeleteShader(m_shader);
  }
}
```

- LoadFile() 구현
    - 파일 로딩 실패시 false 리턴
    - 성공시 로딩된 텍스트 포인터 및 길이 가져오기
    - glCreateShader()를 이용한 shader 오브젝트 생성
    - glShaderSource()로 소스코드 입력
    - glCompileShader()로 shader 컴파일
    - glGetShaderiv()로 컴파일 상태 조회
    - 만약에 성공이 아니라면 glGetShaderInfoLog()로 에러 로그 가져오기
```C++
bool Shader::LoadFile(const std::string& filename, GLenum shaderType) {
    auto result = LoadTextFile(filename);
    if (!result.has_value())
        return false;

    auto& code = result.value();
    const char* codePtr = code.c_str();
    int32_t codeLength = (int32_t)code.length();

    // create and compile shader
    m_shader = glCreateShader(shaderType);
    glShaderSource(m_shader, 1, (const GLchar* const*)&codePtr, &codeLength);
    glCompileShader(m_shader);

      // check compile error
    int success = 0;
    glGetShaderiv(m_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[1024];
        glGetShaderInfoLog(m_shader, 1024, nullptr, infoLog);
        SPDLOG_ERROR("failed to compile shader: \"{}\"", filename);
        SPDLOG_ERROR("reason: {}", infoLog);
        return false;
    }
    return true;
}
```

### Shader 클래스 테스트

- Shader 클래스 생성 및 shader 코드 컴파일 테스트
- src/main.cpp에서 GLAD 초기화 이후 아래 코드를 추가하여 테스트

```C++
auto vertexShader = Shader::CreateFromFile("./shader/simple.vs", GL_VERTEX_SHADER);
auto fragmentShader = Shader::CreateFromFile("./shader/simple.fs", GL_FRAGMENT_SHADER);
SPDLOG_INFO("vertex shader id: {}", vertexShader->Get());
SPDLOG_INFO("fragment shader id: {}", fragmentShader->Get());
```

### VSCODE GLSL EXTENSION

- Extension 탭에서 shader로 검색
- Shader languages support for VS Code 설치
    - glsl 코드 syntax highlight

### VERTEX SHADER CODE
- 가장 단순한 vertex shader 작성
- shader/simple.vs

```C++
#version 330 core
layout (location = 0) in vec3 aPos;

void main() {
  gl_Position = vec4(0.0, 0.0, 0.0, 1.0);
}
```

### FRAGMENT SHADER CODE
- 가장 단순한 fragment shader 작성
- shader/simple.fs

```C++
#version 330 core
out vec4 fragColor;

void main() {
  fragColor = vec4(1.0, 0.0, 0.0, 1.0);
}
```

### 빌드 세팅
- CMakeLists.txt에 방금 작성한 파일들을 추가

```text
add_executable(${PROJECT_NAME}
  src/main.cpp
  src/common.cpp src/common.h
  src/shader.cpp src/shader.h
  )
```


### OpenGL Remarks

- glCreateShader(): OpenGL shader object 생성
- glShaderSource(): shader에 소스 코드 설정
- glCompileShader(): shader 컴파일

- glGetShaderiv(): shader에 대한 정수형 정보를 얻어옴
- glGetShaderInfoLog(): shader에 대한 로그를 얻어옴. 컴파일 에러 얻어내는 용도로 사용
- glDeleteShader(): shader object 제거


</details>

## 03-03 Program과 화면에 점찍기

<details>
<summary>Click</summary>

### PROGRAM CLASS DESIGN

- Program 클래스 설계
    - vertex shader, fragment shader를 연결한 pipeline program
    - 이 program을 이용해서 최종적으로 그림을 그린다
    - 두 개의 shader를 입력 받아서 program을 링크시킨다 -> 함수
    - 싱크에 성공하면 OpenGL program object를 생성
    - 실패하면 메모리 할당 해제

```C++

#ifndef __PROGRAM_H__
#define __PROGRAM_H__

#include "common.h"
#include "shader.h"

CLASS_PTR(Program)
class Program {
public:
    static ProgramUPtr Create(
        const std::vector<ShaderPtr>& shaders);

    ~Program();
    uint32_t Get() const { return m_program; }    
private:
    Program() {}
    bool Link(
        const std::vector<ShaderPtr>& shaders);
    uint32_t m_program { 0 };
};

#endif // __PROGRAM_H__
```


- 이렇게 설계된 이유
    - vertex, fragment shader 외에 여러 개의 Shader를 링크할 수도 있게 함
    - Shader 인스턴스 인자는 필요하지만 소유할 필요는 없음
    - Shader 인스턴스는 다른 Program 인스턴스를 만드는 데 재사용할 수도 있음
    - 따라서 shared pointer를 사용: ShaderPtr

### Program 클래스 구현

```C++
#include "program.h"

ProgramUPtr Program::Create(
  const std::vector<ShaderPtr>& shaders) {
  auto program = ProgramUPtr(new Program());
  if (!program->Link(shaders))
    return nullptr;
  return std::move(program);
}

Program::~Program() {
  if (m_program) {
    glDeleteProgram(m_program);
  }
}
```

- Link() 구현
    - glCreateProgram()으로 새로운 OpenGL program object 생성
    - glAttachShader()로 program에 shader를 붙이기
    - glLinkProgram()으로 program 링크
    - glGetProgramiv()로 프로그램 링크 상태 확인
    - 링크에 실패했다면 glGetProgramInfoLog()로 에러 로그 가져오기

```C++
bool Program::Link(
  const std::vector<ShaderPtr>& shaders) {
  m_program = glCreateProgram();
  for (auto& shader: shaders)
      glAttachShader(m_program, shader->Get());
  glLinkProgram(m_program);

  int success = 0;
  glGetProgramiv(m_program, GL_LINK_STATUS, &success);
  if (!success) {
      char infoLog[1024];
      glGetProgramInfoLog(m_program, 1024, nullptr, infoLog);
      SPDLOG_ERROR("failed to link program: {}", infoLog);
      return false;
  }
  return true;
}
```

### Program 클래스 테스트

- src/main.cpp에 program.h 포함
- src/main.cpp에서 Shader 인스턴스 생성 후 Program 인스턴스 생성
    - Shader 인스턴스가 unique_ptr에서 shared_ptr로 변환되었음을 유의

```C++
ShaderPtr vertShader = Shader::CreateFromFile("./shader/simple.vs", GL_VERTEX_SHADER);
ShaderPtr fragShader = Shader::CreateFromFile("./shader/simple.fs", GL_FRAGMENT_SHADER);
SPDLOG_INFO("vertex shader id: {}", vertShader->Get());
SPDLOG_INFO("fragment shader id: {}", fragShader->Get());

auto program = Program::Create({fragShader, vertShader});
SPDLOG_INFO("program id: {}", program->Get());
```

### OPENGL REMARKS

- glCreateProgram(): OpenGL program object 생성
- glAttachShader(): program에 shader를 붙이기
- glLinkProgram(): program 링크
- glGetProgramiv(): program에 대한 정수형 정보를 얻어옴
- glGetProgramInfoLog(): program에 대한 로그를 얻어옴. 링크 에러 얻어내는 용도로 사용
- glDeleteProgram(): program object 제거

### 리팩토링

- 프로그램 라이프사이클을 고려하여 코드 리팩토링
    - GLFW / OpenGL Context / GLAD 초기화
    - 그림을 그리기 위한 OpenGL objects 생성 (shader / program)
    - 렌더링
    - OpenGL objects 제거
    - GLFW 종료 / 프로그램 종료
- OpenGL object 들을 관리하고 렌더링하는 코드를 분리하자

### Context 클래스 디자인

- src/context.h에 Context 클래스 선언
```C++
#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include "common.h"
#include "shader.h"
#include "program.h"

CLASS_PTR(Context)
class Context {
public:
    static ContextUPtr Create();
    void Render();    
private:
    Context() {}
    bool Init();
    ProgramUPtr m_program;
};

#endif // __CONTEXT_H__
```

### Context 클래스 구현

- src/context.cpp 생성

```C++
#include "context.h"

ContextUPtr Context::Create() {
  auto context = ContextUPtr(new Context());
  if (!context->Init())
    return nullptr;
  return std::move(context);
}

bool Context::Init() {
    ShaderPtr vertShader = Shader::CreateFromFile("./shader/simple.vs", GL_VERTEX_SHADER);
    ShaderPtr fragShader = Shader::CreateFromFile("./shader/simple.fs", GL_FRAGMENT_SHADER);
    if (!vertShader || !fragShader)
        return false;
    SPDLOG_INFO("vertex shader id: {}", vertShader->Get());
    SPDLOG_INFO("fragment shader id: {}", fragShader->Get());
    m_program = Program::Create({fragShader, vertShader});
    if (!m_program)
        return false;
    SPDLOG_INFO("program id: {}", m_program->Get());

    glClearColor(0.1f, 0.2f, 0.3f, 0.0f);
    return true;
}

void Context::Render() {
  glClear(GL_COLOR_BUFFER_BIT);
}
```

</details>


## 03-04 삼각형 그리기

<details>
<summary>Click</summary>


### 정점 그리기
- 정점을 3개 입력하여 삼각형을 그려보자
    - 정점 데이터 준비
    - Vertex buffer object (VBO) 준비
    - Vertex buffer object에 정점 데이터 입력
        - CPU memory 상에 있는 정점 데이터를 GPU로 옮기는 작업
    - Vertex array object (VAO) 준비
        - 우리의 정점 데이터의 구조를 알려주는 descriptor object
    - Program, VBO, VAO를 사용하여 그림 그리기


</details>