cmake_minimum_required(VERSION 3.15)

project(lien_utils LANGUAGES CXX)

add_library(lien_utils
    "src/base64.cpp"
    "src/bit_view.cpp"
    "src/platform.cpp"
)

set_target_properties(lien_utils PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

target_include_directories(lien_utils PUBLIC include)