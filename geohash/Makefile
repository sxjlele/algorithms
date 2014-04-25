
#set your project name
PRJ_NAME = geohash-encoder

#set your project type : choose one below
PRJ_TYPE =  g++ -o

#set Debug or Release
COMPILE_FLAG = Release

#set your output path
OUTPUT:= ./build/

#set dist path, final output of the project result
DIST_PATH := .

#set your source folder
SRC:= ./

#add include files path
INCLUDEPATH :=
#add the lib you used here
LIBS :=  -lm -lpthread
LIBPATH := -L$(DIST_PATH)

###################################
#DON"T MODIFY THE BELOWS

#combine output folder
FINAL_PATH := $(OUTPUT)$(COMPILE_FLAG)/

#list all dirs
SUBDIRS := $(shell find $(SRC) -type d)
#flags in makefile
DEBUG_FLAG = -O0 -g3 -Wall -c -fmessage-length=0 -DLINUX -fPIC -DDEBUG
#-DNOMINMAX
RELEASE_FLAG = -O3 -Wall -c -fmessage-length=0 -DLINUX -fPIC -DNDEBUG
#-DNOMINMAX
RM := rm -rf

#set compile flag
ifeq ($(COMPILE_FLAG),Debug)
CFLAGS := $(DEBUG_FLAG)
else
CFLAGS := $(RELEASE_FLAG)
endif

#prepare files
CPP_SRCS:=$(shell find $(SRC) -name '*.cpp')
OBJS:=$(CPP_SRCS:%.cpp=$(FINAL_PATH)%.o)

#all target
all: dir $(FINAL_PATH)$(PRJ_NAME) todist

dir:
	@mkdir -p $(FINAL_PATH);
	@for val in $(SUBDIRS);do \
	  mkdir -p $(FINAL_PATH)$${val}; \
	done;

#tool invocations
$(FINAL_PATH)$(PRJ_NAME):$(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking:GCC C++ Linker'
	$(PRJ_TYPE) "$@" $^ $(LIBPATH) $(LIBS) 
	@echo 'Finished building target: $@'
	@echo ' '

$(FINAL_PATH)%o:./%cpp
	@echo 'Building file: $<'
	@echo 'Invoking:GCC C++ Compiler'
	g++ $(CFLAGS) $(INCLUDEPATH) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

todist:
	@mkdir -p $(DIST_PATH)
	@cp $(FINAL_PATH)$(PRJ_NAME) $(DIST_PATH)
	@echo 'Copied over to $(DIST_PATH)'
	@echo ' '

#other targets
clean:
	-$(RM) $(OUTPUT)*
	-$(RM) $(DIST_PATH)$(PRJ_NAME)
	-@echo ' '
.PHONY:all clean
.SECONDARY:

