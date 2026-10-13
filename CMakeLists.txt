cmake_minimum_required(VERSION 3.20)

# Nom du projet : changez-le pour chaque TD (sans espace ni accent).
project(Introcpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---------------------------------------------------------------------------
# Liste des fichiers du projet.
# CHAQUE nouveau fichier .cpp DOIT être ajouté ici, sinon il ne sera pas
# compilé (erreur « undefined reference » ou « LNK2019 »).
# Les .h sont listés aussi pour qu'ils apparaissent dans l'éditeur.
# ---------------------------------------------------------------------------
add_executable(${PROJECT_NAME}
    src/main.cpp
)

# Permet d'écrire #include "Example.h" depuis n'importe quel fichier de src/.
target_include_directories(${PROJECT_NAME} PRIVATE src)

# Avertissements activés : lisez-les, ils signalent souvent de vrais bugs.
if(MSVC)
    # /utf-8 : les accents dans le code source s'affichent correctement.
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /utf-8)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()
