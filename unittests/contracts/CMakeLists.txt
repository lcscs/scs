# will be implictly used for any compilation unit if not overrided by SYSTEM_INCLUDE_FOLDERS parameter
# these directories go as -isystem <dir> to avoid warnings from code of third-party libraries

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lcscs.bios/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/lcscs.bios/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lcscs.msig/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/lcscs.msig/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lcscs.system/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/lcscs.system/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lcscs.token/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/lcscs.token/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lcscs.wrap/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/lcscs.wrap/)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/old_versions/v1.6.0-rc3/lcscs.bios/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/old_versions/v1.6.0-rc3/lcscs.bios/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/old_versions/v1.7.0-develop-preactivate_feature/lcscs.bios/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/old_versions/v1.7.0-develop-preactivate_feature/lcscs.bios/)
