#ifndef TYPES_HPP
#define TYPES_HPP

#include <stdexcept>
using RuntimeError = std::runtime_error;

#include <string>
using String = std::string;

#include <vector>
template<typename T> using List = std::vector<T>;

#include <glm/glm.hpp>
using Vector2i = glm::ivec2;
using Vector2f = glm::fvec2;
using Vector3f = glm::fvec3;
using Color3f = glm::fvec3;

#endif // TYPES_HPP
