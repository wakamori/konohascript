## json package
find_library(HAVE_LIB_JSON json)

set(PACKAGE_SOURCE_CODE json.c)
set(PACKAGE_SCRIPT_CODE json.k)
set(PACKAGE_INCLUDE_DIR)
set(PACKAGE_EXTRA_LIBRARY ${HAVE_LIB_JSON})
add_konoha_package(json HAVE_LIB_JSON)
