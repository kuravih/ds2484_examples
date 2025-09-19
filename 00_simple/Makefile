CXX = g++
CC = gcc

LIB_DIR = ../lib
# =====================================================================================================================




# ==== kato source file ===============================================================================================
KATO_HEADERS = $(LIB_DIR)/kato/function.hpp $(LIB_DIR)/kato/log.hpp
KATO_CXXFLAGS = -I$(LIB_DIR)
# ==== kato source file ===============================================================================================




# ==== ds2484 source file =============================================================================================
DS2484_HEADERS = $(LIB_DIR)/ds2484/ds2484.hpp
DS2484_CXXFLAGS = -I$(LIB_DIR)
DS2484_LIBS = -li2c
# ==== ds2484 source file =============================================================================================





# ==== test source files ==============================================================================================
TEST_EXE = test_ds2484
TEST_SOURCES = test_ds2484.cpp
TEST_OBJS = $(addprefix ., $(addsuffix .o, $(basename $(notdir $(TEST_SOURCES)))))
# ==== test source files ==============================================================================================





# ==== gcc flags ======================================================================================================
CXXFLAGS = -Wall -Wextra -Wunused -Wformat -O3 -pthread
CXXFLAGS += $(KATO_CXXFLAGS)
CXXFLAGS += $(DS2484_CXXFLAGS)

LIBS = -lpthread 
LIBS += $(KATO_LIBS)
LIBS += $(DS2484_LIBS)

CFLAGS = $(CXXFLAGS)
CFLAGS_STD = $(CFLAGS) -std=c17
CXXFLAGS_STD = $(CXXFLAGS) -std=c++17
# ==== gcc flags ======================================================================================================





# ==== build rules ====================================================================================================
.%.o:%.cpp $(TEST_HEADERS)
	$(CXX) $(CXXFLAGS_STD) -c -o $@ $<

all: $(TEST_EXE)
	@echo Build complete

$(TEST_EXE): $(TEST_OBJS) $(KATO_HEADERS) $(DS2484_HEADERS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

clean_tester:
	rm -f $(TEST_EXE) $(TEST_OBJS)

clean: clean_tester
# ==== build rules ====================================================================================================
