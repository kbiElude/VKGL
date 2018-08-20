NOTE:
=====

VKGL does not *compile* yet as it is still in very early development stage.

HOW TO BUILD:
=============

In order to build the project:

1. Clone the repository.
2. Download submodules:

git submodule init
git submodule update

3. Create "build" directory in VKGL root directory.
4. Create a solution for IDE of your choice using:

cmake -G "[YOUR IDE]" ..

5. Build the solution either from the IDE or using cmake:

cmake --build ..
