sources = [
  'test_inverted_index.cpp',
]

deps = [core_dep]
deps += test_common_deps

test_core_exe = executable('test_core', sources, dependencies: deps)
test('test core', test_core_exe)
