add_rules("mode.debug", "mode.release")

add_requires("libsdl2")
add_requires("libsdl2_ttf")
add_requires("libsdl2_image")

target("proyecto")
    set_kind("binary")
    add_files("src/*.c")
    add_packages("libsdl2", "libsdl2_ttf", "libsdl2_image")
