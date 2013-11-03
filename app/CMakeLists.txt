cmake_minimum_required(VERSION 2.6)

project(tatoblog)

# set the version
set(PROJECT_VERSION "0.6.2")
set(ARCHIVE_NAME ${CMAKE_PROJECT_NAME}-${PROJECT_VERSION})
add_custom_target(
    dist
    COMMAND git archive --prefix=${ARCHIVE_NAME}/ HEAD
        | bzip2 > ${CMAKE_BINARY_DIR}/${ARCHIVE_NAME}.tar.bz2
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)


#set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")



include_directories(
    src
)


set(
    FRAMEWORK_BUILD_DIR
    build
)


file(
    GLOB
    controllers_files
    src/controllers/*
    src/controllers/webs/*
    src/controllers/generics/*
)

file(
    GLOB
    models_files
    src/models/*
)

file(
    GLOB
    results_files
    src/results/*
)

file(
    GLOB
    contents_files
    src/contents/*
)


file(
    GLOB
    generics_files
    src/generics/*
)


add_executable(
    tatoblog
    src/TatoBlog.cpp
    src/main.cpp
    ${controllers_files}
    ${models_files}
    ${generics_files}
    ${results_files}
    ${contents_files}
    view_responsive_skin_web.cpp
)

set(
    MAIN_PROJECT_LIBS
    cppcms
    cppdb
    booster
    sqlite3
    cppcmsskel
    markdown
    #if you need to link with an other lib add it here
)




target_link_libraries(
    tatoblog
    ${MAIN_PROJECT_LIBS}
)



########################
#  Default responsive skin
########################
set(
    RESPONSIVE_WEB_SKIN_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/src/views/webs/responsive
)

add_custom_command(
    OUTPUT view_responsive_skin_web.cpp
    COMMAND cppcms_tmpl_cc 
        ${RESPONSIVE_WEB_SKIN_DIR}/layouts/master.tmpl
        ${RESPONSIVE_WEB_SKIN_DIR}/layouts/post_edition.tmpl
        ${RESPONSIVE_WEB_SKIN_DIR}/*/*.tmpl 
        -o view_responsive_skin_web.cpp
        -s responsive
    DEPENDS
        ${RESPONSIVE_WEB_SKIN_DIR}/*/*.tmpl 
)



####################
# unit tests
####################

#activate things to do unit testing
enable_testing()



set(
    ALL_TESTS
    #TODO add your tests there
)


foreach(TEST ${ALL_TESTS})
    add_executable(
        ${TEST}
        tests/${TEST}.cpp
        ${controllers_files}
        ${models_files}
        ${generics_files}
        ${results_files}
        ${contents_files}
    )
    target_link_libraries(${TEST} ${MAIN_PROJECT_LIBS})
    add_test(
        ${TEST}
        ${TEST}
    )
endforeach()


