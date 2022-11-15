include_directory = include_directories('.')

sources = ['inverted_index.cpp']

deps = []

core_lib = static_library('core', sources, include_directories: include_directory, dependencies: deps)

core_dep = declare_dependency(dependencies: deps, include_directories: include_directory, link_with: core_lib)
