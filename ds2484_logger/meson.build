threads_dep = dependency('threads')

cc = meson.get_compiler('cpp')
i2c_lib = cc.find_library('i2c', required: true)

lib_include = include_directories('../lib')

executable(
    'ds2484_logger',
    'ds2484_logger.cpp',
    include_directories : lib_include,
    dependencies : [
        threads_dep,
        i2c_dep
    ],
    install : false
)