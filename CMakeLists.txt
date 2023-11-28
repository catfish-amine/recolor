cmake_minimum_required(VERSION 2.6)
#NAME
project (recolor_text)
include(CTest)
set (CMAKE_C_FLAGS "-std=c99 -g -Wall --coverage")

# pkg-config --list-all  | grep -i sdl2
include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_IMG REQUIRED SDL2_image)
pkg_search_module(SDL2_TTF REQUIRED SDL2_ttf)
set(SDL2_ALL_LIBS ${SDL2_LIBRARIES} ${SDL2_IMG_LIBRARIES} ${SDL2_TTF_LIBRARIES})
set(SDL2_ALL_INC ${SDL2_INCLUDE_DIRS} ${SDL2_IMG_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

#PROGRAM
add_executable (recolor_text recolor_text.c)
add_executable (recolor_solve recolor_solve.c)
include_directories(${SDL2_ALL_INC})
add_executable(recolor_sdl main.c recolor_sdl.c)

#LIBRARY
add_library(game game.c game_io.c game_rand.c game_box.c )
add_library(game_sol game.c game_io.c solver.c)
target_link_libraries (recolor_text game)
target_link_libraries (recolor_solve game_sol)
target_link_libraries(recolor_sdl ${SDL2_ALL_LIBS} m game)

#TESTS
add_executable (test_game_mouriche test_game_mouriche.c)
add_executable (test_game_oosmani test_game_oosmani.c)
add_executable (test_game_ibecher test_game_ibecher.c)
add_executable (test_game_mobenamara test_game_mobenamara.c)

target_link_libraries (test_game_mouriche game)
target_link_libraries (test_game_oosmani game)
target_link_libraries (test_game_ibecher game)
target_link_libraries (test_game_mobenamara game)


enable_testing()
add_test(test_mouriche_max_moves test_game_mouriche game_set_max_moves)
add_test(test_mouriche_cell_current_color test_game_mouriche game_cell_current_color)
add_test(test_mouriche_nb_moves_max test_game_mouriche game_nb_moves_max)
add_test(test_mouriche_game_new_empty_ext test_game_mouriche game_new_empty_ext)

add_test(test_oosmani_copy test_game_oosmani game_copy)
add_test(test_oosamni_play_one_move test_game_oosmani game_play_one_move)
add_test(test_oosmani_nb_moves_cur test_game_oosmani game_nb_moves_cur)
add_test(test_oosmani_game_new_ext test_game_oosmani game_new_ext)

add_test(test_ibecher_new test_game_ibecher game_new)
add_test(test_ibecher_new_empty test_game_ibecher game_new_empty)
add_test(test_ibecher_set_cell_init test_game_ibecher game_set_cell_init)
add_test(test_ibecher_game_height test_game_ibecher game_height)
add_test(test_ibecher_game_width test_game_ibecher game_width)
add_test(test_ibecher_game_is_wraaping test_game_ibecher game_is_wrapping)

add_test(test_mobenamara_restart test_game_mobenamara game_restart)
add_test(test_mobenamara_is_over test_game_mobenamara game_is_over)
add_test(test_mobenamara_delete test_game_mobenamara game_delete)
add_test(test_mobenamara_load test_game_mobenamara game_load)
add_test(test_mobenamara_save test_game_mobenamara game_save)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
