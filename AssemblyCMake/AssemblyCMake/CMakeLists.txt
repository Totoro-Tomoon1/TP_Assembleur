# CMakeList.txt : projet CMake pour AssemblyCMake, incluez la source et définissez
# la logique spécifique au projet ici.
#
enable_language(ASM_MASM)
# Ajoutez une source à l'exécutable de ce projet.
add_executable (AssemblyCMake "AssemblyCMake.cpp" "AssemblyCMake.h" "asm_basics.asm" "Chrono.h" "Chrono.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AssemblyCMake PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
