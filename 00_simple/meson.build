threads_dep = dependency('threads')

cc = meson.get_compiler('cpp')
i2c_dep = cc.find_library('i2c', required: true)

lib_include = include_directories('../lib')

executable(
    'test_ds2484',
    'test_ds2484.cpp',
    include_directories : lib_include,
    dependencies : [
        threads_dep,
        i2c_dep
    ],
   install : false
)