# Install script for directory: C:/_Me_GitHub/connogge/build/_deps/assimp-src/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/connogge")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Users/ahmad/MinGW/mingw64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp6.0.2-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/_Me_GitHub/connogge/build/_deps/assimp-build/lib/libassimpd.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/anim.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/aabb.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/ai_assert.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/camera.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/color4.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/color4.inl"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-build/code/../include/assimp/config.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/ColladaMetaData.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/commonMetaData.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/defs.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/cfileio.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/light.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/material.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/material.inl"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/matrix3x3.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/matrix3x3.inl"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/matrix4x4.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/matrix4x4.inl"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/mesh.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/ObjMaterial.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/pbrmaterial.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/GltfMaterial.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/postprocess.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/quaternion.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/quaternion.inl"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/scene.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/metadata.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/texture.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/types.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/vector2.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/vector2.inl"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/vector3.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/vector3.inl"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/version.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/cimport.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/AssertHandler.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/importerdesc.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/Importer.hpp"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/DefaultLogger.hpp"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/ProgressHandler.hpp"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/IOStream.hpp"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/IOSystem.hpp"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/Logger.hpp"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/LogStream.hpp"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/NullLogger.hpp"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/cexport.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/Exporter.hpp"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/DefaultIOStream.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/DefaultIOSystem.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/ZipArchiveIOSystem.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/SceneCombiner.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/fast_atof.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/qnan.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/BaseImporter.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/Hash.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/MemoryIOWrapper.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/ParsingUtils.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/StreamReader.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/StreamWriter.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/StringComparison.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/StringUtils.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/SGSpatialSort.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/GenericProperty.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/SpatialSort.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/SkeletonMeshBuilder.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/SmallVector.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/SmoothingGroups.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/SmoothingGroups.inl"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/StandardShapes.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/RemoveComments.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/Subdivision.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/Vertex.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/LineSplitter.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/TinyFormatter.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/Profiler.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/LogAux.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/Bitmap.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/XMLTools.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/IOStreamBuffer.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/CreateAnimMesh.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/XmlParser.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/BlobIOSystem.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/MathFunctions.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/Exceptional.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/ByteSwapper.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/Base64.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/Compiler/pushpack1.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/Compiler/poppack1.h"
    "C:/_Me_GitHub/connogge/build/_deps/assimp-src/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/_Me_GitHub/connogge/build/_deps/assimp-build/code/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
