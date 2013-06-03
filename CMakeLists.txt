cmake_minimum_required(VERSION 2.6)

project(only4kbps)

file(
	GLOB_RECURSE
	source_files
	src/*
)

file(
	GLOB_RECURSE
	data_files
	data/*
)

Find_Package(SDL REQUIRED)
Find_Package(SDL_image REQUIRED)

link_libraries (
   ${SDL_LIBRARY}
   ${SDLIMAGE_LIBRARY}
)

add_executable(
	only4kbps
	${source_files}
)
