find_package(Doxygen)
option(DOCS "Build and Install Documents" ${DOXYGEN_FOUND})

if(DOCS)
    set(DOXYGEN_EXTRACT_ALL YES)
    set(DOXYGEN_STRIP_FROM_PATH ${CMAKE_SOURCE_DIR})
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE mainpage.md)

    doxygen_add_docs(
        docs
        ${CMAKE_SOURCE_DIR}/docs
        ${CMAKE_SOURCE_DIR}/src
        COMMENT "Generating Documentation"
        ALL
    )

    #This is only to show files used by the documentation
    #within the project tree
    target_sources(docs PRIVATE
        build.md
        CONTRIBUTING.md
        mainpage.md
    )
    install (DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/html" DESTINATION ${CMAKE_INSTALL_DOCDIR} COMPONENT ff7tk_development)
elseif(NOT DOXYGEN_FOUND)
    message(STATUS:"Doxygen Not Found; Documentation will not be built")
endif()
