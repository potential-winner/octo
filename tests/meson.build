catch2_with_main_dep = dependency('catch2-with-main', required: false)
if not catch2_with_main_dep.found()
    catch2_with_main_dep_lib = subproject('catch2')
    catch2_with_main_dep = catch2_with_main_dep_lib.get_variable('catch2_with_main_dep')
endif

test_common_deps = [spdlog_dep, catch2_with_main_dep]

subdir('core')
