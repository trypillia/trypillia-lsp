cmake_minimum_required(VERSION 3.14)
project(trypillia-lsp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  trypillia_language
  GIT_REPOSITORY https://github.com/trypillia/trypillia-language.git
  GIT_TAG        main
)
FetchContent_MakeAvailable(trypillia_language)

FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG        v3.11.3
)
FetchContent_MakeAvailable(json)

add_executable(trypillia-lsp src/LSPMain.cpp src/LSP.cpp)
target_include_directories(trypillia-lsp PRIVATE ${trypillia_language_SOURCE_DIR}/src)
target_link_libraries(trypillia-lsp PRIVATE trypillia_core nlohmann_json::nlohmann_json)
