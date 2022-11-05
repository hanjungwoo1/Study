#ifndef __COMMON_H__
#define __COMMON_H__

#include <memory>
#include <string>
#include <optional>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <spdlog/spdlog.h>


// std::optional<std::string> -> 값이 있든 없든 사용가능하게 -> 동적 할당 Free에 대해 자유로움
std::optional<std::string> LoadTextFile(const std::string& filename);

#endif // __COMMON_H__