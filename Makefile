SHELL=/bin/bash
CXX = g++
BIN = jdm
FOLDER= build

PROP = C:\JDM\.vscode\c_cpp_properties.json
TASK = C:\JDM\.vscode\tasks.json
MAIN = C:\JDM\src\main.cpp
DL1 = C:\JDM\build\libfreetype-6.dll
DL2 = C:\JDM\build\libpng16-16.dll
DL3 = C:\JDM\build\SDL2_image.dll
DL4 = C:\JDM\build\SDL2_ttf.dll
DL5 = C:\JDM\build\SDL2.dll
DL6 = C:\JDM\build\zlib1.dll

LIB = src .
C1 = $(wildcard C:/JDM/JDM/*.cpp)
C2 = $(wildcard C:/JDM/JDM/c_file/c_extra/*.cpp)
C3 = $(wildcard C:/JDM/JDM/c_file/c_game/*.cpp)
C4 = $(wildcard C:/JDM/JDM/c_file/c_helper/*.cpp)
C5 = $(wildcard C:/JDM/JDM/c_file/c_widget/*.cpp)
C6 = $(wildcard C:/JDM/JDM/c_file/c_special/*.cpp)
C7 = $(wildcard C:/JDM/JDM/c_file/c_widget/canvas/*.cpp)
C8 = $(wildcard C:/JDM/JDM/c_file/c_widget/widget/*.cpp)
C9 = $(wildcard C:/JDM/JDM/c_file/c_widget/layout/*.cpp)
C10 = $(wildcard C:/JDM/JDM/c_file/c_widget/behavior/*.cpp)
C11 = $(wildcard C:/JDM/JDM/c_file/c_widget/animation/*.cpp)
ALL_C = $(C1) $(C2) $(C3) $(C4) $(C5) $(C6) $(C7) $(C8) $(C9) $(C10) $(C11)

I1 = -I.
I1 = -IC:/JDM/JDM
I2 = -IC:/JDM/JDM/h_file/h_extra
I3 = -IC:/JDM/JDM/h_file/h_game
I4 = -IC:/JDM/JDM/h_file/h_helper
I5 = -IC:/JDM/JDM/h_file/h_special
I6 = -IC:/JDM/JDM/h_file/h_widget
I7 = -IC:/JDM/JDM/h_file/h_widget/canvas
I8 = -IC:/JDM/JDM/h_file/h_widget/layout
I9 = -IC:/JDM/JDM/h_file/h_widget/widget
I10 = -IC:/JDM/JDM/h_file/h_widget/behavior
I11 = -IC:/JDM/JDM/h_file/h_widget/animation
I12 = -IC:/JDM/include
I13 = -Iheader
ALL_I = $(I1) $(I2) $(I3) $(I4) $(I5) $(I6) $(I7) $(I8) $(I9) $(I10) $(I11) $(I12) $(13)

L1 = -LC:/JDM/lib

D1 = -lmingw32
D2 = -lSDL2main
D3 = -lSDL2
D4 = -lSDL2_image
D5 = -lSDL2_ttf

ALL_D = $(D1) $(D2) $(D3) $(D4) $(D5)
ALL_FILE = $(foreach D, $(LIB), $(wildcard $(D)/*.cpp))

all: intro create_folder compile copydll exec
test: compile

intro:
	@cls
	@echo ----------------------------------------------------
	@echo               Starting Building...
	@echo ----------------------------------------------------

compile:
	@echo            Compiling Neccessary File...
	@$(CXX) -std=c++17 $(ALL_I) $(L1) -o $(FOLDER)/$(BIN) $(ALL_FILE) $(ALL_C) $(ALL_D)


create_folder:
ifeq (,$(wildcard $(FOLDER)))
	@echo                Creating $(FOLDER)...
	@mkdir $(FOLDER)
endif

start:
	@cls
	@echo ----------------------------------------------------
	@echo                Making Template...
	@echo ----------------------------------------------------
ifeq (, $(wildcard src))
	@echo                  Creating src...
	@mkdir src
endif
ifeq (, $(wildcard header))
	@echo                 Creating header...
	@mkdir header
endif
ifeq (, $(wildcard .vscode))
	@echo                 Creating .vscode...
	@mkdir .vscode
endif
ifeq (, $(wildcard src/main.cpp))
	@echo F|xcopy $(MAIN) "src\\main.cpp" /Y > nul
endif
ifeq (, $(wildcard .vscode/c_cpp_properties.json))
	@echo F|xcopy $(PROP) ".vscode\\c_cpp_properties.json" /Y > nul
endif
ifeq (, $(wildcard .vscode/task.json))
	@echo F|xcopy $(TASK) ".vscode\\tasks.json" /Y > nul
endif
	@pause
	@cls

copydll:
	@echo                 Checking the DLL...
ifeq (, $(wildcard build/libfreetype-6.dll))
	@echo            Creating libfreetype-6.dll...
	@echo F|xcopy $(DL1) "build\\libfreetype-6.dll" /Y > nul
endif
ifeq (,$(wildcard build/libpng16-16.dll))
	@echo             Creating libpng16-16.dll...
	@echo F|xcopy $(DL2) "build\\libpng16-16.dll" /Y > nul
endif
ifeq (,$(wildcard build\\SDL2_image.dll))
	@echo             Creating SDL2_image.dll...
	@echo F|xcopy $(DL3) "build\\SDL2_image.dll" /Y > nul
endif
ifeq (,$(wildcard build\\SDL2_ttf.dll))
	@echo              Creating SDL2_ttf.dll...
	@echo F|xcopy $(DL4) "build\\SDL2_ttf.dll" /Y > nul
endif
ifeq (,$(wildcard build\\SDL2.dll))
	@echo                Creating SDL2.dll...
	@echo F|xcopy $(DL5) "build\\SDL2.dll" /Y > nul
endif
ifeq (,$(wildcard build\\zlib1.dll))
	@echo                Creating zlib1.dll...
	@echo F|xcopy $(DL6) "build\\zlib1.dll" /Y > nul
endif
	@echo ----------------------------------------------------

exec:
	@cls
	@echo ----------------------------------------------------
	@./$(FOLDER)/$(BIN).exe
	

clean:
	@del $(FOLDER)\$(BIN).exe
	@cls
