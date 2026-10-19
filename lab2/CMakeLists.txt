project(lab2 LANGUAGES CXX)

set(exe_name ${PROJECT_NAME})

add_executable(${exe_name} main.cpp
        lib/ConfigReader.h
        lib/ConfigReader.cpp
        lib/converters/MuteConverter.h
        lib/converters/MuteConverterCreator.h
        lib/SoundProcessor.h
        lib/converters/Converter.h
        lib/SoundProcessor.cpp
        lib/WavReader.h
        lib/WavReader.cpp
        lib/WavWriter.h
        lib/WavWriter.cpp)