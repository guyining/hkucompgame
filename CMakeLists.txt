cmake_minimum_required(VERSION 3.16)
project(OnirimProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(OnirimProject main.cpp Deck.cpp Deck.h Card.cpp Card.h Hand.cpp Hand.h)