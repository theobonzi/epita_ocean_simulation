#************************************************
#*                                              *
#*   OCEAN_RAYTRACING        Theo Bonzi         *
#*                           Marc Lagoin        *
#*                                       ING2 	*
#*                                              *
#************************************************

CC = g++

CPP_FILES = src/math/Vector3.cpp src/render/Image.cpp src/render/Color.cpp src/render/Ray.cpp src/object/Sphere.cpp src/object/Light.cpp src/math/Complex.cpp src/math/Vector2.cpp
HH_FILES  = src/math/Vector3.h src/render/Image.h src/render/Color.h src/render/Ray.h src/object/Object.h src/object/Light.cpp src/math/Complex.h src/math/Constants.h src/math/Fourier.h src/math/Numbers.h src/math/HeightFields.h src/math/Vector2.h

H_FILES =  $(HH_FILES)
OBJ_FILES = $(CPP_FILES:.cpp=.o)

CXX_FLAGS += -Wall -Wextra -O3 -g -std=c++11
CXX_FLAGS += -lm
CXX_FLAGS += -m64 -march=native
CXX_FLAGS += -fopt-info-vec-optimized #-fopt-info-vec-missed -ftree-vectorize
LDXX_FLAGS =

DIST_DIR = ocean

#For gcc 4.9
#CXXFLAGS+=-fdiagnostics-color=auto
export GCC_COLORS=1

define color
    if test `tput colors` -gt 0 ; then \
	tput setaf $(1); \
    fi
endef

define default_color
 if test `tput colors` -gt 0 ; then  tput sgr0 ; fi
endef


all: post-build

pre-build:
	@make clean
	@clear
	@$(call color,4)
	@echo "******** Starting Compilation ************"
	@$(call default_color)

post-build:
	@make --no-print-directory main-build ; \
	sta=$$?;	  \
	$(call color,4); \
	echo "*********** End Compilation **************"; \
	$(call default_color); \
	exit $$sta;

main-build: pre-build build

build: $(OBJ_FILES)
	#$(CC) src/main.cpp -o ocean $(CXX_FLAGS) $(LDXX_FLAGS)
	$(CC) src/main.cpp -o ocean $(OBJ_FILES) $(CXX_FLAGS) $(LDXX_FLAGS)

%.o: %.cpp %.hh
	@$(call color,2)
	@echo "[$@] $(CXX_FLAGS)"
	@$(call default_color)
	@$(CC) -c -o $@ $< $(CXX_FLAGS) ; \
	sta=$$?;	  \
	if [ $$sta -eq 0 ]; then  \
	  $(call color,2) ; \
	  echo "[$@ succes]" ; \
	  $(call default_color) ; \
	else  \
	  $(call color,1) ; \
	  echo "[$@ failure]" ; \
	  $(call default_color) ; \
	fi ;\
	exit $$sta

.PHONY: all clean pre-build post-build main-build build

clean:
	rm -f $(OBJ_FILES)
	rm -f $(DIST_DIR)