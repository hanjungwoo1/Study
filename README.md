


## 01-02 개발 환경

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

## 02-01 Cmake dependency

### CMAKE를 이용한 외부라이브러리 사용하기(1)


```cmake
// CMakeLists.txt에 다음을 추가 (1)
# ExternalProject 관련 명령어 셋 추가
include(ExternalProject)       

# Dependecy 관련 변수 설정
set(DEP_INSTALL_DIR ${PROJECT_BINARY_DIR}/install)
set(DEP_INCLUDE_DIR ${DEP_INSTALL_DIR}/include)
set(DEP_LIB_DIR ${DEP_INSTALL_DIR}/lib)
```

### CMAKE를 이용한 외부라이브러리 사용하기(2)

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

### CMAKE를 이용한 외부라이브러리 사용하기(3)

```cmake
// CMakeLists.txt에 다음을 추가 (3)
# 우리 프로젝트에 include / lib 관련 옵션 추가
target_include_directories(${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${DEP_LIBS})

# Dependency들이 먼저 build 될 수 있게 관계 설정
add_dependencies(${PROJECT_NAME} ${DEP_LIST})
```
