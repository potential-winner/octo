project('octo', 'cpp', default_options: ['cpp_std=c++20'])

spdlog_dep = dependency('spdlog', required: false)
if not spdlog_dep.found()
    spdlog_lib = subproject('spdlog')
    spdlog_dep = spdlog_lib.get_variable('spdlog_dep')
endif

subdir('src')
subdir('tests')
