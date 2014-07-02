project(primeextractor)

add_library( libmongoclient SHARED IMPORTED )

include_directories(  /usr/lib )

add_executable(primeextractor primeextractor.cpp main.cpp)

install(TARGETS primeextractor RUNTIME DESTINATION bin)
