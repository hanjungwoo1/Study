


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

